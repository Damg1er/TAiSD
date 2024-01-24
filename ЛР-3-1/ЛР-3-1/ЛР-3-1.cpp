#include <iostream>
using namespace std;

// Структура узла списка
struct Node {
    int data;
    Node* next;
};

// Прототипы функций
void addNode(Node*& head, int data);
void removeEven(Node*& head);
void Print_List(Node* head);

int main() {
    setlocale(0, ""); // Установка локали (для корректного отображения сообщений на русском языке)
    Node* head = NULL; // Инициализация указателя на голову списка как NULL
    int n, num;

    // Ввод количества элементов в списке
    do {
        cout << "Введите количество элементов в списке: ";
        while (!(cin >> n) || n < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка ввода. Пожалуйста, введите положительное целое число.\n";
        }
        if (n == 0) {
            cout << "Количество элементов не может быть равно 0. Пожалуйста, введите положительное целое число.\n";
        }
    } while (n <= 0);
    // Ввод элементов списка
    cout << "Введите элементы списка: ";
    for (int i = 0; i < n; i++) {
        do {
            cout << "Введите элемент " << i + 1 << ": ";
            while (!(cin >> num)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            }
            if (cin.peek() != '\n') {
                cout << "Ошибка ввода. Пожалуйста, введите целое число.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (cin.peek() != '\n');
        addNode(head, num); // Добавление элемента в список
    }
    // Вывод исходного списка
    cout << "Исходный список: ";
    Print_List(head);
    // Удаление из списка элементов с четными информационными полями
    cout << "Удаление из списка элементов с четными информационными полями:\n";
    removeEven(head);
    // Освобождение памяти
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}
// Функция добавления узла в конец списка
void addNode(Node*& head, int data) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        cerr << "Ошибка выделения памяти\n";
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode; // Если список пуст, новый узел становится головой списка
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next; // Переход к концу списка
        }
        temp->next = newNode; // Добавление нового узла в конец списка
    }
}

// Функция удаления узлов с четными значениями
void removeEven(Node*& head) {
    Node* current = head;
    Node* previous = nullptr;
    Node* temp;
    while (current != nullptr) {
        if (current->data % 2 == 0) {
            temp = current;
            if (previous != nullptr) {
                previous->next = current->next; // Пропуск узла с четным значением
            }
            else {
                head = current->next; // Если удаляется первый узел, обновляем голову списка
            }
            current = current->next;
            delete temp; // Освобождение памяти удаленного узла
        }
        else {
            previous = current;
            current = current->next;
        }
    }
    Print_List(head); // Вывод списка после удаления
}
// Функция вывода списка
void Print_List(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
