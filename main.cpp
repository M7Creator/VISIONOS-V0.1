#include <iostream>
#include <string>
#include <ctime>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <cstring>
#include <winsock2.h>
#include <fstream>
#include "calculator.h"
#include "shutdown.h"
#include "help.h"
using namespace std;
void receive_thread(int sock) {
    char buffer[1024];
    while (true) {
        memset(buffer, 0, 1024);
        int bytes = recv(sock, buffer, 1024, 0);
        
        if (bytes > 0) {
            // \r стирает текущую строку "@visionos:~$ "
            // \n переносит чат на новую строку
            cout << "\r" << string(buffer, bytes) << "\n";
            // Возвращаем приглашение для ввода
            cout << "@visionos:~$ " << flush;
        } else if (bytes == 0) {
            cout << "\n[СИСТЕМА]: Соединение с сервером разорвано." << endl;
            break;
        } else {
            break;
        }
    }
}

int main() {
    string person;
    
    cout << "Здравствуйте, введите свое имя: " << endl;
    cin >> person;
    cout << "Добро пожаловать, " << person << "!" << endl;
   //fstream fs;
   //fs.open("OS/mainmenu/person.txt");
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
                    calc();
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
                cout << person << "@visionos:~$ ";
                cin >> commandd;

                if (commandd == "help") {
                    runHelp();
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
                else if (commandd == "time") {
                time_t now = time(0);
                char* dt = ctime(&now);
                cout << "Текущее системное время: " << dt;
                }
                else if (commandd == "shutdown"){
                 runShutdown();
                }
                else if (commandd == "echo"){
                    string echotext;
                    cout<<"Введите то что нужно повторить: "<<endl;
                    cin.ignore(); 
                    getline(cin,echotext);
                    cout<<">>"<<echotext<<endl;
                }
                else if (commandd == "guess"){
                    srand(time(NULL)); // Инициализация генератора
                    int randomNumber = 1 + rand() % 10; // Число от 1 до 20
                    int guessnumber;
                    cin>>guessnumber;
                    if (randomNumber == guessnumber){
                        cout<<"Вы угадали!"<<endl;
                    }
                    else{
                        cout<<"Вы не угадали!"<<endl;
                        cout<<"Праивльный ответ: "<<randomNumber<<endl;
                    }
                }
                else if (commandd == "random"){
                  srand(time(NULL)); // Инициализация генератора
                  int randomNumber = 1 + rand() % 999;  
                  cout<<">>"<<randomNumber<<endl;
                }
                else if (commandd == "conact"){
                    cout<<"____________________"<<endl;
                    cout<<"telegram: @perc0dealer"<<endl;
                    cout<<"____________________"<<endl;
                    cout<<"email: markevics123@gmail.com"<<endl;
                    cout<<"____________________"<<endl;
                }
                else if (commandd == "chat") {
                int sock = socket(AF_INET, SOCK_STREAM, 0);
                sockaddr_in serv_addr;
                serv_addr.sin_family = AF_INET;
                serv_addr.sin_port = htons(8080);
                // ЗАМЕНИ НА IP СВОЕГО UBUNTU VPS
                inet_pton(AF_INET, "185.112.59.192", &serv_addr.sin_addr);

                if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
                    cout << "[ОШИБКА]: Сервер чата недоступен." << endl;
                } else {
                    cout << "[СИСТЕМА]: Подключено к глобальному серверу!" << endl;
                    cout << "(Введите 'exit', чтобы выйти из чата)" << endl;
                    
                    // Запускаем поток прослушивания
                    thread(receive_thread, sock).detach();

                    string msg;
                    while (true) {
                        getline(cin >> ws, msg);
                        if (msg == "exit") break;
                        
                        string full_msg = "[" + person + "]: " + msg;
                        send(sock, full_msg.c_str(), full_msg.length(), 0);
                    }
                    close(sock);
                    cout << "[СИСТЕМА]: Вы вышли из чата." << endl;
                }
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
