#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
bool compare(const std::string& lhs, const std::string& rhs) {
	return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
}
int main() {
	int N; 
	std::vector<std::string>a;
	std::cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin>> a[i];
	}
	std::sort(a.begin(), a.end(), compare);
	for (int i = 0; i < N; i++) {
		std::cout << a[i]<<" ";
	}
	system("pause");
	return 0;
}
