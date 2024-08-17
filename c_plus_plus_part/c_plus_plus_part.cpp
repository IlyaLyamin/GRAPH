#include "Header1.h"
#include <map>
// просто в матричном виде
// создаём словарь
// питон закидывает записанные точки в файл, оттуда их читаеат программа

using namespace std;


void fill_dict(map<unsigned short int, string>* dict, string* names) {// на конце names должен быть 0
	unsigned short int i = 0;
	while (names[i] != "0") {
		(*dict)[i] = string(names[i]);// names[i];
		cout << names[i] << endl;
		i++;
	}
	names[i] = "0";
}


int main() {
	setlocale(LC_ALL, "rus");
	map<unsigned short int, string> dict;
	string* a = new string[10];// names

// тестовый массив
	for (int i = 0; i < 9; i++) {
		a[i] = 'i';
	}
	a[9] = '0';
//
	for (int i = 0; i < 10; i++) {
		cout << a[i];
	}
	fill_dict(&dict, a);
}