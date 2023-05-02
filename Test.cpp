#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;

TEST_CASE("Fraction constructors") {
    Fraction f1;
    Fraction f2(3, 4);
    Fraction f3(1.25);

    CHECK(f1 == 0);
    CHECK(f2 == 0.75);
    CHECK(f3 == 1.25);
}

TEST_CASE("Fraction arithmetic operators") {
    Fraction f1(1, 2);
    Fraction f2(1, 4);

    CHECK(f1 + f2 == 0.75);
    CHECK(f1 - f2 == Fraction(1, 4));
    CHECK(f1 * f2 == Fraction(1, 8));
    CHECK(f1 / f2 == Fraction(2, 1));
}

TEST_CASE("Fraction comparison operators") {
    Fraction f1(3, 4);
    Fraction f2(1, 2);

    CHECK(f1 == Fraction(6, 8));
    CHECK(f1 != f2);
    CHECK(f1 > f2);
    CHECK(f2 < f1);
    CHECK(f1 >= Fraction(6, 8));
    CHECK(f2 <= Fraction(1, 2));
}

TEST_CASE("Fraction increment and decrement operators") {
    Fraction f1(1, 2);
    Fraction f2 = f1++;

    CHECK(f1 == Fraction(3, 2));
    CHECK(f2 == Fraction(1, 2));

    Fraction f3(3, 4);
    Fraction f4 = ++f3;

    CHECK(f3 == Fraction(7, 4));
    CHECK(f4 == Fraction(7, 4));

    Fraction f5(5, 4);
    Fraction f6 = f5--;

    CHECK(f5 == Fraction(1, 4));
    CHECK(f6 == Fraction(5, 4));

    Fraction f7(7, 4);
    Fraction f8 = --f7;

    CHECK(f7 == Fraction(3, 4));
    CHECK(f8 == Fraction(3, 4));
}


TEST_CASE("Fraction mixed type arithmetic operators") {
    Fraction f1(1, 2);

    CHECK(2.0 + f1 == Fraction(5, 2));
    CHECK(1.25 - f1 == Fraction(3, 4));
    CHECK(1.25 * f1 == Fraction(5, 8));
    CHECK(0.5 / f1 == Fraction(1, 4));
}

TEST_CASE("Fraction mixed type comparison operators") {
    Fraction f1(3, 4);

    CHECK(1.0 == f1);
    CHECK(1.0 != f1);
    CHECK(1.0 > f1);
    CHECK(0.5 < f1);
    CHECK(1.0 >= f1);
    CHECK(0.5 <= f1);
}
