#pragma once
#include<iostream>
class vector2
{
private:
	float x_0, y_0;
public:
	
	vector2();
	vector2(float a, float b);
	
	// fixit: деструктор и конструктор копирования в данном случае не нужны, т.к. компилятор сгенерирует сам ровно тот же код
	vector2(const vector2& other);
	~vector2();
	
	friend std::ostream& operator<<(std::ostream& stream, const vector2& v);
	friend std::istream& operator>>(std::istream& stream, vector2& v);
	vector2 operator*(float k) const;
	friend vector2 operator*(float k, const vector2& v);
	vector2& operator+=(const vector2&other);
	vector2 operator+(const vector2&other)const;
	
	// fixit: оператор присваивания тоже не нужно самим писать в данном случае. 
	const vector2& operator=(const vector2&other);
	
	vector2& operator-=(const vector2&other);
	vector2 operator-(const vector2&orther)const;
	float operator*(const vector2&other)const;//scalar
	
	// вроде векторное произведение - тоже полезная штука :) можно было бы и оставить operator^
	//float operator^(const vector2&other)const;// 
	
	// неясно чем отличается norm от normal
	vector2& norm();
	vector2& normal();
	
	float len() const;
	float squareLen() const;
	vector2 operator-()const;//unary_minus
	
	// fixit: rotate должен вернуть vector2&
	vector2 rotate(float angle);// change the components of the vector x and y 
								//so that they correspond to the rotated angle vector
	vector2 getRotate(float angle) const;//return the rotated vector
};
