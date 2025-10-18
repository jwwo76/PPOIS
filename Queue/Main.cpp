#include "Queue.h"

int main() {
    setlocale(LC_ALL, "ru");
    Queue q;
    int choice, value;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Добавить элемент (enqueue)\n";
        cout << "2. Удалить элемент (dequeue)\n";
        cout << "3. Показать очередь\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите число: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 0:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}