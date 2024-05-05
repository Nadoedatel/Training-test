#include <iostream>
#include <stack>
using namespace std;
/*
Разработать функцию, которая удаляет из стека первый
отрицательный элемент, если такой есть.
*/

void Function(stack<int> func_element, stack<int> Plus, stack<int> Minus, int i) {
	while (i != 0) {
		if (func_element.top() < 0) {
			Minus.push(func_element.top());
			cout << "Элемент удален" << endl;
			func_element.pop();
		}
		else {
			Plus.push(func_element.top());
			cout << "Элемент не удален" << endl;
			func_element.pop();
		}
		i--;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	stack<int> func_element;
	stack<int> Plus;
	stack<int> Minus;
	int i = 0;
	cout << "Сколько чисел вы хотите ввести:";
	cin >> i;
	int j = i;
	while (i != 0) {
		cout << "Введите число для стека: ";
		int Number;
		cin >> Number;
		func_element.push(Number);
		i--;
	}
	cout << func_element.size() << endl;

	while (j != 0) {
		if (func_element.top() < 0) {
			Minus.push(func_element.top());
			cout << "Элемент удален" << endl;
			func_element.pop();
		}
		else {
			Plus.push(func_element.top());
			cout << "Элемент не удален" << endl;
			func_element.pop();
		}
		j--;
	}
	
	if (Minus.size() != 0 && Plus.size() != 0) {
		if (Minus.size() != 0) {
			while (!Minus.empty()) {
				cout << Minus.top() << endl;
				cout << "Это первый стек" << endl;
				Minus.pop();
			}
		}
		while (!Plus.empty()) {
			cout << Plus.top() << endl;
			cout << "Это второй стек" << endl;
			Plus.pop();
		}
	}
	else if (!Minus.empty()) {
		while (!Minus.empty()) {
			cout << Minus.top() << endl;
			Minus.pop();
		}
	}
	else if (!Plus.empty()) {
		while (!Plus.empty()) {
			cout << Plus.top() << endl;
			Plus.pop();
		}
	}
	else {
		cout << "Оба элемента пустые" << endl;
	}	
	return 0;
}