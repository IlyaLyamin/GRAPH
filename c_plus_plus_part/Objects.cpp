//#include "MyVector.cpp"
#include "Exceptions.h"
#include "MyVector.cpp"
using namespace std;


class Road {
public:
	Road() :col_points(0), len(0) {}

	Road(int col_points){
		this -> col_points = col_points;
		Points.SetSize(col_points);
		Lengths.SetSize(col_points - 1);
		check_length();
	}

	void add_one_point(char name, int length) {
		Points.PushBack(name);
		Lengths.PushBack(length);
		check_length();
	}

	void del_last_point() {
		Points.SetSize(len - 1);// допиши сохранение предыдущих элементов
	}

	void check_length() {
		len = 0;
		try
		{
			for (int i = 0; i < (col_points - 1); i++) {
				len += Lengths[i];
			}
		}
		catch (const exception&)
		{
			cout << _1 << exception().what() << endl;
		}
		cout << "Current len is - " << len << endl;
	}

	void print() {
		cout << Points[0];
		for (int i = 0; i < col_points; i++) {

		}
	}

private:
	int col_points;
	int len;
	MyVector<char> Points;// наименования пунктов
	MyVector<int> Lengths;// длины участков
};