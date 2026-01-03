#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>

// Theoretical upper bound for comparisons from the provided formula
int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k)
    {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(std::ceil(std::log(value) / std::log(2.0)));
    }
    return sum;
}

template <typename It>
bool isSorted(It first, It last)
{
    if (first == last)
        return true;
    It prev = first;
    for (It it = ++first; it != last; ++it, ++prev)
    {
        if (*prev > *it)
            return false;
    }
    return true;
}

struct CaseResult
{
    size_t vectorComparisons;
    size_t listComparisons;
    bool vectorSorted;
    bool listSorted;
};

struct NStats
{
    size_t bound;
    size_t runs;
    size_t worstVectorComps;
    bool exceededBound;
    bool sortedFail;
    bool initialized;
    NStats() : bound(0), runs(0), worstVectorComps(0), exceededBound(false), sortedFail(false), initialized(false) {}
};

CaseResult runCase(const std::vector<int>& input)
{
    CaseResult res;
    PmergeMe sorter;

    std::vector<int> vec = input;
    PmergeMe::resetComparisonCount();
    sorter.sortVector(vec);
    res.vectorComparisons = PmergeMe::getComparisonCount();
    res.vectorSorted = isSorted(vec.begin(), vec.end());

    std::list<int> lst(input.begin(), input.end());
    PmergeMe::resetComparisonCount();
    sorter.sortList(lst);
    res.listComparisons = PmergeMe::getComparisonCount();
    res.listSorted = isSorted(lst.begin(), lst.end());

    return res;
}

void logFailure(int n, const std::vector<int>& input, const CaseResult& res, size_t bound)
{
    std::cout << "Failure for n=" << n << " (bound=" << bound << ")\n";
    std::cout << "  Input: ";
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (i)
            std::cout << " ";
        std::cout << input[i];
    }
    std::cout << "\n";
    std::cout << "  Vector sorted=" << res.vectorSorted << " comps=" << res.vectorComparisons
              << " withinBound=" << (res.vectorComparisons <= bound) << "\n";
    std::cout << "  List   sorted=" << res.listSorted << " comps=" << res.listComparisons << "\n";
}

void exhaustivePermutationsUpTo8(size_t& totalRuns, size_t& failures, size_t& worstVectorComps, std::vector<NStats>& stats)
{
    for (int n = 1; n <= 8; ++n)
    {
        std::vector<int> data;
        for (int i = 1; i <= n; ++i)
            data.push_back(i);

        size_t bound = static_cast<size_t>(F(n));
        stats[n].bound = bound;
        stats[n].initialized = true;
        do
        {
            CaseResult res = runCase(data);
            ++totalRuns;
            ++stats[n].runs;
            if (!res.vectorSorted || !res.listSorted || res.vectorComparisons > bound)
            {
                ++failures;
                logFailure(n, data, res, bound);
                stats[n].sortedFail = stats[n].sortedFail || (!res.vectorSorted || !res.listSorted);
                stats[n].exceededBound = stats[n].exceededBound || (res.vectorComparisons > bound);
            }
            if (res.vectorComparisons > worstVectorComps)
                worstVectorComps = res.vectorComparisons;
            if (res.vectorComparisons > stats[n].worstVectorComps)
                stats[n].worstVectorComps = res.vectorComparisons;
        } while (std::next_permutation(data.begin(), data.end()));
    }
}

void sampledPermutations9to30(size_t& totalRuns, size_t& failures, size_t& worstVectorComps, std::vector<NStats>& stats)
{
    const int samplesPerN = 200;
    for (int n = 9; n <= 30; ++n)
    {
        std::vector<int> data;
        for (int i = 1; i <= n; ++i)
            data.push_back(i);

        size_t bound = static_cast<size_t>(F(n));
        stats[n].bound = bound;
        stats[n].initialized = true;
        for (int s = 0; s < samplesPerN; ++s)
        {
            std::random_shuffle(data.begin(), data.end());
            CaseResult res = runCase(data);
            ++totalRuns;
            ++stats[n].runs;
            if (!res.vectorSorted || !res.listSorted || res.vectorComparisons > bound)
            {
                ++failures;
                logFailure(n, data, res, bound);
                stats[n].sortedFail = stats[n].sortedFail || (!res.vectorSorted || !res.listSorted);
                stats[n].exceededBound = stats[n].exceededBound || (res.vectorComparisons > bound);
            }
            if (res.vectorComparisons > worstVectorComps)
                worstVectorComps = res.vectorComparisons;
            if (res.vectorComparisons > stats[n].worstVectorComps)
                stats[n].worstVectorComps = res.vectorComparisons;
        }
    }
}

void largeRandom3000()
{
    const int n = 3000;
    std::vector<int> data;
    data.reserve(n);
    for (int i = 1; i <= n; ++i)
        data.push_back(i);
    std::random_shuffle(data.begin(), data.end());

    size_t bound = static_cast<size_t>(F(n));
    CaseResult res = runCase(data);

    std::cout << "3000-element random test:\n";
    std::cout << "  vector sorted=" << res.vectorSorted << " comps=" << res.vectorComparisons
              << " bound=" << bound << " withinBound=" << (res.vectorComparisons <= bound) << "\n";
    std::cout << "  list   sorted=" << res.listSorted << " comps=" << res.listComparisons << "\n";
}

void printSummary(const std::vector<NStats>& stats)
{
    std::cout << "\nPer-n summary (1..30):\n";
    for (size_t n = 1; n < stats.size(); ++n)
    {
        if (!stats[n].initialized)
            continue;
        std::cout << "  n=" << n
                  << " runs=" << stats[n].runs
                  << " bound=" << stats[n].bound
                  << " worstVectorComps=" << stats[n].worstVectorComps
                  << " exceededBound=" << stats[n].exceededBound
                  << " sortedFail=" << stats[n].sortedFail
                  << "\n";
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    size_t totalRuns = 0;
    size_t failures = 0;
    size_t worstVectorComps = 0;
    std::vector<NStats> stats(31);

    exhaustivePermutationsUpTo8(totalRuns, failures, worstVectorComps, stats);
    if (failures == 0)
        sampledPermutations9to30(totalRuns, failures, worstVectorComps, stats);

    if (failures == 0)
    {
        std::cout << "Checked " << totalRuns << " cases (permutations up to 8 exhaustively, 200 samples each for n=9..30).\n";
        std::cout << "Worst vector comparisons observed: " << worstVectorComps << "\n";
        std::cout << "All cases sorted correctly and within F(n) bound.\n";
    }
    else
    {
        std::cout << "Testing aborted after first failure.\n";
    }

    printSummary(stats);
    largeRandom3000();

    return failures == 0 ? 0 : 1;
}
