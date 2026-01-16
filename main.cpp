#include <iostream>
#include <string>

using namespace std;

int main() {
    string person;
    
    cout << "Здравствуйте, введите свое имя: " << endl;
    cin >> person;
    cout << "Добро пожаловать, " << person << "!" << endl;

    int mainmenu;
    bool mainrunning = true;

    while (mainrunning) {
        cout << "\n--- MAIN ---" << endl;
        cout << "1. Работа с числами" << endl;
		cout << "2. Терминал"<<endl;
        cout << "3. Выход из программы" << endl;
        cout << "Выберите: ";
        cin >> mainmenu;

        if (mainmenu == 1) {
            bool calcRunning = true;
            while (calcRunning) {
                cout << "\n--- МЕНЮ (ЧИСЛА) ---" << endl;
                cout << "1. Калькулятор" << endl;
                cout << "2. Создать файл (в разработке)" << endl;
                cout << "3. Назад в главное меню" << endl;
                cout << "Выберите действие: ";
                
                int calcChoice; // Считываем выбор сюда
                cin >> calcChoice;

                if (calcChoice == 1) {
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
                else if (calcChoice == 3) {
                    cout << "Возвращаемся в главное меню..." << endl;
                    calcRunning = false; // Выход из цикла калькулятора
                }
                else if (calcChoice == 2) {
                    cout << "Функция в разработке..." << endl;
                }
            }
        } 
        else if (mainmenu == 3) {
            cout << "До свидания, " << person << "!" << endl;
            mainrunning = false; // Полный выход
        }
    if (mainmenu == 2) {
            bool terminalc = true; // Исправлено: bool вместо string
            string commandd;
            cout << "\nТерминал запущен. Введите 'help' для списка команд или 'exit' для выхода." << endl;
            
            while(terminalc) {
                cout << person << "@myos:~$ ";
                cin >> commandd;

                if (commandd == "help") {
                    cout << "\n--- СПИСОК ДОСТУПНЫХ КОМАНД ---" << endl;
                    cout << "help     - показать это меню" << endl;
                    cout << "hello    - получить приветствие" << endl;
                    cout << "clear    - очистить экран (эмуляция)" << endl;
                    cout << "exit     - выйти из терминала" << endl;
                    cout << "time     - Время например(17.01.2026)" << endl;
                    cout << "-------------------------------" << endl;
                } 
                else if (commandd == "hello") {
                    cout << "Привет, " << person << "! Система работает в штатном режиме." << endl;
                }
                else if (commandd == "exit") {
                    terminalc = false; // Выход из терминала
                }
                else if (commandd == "clear"){
                    system("clear");
                    cout<<"Экран очищен"<<endl;
                }
                else {
                    cout << "Команда '" << commandd << "' не найдена." << endl;
                }
            }
		}  
    } 
    // Очистка перед выходом
    cin.ignore(10000, '\n'); 
    cout << "\nНажмите Enter, чтобы закрыть программу..." << endl;
    cin.get(); 

    return 0;
}
