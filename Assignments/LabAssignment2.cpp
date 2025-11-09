#include <iostream>
#include <string>
using namespace std;

// ========================= Menu Management (Singly Linked List) =========================

class MenuItem {
public:
    string name;
    int price;
    MenuItem* next;

    MenuItem(string name, int price) : name(name), price(price), next(NULL) {}
};

class MenuLinkedList {
private:
    MenuItem* head;

public:
    MenuLinkedList() : head(NULL) {}

    void insertItem(string name, int price) {
        MenuItem* newItem = new MenuItem(name, price);
        if (!head) {
            head = newItem;
        } else {
            MenuItem* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
    }

    void deleteItem(string name) {
        if (!head) return;
        if (head->name == name) {
            MenuItem* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        MenuItem* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next) {
            MenuItem* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void displayMenu() {
        MenuItem* temp = head;
        if (!temp) {
            cout << "Menu is empty!" << endl;
            return;
        }
        while (temp) {
            cout << temp->name << " - ₹" << temp->price << endl;
            temp = temp->next;
        }
    }
};

// ========================= Order Queue (Circular Queue) =========================

class CircularQueue {
private:
    string* queue;
    int front, rear, size;

public:
    CircularQueue(int size) {
        this->size = size;
        queue = new string[size];
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(string order) {
        if (isFull()) {
            cout << "Error: Queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = order;
        cout << "Order placed: " << order << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Error: Queue is empty!" << endl;
            return;
        }
        cout << "Processing order: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Order queue: ";
        int i = front;
        while (i != rear) {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        }
        cout << queue[rear] << endl;
    }
};

// ========================= Customer Order History (Stack) =========================

class OrderHistoryNode {
public:
    string order;
    OrderHistoryNode* next;

    OrderHistoryNode(string order) : order(order), next(NULL) {}
};

class OrderHistoryStack {
private:
    OrderHistoryNode* top;

public:
    OrderHistoryStack() : top(NULL) {}

    void push(string order) {
        OrderHistoryNode* newNode = new OrderHistoryNode(order);
        newNode->next = top;
        top = newNode;
        cout << "Order added to history: " << order << endl;
    }

    void pop() {
        if (top == NULL) {
            cout << "Error: Stack is empty!" << endl;
            return;
        }
        cout << "Removed order from history: " << top->order << endl;
        OrderHistoryNode* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Latest order: " << top->order << endl;
    }
};

// ========================= Combo Deals (Polynomials with Linked List) =========================

class ComboNode {
public:
    int coeff;
    int exp;
    ComboNode* next;

    ComboNode(int coeff, int exp) : coeff(coeff), exp(exp), next(NULL) {}
};

class ComboDeals {
public:
    ComboNode* head;

    ComboDeals() : head(NULL) {}

    void addPolynomial(int coeff, int exp) {
        ComboNode* newNode = new ComboNode(coeff, exp);
        if (!head || head->exp < exp) {
            newNode->next = head;
            head = newNode;
        } else {
            ComboNode* temp = head;
            while (temp->next && temp->next->exp >= exp) {
                if (temp->next->exp == exp) {
                    temp->next->coeff += coeff;
                    return;
                }
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void displayPolynomial() {
        if (!head) {
            cout << "No combo deals available!" << endl;
            return;
        }
        ComboNode* temp = head;
        while (temp) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ========================= Main Program =========================

int main() {
    // 1. Menu Management
    MenuLinkedList menu;
    menu.insertItem("Pizza", 250);
    menu.insertItem("Burger", 150);
    menu.insertItem("Pasta", 200);

    cout << "Current Menu: " << endl;
    menu.displayMenu();

    menu.deleteItem("Burger");
    cout << "\nMenu after deleting Burger: " << endl;
    menu.displayMenu();

    // 2. Order Queue
    CircularQueue queue(3);
    queue.enqueue("Order 1: John");
    queue.enqueue("Order 2: Sarah");
    queue.displayQueue();

    queue.dequeue();
    queue.displayQueue();

    // 3. Customer Order History
    OrderHistoryStack stack;
    stack.push("Pizza, Coke");
    stack.push("Burger, Fries");
    stack.peek();
    stack.pop();
    stack.peek();

    // 4. Combo Deals
    ComboDeals combo;
    combo.addPolynomial(2, 2);  // 2x^2 (Burger)
    combo.addPolynomial(1, 1);  // 1x (Coke)
    combo.addPolynomial(3, 0);  // 3 (Fries)

    cout << "Combo Deals: ";
    combo.displayPolynomial();

    return 0;
}
