// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "credit.h"
#include <fstream>


int main()
{
    int validCardNumber{ 0 };
    int invalidCardNumber{ 0 };

    std::string inputFilename = "cards.txt";
    std::ifstream fin;
    fin.open(inputFilename);
    if (fin.is_open()) {
        std::cout << "---------------------------------------";
        std::string ccNumber;
        while (fin >> ccNumber) {
            //create a reference for ccNumber;
            const std::string& ccRef = ccNumber;
            if (isCardValid(ccRef)) {
                std::cout << "\n" << ccRef << "  valid: " << isCardValid(ccRef);
                validCardNumber++;
            }
            else
            {
                std::cout << "\n" << ccRef << "  valid: " << isCardValid(ccRef);
                invalidCardNumber++;
            }
        }
        fin.close();
        std::cout <<"\n" << "--------------------------------------- " << "\n" << "valid cards: " << validCardNumber << "\n" << "invalid cards: " << invalidCardNumber;
    }
    else {
        std::cout << "Error: could not open file: \"" << inputFilename << "\"" << std::endl;
        exit(1);
    }
    //std::cout << sum; 

    //functionTest();
}




// 1. an input function to get user input. int getInput()
// 2. get the sum of doubled every second digits,if doubling of a digit results in a two-digit number, then add the two digits to get a single number. int getSum(odd); 
// 3. get the sum of all digits in the odd places. int getSum(odd); 
// 4. get the sum of the 2 sum and check if it satisfy the condition. bool numberChecker(oddSum, evenSum);
// 5. 

