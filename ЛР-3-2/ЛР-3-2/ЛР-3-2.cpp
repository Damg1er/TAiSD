#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
// Структура узла списка
struct Node {
    string data;
    Node* prev;
    Node* next;
};
// Класс двусвязного списка
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
public:
    // Конструктор класса
    DoublyLinkedList() : head(NULL), tail(NULL) {}
    // Метод для вставки элемента на заданную позицию
    void insertAtPosition(string value, int position);
    // Метод для добавления элемента на нечетные позиции
    void addElementsAtOddPositions(string value);
    // Метод для получения размера списка
    int size();
    // Метод для отображения содержимого списка
    void display();
};
// Метод вставки элемента на заданную позицию
void DoublyLinkedList::insertAtPosition(string value, int position) {
    if (position <= 0) {
        cout << "Неправильный номер\n";
        return;
    }
    // Создание нового узла
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        // Если список пуст, новый узел становится единственным узлом в списке
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    if (position == 1) {
        // Вставка в начало списка
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        // Вставка на указанную позицию
        Node* temp = head;
        int currentPosition = 1;
        // Поиск позиции вставки
        while (currentPosition < position - 1 && temp != NULL) {
            temp = temp->next;
            currentPosition++;
        }
        // Если позиция вставки выходит за пределы списка
        if (temp == NULL) {
            cout << "Неправильный номер\n";
            delete newNode;
            return;
        }
        // Вставка нового узла
        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        // Если вставляется в конец списка, обновляем хвост
        if (temp == tail) {
            tail = newNode;
        }
    }
}
// Метод добавления элементов на нечетные позиции
void DoublyLinkedList::addElementsAtOddPositions(string value) {
    // Создание нового узла
    Node* newNode = new Node();
    newNode->data = value;
    if (head == NULL) {
        // Если список пуст, новый узел становится единственным узлом в списке
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    // Поиск первой нечетной позиции
    Node* temp = head;
    int currentPosition = 1;
    while (temp != NULL) {
        if (currentPosition % 2 != 0) {
            newNode->prev = temp;
            newNode->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            // Если вставляется в конец списка, обновляем хвост
            if (temp == tail) {
                tail = newNode;
            }
            break;
        }
        temp = temp->next;
        currentPosition++;
    }
}
// Метод для получения размера списка
int DoublyLinkedList::size() {
    int count = 0;
    Node* temp = head;
    // Подсчет элементов в списке
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
// Метод для отображения содержимого списка
void DoublyLinkedList::display() {
    if (head == NULL) {
        cout << "Список пуст\n";
        return;
    }
    Node* temp = head;
    cout << "Ваш список: ";
    // Вывод элементов списка
    while (temp != NULL) {
        cout << "\"" << temp->data << "\" ";
        temp = temp->next;
    }

    cout << endl;
}
// Основная функция
int main() {
    // Установка кодовой страницы для поддержки русских символов в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    DoublyLinkedList List;  // Создание объекта класса DoublyLinkedList
    string value;
    int totalStrings, newStrings;
    // Ввод количества строк
    cout << "Введите количество строк: ";
    string totalStringsStr;
    getline(cin, totalStringsStr);
    while (!(istringstream(totalStringsStr) >> totalStrings) || totalStrings < 0) {
        cout << "Ошибка ввода. Пожалуйста, введите положительное целое число.\n";
        cout << "Введите количество строк: ";
        getline(cin, totalStringsStr);
    }
    // Ввод строк для добавления в начало списка
    for (int i = 1; i < totalStrings + 1; i++) {
        cout << "Введите строку для добавления: ";
        getline(cin, value);
        List.insertAtPosition(value, i);
    }
    List.display();  // Отображение содержимого списка
    // Ввод количества новых строк для добавления
    cout << "\nВведите количество новых строк для добавления: ";
    string newStringsStr;
    getline(cin, newStringsStr);
    while (!(istringstream(newStringsStr) >> newStrings) || newStrings < 0) {
        cout << "Ошибка ввода. Пожалуйста, введите положительное целое число.\n";
        cout << "\nВведите количество новых строк для добавления: ";
        getline(cin, newStringsStr);
    }

    // Ввод новых строк для добавления на нечетные позиции
    for (int i = 1; i <= newStrings; i++) {
        cout << "Введите новую строку для добавления: ";
        getline(cin, value);
        List.insertAtPosition(value, 2 * i - 1);  // Добавление новых строк на нечетные позиции
    }
    List.display();  // Отображение содержимого списка
    return 0;
}
