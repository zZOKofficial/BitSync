#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head != nullptr) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int data, int afterValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != afterValue)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node with value " << afterValue << " not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteFrom(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->data != value)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Node with value " << value << " not found.\n";
            return;
        }

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
    }

      void printList() {
        Node* temp = head;
        cout << "Forward List: ";
        Node* last = nullptr;  // Track last node for reverse traversal
        while (temp != nullptr) {
            cout << temp->data << " <--> ";
            last = temp;
            temp = temp->next;
        }
        cout << "NULL\n";

        // Now print in reverse
        cout << "Backward List: ";
        while (last != nullptr) {
            cout << last->data << " <--> ";
            last = last->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "Initial List:\n";
    list.printList();

    list.insertAtEnd(5);
    list.insertAfter(15, 10); // insert 15 after node with data 10
    cout << "\nAfter insertions:\n";
    list.printList();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFrom(10);
    cout << "\nAfter deletions:\n";
    list.printList();

    return 0;
}