#include "Fraction.hpp"   // Include header file
#include <stdexcept>      // Include exception classes
#include <iostream>       // Include input and output stream classes
#include <sstream>        // Include string stream classes
#include <limits>         // Include numeric limits
#include <cstdlib>        // Include C Standard General Utilities Library

using namespace std;     // Use standard namespace
using namespace ariel;   // Use namespace ariel

// Default constructor
/**
 * @brief Create a new Fraction object with default values.
 */
Fraction::Fraction() : numerator(0), denominator(1) {}

// Constructor with parameters
/**
 * @brief Create a new Fraction object with given numerator and denominator values.
 * @param numerator The numerator of the fraction.
 * @param denominator The denominator of the fraction.
 * @throws invalid_argument If denominator is 0.
 */
Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    int gcdValue = abs(gcd(numerator, denominator));
    this->numerator = ((numerator < 0) ^ (denominator < 0)) ? -abs(numerator / gcdValue) : abs(numerator / gcdValue);
    this->denominator = abs(denominator / gcdValue);
}

// Constructor with parameter float
/**
 * @brief Create a new Fraction object with given float value.
 * @param number The float value to convert to fraction.
 */
Fraction::Fraction(float number) {
    if (number == 0) {
        this->numerator = 0;
        this->denominator = 1;
    } else {
        number = (int)(number * 1000);
        int gcdValue = abs(gcd(number, 1000));
        this->numerator = number / gcdValue;
        this->denominator = 1000 / gcdValue;
    }
}

// Getter functions
/**
 * @brief Get the numerator of the fraction.
 * @return The numerator of the fraction.
 */
int Fraction::getNumerator() const {
    return numerator;
}
/**
 * @brief Get the denominator of the fraction.
 * @return The denominator of the fraction.
 */
int Fraction::getDenominator() const {
    return denominator;
}

// Setter functions
/**
 * @brief Set the numerator of the fraction.
 * @param num The new numerator value.
 */
void Fraction::setNumerator(int num) {
    numerator = num;
}
/**
 * @brief Set the denominator of the fraction.
 * @param num The new denominator value.
 * @throws invalid_argument If denominator is 0.
 */
void Fraction::setDenominator(int num) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    denominator = num;
}

/**
 * @brief Calculates the greatest common divisor (GCD) of the given numerator and denominator.
 * @param numerator The numerator of the fraction.
 * @param denominator The denominator of the fraction.
 * @return The greatest common divisor of the numerator and denominator.
*/
int Fraction::gcd(int numerator, int denominator) {
    if (numerator == 0) {
        return denominator;
    }
    return gcd(denominator % numerator, numerator);
}

/**
 * @brief Addition operator overload for Fraction class.
 * @param other The Fraction object to be added to this Fraction object.
 * @return A new Fraction object that represents the result of adding this and other.
 * @throw std::overflow_error if the addition results in integer overflow.
*/
Fraction Fraction::operator+(const Fraction& other) const {
    if ((numerator != 0) && (other.numerator != 0))
    {
        if ((abs(numerator) > std::numeric_limits<int>::max() / abs(other.denominator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.numerator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.denominator))){
            throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
        }
    }

    int num1 = numerator * other.denominator;
    int num2 = other.numerator * denominator;
    int new_denominator = denominator * other.denominator;

    if ((num1 < 0) && (num2 < 0) && (num1 < std::numeric_limits<int>::min() - num2) ||
    (num1 > 0) && (num2 > 0) && (num1 > std::numeric_limits<int>::max() - num2)) {
        throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
    }
    int new_numerator = num1 + num2;
    return Fraction(new_numerator, new_denominator);
}

/**
 * @brief Subtraction operator overload for Fraction class.
 * @param other The Fraction object to be subtracted from this Fraction object.
 * @return A new Fraction object that represents the result of subtracting other from this.
 * @throw std::overflow_error if the subtraction results in integer overflow.
*/
Fraction Fraction::operator-(const Fraction& other) const {
    if ((numerator != 0) && (other.numerator != 0))
    {
        if ((abs(numerator) > std::numeric_limits<int>::max() / abs(other.denominator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.numerator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.denominator))){
            throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
        }
    }

    int num1 = numerator * other.denominator;
    int num2 = other.numerator * denominator;
    int new_denominator = denominator * other.denominator;

    if ((num1 < 0) && (num2 > 0) && (num1 < std::numeric_limits<int>::min() + num2) ||
    (num1 > 0) && (num2 < 0) && (num1 > std::numeric_limits<int>::max() + num2)) {
        throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
    }
    int new_numerator = num1 - num2;
    return Fraction(new_numerator, new_denominator);
}


/**
 * @brief This method overloads the multiplication operator '*' for the Fraction class.
 * @param other The fraction to multiply with the current fraction.
 * @return The result of multiplying the current fraction with the other fraction.
 * @throws std::overflow_error if the operation would result in an integer overflow.
 */
Fraction Fraction::operator*(const Fraction& other) const {
    if ((numerator != 0) && (other.numerator != 0))
        {
        // Check for potential integer overflow during multiplication.
        if ((abs(numerator) > std::numeric_limits<int>::max() / abs(other.numerator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.denominator))) {
            throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
        }
    }

    // Calculate the new numerator and denominator after multiplication.
    int new_numerator = numerator * other.numerator;
    int new_denominator = denominator * other.denominator;

    return Fraction(new_numerator, new_denominator);
}

/**
 * @brief This method overloads the division operator '/' for the Fraction class.
 * @param other The fraction to divide the current fraction by.
 * @return The result of dividing the current fraction by the other fraction.
 * @throws std::runtime_error if attempting to divide by zero.
 * @throws std::overflow_error if the operation would result in an integer overflow.
*/
Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::runtime_error("Cannot divide by zero");
    }

    if ((numerator != 0) && (other.numerator != 0))
    {
    // Check for potential integer overflow during multiplication.
        if ((abs(numerator) > std::numeric_limits<int>::max() / abs(other.denominator)) ||
        (abs(denominator) > std::numeric_limits<int>::max() / abs(other.numerator))) {
            throw std::overflow_error("Multiplication the numerators would result in integer overflow!");
        }
    }

    // Calculate the new numerator and denominator after division.
    int new_numerator = numerator * other.denominator;
    int new_denominator = denominator * other.numerator;

    return Fraction(new_numerator, new_denominator);
}

/**
 * @brief This method checks whether the current fraction is equal to the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the fractions are equal, false otherwise.
*/
bool Fraction::operator==(const Fraction& other) const {
    // Convert both fractions to floating-point numbers for comparison.
    float num1 = ((float)numerator / denominator);
    float num2 = ((float)other.numerator / other.denominator);

    // Check if the difference between the fractions is within a small tolerance.
    if (num1 > num2) {
        return (num1 - num2) < 0.001;
    }
    else {
        return (num2 - num1) < 0.001;
    }
}

/**
 * @brief This method checks whether the current fraction is not equal to the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the fractions are not equal, false if they are equal.
*/
bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

/**
 * @brief This method checks whether the current fraction is greater than the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the current fraction is greater than the other fraction, false otherwise.
*/
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

/**
 * @brief This method checks whether the current fraction is less than the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the current fraction is less than the other fraction, false otherwise.
*/
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

/**
 * @brief This method checks whether the current fraction is greater than or equal to the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the current fraction is greater than or equal to the other fraction, false otherwise.
*/
bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

/**
 * @brief This method checks whether the current fraction is less than or equal to the other fraction.
 * @param other The fraction to compare with the current fraction.
 * @return true if the current fraction is less than or equal to the other fraction, false otherwise.
*/
bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other);
}

/**
 * @brief This method overloads the pre-increment operator '++' for the Fraction class.
 * @return The fraction after incrementing its numerator by the value of the denominator.
*/
Fraction Fraction::operator++() {
    numerator += denominator;
return *this;
}

/**
 * @brief This method overloads the post-increment operator '++' for the Fraction class.
 * @param int Dummy parameter to differentiate from the pre-increment operator.
 * @return A copy of the fraction before incrementing, followed by incrementing its numerator by the value of the denominator.
*/
Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    ++(*this);
    return temp;
}

/**
 * @brief This method overloads the pre-decrement operator '--' for the Fraction class.
 * @return The fraction after decrementing its numerator by the value of the denominator.
*/
Fraction Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

/**
 * @brief This method overloads the post-decrement operator '--' for the Fraction class.
 * @param int Dummy parameter to differentiate from the pre-decrement operator.
 * @return A copy of the fraction before decrementing, followed by decrementing its numerator by the value of the denominator.
*/
Fraction Fraction::operator--(int) {
    Fraction temp(*this);
    --(*this);
    return temp;
}

/**
 * @brief This function overloads the output stream operator '<<' to allow printing a Fraction object to the output stream.
 * @param outs The output stream to write to.
 * @param fraction The Fraction object to be printed.
 * @return The output stream after printing the Fraction object.
*/
std::ostream& ariel::operator<<(std::ostream& outs, const Fraction& fraction) {
    if (fraction.denominator < 0) {
        outs << -fraction.numerator << "/" << -fraction.denominator;
        return outs;
    }
    outs << fraction.numerator << "/" << fraction.denominator;
    return outs;
}

/**
 * @brief This function overloads the input stream operator '>>' to allow reading a Fraction object from the input stream.
 * @param ins The input stream to read from.
 * @param fraction The Fraction object to store the read value.
 * @return The input stream after reading the Fraction object.
*/
std::istream& ariel::operator>>(std::istream& ins, Fraction& fraction) {
    int denominator;
    char slash;

    // Read the numerator
    ins >> fraction.numerator;
    if (ins.peek() == '.') {
        throw std::runtime_error("Operator with floating-point can't be input");
    }

    ins.ignore(1);
    // Check if the next character is a slash
    if (ins.fail()) {
        throw std::runtime_error("Invalid input format");
    }

    // Read the denominator
    ins >> denominator;
    if (denominator == 0) {
        throw std::runtime_error("Denominator cannot be zero");
    }

    fraction.denominator = denominator;

    return ins;
}

/**
 * @brief This function overloads the addition operator '+' to allow adding a float value and a Fraction object.
 * @param number The float value to be added.
 * @param other The Fraction object to be added.
 * @return The resulting Fraction after addition.
*/
Fraction ariel::operator+(const float number, const Fraction& other) {
    Fraction num(number);
    return num + other;
}

/**
 * @brief This function overloads the subtraction operator '-' to allow subtracting a float value and a Fraction object.
 * @param number The float value to be subtracted.
 * @param other The Fraction object to be subtracted.
 * @return The resulting Fraction after subtraction.
*/
Fraction ariel::operator-(const float number, const Fraction& other) {
    Fraction num(number);
    return num - other;
}

/**
 * @brief This function overloads the multiplication operator '*' to allow multiplying a float value and a Fraction object.
 * @param number The float value to be multiplied.
 * @param other The Fraction object to be multiplied.
 * @return The resulting Fraction after multiplication.
*/
Fraction ariel::operator*(const float number, const Fraction& other) {
    Fraction num(number);
    int new_numerator = num.numerator * other.numerator;
    int new_denominator = num.denominator * other.denominator;
    return Fraction(new_numerator, new_denominator);
}

/**
 * @brief This function overloads the division operator '/' to allow dividing a float value and a Fraction object.
 * @param number The float value to be divided.
 * @param other The Fraction object to be divided.
 * @return The resulting Fraction after division.
*/
Fraction ariel::operator/(const float number, const Fraction& other) {
    Fraction num(number);
    int new_numerator = num.numerator * other.denominator;
    int new_denominator = num.denominator * other.numerator;
    return Fraction(new_numerator, new_denominator);
}

/**
 * @brief Check if a float number and a Fraction object are equal.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number and the Fraction object are equal, false otherwise.
*/
bool ariel::operator==(const float number, const Fraction& other) {
    Fraction num(number);
    float num1 = ((float)num.numerator/num.denominator);
    float num2 = ((float)other.numerator/other.denominator);

    if (num1>num2) {
        return (num1 - num2) < 0.001;
    }
    else {
        return (num2 - num1) < 0.001;
    }
}

/**
 * @brief Check if a float number and a Fraction object are not equal.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number and the Fraction object are not equal, false otherwise.
*/
bool ariel::operator!=(const float number, const Fraction& other) {
    return !(number == other);
}

/**
 * @brief Check if a float number is greater than a Fraction object.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number is greater than the Fraction object, false otherwise.
*/
bool ariel::operator>(const float number, const Fraction& other) {
    Fraction num(number);
    return num.numerator * other.denominator > other.numerator * num.denominator;
}

/**
 * @brief Check if a float number is less than a Fraction object.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number is less than the Fraction object, false otherwise.
*/
bool ariel::operator<(const float number, const Fraction& other) {
    Fraction num(number);
    return num.numerator * other.denominator < other.numerator * num.denominator;
}

/**
 * @brief Check if a float number is greater than or equal to a Fraction object.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number is greater than or equal to the Fraction object, false otherwise.
*/
bool ariel::operator>=(const float number, const Fraction& other) {
    return !(number < other);
}

/**
 * @brief Check if a float number is less than or equal to a Fraction object.
 * @param number: a float number
 * @param other: a Fraction object
 * @return true if the float number is less than or equal to the Fraction object, false otherwise.
*/
bool ariel::operator<=(const float number, const Fraction& other) {
    return !(number > other);
}