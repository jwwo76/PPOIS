#include "Rectangle.h"
using namespace std;

void printMenu() {
    cout << "\n===== МЕНЮ =====" << endl;
    cout << "1. Ввод прямоугольников" << endl;
    cout << "2. Вывод прямоугольников" << endl;
    cout << "3. Сдвиг прямоугольника" << endl;
    cout << "4. Инкремент/декремент (++/--)" << endl;
    cout << "5. Сложение (r1 + r2)" << endl;
    cout << "6. Вычитание (r1 - r2)" << endl;
    cout << "7. Сравнение (==, !=)" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите номер пункта: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    rectangle r1, r2;
    bool initialized = false;

    int choice;
    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            int x1, y1, x2, y2;
            cout << "Введите координаты r1 (x1 y1 x2 y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            r1 = rectangle(x1, y1, x2, y2);

            cout << "Введите координаты r2 (x1 y1 x2 y2): ";
            cin >> x1 >> y1 >> x2 >> y2;
            r2 = rectangle(x1, y1, x2, y2);

            initialized = true;
            break;
        }
        case 2:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            cout << "r1 = " << r1 << endl;
            cout << "r2 = " << r2 << endl;
            break;

        case 3:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            {
                int dx, dy;
                cout << "Введите смещение dx, dy для r1: ";
                cin >> dx >> dy;
                r1.move_rectangle(dx, dy);
                cout << "r1 после сдвига: " << r1 << endl;
            }
            break;

        case 4:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            {
                int op;
                cout << "1 - r1++, 2 - ++r1, 3 - r1--, 4 - --r1: ";
                cin >> op;
                if (op == 1) r1++;
                else if (op == 2) ++r1;
                else if (op == 3) r1--;
                else if (op == 4) --r1;
                cout << "r1 сейчас: " << r1 << endl;
            }
            break;

        case 5:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            cout << "Результат r1 + r2 = " << (r1 + r2) << endl;
            break;

        case 6:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            cout << "Результат r1 - r2 = " << (r1 - r2) << endl;
            break;

        case 7:
            if (!initialized) { cout << "Сначала введите прямоугольники!" << endl; break; }
            cout << "r1 == r2? " << (r1 == r2 ? "Да" : "Нет") << endl;
            cout << "r1 != r2? " << (r1 != r2 ? "Да" : "Нет") << endl;
            break;

        case 0:
            cout << "Выход из программы..." << endl;
            break;

        default:
            cout << "Некорректный ввод!" << endl;
        }

    } while (choice != 0);

    return 0;
}
