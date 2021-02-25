#include <cmath>

class Rational {
    int numerator;
    int denominator;

    int gcd(int x, int y) {
        while (x != 0) {
            int temp = x;
            x = y % x;
            y = temp;
        }
        return std::abs(y);
    }

public:
    Rational(int x = 0, int y = 1) {
        numerator = x / gcd(x, y);
        denominator = y / gcd(x, y);
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

    Rational operator+() {
        return Rational(numerator, denominator);
    }

    Rational &operator++() {
        numerator += denominator;
        return *this;
    }

    Rational operator++(int) {
        Rational temp = *this;
        numerator += denominator;
        return temp;
    }

    Rational operator-() {
        return Rational(-numerator, denominator);
    }

    Rational &operator--() {
        numerator -= denominator;
        return *this;
    }

    Rational operator--(int) {
        Rational temp = *this;
        numerator -= denominator;
        return temp;
    }

    friend Rational operator+(const Rational &self, const Rational &other) {
        return Rational(
                self.numerator * other.denominator + other.numerator * self.denominator,
                self.denominator * other.denominator);
    }

    friend Rational operator-(const Rational &self, const Rational &other) {
        return Rational(
                self.numerator * other.denominator - other.numerator * self.denominator,
                self.denominator * other.denominator);
    }

    friend Rational operator*(const Rational &self, const Rational &other) {
        return Rational(self.numerator * other.numerator, self.denominator * other.denominator);
    }

    friend Rational operator/(const Rational &self, const Rational &other) {
        if (other.Numerator() < 0) {
            return Rational(-self.numerator * other.denominator,
                            -self.denominator * other.numerator);
        } else {
            return Rational(self.numerator * other.denominator,
                            self.denominator * other.numerator);
        }
    }

    Rational &operator+=(const Rational &other) {
        Rational sum = Rational(numerator, denominator) + other;
        numerator = sum.Numerator();
        denominator = sum.Denominator();
        return *this;
    }

    Rational &operator-=(const Rational &other) {
        Rational diff = Rational(numerator, denominator) - other;
        numerator = diff.Numerator();
        denominator = diff.Denominator();
        return *this;
    }

    Rational &operator*=(const Rational &other) {
        Rational prod = Rational(numerator, denominator) * other;
        numerator = prod.Numerator();
        denominator = prod.Denominator();
        return *this;
    }

    Rational &operator/=(const Rational &other) {
        Rational frac = Rational(numerator, denominator) / other;
        numerator = frac.Numerator();
        denominator = frac.Denominator();
        return *this;
    }

    bool operator==(Rational other) {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(Rational other) {
        return !(numerator == other.numerator && denominator == other.denominator);
    }
};
