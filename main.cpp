#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/***
Write a computer program (in a language of your choice) that performs CRC operations.
 It should accept a string of 0s and 1s as a generator polynomial
and another string as the data to perform the calculation on.
 It should output the remainder of the calculation.
 ***/

// function to convert Binary text into an integer value
int getIntFromBinaryText(const char *text) {
    int value = 0;
    while (*text) {
        value <<= 1;
        if (*text == '1') value |= 1;
        else if (*text == '0');          // do nothing
        else return -1; // invalid input... return a negative number to indicate error
        ++text;
    }

    return value;
}

// function to calculate the highest polynomial and subract one from it
// ie x^4 + 1 would be entered 10000 and have 5 digits so it should return 4
int getZerosfromPolynomial(const char *text) {

    std::string textString = text;
    int highestPolynomial = textString.length();
    return highestPolynomial - 1;

}


// function to create Binary Text from an integer
std::string getBinaryTextFromInt(int value) {
    std::string text;
    // note I'm assuming 'value' is positive here

    while (value > 0) {
        if (value & 1) text += '1';
        else text += '0';
        value >>= 1;
    }

    if (text.empty()) return "0";
    std::reverse(text.begin(), text.end());       // #include <algorithm>
    return text;
}


int main() {

    // get the generator as a string input from the user
    std::string polynomial;
    cout << " polynomial ?" << endl;
    cin >> polynomial;

    // calculate the number of zeros
    int zeros = getZerosfromPolynomial(polynomial.c_str());


    // get the message as a string input from the user
    std::string message;
    cout << " message ?" << endl;
    cin >> message;

    // append the necessary number of zeros to the message
    for (int i = 0; i < zeros; i++) {
        message.append("0");
    }

    //calculate the result and the remainder of binary division

    int divisor = getIntFromBinaryText(polynomial.c_str());  // or just "divisor = 11;"
    int dividend = getIntFromBinaryText(message.c_str());
    int result = dividend / divisor;
    int remainder = dividend % divisor;

    cout << "dividend=" << getBinaryTextFromInt(dividend);
    cout << "    divisor=" << getBinaryTextFromInt(divisor);
    cout << "    result=" << getBinaryTextFromInt(result);
    cout << "    remainder=" << getBinaryTextFromInt(remainder);

}