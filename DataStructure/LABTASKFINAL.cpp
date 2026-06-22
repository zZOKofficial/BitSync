#include <iostream>
using namespace std;

class Order {
public:
    int id;
    string type;
    int price;
    Order* next;

    Order(int _id, string _type, int _price) {
        id = _id;
        type = _type;
        price = _price;
        next = nullptr;
    }
};

class OrderList {
private:
    Order* head;

public:
    OrderList() {
        head = nullptr;
    }

    // Insert order based on type and price
    void insertOrder(int id, string type, int price) {
        Order* newOrder = new Order(id, type, price);

        if (!head || shouldInsertBefore(newOrder, head)) {
            newOrder->next = head;
            head = newOrder;
            return;
        }

        Order* temp = head;
        while (temp->next && !shouldInsertBefore(newOrder, temp->next))
            temp = temp->next;

        newOrder->next = temp->next;
        temp->next = newOrder;
    }

    // Helper to decide insertion priority
    bool shouldInsertBefore(Order* a, Order* b) {
        if (a->type == b->type) {
            if (a->type == "buy")
                return a->price > b->price;
            else
                return a->price < b->price;
        }
        return false; // never insert before different type (assume grouped types)
    }

    // Search by ID
    Order* search(int id) {
        Order* temp = head;
        while (temp) {
            if (temp->id == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Remove order by ID
    void removeOrder(int id) {
        if (!head) return;
        if (head->id == id) {
            Order* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Order* temp = head;
        while (temp->next && temp->next->id != id)
            temp = temp->next;

        if (temp->next) {
            Order* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }

    // Reverse the order list
    void reverse() {
        Order* prev = nullptr;
        Order* current = head;
        while (current) {
            Order* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Display all orders
    void display() {
        Order* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Type: " << temp->type << ", Price: " << temp->price << endl;
            temp = temp->next;
        }
    }
};

// Main function to test
int main() {
    OrderList orders;
    orders.insertOrder(1, "buy", 100);
    orders.insertOrder(2, "buy", 110);
    orders.insertOrder(3, "sell", 90);
    orders.insertOrder(4, "sell", 85);
    orders.insertOrder(5, "sell", 95);

    cout << "All Orders:\n";
    orders.display();

    cout << "\nSearching for order ID 3...\n";
    Order* found = orders.search(3);
    if (found)
        cout << "Found: ID " << found->id << ", Price: " << found->price << endl;

    cout << "\nRemoving order ID 4...\n";
    orders.removeOrder(4);
    orders.display();

    cout << "\nReversing order list...\n";
    orders.reverse();
    orders.display();

    return 0;
}