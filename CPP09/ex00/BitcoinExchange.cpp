#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>

const std::string BitcoinExchange::DATABASE_FILENAME("data.csv");

BitcoinExchange::BitcoinExchange() : priceHistory() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : priceHistory(other.priceHistory) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        priceHistory = other.priceHistory;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::processInputFile(const std::string& inputFileName)
{
    if (!initializePriceDatabase())
        return 1;
    
    evaluateInputFile(inputFileName);
    return 0;
}

std::string BitcoinExchange::trimWhitespace(const std::string& str) const
{
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;
    
    return str.substr(start, end - start);
}

bool BitcoinExchange::splitString(const std::string& line, const std::string& delimiter,
                                   std::string& left, std::string& right) const
{
    size_t pos = line.find(delimiter);
    if (pos == std::string::npos)
        return false;
    
    left = line.substr(0, pos);
    right = line.substr(pos + delimiter.length());
    return true;
}

bool BitcoinExchange::parseNumericValue(const std::string& str, double& result) const
{
    if (str.empty())
        return false;
    
    int dotCount = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
        else if (!isdigit(str[i]))
            return false;
    }
    
    std::istringstream iss(str);
    iss >> result;
    return !iss.fail();
}

bool BitcoinExchange::validateDateLogic(int year, int month, int day) const
{
    struct tm testDate = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    testDate.tm_year = year - 1900;
    testDate.tm_mon = month - 1;
    testDate.tm_mday = day;
    testDate.tm_isdst = -1;
    
    struct tm originalDate = testDate;
    mktime(&testDate);
    
    return (testDate.tm_year == originalDate.tm_year &&
            testDate.tm_mon == originalDate.tm_mon &&
            testDate.tm_mday == originalDate.tm_mday);
}

bool BitcoinExchange::validateDateFormat(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return false;
    }
    
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    
    return validateDateLogic(year, month, day);
}

bool BitcoinExchange::initializePriceDatabase()
{
    std::ifstream dbFile(DATABASE_FILENAME.c_str());
    if (!dbFile.is_open())
    {
        std::cout << "Critical error: could not access database " << DATABASE_FILENAME << "\n";
        return false;
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(dbFile, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            if (line == "date,exchange_rate")
                continue;
        }
        
        if (!extractAndStorePriceEntry(line, ','))
        {
            dbFile.close();
            if (line.empty())
                std::cout << "Critical error: invalid database => {empty}\n";
            else
                std::cout << "Critical error: invalid database => " << line << "\n";
            return false;
        }
    }
    
    dbFile.close();
    return true;
}

bool BitcoinExchange::extractAndStorePriceEntry(const std::string& line, char separator)
{
    std::string dateStr, valueStr;
    std::string delimStr(1, separator);
    
    if (!splitString(line, delimStr, dateStr, valueStr))
        return false;
    
    dateStr = trimWhitespace(dateStr);
    valueStr = trimWhitespace(valueStr);
    
    if (!validateDateFormat(dateStr))
        return false;
    
    double price;
    if (!parseNumericValue(valueStr, price) || price < 0)
        return false;
    
    priceHistory[dateStr] = price;
    return true;
}

double BitcoinExchange::retrieveRateForDate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator exact = priceHistory.find(date);
    if (exact != priceHistory.end())
        return exact->second;
    
    std::map<std::string, double>::const_iterator upper = priceHistory.upper_bound(date);
    
    if (upper == priceHistory.begin())
        return priceHistory.begin()->second;
    
    --upper;
    return upper->second;
}

void BitcoinExchange::displayError(const std::string& message) const
{
    std::cout << "Error: " << message << "\n";
}

void BitcoinExchange::displayResult(const std::string& date, double amount, double rate) const
{
    std::cout << date << " => " << amount << " = " << (amount * rate) << "\n";
}

void BitcoinExchange::evaluateAndDisplayExchange(const std::string& line)
{
    std::string dateStr, amountStr;
    
    if (!splitString(line, " | ", dateStr, amountStr))
    {
        displayError("no ' | ' delimeter or value after it => " + line);
        return;
    }
    
    dateStr = trimWhitespace(dateStr);
    amountStr = trimWhitespace(amountStr);
    
    if (!validateDateFormat(dateStr))
    {
        displayError("bad input => " + dateStr);
        return;
    }
    
    double amount;
    if (!parseNumericValue(amountStr, amount))
    {
        displayError("not a positive number => " + amountStr);
        return;
    }
    
    if (amount < 0)
    {
        displayError("not a positive number => " + amountStr);
        return;
    }
    
    if (amount > 1000)
    {
        displayError("the number is too large => " + amountStr);
        return;
    }
    
    double rate = retrieveRateForDate(dateStr);
    displayResult(dateStr, amount, rate);
}

void BitcoinExchange::evaluateInputFile(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Critical error: could not access input file " << inputFileName << "\n";
        return;
    }
    
    std::string line;
    bool isFirstLine = true;
    
    while (std::getline(inputFile, line))
    {
        if (isFirstLine)
        {
            isFirstLine = false;
            if (line == "date | value")
                continue;
        }
        
        evaluateAndDisplayExchange(line);
    }
    
    inputFile.close();
}
