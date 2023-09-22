#include "geometry.h"
#include <math.h>
#include "calc.h"
// p1指向p2的向量
Vector::Vector(const Point &p1, const Point &p2) : _x(p2._x - p1._x), _y(p2._y - p1._y) {}

Vector &Vector::operator=(Vector const &v) // return type + space + class name + :: +function name(parameters)
// Vector& (排版后变成Vector &) 表示返回值是 Vector 类型的引用
{
    if (this == &v) // 自我赋值
    {
        return *this;
    }
    else
    {
        this->_x = v._x; // this 是特殊指针, 指向当前对象地址
        this->_y = v._y; // this 被用于比较当前对象的地址和另一个对象 v 的地址
        return *this;    //*解引用, 返回的是this指针地址的内容 此处即 Vector类型的引用
    }
} // 赋值, 修改了_x, _y不可以加const了

Point &Point::operator=(const Point &p)
{
    if (this == &p)
    {
        return *this;
    }
    else
    {
        this->_x=p._x;
        this->_y=p._y;
        return *this;
    }
}
Vector Vector ::rotateTran(double theta)
{
    double x = mod() * cos(deg2rad(dir() + theta));
    double y = mod() * sin(deg2rad(dir() + theta));
    return Vector(x, y);
}//有了这个函数你就可以 世界坐标系和机器人坐标系转换哩!

