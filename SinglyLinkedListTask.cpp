#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert after a specific node value
    void insertAfter(int afterValue, int value) {
        Node* temp = head;
        while (temp && temp->data != afterValue)
            temp = temp->next;
        if (temp) {
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Search for a value
    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    // Delete at beginning
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void deleteEnd() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete specific value (middle)
    void deleteValue(int value) {
        if (!head) return;
        if (head->data == value) {
            deleteBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;
        if (temp->next) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function to test
int main() {
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.display();

    list.insertBeginning(5);
    list.insertAfter(10, 15);
    list.display();

    cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    list.deleteBeginning();
    list.deleteEnd();
    list.deleteValue(15);
    list.display();

    return 0;
}