#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>

bool validateNumber(const std::string& arg)
{
    if (arg.empty() || arg[0] == '-')
        return false;
    
    for (size_t i = 0; i < arg.length(); i++)
    {
        if (!isdigit(static_cast<unsigned char>(arg[i])))
            return false;
    }
    
    errno = 0;
    long value = strtol(arg.c_str(), NULL, 10);
    if (errno == ERANGE || value > INT_MAX || value < 0)
        return false;
    
    return true;
}

bool validateArguments(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error\n";
        return false;
    }
    
    for (int i = 1; i < argc; i++)
    {
        if (!validateNumber(argv[i]))
        {
            std::cerr << "Error\n";
            return false;
        }
    }
    return true;
}

void parseInputToVector(int argc, char** argv, std::vector<int>& output)
{
    output.clear();
    output.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        output.push_back(atoi(argv[i]));
    }
}

void parseInputToList(int argc, char** argv, std::list<int>& output)
{
    output.clear();
    for (int i = 1; i < argc; i++)
    {
        output.push_back(atoi(argv[i]));
    }
}

void displaySequence(const std::string& label, const std::vector<int>& data, size_t maxDisplay)
{
    std::cout << label;
    size_t displayCount = data.size() < maxDisplay ? data.size() : maxDisplay;
    
    for (size_t i = 0; i < displayCount; i++)
    {
        if (i > 0)
            std::cout << " ";
        std::cout << data[i];
    }
    
    if (data.size() > maxDisplay)
        std::cout << " [...]";
    
    std::cout << "\n";
}

template <typename Container>
bool verifySorted(const Container& data)
{
    for (size_t i = 1; i < data.size(); i++)
    {
        if (data[i - 1] > data[i])
            return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    if (!validateArguments(argc, argv))
        return 1;
    
    PmergeMe sorter;
    
    clock_t vectorStart = clock();
    std::vector<int> originalData;
    parseInputToVector(argc, argv, originalData);
    std::vector<int> vectorData = originalData;
    PmergeMe::resetComparisonCount();
    sorter.sortVector(vectorData);
    size_t vectorComparisons = PmergeMe::getComparisonCount();
    clock_t vectorEnd = clock();
    double vectorTime = static_cast<double>(vectorEnd - vectorStart) / CLOCKS_PER_SEC * 1000000;
    
    clock_t listStart = clock();
    std::list<int> listData;
    parseInputToList(argc, argv, listData);
    PmergeMe::resetComparisonCount();
    sorter.sortList(listData);
    size_t listComparisons = PmergeMe::getComparisonCount();
    clock_t listEnd = clock();
    double listTime = static_cast<double>(listEnd - listStart) / CLOCKS_PER_SEC * 1000000;
    
    std::vector<int> listAsVec(listData.begin(), listData.end());
    if (!verifySorted(vectorData) || !verifySorted(listAsVec))
    {
        std::cerr << "Error: Sorting failed\n";
        return 1;
    }
    
    displaySequence("Before: ", originalData, 5);
    displaySequence("After:  ", vectorData, 5);
    
    std::cout << "Time to process a range of " << vectorData.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(5)
              << vectorTime << " us\n";
    std::cout << "Comparisons used with std::vector: " << vectorComparisons << "\n";
    
    std::cout << "Time to process a range of " << listData.size()
              << " elements with std::list:    " << std::fixed << std::setprecision(5)
              << listTime << " us\n";
    std::cout << "Comparisons used with std::list:    " << listComparisons << "\n";
    
    return 0;
}
