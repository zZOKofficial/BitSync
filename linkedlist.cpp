#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        data = 0;
        next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
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
    }

    void insertAfter(int data, int positionValue) {
        Node* temp = head;
        while (temp != nullptr && temp->data != positionValue)
            temp = temp->next;
        if (temp == nullptr) {
            cout << "Node with value " << positionValue << " not found." << endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteFrom(int positionValue) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == positionValue) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != positionValue)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node with value " << positionValue << " not found." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ---> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);

    cout << "Initial List:\n";
    list.printList();

    list.insertAtEnd(5);
    list.insertAfter(15, 10); // insert 15 after 10
    cout << "\nAfter insertions:\n";
    list.printList();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    //list.deleteFrom(10);
    //cout << "\nAfter deletions:\n";
    list.printList();

    return 0;
}