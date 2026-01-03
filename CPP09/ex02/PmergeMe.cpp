#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <list>

size_t PmergeMe::comparisonCount = 0;

struct FJPair
{
    size_t small;
    size_t large;
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

// ============================================================================
// VECTOR IMPLEMENTATION - FORD-JOHNSON WITH INDEX GROUPS
// ============================================================================

void PmergeMe::sortVector(std::vector<int>& data)
{
    if (data.size() <= 1)
        return;
    
    // Work with indices into original data to handle duplicates correctly
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

static size_t binarySearchIdx(const std::vector<int>& vals, const std::vector<size_t>& chain,
                              int value, size_t left, size_t right,
                              bool (*cmp)(int, int))
{
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        if (cmp(vals[chain[mid]], value))
            left = mid + 1;
        else
            right = mid;
    }
    return left;
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
        std::vector<bool> used(numPairs, false);
        std::vector<FJPair> sortedPairs;
        sortedPairs.reserve(numPairs);
        for (size_t i = 0; i < numPairs; ++i)
        {
            size_t target = largerIndices[i];
            for (size_t j = 0; j < numPairs; ++j)
            {
                if (!used[j] && pairs[j].large == target)
                {
                    sortedPairs.push_back(pairs[j]);
                    used[j] = true;
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

        size_t pos = binarySearchIdx(vals, mainChain, vals[valueIdx], 0, boundPos, lessThan);
        mainChain.insert(mainChain.begin() + pos, valueIdx);
    }

    indices = mainChain;
}

// ============================================================================
// LIST IMPLEMENTATION
// ============================================================================

void PmergeMe::sortList(std::list<int>& data)
{
    if (data.size() <= 1)
        return;

    std::vector<int> tmp(data.begin(), data.end());
    sortVector(tmp);
    data.assign(tmp.begin(), tmp.end());
}
