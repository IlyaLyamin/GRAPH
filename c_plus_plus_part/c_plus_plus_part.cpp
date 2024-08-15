#include "Header1.h"
//#include "MyVector.cpp"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");

	MyVector<int> vec_;
	int N;

	cout << "Введите количество элементов: ";
	cin >> N;
	InputMyVector(vec_, N);
	//vec.SetSize(N);
	//for (int i = 0; i < N; i++) {
	//	cout << "Элемент массива " << i + 1 << " равен: ";
	//	cin >> vec[i];
	//	cout << endl;
	//}
	OutputMyVector(vec_);
	cout << endl << "Измените размер вектора: ";
	cin >> N;

	if (N < vec_.Length()) {
		vec_.SetSize(N);
		cout << "осталось: ";
		OutputMyVector(vec_);
	}
	else {
		vec_.SetSize(N);
	}
	if (N != 0)
	{
		for (int i = 0; i < N; i++)
		{
			cout << "Элемент массива " << i + 1 << " равен: ";
			cin >> vec_[i];
			cout << endl;
		}
	}
	OutputMyVector(vec_);

	// Myvector
	MyVector<char> vec_2;
	int N_2;

	cout << "Введите количество элементов: ";
	cin >> N_2;
	vec_2.SetSize(N_2);
	for (int i = 0; i < N_2; i++) {
		cout << "Элемент массива " << i + 1 << " равен: ";
		cin >> vec_2[i];
		cout << endl;
	}
	//Вывод
	for (int i = 0; i < N_2; i++)
	{
		cout << vec_2[i] << " ";
	}
	cout << endl;
}