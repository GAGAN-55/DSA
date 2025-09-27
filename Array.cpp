#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX];
int n = 0;  // Current number of elements

// Display the array
void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Insert at beginning
void insertBeginning(int val) {
    if (n == MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = val;
    n++;
    cout << val << " inserted at the beginning.\n";
}

// Insert at end
void insertEnd(int val) {
    if (n == MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    arr[n] = val;
    n++;
    cout << val << " inserted at the end.\n";
}

// Insert at specific position (0-based index)
void insertMiddle(int pos, int val) {
    if (n == MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    if (pos < 0 || pos > n) {
        cout << "Invalid position! Must be between 0 and " << n << ".\n";
        return;
    }
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
    cout << val << " inserted at position " << pos << ".\n";
}

// Delete from beginning
void deleteBeginning() {
    if (n == 0) {
        cout << "Array is empty! Nothing to delete.\n";
        return;
    }
    int deleted = arr[0];
    for (int i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << deleted << " deleted from the beginning.\n";
}

// Delete from end
void deleteEnd() {
    if (n == 0) {
        cout << "Array is empty! Nothing to delete.\n";
        return;
    }
    int deleted = arr[n - 1];
    n--;
    cout << deleted << " deleted from the end.\n";
}

// Delete from specific position
void deletePosition(int pos) {
    if (n == 0) {
        cout << "Array is empty! Nothing to delete.\n";
        return;
    }
    if (pos < 0 || pos >= n) {
        cout << "Invalid position! Must be between 0 and " << n - 1 << ".\n";
        return;
    }
    int deleted = arr[pos];
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << deleted << " deleted from position " << pos << ".\n";
}

// Search for a value, return first position or -1 if not found
int search(int val) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

// Main menu function
void menu() {
    cout << "\n=== Array Operations Menu ===\n";
    cout << "1. Insert at Beginning\n";
    cout << "2. Insert at End\n";
    cout << "3. Insert at Position\n";
    cout << "4. Delete from Beginning\n";
    cout << "5. Delete from End\n";
    cout << "6. Delete from Position\n";
    cout << "7. Search for a Value\n";
    cout << "8. Display Array\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice, val, pos;
    
    cout << "Enter initial size of array (max " << MAX << "): ";
    cin >> n;
    if (n < 0 || n > MAX) {
        cout << "Invalid size! Exiting.\n";
        return 1;
    }
    
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                insertBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                insertEnd(val);
                break;
            case 3:
                cout << "Enter position (0 to " << n << ") to insert at: ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> val;
                insertMiddle(pos, val);
                break;
            case 4:
                deleteBeginning();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                cout << "Enter position (0 to " << n - 1 << ") to delete from: ";
                cin >> pos;
                deletePosition(pos);
                break;
            case 7:
                cout << "Enter value to search for: ";
                cin >> val;
                pos = search(val);
                if (pos == -1)
                    cout << val << " not found in the array.\n";
                else
                    cout << val << " found at position " << pos << ".\n";
                break;
            case 8:
                display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
