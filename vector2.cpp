#include "vector2.h"
#include <cmath>
#define PI 3.14159265
//Default constructor
vector2::vector2(){
	x_0 = 0;
	y_0 = 0;
	}
vector2::vector2(float x, float y){
	x_0 = x;
	y_0 = y;
}
vector2::vector2(const vector2& other){
	// можно убрать. компилятор сам такое сгенерирует
	x_0 = (other.x_0);
	y_0 = (other.y_0);
}
vector2::~vector2()
{
	// деструктор не обязательно самим реализовывать в данном случае (отладочный вывод не обязателен)
	std::cout << "destructor" <<std::endl;
}

vector2 vector2::operator*(float k) const
{
	return vector2(k * x_0, k * y_0);
}
vector2 operator*(float k, const vector2& v)
{
	return vector2(v.x_0 * k, v.y_0 * k);
}

std::ostream& operator<<(std::ostream& stream, const vector2& v)
{
	stream  << v.x_0<< " " << v.y_0 ;
	return stream;
}
std::istream& operator>>(std::istream& stream,  vector2& v)
{
	stream >> v.x_0 >> v.y_0;
	return stream;
}
const vector2& vector2::operator=(const vector2&other) 
{
	// компилятор сам такой operator= сгенерирует
	x_0 = other.x_0;
	y_0 = other.y_0;
	return *this;
}

vector2& vector2::operator+=(const vector2&other)
{
	x_0 += other.x_0;
	y_0 += other.y_0;
	return (*this);
}
vector2 vector2::operator+(const vector2&other) const {
	return vector2(x_0 + other.x_0, y_0 + other.y_0);
}
vector2 &  vector2::operator-=(const vector2&other)
{
	x_0 -= other.x_0;
	y_0 -= other.y_0;
	return *this;
}
vector2 vector2::operator-(const vector2&other) const {
	return vector2(x_0 - other.x_0, y_0 - other.y_0);
}
float vector2::len() const
{
	// fixit: чтобы не дублировать код можно написать так: return sqrt(squareLen());
	return sqrt(x_0 * x_0 + y_0  * y_0);
}

float vector2::squareLen() const
{
	return (x_0 * x_0 + y_0 * y_0);
}

float vector2::operator*(const vector2&other)const
{
	return (x_0 * other.x_0 + y_0 * other.x_0);
}
vector2& vector2::norm() {
	if (x_0 == 0 && y_0 == 0)
	{
		return *this;
	}
	else
	{
		// fixit:
		// лучше так: float invLen = 1.0f / len(); 
		// x_0 *= invLen; y_0 *= invLen;
		float a = x_0;
		x_0 = x_0 / sqrt(x_0 * x_0 + y_0 * y_0);
		y_0 = y_0 / sqrt(a * a + y_0 * y_0);
		return *this;
	}
}
vector2& vector2::normal()
{
	if (x_0 == 0 && y_0 == 0)
	{
		return *this;
	}
	float a;
	a = x_0;
	x_0 = y_0;
	y_0 = -a;
	return *this;
}
vector2 vector2::operator-()const 
{
	
	return vector2(-x_0, -y_0);
}
vector2 vector2::rotate(float angle)
{
	float x, y;
	float cosa = cos(angle * PI / 180);
	float sina = sin(angle * PI / 180);
	if (x_0 == 0 && y_0 == 0)
		return vector2(x_0, y_0);
	else
	{
		x = x_0 * cosa - y_0 * sina;
		y = x_0 * sina - y_0 * cosa;
	}
	return vector2(x, y);
}
vector2 vector2::getRotate(float angle) const
{
	// fixit: у вас rotate и getRotated делают по сути одно и то же
	vector2 getrotate = *this;
	getrotate.rotate(angle);
	return getrotate;
}
