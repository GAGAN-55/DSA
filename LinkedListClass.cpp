#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Destructor
    ~LinkedList() {
        freeList();
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert at position (1-based)
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position must be >= 1\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // Delete from position
    void deleteFromPosition(int position) {
        if (position < 1) {
            cout << "Position must be >= 1\n";
            return;
        }

        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; temp != NULL && i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of range\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search for value
    void search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Value " << value << " found at position " << position << "\n";
                return;
            }
            temp = temp->next;
            position++;
        }

        cout << "Value " << value << " not found in the list\n";
    }

    // Free all nodes
    void freeList() {
        while (head != NULL) {
            deleteFromBeginning();
        }
    }
};

// ---------------- Main Function ----------------

int main() {
    LinkedList list;
    int choice, value, position;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display\n";
        cout << "8. Search\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
