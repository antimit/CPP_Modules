#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    int processInputFile(const std::string& inputFileName);

  private:
    static const std::string DATABASE_FILENAME;
    std::map<std::string, double> priceHistory;

    bool initializePriceDatabase();
    void evaluateInputFile(const std::string& inputFileName);
    
    bool extractAndStorePriceEntry(const std::string& line, char separator);
    void evaluateAndDisplayExchange(const std::string& line);
    double retrieveRateForDate(const std::string& date) const;
    
    bool validateDateFormat(const std::string& date) const;
    bool validateDateLogic(int year, int month, int day) const;
    bool parseNumericValue(const std::string& str, double& result) const;
    void displayError(const std::string& message) const;
    void displayResult(const std::string& date, double amount, double rate) const;
    
    std::string trimWhitespace(const std::string& str) const;
    bool splitString(const std::string& line, const std::string& delimiter, 
                     std::string& left, std::string& right) const;
};

#endif
