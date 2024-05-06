/*
Разработать функцию, которая формирует стек Stack, включив в него
по одному разу элементы, которые входят в один из стеков Stack1 и Stack2, но
не входят в другой.
*/
#include <stack>
#include <iostream>
using namespace std;

int main() {
	setlocale(0, "ru");
	stack<int> Stack;
	stack<int> Stack1;
	stack<int> Stack2;

	cout << "В стэке максимум 3 числа!" << endl;
	cout << "Введите числа в 1-ый стек: " << endl;
	int i = 0;
	int arrStack1[3];
	while (i < 3)
	{
		int Num;
		cin >> Num;
		Stack1.push(Num);
		arrStack1[i] = Num;
		i++;
	}
	int j = 0;
	int arrStack2[3];
	cout << "Введите числа во 2-ой стек: " << endl;
	while (j < 3)
	{
		int Num;
		cin >> Num;
		Stack2.push(Num);
		arrStack2[j] = Num;
		j++;
	}
	
	for (int i = 0; i < 3; i++) {
		int temp = arrStack1[i];
		int Sovpadinai = 0;
		for (int j = 0; j < 3; j++) {
			if (temp == arrStack2[j]) {
				Sovpadinai++;
			}
		}
		if (Sovpadinai == 0) {
			Stack.push(temp);
		}
	}
	for (int i = 0; i < 3; i++) {
		int temp = arrStack2[i];
		int Sovpadinai = 0;
		for (int j = 0; j < 3; j++) {
			if (temp == arrStack1[j]) {
				Sovpadinai++;
			}
		}
		if (Sovpadinai == 0) {
			Stack.push(temp);
		}
	}

	if (Stack2.size() == 0 && Stack1.size() == 0) {
		cout << "Оба стека пустые" << endl;
	}
	cout << "Стек в котором будут разные числа: " << endl;
	while (!Stack.empty()) {
		cout << Stack.top() << endl;
		Stack.pop();
	}
}