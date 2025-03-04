// 2.FJ的字符串
// Created by Administrator on 2025/3/4.
//

#include <iostream>
#include <string>
using namespace std;


string fj(int n) {
	if (n == 1)
		return "A";
	return fj(n - 1) + (char)('A' + n - 1) + fj(n - 1);
}


int main() {
	int n;
	cin >> n;
	cout << fj(n) << endl;

	return 0;
}
