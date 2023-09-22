#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <cmath>
#include "calc.h"
// 注意{} ; const
// 加const是个好习惯, 当意外修改类成员时编译器会报错
class Point; // 前置声明
class Vector
{
public:
    double _x;
    double _y;
    Vector() : _x(0), _y(0) {} // 构造函数赋初始值
    Vector(double x, double y) : _x(x), _y(y) {}
    Vector(const Vector &v) : _x(v._x), _y(v._y) {} // 构造函数创建一个新的向量，其值与向量v相同 (拷贝构造函数)
    Vector(const Point &, const Point &);
    // Vector::Vector(const Point &p1, const Point &p2):_x(p2._x-p1._x),_y(p2._y-p1._y)
    //  Point对象的引用被传递到构造函数内部进行处理。这个构造函数的作用是根据两个点来创建一个向量
    //  运算符重载 此处不写在.cpp里了, 会乱码
    Vector operator+(Vector const &v) const
    // const 放在成员函数声明的末尾，用来表示该函数是一个常量成员函数，不修改对象(这里指_x,_y)
    // 而是生成一个新的 Vector 对象来存储结果。
    {
        return Vector(_x + v._x, _y + v._y);
    }
    Vector operator-(Vector &v) const
    {
        return Vector(_x - v._x, _y - v._y);
    }
    friend Vector operator*(double a, Vector const &v) //??为什么不加const加friend?
    // 加上friend后是一个全局函数, 而非成员函数, const 是用于成员函数的修饰符，不适用于非成员函数。
    {
        return Vector(v._x * a, v._y * a);
    }
    Vector operator/(double a) const
    {
        return Vector(_x / a, _y / a);
    }
    double operator*(Vector const &v) const // dot product
    {
        return double(_x * v._x + _y * v._y);
    }
    Vector operator*(double a) const
    {
        return Vector(_x * a, _y * a);
    }
    Vector &operator=(Vector const &); // 返回类型是Vector类的对象的地址
                                       // 这些运算符重载并不一定都会用到, 只是列着方便以后用
    /**
     * @brief 返回速度的值
     */
    double mod() const
    {
        return sqrt(_x * _x + _y * _y);
    }
    /**
     * @brief 返回当前速度的角度
     */
    double dir() const
    {
        return rad2deg(atan2(_y, _x)); //// 返回点 (_x, _y) 相对于原点的极坐标角度
    }
    Vector rotateTran(double);
    void setV(double x, double y)
    {
        _x = x;
        _y = y;
    }
    void resetV()
    {
        _x = 0;
        _y = 0;
    }
};
/**
 * @brief 本意应是区分速度和位置的类, 但是通过重载实现两者的互相转换
 *
 */
class Point
{
public:
    double _x;
    double _y;
    Point() : _x(0), _y(0) {}
    Point(double x, double y) : _x(x), _y(y) {}
    Point(const Point &p) : _x(p._x), _y(p._y) {}
    Point operator+(const Point &p) const
    {
        return Point(_x + p._x, _y + p._y);
    }
    Point operator+(const Vector &v) const
    {
        return Point(_x + v._x, _y + v._y);
    }
    friend Point operator+(const Point &p, const Vector &v)
    {
        return Point(v._x + p._x, v._y + p._y);
    }
    Vector operator-(const Point &p) const
    {
        return Vector(_x - p._x, _y - p._y);
    }
    Point operator-(const Vector &v) const
    {
        return Point(_x - v._x, _y - v._y);
    }
    Point &operator=(const Point &);
    void setP(double x, double y)
    {
        _x = x;
        _y = y;
    }
    void resetP()
    {
        _x = 0;
        _y = 0;
    }
};
#endif
