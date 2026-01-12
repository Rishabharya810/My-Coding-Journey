#include <iostream>
using namespace std;

class triangle
{
    double a;
    double b;
    double c;

public:
    triangle(double a_in, double b_in, double c_in);

    double perimeter()
    {
        return this->a + this->b + this->c;
    }
    void scale(double s)
    {

        this->a *= s;
        this->b *= s;
        this->c *= s;
    }
};

int main()
{
    triangle a;

    a.perimeter(2, 3, 5);

    return 0;
}
