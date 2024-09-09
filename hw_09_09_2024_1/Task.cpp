#include <iostream> 
using namespace std;

class Fraction
{
private:
    int numerator; //числитель 
    int denominator; //знаменатель 

    int gcd(int a, int b) const //GCD (Greaster Common Divisor ) = НОД (Наибольший Общий Делитель) 
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        if (denom == 0)
        {
            throw invalid_argument("Denominator can`t be zero");
        }
        reduce();
    }

    void input()
    {
        cout << "Enter numerator : ";
        cin >> numerator;
        cout << "Enter denominator : ";
        cin >> denominator;
        if (denominator == 0)
        {
            throw invalid_argument("Denominator can`t be zero");
        }
        reduce();
    }

    void output() const
    {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const
    {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator-(const Fraction& other) const
    {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator*(const Fraction& other) const
    {
        int new_numerator = numerator * other.numerator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("Division by zero is undefined");
        }
        int new_numerator = numerator * other.denominator;
        int new_denominator = denominator * other.numerator;
        return Fraction(new_numerator, new_denominator);
    }
};

int main()
{
    Fraction f1(3, 4), f2(2, 5);

    Fraction sum = f1 + f2;
    cout << "Sum : ";
    sum.output();

    Fraction difference = f1 - f2;
    cout << "Difference : ";
    difference.output();

    Fraction product = f1 * f2;
    cout << "Result : ";
    product.output();

    Fraction quotient = f1 / f2;
    cout << "Quotient : ";
    quotient.output();
    return 0;
}