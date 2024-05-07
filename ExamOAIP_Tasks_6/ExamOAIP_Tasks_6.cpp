/*
Разработать функцию, которая подсчитывает количество элементов
стека, у которых равные "соседи".
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	setlocale(0, "ru");
	stack<int> Stack;
	stack<int> Stack2;
	cout << "Введите любые числа в стек" << endl;
	for (int i = 0; i < 3; i++)
	{
		int Num;
		cin >> Num;
		Stack.push(Num);
	}
	cout << "Поиск соседей" << endl;
	int neibhourse = 0;
	while (Stack.size() > 1)
	{
		int temp = Stack.top();
		Stack2.push(Stack.top());
		Stack.pop();
		if (temp == Stack.top()) {
			neibhourse++;
		}
	}
	cout << "Количество соседей " << neibhourse << endl;
}