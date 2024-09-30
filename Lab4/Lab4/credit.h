#ifndef CREDIT_H
#define CREDIT_H

#include <iostream>

namespace Constants {
	const std::string validPrefixes[] {"4", "5", "6", "37"};
}


// Given an int, return the sum of its individual digits
// hint: an easy way to parse an int into digits is by isolating
// the ‘ones’ column (via %10), and reducing the number (via /10)
// in a loop until it is 0.
// - params: int - a number to analyze (eg: 123)
// - return an int representing the sum of digits (eg: 123 returns 6)
int getSumOfDigits(int creditCardNum);

// Determine if a given card number starts with a given prefix
// - param 1: a string representing the card number
// - param 2: a string representing the prefix
// - return: true if cardNumber starts with prefix (false otherwise)
bool startsWith(const std::string& cardNum, std::string prefix);


// Determine if a cardNum has a valid prefix.
// - param 1: a string representing the cardNumber
// - return: true if cardNumber starts with string literals:
// "4", "5", "6" or "37" (false otherwise)
bool hasValidPrefix(const std::string& cardNum);

// Add up the odd-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of odd-place digits from right to left in the card
// number (step 1, part 3).
// Eg: "34567" returns 15. (7+5+3)
int sumOddDigitsRightToLeft(const std::string& cardNum);

// Add up the even-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of the (even-place digits * 2) from right to left
// in the card number (step 1, part 1 & 2).
// Special rule: multi digit #'s need to be converted by adding
// their digits together before being added into the sequence.
// Eg: "34567" returns 11. ((6*2 = 12, converted to 1+2 = 3) + (4*2)) equals 11
int sumEvenDigitsRightToLeft(const std::string& cardNum);

// Determine if a card # is valid. Valid if:
// - between 13 & 16 digits
// - has a valid prefix
// - sum of digits according to formula results in a number
// evenly divisible by 10
// This is the "workhorse" function that co - ordinates
// all the others.
// - param 1: a string to represent the cardNumber
// - return: true if the card number is valid (false otherwise)
bool isCardValid(const std::string& cardNum);


//test individual functionsl
void functionTest();

#endif