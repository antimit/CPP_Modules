#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <vector>
#include <cstddef>

class PmergeMe
{
  public:
    struct ListNodeRef
    {
        std::list<int>::iterator it;
        size_t idx;
    };

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortVector(std::vector<int>& data);
    void sortList(std::list<int>& data);

    // Comparison tracking (useful for validating Jacobsthal insertion bounds)
    static void resetComparisonCount();
    static size_t getComparisonCount();

  private:
    static bool lessThan(int lhs, int rhs);
    static size_t comparisonCount;

    // Core Ford-Johnson recursive implementation
    void mergeInsertVector(std::vector<int>& vals, std::vector<size_t>& indices);
    void mergeInsertList(std::list<ListNodeRef>& nodes);
};

#endif
