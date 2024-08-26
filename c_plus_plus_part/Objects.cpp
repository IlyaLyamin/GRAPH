//#include "MyVector.cpp"
#include "Exceptions.h"
#include "MyVector.cpp"
using namespace std;

template <class Type> 
void print_2d_arr(Type** array, int ind) {
	for (int row = 0; row < ind; row++) {
		for (int column = 0; column < ind; column++) {
			cout << array[row][column] << " ";
		}
		cout << endl;
	}
}

class Road {
public:
	Road() :col_points(0), len(0) {}

	Road(string start_point) {
		col_points = 1;
		len = 0;
		Points.PushBack(start_point);
	}

	void check_all_inf() {
		cout << " оличество точек: " << col_points << endl;
		cout << "ќбща€ длина всех путей: " << len << endl;
		cout << "“очки: ";
		for (int i = 0; i < col_points; i++) {
			cout << Points[i] << " ";
		}
		cout << endl;
	}

	void add_one_point(string name, int length) {
		Points.PushBack(name);
		Lengths.PushBack(length);
		col_points++;
		check_length();
	}

	void del_last_point() {
		Points.SetSize(len - 1);
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
	}

	int get_col_p() const{
		return col_points;
	}

	int get_len() const{
		return len;
	}

	Road operator+(Road& rhs) {// вместо того, что бы использовать const просто создал доп метод в классе Road
		Road new_r;
		new_r.col_points = this->col_points + rhs.get_col_p() - 1;
		new_r.len = this->len + rhs.get_len();
		
		cout << "—мотри============================================\n";
		this->Points.print();
		cout << " -compare- ";
		rhs.Points.print();
		cout << endl;
		// сейчас здесь будет написан ужастный беспредел который надо будет когда-нибудь убрать
		if (this->Points[0] == rhs.Points[(rhs.get_col_p() - 1)]) {
			for (int i = (this->get_col_p() - 1); i >= 0; i--) {
				new_r.Points.PushBack(this->Points[i]);
				new_r.Lengths.PushBack(this->Lengths[i]);
			}

			for (int i = (rhs.get_col_p() - 2); i >= 0; i--) {// начинаю добавл€ть с первой потому что сумма вида a -> b + b -> c = a -> b -> c
				new_r.Points.PushBack(rhs.Points[i]);
				new_r.Lengths.PushBack(rhs.Lengths[i - 1]);
			}
		}
		else if (this->Points[0] == rhs.Points[0]) {
			for (int i = (this->get_col_p() - 1); i >= 0; i--) {
				new_r.Points.PushBack(this->Points[i]);
				new_r.Lengths.PushBack(this->Lengths[i]);
			}

			for (int i = 1; i < rhs.get_col_p(); i++) {// начинаю добавл€ть с первой потому что сумма вида a -> b + b -> c = a -> b -> c
				new_r.Points.PushBack(rhs.Points[i]);
				new_r.Lengths.PushBack(rhs.Lengths[i - 1]);
			}
		}
		else if (this->Points[(this->col_points - 1)] == rhs.Points[0]) {
			for (int i = 0; i < this->get_col_p(); i++) {
				new_r.Points.PushBack(this->Points[i]);
				new_r.Lengths.PushBack(this->Lengths[i]);
			}

			for (int i = 1; i < rhs.get_col_p(); i++) {// начинаю добавл€ть с первой потому что сумма вида a -> b + b -> c = a -> b -> c
				new_r.Points.PushBack(rhs.Points[i]);
				new_r.Lengths.PushBack(rhs.Lengths[i - 1]);
			}
		}
		else if (this->Points[(this->col_points - 1)] == rhs.Points[(rhs.get_col_p() - 1)]) {
			for (int i = 0; i < this->get_col_p(); i++) {
				new_r.Points.PushBack(this->Points[i]);
				new_r.Lengths.PushBack(this->Lengths[i]);
			}

			for (int i = (rhs.get_col_p() - 2); i >= 0; i--) {// начинаю добавл€ть с первой потому что сумма вида a -> b + b -> c = a -> b -> c
				new_r.Points.PushBack(rhs.Points[i]);
				new_r.Lengths.PushBack(rhs.Lengths[i - 1]);
			}
		}
		return new_r;
	}

	Road& operator= (const Road& rhs) {
		MyVector<int> new_l;
		MyVector<string> new_p;
		this->col_points = rhs.col_points;//->
		this->len = rhs.get_len();// можно использовать, что объект что метод, разницы нет потому что есть const
		for (int i = 0; i < col_points; i++) {
			if (i < (col_points - 1)) {
				new_l.PushBack(rhs.Lengths[i]);
			}
			new_p.PushBack(rhs.Points[i]);
		}
		Lengths = new_l;
		Points = new_p;
		return *this;
	}

private:
	int col_points;
	int len;
	MyVector<string> Points;// наименовани€ пунктов
	MyVector<int> Lengths;// длины участков
};