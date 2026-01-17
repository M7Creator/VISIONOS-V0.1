#include <iostream>
#include "help.h"
#include <string>
using namespace std;
void runHelp(){
    cout << "\n--- СПИСОК ДОСТУПНЫХ КОМАНД ---" << endl;
    cout << "help     - показать это меню" << endl;
    cout << "hello    - получить приветствие" << endl;
    cout << "clear    - очистить экран (эмуляция)" << endl;
    cout << "exit     - выйти из терминала" << endl;
    cout << "time     - Время например(17.01.2026)" << endl;
    cout << "echo     - Повторение вашего текста"<<endl;
    cout << "shutdown - Завершения процесса"<<endl;
    cout << "guess    - Мини-игра угадай число (от 1 до 10)"<<endl;
    cout << "random   - Рандомное число от 0 до 999"<<endl;
    cout << "contact  - Данные для контакта с разработчиком"<<endl;
    cout << "-------------------------------" << endl;
}