#include <iostream>
#include <Windows.h>
using namespace std;

// Структура, що представляє вузол двунаправленого списку
struct Node {
    int data;     // Дані вузла
    Node* prev;   // Вказівник на попередній вузол
    Node* next;   // Вказівник на наступний вузол
};

// Функція для створення двунаправленого списку на основі масиву значень
Node* createListHelper(int values[], int size, int index) {
    if (index >= size) {
        return nullptr;
    }

    Node* newNode = new Node(); //1
    newNode->data = values[index]; //2
    newNode->prev = nullptr; // 3
    newNode->next = createListHelper(values, size, index + 1); // 4

    if (newNode->next != nullptr) {
        newNode->next->prev = newNode;
    }

    return newNode;
}

Node* createList(int values[], int size) {
    return createListHelper(values, size, 0);
}

// Функція для підрахунку кількості вузлів з непарними значеннями
int countOddElementsHelper(Node* current) {
    if (current == nullptr) {
        return 0;
    }

    int count = countOddElementsHelper(current->next);
    if (current->data % 2 != 0) {
        count++;
    }

    return count;
}

int countOddElements(Node* head) {
    return countOddElementsHelper(head);
}

// Функція для виведення значень усіх вузлів у списку
void printListHelper(Node* current) {
    if (current == nullptr) {
        cout << endl;
        return;
    }

    cout << current->data << " ";
    printListHelper(current->next);
}

void printList(Node* head) {
    printListHelper(head);
}

// Функція для видалення всього списку та звільнення пам'яті
void deleteList(Node* head) {
    if (head == nullptr) {
        return;
    }

    deleteList(head->next);
    delete head;
}

int main() {

    int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Масив значень для створення списку
    int size = sizeof(values) / sizeof(values[0]);  // Розмір масиву

    Node* head = createList(values, size);  // Створення двунаправленого списку

    cout << "Список елементів:" << endl;
    printList(head);  // Виведення елементів списку

    int oddCount = countOddElements(head);  // Підрахунок непарних елементів
    cout << "Кількість елементів з непарними значеннями: " << oddCount << endl;

    deleteList(head);  // Видалення списку та звільнення пам'яті

    return 0;
}
