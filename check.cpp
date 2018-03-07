#include <iostream>
#include "vector2.h"
int main()
{
	vector2 m, l;
	float angle;
	std::cout << "Input new vector2" <<std::endl;
	std::cin >> m;
	
	vector2 n(1, 0);
	std::cout << n <<std::endl;

	std::cout << "m = " << m <<std::endl;
	std::cout << "n = " << n << std::endl;
	std::cout << "m + n = " << m + n << std::endl;
	std::cout << "m - n = " << m - n << std::endl;
	
	std::cout << " 3 * m = " << 3 * m <<std::endl;
	std::cout << "m * 3 = " << m * 3 << std::endl;
	std::cout << "-m = " << -m << std::endl;
	
	std::cout << "len of m " << m.len() << std::endl;
	std::cout << "squareLen of m " << m.squareLen() << std::endl;
	std::cout << "nor of m " << m.norm() << std::endl;

	std::cout << "normal of m " <<m.normal() << std::endl;

	vector2 a(4, 5);
	l = a;
	std::cout << "(l = a) " << l<<std::endl;
	std::cout << "(l += a)" << (l += a)<< std::endl;
	std::cout << "(l -= a) " << (l -= a) << std::endl;
	

	std::cout << "(a * n) " << a * n << std::endl;


	vector2 k;
	std::cout << " Input new vector k =" <<std::endl;
	std::cin >> k;
	std::cout << " Input angle =" <<std::endl;
	std::cin >> angle;
	std::cout << "new vector 2 = " << k.rotate(angle) <<std::endl;
	std::cout << "return vector 2 = " << k.getRotate(-1* angle )<<std::endl; 
	system("pause");
	return 0;
}