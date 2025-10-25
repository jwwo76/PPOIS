#include "Machine.h"
#include <iostream>
#include <fstream>
using namespace std;

void menu() {
    cout << "\n===== Меню машины Поста =====\n";
    cout << "1. Загрузить и выполнить программу из файла\n";
    cout << "2. Ручное управление лентой (тестирование операций)\n";
    cout << "0. Выход\n";
    cout << "Выбор: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    Machine machine;
    int choice;

    while (true) {
        menu();
        cin >> choice;
        if (choice == 0) break;

        if (choice == 1) {
            string filename;
            cout << "Введите путь к файлу программы: ";
            cin >> filename;
            ifstream fin(filename);
            if (!fin) {
                cout << "Ошибка: не удалось открыть файл.\n";
                continue;
            }
            machine.loadTape(fin);
            machine.loadProgram(fin);
            cout << "=== Выполнение программы ===\n";
            machine.run();
        }
        else if (choice == 2) {
            Tape tape;
            while (true) {
                cout << "\n--- Работа с лентой ---\n";
                tape.print();
                cout << "[L] Влево, [R] Вправо, [W] Записать 1, [E] Стереть (0), [Q] Выход: ";
                char cmd; cin >> cmd;
                if (cmd == 'L' || cmd == 'l') tape.moveLeft();
                else if (cmd == 'R' || cmd == 'r') tape.moveRight();
                else if (cmd == 'W' || cmd == 'w') tape.write(1);
                else if (cmd == 'E' || cmd == 'e') tape.write(0);
                else if (cmd == 'Q' || cmd == 'q') break;
            }
        }
    }

    cout << "Выход из программы.\n";
    return 0;
}
