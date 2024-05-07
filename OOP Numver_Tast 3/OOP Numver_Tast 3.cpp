/*
Задача 3
Определить класс Вектор.
Конструкторы должны проверять корректность задаваемых параметров.
Реализовать методы для вычисления модуля вектора, скалярного произведения, сложения, вычитания, умножения на константу.
Создать массив объектов.
Вывести:
a) вектора с заданным модулем;
b) определить вектор с наибольшей/наименьшей суммой элементов.
*/
#include <iostream>
#include <cmath>

class Vector {
public:
    // Конструктор, принимающий массив компонент и его размер
    Vector(double* components, int size) {
        if (size <= 0) {
            throw std::invalid_argument("Размер вектора должен быть больше 0");
        }
        this->components = new double[size];
        for (int i = 0; i < size; ++i) {
            this->components[i] = components[i];
        }
        this->size = size;
    }

    // Деструктор
    ~Vector() {
        delete[] components;
    }

    // Метод для вычисления модуля вектора
    double module() const {
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += components[i] * components[i];
        }
        return std::sqrt(sum);
    }

    // Метод для вычисления скалярного произведения
    double dotProduct(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Векторы должны иметь одинаковую размерность для скалярного произведения");
        }
        double sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += components[i] * other.components[i];
        }
        return sum;
    }

    // Метод для сложения векторов
    Vector operator+(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Векторы должны иметь одинаковую размерность для сложения");
        }
        double* result = new double[size];
        for (int i = 0; i < size; ++i) {
            result[i] = components[i] + other.components[i];
        }
        return Vector(result, size);
    }

    // Метод для вычитания векторов
    Vector operator-(const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Векторы должны иметь одинаковую размерность для вычитания");
        }
        double* result = new double[size];
        for (int i = 0; i < size; ++i) {
            result[i] = components[i] - other.components[i];
        }
        return Vector(result, size);
    }

    // Метод для умножения вектора на константу
    Vector operator*(double scalar) const {
        double* result = new double[size];
        for (int i = 0; i < size; ++i) {
            result[i] = components[i] * scalar;
        }
        return Vector(result, size);
    }

    // Метод для вывода вектора
    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << components[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // Массив компонент
    double* components;
    // Размер массива
    int size;
};

int main() {
    setlocale(0, "ru");
    // Создаем массив объектов класса Vector
    double components1[] = { 3, 4, 0 };
    double components2[] = { 1, 2, 0 };
    double components3[] = { 5, 6, 0 };
    Vector v1(components1, sizeof(components1) / sizeof(components1[0]));
    Vector v2(components2, sizeof(components2) / sizeof(components2[0]));
    Vector v3(components3, sizeof(components3) / sizeof(components3[0]));

    // Выводим вектора с заданным модулем
    std::cout << "Векторы с заданным модулем:" << std::endl;
    v1.print();
    v2.print();
    v3.print();

    // Определяем вектор с наибольшей/наименьшей суммой элементов
    Vector maxSumVector = v1 + v2 + v3;
    Vector minSumVector = v1 - v2 - v3;
    std::cout << "Вектор с наибольшей суммой элементов:" << std::endl;
    maxSumVector.print();
    std::cout << "Вектор с наименьшей суммой элементов:" << std::endl;
    minSumVector.print();

    return 0;
}
