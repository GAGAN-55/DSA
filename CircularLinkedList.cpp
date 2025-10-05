#include <iostream>
using namespace std;

// Node class representing each element in the Circular Linked List
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(NULL) {}
};

// CircularLinkedList class to manage the list
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() : head(NULL) {}

    // Check if the list is empty
    bool isEmpty() {
        return head == NULL;
    }

    // Add a node at the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;  // Point the next of the new node to head to make it circular
        } else {
            Node* temp = head;
            while (temp->next != head) { // Traverse until we reach the node pointing to the head
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;  // Make the new node point to head
        }
    }

    // Display all the elements in the list
    void display() {
        if (isEmpty()) {
            cout << "The list is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Delete a node with a given value
    void deleteNode(int value) {
        if (isEmpty()) {
            cout << "The list is empty!" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        // If the node to be deleted is the head node
        if (head->data == value) {
            if (head->next == head) {  // Only one node in the list
                delete head;
                head = NULL;
            } else {
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;  // Update the last node to point to the new head
                delete head;
                head = head->next;
            }
            return;
        }

        // Search for the node to be deleted
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        // If the value was not found
        if (temp == head) {
            cout << "Value not found in the list!" << endl;
            return;
        }

        // Remove the node
        prev->next = temp->next;
        delete temp;
    }

    // Destructor to clean up the dynamically allocated memory
    ~CircularLinkedList() {
        if (head != NULL) {
            Node* temp = head;
            do {
                Node* nextNode = temp->next;
                delete temp;
                temp = nextNode;
            } while (temp != head);
        }
    }
};

int main() {
    CircularLinkedList list;

    // Append values to the list
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    // Display the list
    cout << "Circular Linked List: ";
    list.display();

    // Delete a node with value 20
    cout << "Deleting node with value 20..." << endl;
    list.deleteNode(20);

    // Display the updated list
    cout << "Updated Circular Linked List: ";
    list.display();

    // Delete the head node (value 10)
    cout << "Deleting node with value 10..." << endl;
    list.deleteNode(10);

    // Display the updated list
    cout << "Updated Circular Linked List: ";
    list.display();

    return 0;
}
