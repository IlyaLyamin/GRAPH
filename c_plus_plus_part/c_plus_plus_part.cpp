#define _CRT_SECURE_NO_DEPRECATE
#include "Header1.h"
#include<stdio.h>
#include <map>
#include <stdlib.h>  // Для использования функции strtol()
#include <set>

// просто в матричном виде
// создаём словарь
// питон закидывает записанные точки в файл, оттуда их читаеат программа
#define SIZE 250// из-за этого программа не будет выдерживать больше 124 точек

using namespace std;


void read_file_points(int* col_p) {// Создаёт двумерный массив и получает все точки
	cout << "В функции" << endl;
	FILE* file = fopen("table.csv", "r");
	int b = fscanf(file, "%d", col_p);
	try
	{
		if (!b) {
			cout << "Error" << endl;
			throw 0;
		}
		//char* token = strtok();
		//while (token != '\n')
		fclose(file);
	}
	catch (const std::exception&)
	{
		cout << exception().what() << endl;
	}
	catch (int kod) {
		if (kod == 0) cout << "Не считано количество точек" << endl;
	}
}


void read_file_array(int col_p, string* points, int** array) {
	FILE* file = fopen("table.csv", "r");
	FILE* file_2 = fopen("vertices.csv", "r");
	char line[1024];
	char points_[1024];

	
	try
	{
		fgets(points_, SIZE, file_2);
		char* token_1;
		// Начало разделения строки по запятой
		token_1 = strtok(points_, " ");
		int column = 0;
		while (token_1 != NULL) {
			// Преобразуем токен в число (если нужно) или оставляем как строку
			if (token_1) {
				points[column] = token_1;
				column++;
			}
			// Получаем следующий токен
			token_1 = strtok(NULL, " ");
		}
		//
		for (int i = 0; i < col_p; i++) {
			cout << points[i] << " ";
		}
		//

		// Считываем файл построчно
		int row = 0;
		
		fgets(line, sizeof(line), file);

		while (fgets(line, sizeof(line), file)) {
			column = 0;
			// Указатель для разделения строки
			char* token;

			// Начало разделения строки по запятой
			token = strtok(line, ",");
			// Перебираем все значения в строке
			while (token != NULL) {
				// Преобразуем токен в число (если нужно) или оставляем как строку
				int value = strtol(token, NULL, 10);
				
				if (value) {
					array[row][column] = value;
					column++;
				}
				// Получаем следующий токен
				token = strtok(NULL, ",");
				if (column == col_p) {
					row++;
					column = 0;
				}
			}
		}
		fclose(file);
		fclose(file_2);
	}
	catch (const std::exception&)
	{
		cout << exception().what() << endl;
	}
}


void fill_dict(map<unsigned short int, string>* dict, string* names, int col_p) {
	unsigned short int i = 0;
	for (int i = 0;i < col_p; i++){
		(*dict)[i] = names[i];// names[i];
	}
}


void floid_aloritm_undirected(map<unsigned short int, string>* dict, int** array, int col_p) {
	map<set<int>, Road> main_dict;
	int col_road = 0;
	for (int i = 0; i < col_p; i++) {// Общее количество дорог не больше суммы первых n-1-го элемента в случае неоринтированного графа
		col_road += i;
	}
	// заполняем базовый главный словарь
	for (int row = 0; row < col_p; row++) {
		for (int column = (row + 1); column < col_p; column++) {
			main_dict[{row, column}] = Road((*dict)[row]);
			if (array[row][column] != -1) {
				main_dict[{row, column}].add_one_point((*dict)[column], array[row][column]);
			}
			main_dict[{row, column}].check_all_inf();
		}
	}

}


int main() {
	setlocale(LC_ALL, "rus");
	map<unsigned short int, string> dict;
	int col_points;

	read_file_points(&col_points);
	
	string* points = new string[col_points];// создание массива вершин
	// создание массива
	int** array = new int* [col_points];
	for (int i = 0; i < col_points; i++) {
		array[i] = new int[col_points];
	}
	//
	read_file_array(col_points, points, array);
	// cout << array
	for (int i = 0; i < col_points; i++) {
		for (int j = 0; j < col_points; j++) {
			cout << array[i][j] << " ";
		}
		cout << "\n";
	}
	//
	fill_dict(&dict, points, col_points);

	for (int i = 0; i < col_points; i++) {
		cout << dict[i] << " ";
	}

	floid_aloritm_undirected(&dict, array, col_points);
}