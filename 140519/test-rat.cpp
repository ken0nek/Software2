/* test-rat.cpp */
#include <iostream>

class Rat {
    private:
        int numerator;
        int denominator;
    public:
        Rat() {}
        Rat(int n, int d) {
            numerator = n;
            denominator = d;
        }
        int GetNumer() const { return numerator; }
        int GetDenom() const { return denominator; }

        Rat operator+(const Rat& r) {
            return Rat(((GetNumer() * r.GetDenom()) +
                        (GetDenom() * r.GetNumer())),
                    (GetDenom() * r.GetDenom()));
        }
        Rat operator-(const Rat& r) {
            return Rat(((GetNumer() * r.GetDenom()) -
                        (GetDenom() * r.GetNumer())),
                    (GetDenom() * r.GetDenom()));
        }
        Rat operator*(const Rat& r) {
            return Rat((GetNumer() * r.GetNumer()),
                    (GetDenom() * r.GetDenom()));
        }
        Rat operator/(const Rat& r) {
            return Rat((GetNumer() * r.GetDenom()),
                    (GetDenom() * r.GetNumer()));
        }
};

std::ostream& operator<<(std::ostream& os, const Rat& r) {
    return ( os << r.GetNumer() << "/" << r.GetDenom() );
}

template <class T> T linear_combination (T a, T b, T x, T y) {
    return (a*x) + (b*y);
}
/* 
テンプレート関数を用いることで,以下のように重複した内容を
書くことを防いでいる。
linear_combination(int a, int b, int x, int y) {
    return (a*x) + (b*y);
}
linear_combination(float a, float b, float x, float y) {
    return (a*x) + (b*y);
}
linear_combination(double a, double b, double x, double y) {
    return (a*x) + (b*y);
}
*/

int main() {
    Rat one_half = Rat(1, 2);
    Rat one_third = Rat(1, 3);

    std::cerr << one_half << std::endl;
    std::cerr << one_third << std::endl;

    std::cerr << "1/2 + 1/3: " << std::endl;
    std::cerr << one_half + one_third << std::endl;
    std::cerr << "1/2 - 1/3: " << std::endl;
    std::cerr << one_half - one_third << std::endl;
    std::cerr << "1/2 * 1/3: " << std::endl;
    std::cerr << one_half * one_third << std::endl;
    std::cerr << "1/2 / 1/3: " << std::endl;
    std::cerr << one_half / one_third << std::endl;

    std::cerr << linear_combination(1,2,3,4) << std::endl;
    std::cerr << linear_combination(1.1,2.2,3.3,4.4) << std::endl;
    std::cerr << linear_combination(one_half, one_half, one_third, one_third)
        << std::endl;
}
