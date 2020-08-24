#include "tupleTest.h"

std::ostream &operator<<(std::ostream &out, ThreeD &td)
{
    out << std::get<0>(td.point) << ", " << std::get<1>(td.point) << ", " << std::get<2>(td.point);
    return out;
}

ThreeD &ThreeD::operator+(ThreeD &other3d)
{
    std::get<0>(this->point) += std::get<0>(other3d.point);
    std::get<1>(this->point) += std::get<1>(other3d.point);
    std::get<2>(this->point) += std::get<2>(other3d.point);
    return *this;
}

ThreeD &ThreeD::operator*(int x)
{
    std::get<0>(point) *= x;
    std::get<1>(point) *= x;
    std::get<2>(point) *= x;
    return *this;
}

int main()
{
    ThreeD td1;
    ThreeD td2(3, 4, 5);
    std::cout << td1 << std::endl;
    std::cout << td2 << std::endl;
    td1 + td2;
    std::cout << td1 << std::endl;
    td1 * 3;
    std::cout << td1 << std::endl;
    return 0;
}