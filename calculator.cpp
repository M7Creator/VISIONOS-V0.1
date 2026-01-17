#include "calculator.h"
#include <iostream>
#include <string>
using namespace std;

void calc(){
    double a, b;
                    char deystvie;
                    cout << "--- Калькулятор ---" << endl;
                    cout << "Введите первое число: "; cin >> a;
                    cout << "Действие (+, -, *, /): "; cin >> deystvie;
                    cout << "Введите второе число: "; cin >> b;

                    cout << "Результат: ";
                    if (deystvie == '+') cout << a + b;
                    else if (deystvie == '-') cout << a - b;
                    else if (deystvie == '*') cout << a * b;
                    else if (deystvie == '/') {
                        if (b != 0) cout << a / b;
                        else cout << "Ошибка! На ноль делить нельзя.";
                    }
                    else cout << "Неизвестная операция.";
                    cout << endl;
}