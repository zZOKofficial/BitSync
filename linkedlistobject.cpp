
#include <iostream>
using namespace std;

// Person class
class Person {
public:
    string name;
    int age;

    Person() {
        name = "";
        age = 0;
    }

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void print() const {
        cout << "[" << name << ", " << age << "]";
    }

    bool equals(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Node class storing Person object
class Node {
public:
    Person data;
    Node* next;

    Node() {
        next = nullptr;
    }

    Node(Person data) {
        this->data = data;
        this->next = nullptr;
    }


};

// Singly Linked List class for Person objects
class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(Person data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(Person data) {
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

    void insertAfter(Person data, Person afterPerson) {
        Node* temp = head;
        while (temp != nullptr && !temp->data.equals(afterPerson))
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Person not found.\n";
            return;
        }

        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
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

    void deleteFrom(Person personToDelete) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data.equals(personToDelete)) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && !temp->next->data.equals(personToDelete))
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Person not found.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data.print();
            cout << " ---> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function to demonstrate object-based linked list
int main() {
    LinkedList list;

    Person p1("Alice", 25);
    Person p2("Bob", 30);
    Person p3("Charlie", 35);
    Person p4("Diana", 40);
    Person p5("Eve", 28);
    Person p6("Frank", 45);

    list.insertAtBeginning(p1);
    list.insertAtBeginning(p2);
    list.insertAtBeginning(p3);

    cout << "Initial List:\n";
    list.printList();

    list.insertAtEnd(p4);
    list.insertAfter(p5, p1); // Insert Eve after Alice

    cout << "\nAfter Insertions:\n";
    list.printList();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFrom(p1); // Delete Alice

    cout << "\nAfter Deletions:\n";
    list.printList();

    return 0;
}
