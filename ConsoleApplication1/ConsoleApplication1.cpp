#include <iostream>
#include <stack>
using namespace std;
/*
Разработать функцию, которая удаляет из стека первый
отрицательный элемент, если такой есть.
*/

void Function() {

}

int main() {
	setlocale(LC_ALL, "Russian");

	stack<int> func_element;
	stack<int> Perezapis;
	int i = 0;
	cout << "Сколько чисел вы хотите ввести:";
	cin >> i;
	while (i < 5) {
		cout << "Введите число для стека: ";
		int Number;
		cin >> Number;
		func_element.push(Number);
	}
	cout << func_element.size();
	return 0;
}