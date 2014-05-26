#include <iostream>

using namespace std;

class Rat
{
private:
	int numerator;
	int denominator;
public:
	Rat() {};
	Rat(int n, int d) {
		numerator = n;
		denominator = d;
	}
	int GetNumer() const {return numerator;}
	int GetDenom() const {return denominator;}

	Rat operator+(const Rat& r)
	{
		return Rat(((GetNumer() * r.GetDenom()) + (GetDenom() * r.GetNumer())), (GetDenom() * r.GetDenom()));
	}
	Rat operator*(const Rat& r)
	{
		return Rat((GetNumer() * r.GetNumer()), (GetDenom() * r.GetDenom()));
	}
};

ostream& operator << (ostream& os, const Rat& r)
{
	return (os << r.GetNumer() << "/" << r.GetDenom());
}

template <class T> T liner_combination (T a, T b, T x, T y) {
	return (a * x) + (b * y);
}

int main()
{
	Rat one_half = Rat(1, 2);
	Rat one_third = Rat(1, 3);

	cerr << one_half << endl;
	cerr << one_third << endl;

	cerr << one_half + one_third << endl;
	cerr << one_half * one_third << endl;

	cerr << liner_combination(1, 2, 3, 4) << endl;
	cerr << liner_combination(one_half, one_half, one_third, one_third) << endl;
}