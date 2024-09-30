#include "credit.h"

int getSumOfDigits(int creditCardNum) {

    int sum{};

    while (creditCardNum % 10 > 0) {
        sum += creditCardNum % 10;
        creditCardNum = creditCardNum / 10;
    }

    return sum;
}


bool startsWith(const std::string& cardNum, std::string prefix) {

    if (prefix.length() == 2 && cardNum.substr(0, 2) == prefix) {
        return true;
    }

    if (cardNum.substr(0, 1) == prefix) {
        return true;
    }

    return false;
}


bool hasValidPrefix(const std::string& cardNum) {

    for (int i = 0; i < std::size(Constants::validPrefixes); i++) {
        if (startsWith(cardNum, Constants::validPrefixes[i])) {
            return true;
        }
    }

    return false;
}


int sumOddDigitsRightToLeft(const std::string& cardNum) {
    //int totalOddNum = (cardNum.length() % 2 + cardNum.length() / 2);
    int sum{ 0 };

    for (int i = cardNum.length() - 1; i >= 0; --i) {
        if ((cardNum.length() - i - 1) % 2 == 0) {
            //because static_cast can't cast char into integer correctly, but cast char into ASCII value, so we need to subtract ascii value of '0'
            // to get the correct value.
            sum += static_cast<int>(cardNum.at(i) - '0');
            //std::cout << "\n at i" << cardNum.at(i) << "\n";
        }
    }
    return sum;
}


int sumEvenDigitsRightToLeft(const std::string& cardNum) {
    int sum{};

    for (int i = cardNum.length() - 1; i >= 0; --i) {
        //std::cout<<i;
        if ((cardNum.length() - i - 1) % 2 != 0) {
            if ((static_cast<int>(cardNum.at(i) - '0') * 2) > 9) {
                sum += static_cast<int>(cardNum.at(i) - '0') * 2 - 10 + 1;
                //std::cout << sum<<"\n"<<static_cast<int>(cardNum.at(i) - '0') * 2 - 10 + 1;
            }
            else
                //because static_cast can't cast char into integer correctly, but cast char into ASCII value, so we need to minus '0' to get the correct value.
                sum += static_cast<int>(cardNum.at(i) - '0') * 2;
        }
    }
    return sum;
}


bool isCardValid(const std::string& cardNum) {
    if (cardNum.size() > 12 && cardNum.size() < 17 && hasValidPrefix(cardNum) && getSumOfDigits(sumOddDigitsRightToLeft(cardNum) + sumEvenDigitsRightToLeft(cardNum)) % 10 == 0) {
        return true;
    }
    else
    {
        return false;
    }
}

void functionTest() {

    std::string testCardNumbers[] = { "378282246310005", "371449635398431", "4012888888881881", "4388576018402626", "4388576018410707" };

    for (std::string number : testCardNumbers) {

        //int sum = getSumOfDigits(15);
        //std::cout << sum << "\n";

        //std::cout << hasValidPrefix(number) << "\n";

        //int oddSum = sumOddDigitsRightToLeft(number);
        //std::cout << oddSum << "\n";

        //int evenSum = sumEvenDigitsRightToLeft(number);
        //std::cout << evenSum << "\n";

        std::cout << "\n" << number << "  valid: " << isCardValid(number);
    }
}