#include <iostream>
#include <math.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void exercise();
void exercise2();

int main()
{
    setlocale(0, ".1251");
    //Вибір завдання
    std::cout << "Яку вправу ви би хотiли побачити?\n";
    std::cout << "1 = Перша вправа, 2 = Друга вправа\n";

    int n = 1;
    if (n != 0) {
        std::cin >> n;
        switch (n) {
        case 1:
            exercise();
            break;
        case 2:
            exercise2();
            break;
        default:
            std::cout << "Нажаль, такої вправи немає" << std::endl;
            break;
        }
    }
}
//Перше завдання
void exercise() {
    const int n = 10;
    double mass[n];
    std::cout << "Введiть масив" << std::endl;//Введення чисел масиву
    for (int i = 0; i < n; i++)
    {
        std::cin >> mass[i];
    }
    double b = 1;
    int k = 0;
    for (int i = 0; i < n; i++)
        if (mass[i] < 0)
        {
            b += mass[i];
            k++;
        }
    if (k == 0) {
        std::cout << std::endl << "Намає негативних елементiв";
    }
    else
        std::cout << "Вiдповiдь \n" << b;//Відповідь
};
//друге завдання
void exercise2() {
    int n = 10, idxmin, idxmax;
    int* mass = new int[n];
    long int mul = 1;
    std::cout << "Введiть масив" << std::endl;//Введення чисел масиву
    for (int i = 0; i < n; i++)
    {
        std::cin >> mass[i];
    }
    for (int i = 0; i < n; i++) {
        mass[i] = mass[i];
        cout << mass[i] << " ";
        if (i == 0) {
            idxmin = idxmax = i;
        }
        else {
            if (mass[i] < mass[idxmin]) {
                idxmin = i;
            }
            if (mass[i] > mass[idxmax]) {
                idxmax = i;
            }
        }
    }
    cout << endl << "Мiнiмальне: " << mass[idxmin] << endl << "Максимальне: " << mass[idxmax] << endl;

    for (int i = min(idxmin, idxmax) + 1; i < max(idxmin, idxmax); i++) {
        mul *= mass[i];
    }
    cout << "Елементи для добутку: " << mul << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            if (mass[j] > mass[j + 1]) {
                int b = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = b;
            }
        }

    }
    std::cout << std::endl << "Вiдсортирований масив" << std::endl;
    for (int i = 9; i >= 0; i--) {
        std::cout << mass[i] << " ";
    }
    delete[] mass;
}