#include <iostream>
using namespace std;

class Rational
{
	public:
		Rational(int numerator, int denominator):numerator(numerator), denominator(denominator){}
		inline int getNum(){return numerator;}
		inline int getDenom(){return denominator;}	
		inline operator double() { return (double)numerator/denominator;}
		friend ostream &operator<<(ostream &out, const Rational &r)
		{
			return out << r.numerator << "/" << r.denominator << endl;
		}
		Rational &operator+(Rational &r2)
		{
			return *new Rational(numerator+r2.getNum(), denominator+r2.getDenom());
		}
		Rational &operator+(int i)
		{
			Rational *r2 = new Rational(i*denominator, denominator);
			return *this+*r2;
		}
	private:
		int numerator;
		int denominator;
};

int main()
{
	Rational *r = new Rational(4,5);
	cout << *r;	 
	Rational *r2 = new Rational(9,13);
	cout << *r+*r2 << endl;	
	int i = 4;
	cout << *r+i << endl;
	cout << static_cast<double>(*r) << endl;
	return 0;
}
