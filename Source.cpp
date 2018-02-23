#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <cctype>
#include <list>
#include <utility> 
std::string prepare(const std::string& s)
{
	 
	std::string result, token;
	std::transform(s.begin(), s.end(), std::back_inserter(result), tolower);//перевести в нижний регистр
	std::copy_if(begin(result), end(result), std::back_inserter(token),
		[](char c) { return !ispunct(c); });// удалить знак препинания с конца слова ,ispunct Проверяет знак препинания
	return token;
}
int main() {
	//std::vector<Statistics> s;
	std::ifstream file("file.txt");
	std::string all_word;
	std::map< std::string, int > find;
	if (file.is_open())
	{
		
		while (!file.eof())
		{
			file >> all_word; 
			all_word = prepare(all_word);
			find[all_word]++; //заполняя map find< слово, сколько раз встретилось>
			
		}
	}
	using pair_type = decltype(find)::value_type;//template <class T1, class T2> struct pair;
	 // найти максимум в map 
	auto max_find = std::max_element
	(
		std::begin(find), std::end(find),
		[](const pair_type&p1, const pair_type&p2) {
		return p1.second < p2.second;// сравнить количество (сколько раз встретилось слово)
		}
	);
	std::cout <<max_find->first<< " => "<<max_find-> second <<"\n";
	file.close();
	system("pause");
	return 0;
}

