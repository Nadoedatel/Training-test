/*
Создать класс типа - Окружность.
Поля – координаты центра, радиус.
Методы  вычисляют площадь, длину окружности.
Конструкторы должны проверять корректность задаваемых параметров.
Создать массив объектов.
Вывести:
a) группы окружностей, центры которых лежат на одной прямой;
b) наибольший и наименьший по площади (периметру) объект.
*/
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Circle {
public:
	int X;
	int Y;
	int r;
	Circle* next = nullptr;
	Circle* prev = nullptr;
	Circle(int a_X, int a_Y, int a_r) {
		X = a_X;
		Y = a_Y;
		r = a_r;
	};
	void Print() {
		cout << "X = " << X << " Y = " << Y << " r = " << r << endl;
	}
	double C_Are() {
		double S;
		S = M_PI * pow(r, 2);
		cout << "Площадь окружности: " << S << endl;
		return S;
	}
	double C_Circle() {
		double C;
		C = 2 * M_PI * r;
		cout << "Длина окружности " << C << endl;
		return C;
	}
};

int main() {
	setlocale(0, "ru");

	int countCircle;
	cout << "Сколько вы хотите ввести окружностей: " << endl;
	cin >> countCircle;

	Circle* firstCircle = nullptr;
	Circle* currentCircle = nullptr;

	for (int i = 0; i < countCircle; i++) {
		cout << "Заполните окружность " <<  i + 1 <<  endl;
		int X, Y, r;
		cin >> X >> Y >> r;

		Circle* newCircle = new Circle(X, Y, r);
		if (i == 0) {
			firstCircle = newCircle;
			currentCircle = newCircle;
		}
		else {
			currentCircle->next = newCircle;
			newCircle->prev = currentCircle;
			currentCircle = newCircle;
		}
	}

	cout << "Вывод работы по окружностям" << endl;
	currentCircle = firstCircle;
	while (currentCircle != nullptr) {
		currentCircle->Print();
		currentCircle->C_Are();
		currentCircle->C_Circle();
		currentCircle = currentCircle->next;
	}
	
	cout << "Вывод самого большого по площади" << endl;
	Circle* maxCircle = nullptr;
	double maxArea = 0;
	currentCircle = firstCircle;
	while (currentCircle != nullptr) {
		currentCircle->Print();
		double temp = currentCircle->C_Are();
		if (temp > maxArea) {
			maxArea = temp;
			maxCircle = currentCircle;
		}
		currentCircle = currentCircle->next;
	}
	if (maxCircle != nullptr) {
		cout << "Наибольшая площадь у окружности: " << endl;
		maxCircle->Print();
	}
}