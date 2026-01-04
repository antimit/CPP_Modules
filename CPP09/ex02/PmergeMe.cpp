#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <iterator>
#include <list>

size_t PmergeMe::comparisonCount = 0;

struct FJPair
{
    size_t small;
    size_t large;
};

struct ListPair
{
    PmergeMe::ListNodeRef small;
    PmergeMe::ListNodeRef large;
};

bool PmergeMe::lessThan(int lhs, int rhs)
{
    comparisonCount++;
    return lhs < rhs;
}

void PmergeMe::resetComparisonCount() { comparisonCount = 0; }

size_t PmergeMe::getComparisonCount() { return comparisonCount; }

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe() {}

// ============================================================================
// JACOBSTHAL SEQUENCE
// ============================================================================

static size_t jacobsthal(size_t n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    size_t a = 0, b = 1;
    for (size_t i = 2; i <= n; ++i)
    {
        size_t c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

// Build Jacobsthal-based insertion order for pend elements
// Returns indices into pend array in optimal insertion order
static std::vector<size_t> buildInsertionOrder(size_t pendSize)
{
    std::vector<size_t> order;
    if (pendSize == 0)
        return order;

    order.push_back(0);
    for (size_t k = 2; order.size() < pendSize; ++k)
    {
        size_t jk = jacobsthal(k);
        size_t jprev = jacobsthal(k - 1);
        size_t limit = jk > pendSize ? pendSize : jk;
        for (size_t idx = limit; idx > jprev && order.size() < pendSize; --idx)
            order.push_back(idx - 1);
    }
    return order;
}

static std::list<size_t> buildInsertionOrderList(size_t pendSize)
{
    std::list<size_t> order;
    if (pendSize == 0)
        return order;

    order.push_back(0);
    for (size_t k = 2; order.size() < pendSize; ++k)
    {
        size_t jk = jacobsthal(k);
        size_t jprev = jacobsthal(k - 1);
        size_t limit = jk > pendSize ? pendSize : jk;
        for (size_t idx = limit; idx > jprev && order.size() < pendSize; --idx)
            order.push_back(idx - 1);
    }
    return order;
}

// ============================================================================
// VECTOR IMPLEMENTATION - FORD-JOHNSON WITH INDEX GROUPS
// ============================================================================

void PmergeMe::sortVector(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;
    
    // Work with indices into original data to keep duplicate ordering deterministic
    std::vector<size_t> indices(data.size());
    for (size_t i = 0; i < data.size(); ++i)
        indices[i] = i;
    
    mergeInsertVector(data, indices);
    
    // Reorder data according to sorted indices
    std::vector<int> result(data.size());
    for (size_t i = 0; i < indices.size(); ++i)
        result[i] = data[indices[i]];
    data = result;
}

static bool lessWithIndexTiebreak(const std::vector<int>& vals,
                                  size_t lhsIdx,
                                  size_t rhsIdx,
                                  bool (*cmp)(int, int))
{
    bool lhsLess = cmp(vals[lhsIdx], vals[rhsIdx]);
    if (!lhsLess && vals[lhsIdx] == vals[rhsIdx])
        return lhsIdx < rhsIdx;
    return lhsLess;
}

static size_t binarySearchIdx(const std::vector<int>& vals, const std::vector<size_t>& chain,
                              size_t valueIdx, size_t left, size_t right,
                              bool (*cmp)(int, int))
{
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (lessWithIndexTiebreak(vals, chain[mid], valueIdx, cmp))
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

static bool lessWithIndexTiebreakNode(const PmergeMe::ListNodeRef& lhs,
                                      const PmergeMe::ListNodeRef& rhs,
                                      bool (*cmp)(int, int))
{
    bool lhsLess = cmp(*lhs.it, *rhs.it);
    if (!lhsLess && *lhs.it == *rhs.it)
        return lhs.idx < rhs.idx;
    return lhsLess;
}

static size_t findPositionByIdx(const std::list<PmergeMe::ListNodeRef>& chain, size_t targetIdx)
{
    size_t pos = 0;
    for (std::list<PmergeMe::ListNodeRef>::const_iterator it = chain.begin(); it != chain.end(); ++it, ++pos)
    {
        if (it->idx == targetIdx)
            return pos;
    }
    return pos;
}

static std::list<PmergeMe::ListNodeRef>::iterator binarySearchList(
    std::list<PmergeMe::ListNodeRef>& chain,
    const PmergeMe::ListNodeRef& value,
    size_t left,
    size_t right,
    bool (*cmp)(int, int))
{
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        std::list<PmergeMe::ListNodeRef>::iterator midIt = chain.begin();
        std::advance(midIt, mid);
        if (lessWithIndexTiebreakNode(*midIt, value, cmp))
            left = mid + 1;
        else
            right = mid;
    }
    std::list<PmergeMe::ListNodeRef>::iterator insertPos = chain.begin();
    std::advance(insertPos, left);
    return insertPos;
}

void PmergeMe::mergeInsertVector(std::vector<int>& vals, std::vector<size_t>& indices)
{
    size_t n = indices.size();
    if (n <= 1)
        return;

    std::vector<FJPair> pairs;
    pairs.reserve(n / 2);

    bool hasStraggler = (n % 2 == 1);
    size_t stragglerIdx = hasStraggler ? indices.back() : 0;

    // Pair formation
    for (size_t i = 0; i + 1 < n; i += 2)
    {
        size_t a = indices[i];
        size_t b = indices[i + 1];
        FJPair p;
        if (lessThan(vals[a], vals[b]))
        {
            p.small = a;
            p.large = b;
        }
        else
        {
            p.small = b;
            p.large = a;
        }
        pairs.push_back(p);
    }

    // Recursively sort by larger elements to minimize comparisons
    size_t numPairs = pairs.size();
    if (numPairs > 1)
    {
        std::vector<size_t> largerIndices(numPairs);
        for (size_t i = 0; i < numPairs; ++i)
            largerIndices[i] = pairs[i].large;

        mergeInsertVector(vals, largerIndices);

        // Reorder pairs to match sorted largerIndices
        std::vector<FJPair> sortedPairs;
        sortedPairs.reserve(numPairs);
        for (size_t i = 0; i < numPairs; ++i)
        {
            size_t target = largerIndices[i];
            for (size_t j = 0; j < numPairs; ++j)
            {
                if (pairs[j].large == target)
                {
                    sortedPairs.push_back(pairs[j]);
                    break;
                }
            }
        }
        pairs.swap(sortedPairs);
    }

    // Build main chain and pending inserts
    std::vector<size_t> mainChain;
    std::vector<size_t> pend;

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        mainChain.push_back(pairs[i].large);
        pend.push_back(pairs[i].small);
    }

    if (hasStraggler)
        pend.push_back(stragglerIdx);

    // Insert pend using Jacobsthal order, bounding search to partner (or end for straggler)
    std::vector<size_t> order = buildInsertionOrder(pend.size());
    for (size_t k = 0; k < order.size(); ++k)
    {
        size_t pendIdx = order[k];
        size_t valueIdx = pend[pendIdx];

        // By definition, the first pend element leads the chain with zero comparisons.
        if (pendIdx == 0)
        {
            mainChain.insert(mainChain.begin(), valueIdx);
            continue;
        }

        size_t boundPos;
        if (pendIdx < pairs.size())
        {
            size_t partnerValue = pairs[pendIdx].large;
            std::vector<size_t>::iterator boundIt = std::find(mainChain.begin(), mainChain.end(), partnerValue);
            boundPos = static_cast<size_t>(boundIt - mainChain.begin());
        }
        else
        {
            boundPos = mainChain.size();
        }

        size_t pos = binarySearchIdx(vals, mainChain, valueIdx, 0, boundPos, lessThan);
        mainChain.insert(mainChain.begin() + pos, valueIdx);
    }

    indices = mainChain;
}

void PmergeMe::mergeInsertList(std::list<ListNodeRef>& nodes)
{
    size_t n = nodes.size();
    if (n <= 1)
        return;

    std::list<ListPair> pairs;
    bool hasStraggler = (n % 2 == 1);
    ListNodeRef straggler;
    bool stragglerSet = false;

    // Pair formation
    std::list<ListNodeRef>::iterator it = nodes.begin();
    while (it != nodes.end())
    {
        ListNodeRef first = *it;
        ++it;
        if (it == nodes.end())
        {
            if (hasStraggler)
            {
                straggler = first;
                stragglerSet = true;
            }
            break;
        }
        ListNodeRef second = *it;
        ++it;

        ListPair p;
        if (lessThan(*first.it, *second.it))
        {
            p.small = first;
            p.large = second;
        }
        else
        {
            p.small = second;
            p.large = first;
        }
        pairs.push_back(p);
    }

    // Recursively sort by larger elements to minimize comparisons
    if (pairs.size() > 1)
    {
        std::list<ListNodeRef> largerElements;
        for (std::list<ListPair>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
            largerElements.push_back(pit->large);

        mergeInsertList(largerElements);

        std::list<ListPair> sortedPairs;
        for (std::list<ListNodeRef>::iterator lit = largerElements.begin(); lit != largerElements.end(); ++lit)
        {
            for (std::list<ListPair>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
            {
                if (pit->large.idx == lit->idx)
                {
                    sortedPairs.push_back(*pit);
                    pairs.erase(pit);
                    break;
                }
            }
        }
        pairs.swap(sortedPairs);
    }

    // Build main chain and pending inserts
    std::list<ListNodeRef> mainChain;
    std::list<ListNodeRef> pend;

    for (std::list<ListPair>::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
    {
        mainChain.push_back(pit->large);
        pend.push_back(pit->small);
    }

    if (hasStraggler && stragglerSet)
        pend.push_back(straggler);

    // Insert pend using Jacobsthal order, bounding search to partner (or end for straggler)
    std::list<size_t> order = buildInsertionOrderList(pend.size());
    size_t pairCount = pairs.size();
    for (std::list<size_t>::iterator oit = order.begin(); oit != order.end(); ++oit)
    {
        size_t pendIdx = *oit;
        std::list<ListNodeRef>::iterator pendIt = pend.begin();
        std::advance(pendIt, pendIdx);
        ListNodeRef value = *pendIt;

        // By definition, the first pend element leads the chain with zero comparisons.
        if (pendIdx == 0)
        {
            mainChain.push_front(value);
            continue;
        }

        size_t boundPos;
        if (pendIdx < pairCount)
        {
            std::list<ListPair>::iterator pairIt = pairs.begin();
            std::advance(pairIt, pendIdx);
            boundPos = findPositionByIdx(mainChain, pairIt->large.idx);
        }
        else
        {
            boundPos = mainChain.size();
        }

        std::list<ListNodeRef>::iterator insertPos = binarySearchList(mainChain, value, 0, boundPos, lessThan);
        mainChain.insert(insertPos, value);
    }

    nodes.swap(mainChain);
}

// ============================================================================
// LIST IMPLEMENTATION
// ============================================================================

void PmergeMe::sortList(std::list<int>& data)
{
    if (data.size() <= 1)
        return;

    std::list<ListNodeRef> nodes;
    size_t idx = 0;
    for (std::list<int>::iterator it = data.begin(); it != data.end(); ++it, ++idx)
    {
        ListNodeRef ref;
        ref.it = it;
        ref.idx = idx;
        nodes.push_back(ref);
    }

    mergeInsertList(nodes);

    std::list<int> sorted;
    for (std::list<ListNodeRef>::iterator it = nodes.begin(); it != nodes.end(); ++it)
        sorted.push_back(*it->it);
    data.swap(sorted);
}
