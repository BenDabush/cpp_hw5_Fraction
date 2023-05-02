#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>

namespace ariel {

    class Fraction {
        private:
            int numerator;
            int denominator;
            int number;
            int gcd(int numerator, int denominator);  // a helper function to calculate the greatest common divisor

        public:
            // constructors
            Fraction();
            Fraction(int numerator, int denominator);
            Fraction(float number);

            // getter functions
            int getNumerator() const;
            int getDenominator() const;

            // setter functions
            void setNumerator(int num);
            void setDenominator(int num);

            // arithmetic operator overloading for Fraction objects
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;

            // comparison operator overloading for Fraction objects
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator>(const Fraction& other) const;
            bool operator<(const Fraction& other) const;
            bool operator>=(const Fraction& other) const;
            bool operator<=(const Fraction& other) const;

            // Self arithmetic operator overloading for fraction objects
            Fraction operator++();  // pre-increment operator
            Fraction operator++(int);  // post-increment operator
            Fraction operator--();  // pre-decrement operator
            Fraction operator--(int);  // post-decrement operator

            // output and input stream operator overloading
            friend std::ostream& operator<<(std::ostream& outs, const Fraction& fraction);  // output stream operator overloading
            friend std::istream& operator>>(std::istream& ins, Fraction& fraction);  // input stream operator overloading

            // arithmetic operator overloading for float and Fraction objects
            friend Fraction operator+(float, const Fraction& other);
            friend Fraction operator-(float, const Fraction& other);
            friend Fraction operator*(float, const Fraction& other);
            friend Fraction operator/(float, const Fraction& other);

            // comparison operator overloading for float and Fraction objects
            friend bool operator==(float, const Fraction& other);
            friend bool operator!=(float, const Fraction& other);
            friend bool operator>(float, const Fraction& other);
            friend bool operator<(float, const Fraction& other);
            friend bool operator>=(float, const Fraction& other);
            friend bool operator<=(float, const Fraction& other);
    };
}

#endif /* FRACTION_HPP */
