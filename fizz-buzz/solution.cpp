/*
FIZZBUZZ

author: Yaushev Farukh
date: 19.02.2020

1. Input - sequence of numbers.
2. If number is divisible by 3, replace it with fizz
3. if number is divisible by 5, replace it with buzz
4. If both, then fizzbuzz
5. Output to the console
IMPORTANT: division operation and modulo operation is prohibited

*/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;


set<char> VALIDATE = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Проверка корректности ввода:
// 1) число не выходит за пределы long long
// 2) ввели число
// input - вход, который надо проверить
char Validate(const string &input);

// Возвращает сумму цифр по модулю 9. Делаем это рекурсивно до тех пор пока не останется число которое состоит из одной цифры.
// n - числу, сумму цифр которго надо вернуть
string sum_of_digits(const string & n);

// Проверка делимости на 3
// Возвращает ture, если num делится на три
// false - иначе
bool isDivisibleBy3(const string &num);

// Проверка делимости на 5
bool isDivisibleBy5(const string &num);

// На вход получает вектор с числами - v и делает замену в тех метсах, где это требуется
// Полсе вызова функции элементы вектор v будет замены на то, что нужно
void answer(vector <string> &v);

int main() {

	vector <string> v;
	string s;
	int cnt;
	
	cin >> cnt;
	if (cnt < 0) {
		cout << "incorrect input" << endl;
		return 0;
	}
	
	for (int i = 0; i < cnt; i++) {
		cin >> s;
		switch(Validate(s)) {
			case 1:
				cout << s <<" is not a number" << endl;
				return 1;
			break;
			case 2:
				cout << s << " :overflow" << endl;
				return 1;
			break;
		}
		v.push_back(s);
	}
	
	answer(v);
	for (auto i : v) {
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

string sum_of_digits(const string & n) {
	int sum = 0; // Сумма цифр
	int i = 0;
	string tmp = "";
	if (n[0] == '-') {// Отрицательное число
		i = 1;// Пропутим первый символ, то есть знак "-"
	}
	for (i = 0; i < (int)n.size(); i++) {
		tmp = n[i];
		sum += atoi(tmp.c_str());
	}
	string sum_str = to_string(sum);
	if (sum_str.size() == 1) { // "Длина" числа равна 1
		return to_string(sum);
	}
	return sum_of_digits(to_string(sum));
}


bool isDivisibleBy3(const string &num) {
	string sum = sum_of_digits(num); // Посмотрим чему равляется сумма цифр по модулю 9
	// Если исходное число делится на 3, то функцияя вернет либо 0, либо 3, лмбо 6, либо 9
	if (sum == "3" || sum == "6" || sum == "9" || sum == "0") {
		return true;
	} else {
		return false;
	}
}

bool isDivisibleBy5(const string &num) {
	if (num[num.size()-1] == '0' || num[num.size()-1] == '5') {
		return true;
	} else {
		return false;
	}
}

void answer(vector <string> &v) {
	for (int i = 0; i < (int)v.size(); i++) {
		if (isDivisibleBy3(v[i])) { // делится на 3
			if(isDivisibleBy5(v[i])) {// делится на 5
				v[i] = "fizzbuzz";// fizzbuzz
				continue;
			}
			v[i] = "fizz";// fizz
			continue;
		} else {
			if(isDivisibleBy5(v[i])) {
				v[i] = "buzz";// buzz
				continue;
			}
		}
	}
}