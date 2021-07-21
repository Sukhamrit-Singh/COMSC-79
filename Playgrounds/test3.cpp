#include <iostream>
class Fraction
{
 private:
    int numerator;
    int denominator;
 public:
    void setNumerator (int num);
    void setDenominator (int denom);
    int  Numerator (void);
    int  Denominator (void);
    void print (Fraction f);
};
void Fraction::setNumerator (int num)
{
    numerator = num;
}
void Fraction::setDenominator (int denom)
{
    denominator = denom;
}
int Fraction::Numerator (void)
{
    return numerator;
}
int Fraction::Denominator (void)
{
    return denominator;
}
void Fraction::print (Fraction f)
{
    std::cout << "The value of the fraction is " << numerator <<
'/'
             << denominator << '\n';
}
int main (void)
{
    Fraction  myFract;
    myFract.setNumerator (1);
    myFract.setDenominator (3);
    myFract.print (myFract);
    return 0;
}