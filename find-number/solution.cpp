/*
Find number

author: Yaushev Farukh
date: 19.02.2020

1.You have sequence from 0 to M.
2.Input – unordered array of integer numbers of size M-n.
3.Output – array of missing numbers in input array.
4.Example: M = 5, arraySize= 3, array = {4, 1, 3}Output = {0, 2}

*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;


set<char> VALIDATE = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Проверка корректности ввода:
// 1) число не выходит за пределы long long
// 2) ввели число
// input - вход, который надо проверить
char Validate(const string &input);

// Принимает на вход:
// m - длина "полного" массива
// v - вектор, в котором надо найти недостающие элементы
vector<long long> find_number(const int m,const vector <long long> &v);

int main() {
	string str_n, str_m;
	cin >> str_n;
	cin >> str_m;
	if(!Validate(str_n) || !Validate(str_n)) {
		cout << "input error" << endl;
		return 1;
	}
	long long n = stoll(str_n);
	long long m = stoll(str_m);
	if (n > m) {
		cout << "input error" << endl;
		return 0;
	} 
	vector <long long> v(n);
	for (long long i = 0; i < n; i++) {
		cin >> v[i];
		if(!Validate(to_string(v[i])) || v[i] < 0) {
			cout << "input error" << endl;
			return 1;
		}
	}

	vector <long long> ans = find_number(m, v);
	for (const auto &i : ans) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}


char Validate(const string &input) {
	int i = 0;
	if (input[0] == '-') {
		i = 1;
	}
	for (i; i < (int)input.size(); i++) {
	    auto it = VALIDATE.find(input[i]);

	    if (it == VALIDATE.end() ) {
	    	return 1;
	    }
	}
	
	try {
		stoll(input);
		return 0;
	}
	catch (...){
		return 2;
	}
}

vector<long long> find_number(const int m,const vector <long long> &v) {
	vector <long long> full(m, -1);// Вектор размера m, все элементы которого равны -1
	vector <long long> ans; // Mассив пропущенных чисел
//	Входной вектор v состоит из целых чисел в диапазоне от 0 до m-1,
//	поэтому можно использовать эти числа в качестве номеров позиция в векторе full.
//	Заменив -1 на 0 в указанных в векторе v позициях, можно легко определить пропущенные числа.
//	Для этого нужно найти номера позиций в которых осталась -1.
	for (const auto&  i : v) {
		full[i] = 0;
	}
	for (int i = 0; i < m; i++) {// ищем позиции в которых -1.
		if (full[i] == -1) {
			ans.push_back(i);
		}
	}
	return ans;
}
