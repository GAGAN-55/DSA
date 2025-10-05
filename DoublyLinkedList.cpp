#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty list
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete from the beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    // Delete from the end
    void deleteFromEnd() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    // Display the list from head to tail
    void displayFromHead() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = head;
        cout << "List (Head to Tail): ";
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Display the list from tail to head
    void displayFromTail() {
        if (!tail) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* current = tail;
        cout << "List (Tail to Head): ";
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    // Destructor to clean up memory
    ~DoublyLinkedList() {
        while (head) {
            deleteFromBeginning();
        }
    }
};

int main() {
    DoublyLinkedList list;

    // Inserting elements
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    // Display the list
    list.displayFromHead();  // Output: 20 10 30 40
    list.displayFromTail();  // Output: 40 30 10 20

    // Deleting elements
    list.deleteFromBeginning();  // Removes 20
    list.deleteFromEnd();        // Removes 40

    // Display after deletion
    list.displayFromHead();  // Output: 10 30
    list.displayFromTail();  // Output: 30 10

    return 0;
}
