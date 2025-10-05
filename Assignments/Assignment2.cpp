#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <cctype>

using namespace std;

// Patient Record ADT
struct PatientRecord {
    int PatientID;
    string PatientName;
    string AdmissionDate;
    double TreatmentCost;  // Changed to store numerical treatment cost

    PatientRecord(int id, const string& name, const string& date, double cost)
        : PatientID(id), PatientName(name), AdmissionDate(date), TreatmentCost(cost) {}
};

// Linked List to manage Patient Records
class PatientLinkedList {
public:
    struct Node {
        PatientRecord data;
        Node* next;
        Node(PatientRecord patient) : data(patient), next(NULL) {}
    };

    Node* head;

    PatientLinkedList() : head(NULL) {}

    void insertPatient(PatientRecord patient) {
        Node* newNode = new Node(patient);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deletePatient(int PatientID) {
        if (!head) return;
        if (head->data.PatientID == PatientID) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data.PatientID != PatientID) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
        }
    }

    void retrievePatient(int PatientID) {
        Node* temp = head;
        while (temp) {
            if (temp->data.PatientID == PatientID) {
                cout << "Patient ID: " << temp->data.PatientID << "\n";
                cout << "Name: " << temp->data.PatientName << "\n";
                cout << "Admission Date: " << temp->data.AdmissionDate << "\n";
                cout << "Treatment Cost: $" << temp->data.TreatmentCost << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found.\n";
    }
};

// Custom Stack Class for Undo functionality
class CustomStack {
public:
    struct StackNode {
        PatientRecord data;
        StackNode* next;
        StackNode(PatientRecord patient) : data(patient), next(NULL) {}
    };

    StackNode* top;

    CustomStack() : top(NULL) {}

    void push(PatientRecord patient) {
        StackNode* newNode = new StackNode(patient);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) return;
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    PatientRecord peek() {
        if (top != NULL) {
            return top->data;
        } else {
            throw runtime_error("Stack is empty.");
        }
    }

    bool isEmpty() {
        return top == NULL;
    }
};

// Circular Queue for Emergency Queue (Storing only numeric values)
class CircularQueue {
private:
    int front, rear, size;
    int capacity;
    double* queue;  // Store only numeric values (treatment costs)

public:
    CircularQueue(int cap) : front(0), rear(0), size(0), capacity(cap) {
        queue = new double[capacity];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool enqueue(double cost) {
        if (size == capacity) {
            cout << "Queue is full.\n";
            return false;
        }
        queue[rear] = cost;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return false;
        }
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    void displayQueue() {
        if (size == 0) {
            cout << "Queue is empty.\n";
            return;
        }
        int tempFront = front;
        for (int i = 0; i < size; ++i) {
            cout << "Treatment Cost: $" << queue[tempFront] << "\n";
            tempFront = (tempFront + 1) % capacity;
        }
    }
};

// Priority Queue for Emergency Queue (Using Array)
class PriorityQueue {
private:
    struct PriorityQueueNode {
        int priority;
        double cost;  // Storing only the numeric treatment cost
        PriorityQueueNode(int p, double c) : priority(p), cost(c) {}
    };

    PriorityQueueNode** heap;
    int size;
    int capacity;

    void heapifyUp(int index) {
        while (index > 0 && heap[index]->priority < heap[(index - 1) / 2]->priority) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left]->priority < heap[smallest]->priority) {
            smallest = left;
        }
        if (right < size && heap[right]->priority < heap[smallest]->priority) {
            smallest = right;
        }
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    PriorityQueue(int cap) : size(0), capacity(cap) {
        heap = new PriorityQueueNode*[capacity];
    }

    ~PriorityQueue() {
        for (int i = 0; i < size; ++i) {
            delete heap[i];
        }
        delete[] heap;
    }

    void enqueue(double cost, int priority) {
        if (size == capacity) {
            cout << "Priority Queue is full.\n";
            return;
        }
        heap[size] = new PriorityQueueNode(priority, cost);
        heapifyUp(size);
        size++;
    }

    bool dequeue() {
        if (size == 0) {
            cout << "Priority Queue is empty.\n";
            return false;
        }
        swap(heap[0], heap[size - 1]);
        delete heap[size - 1];
        size--;
        heapifyDown(0);
        return true;
    }

    void displayQueue() {
        if (size == 0) {
            cout << "Priority Queue is empty.\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << "Treatment Cost: $" << heap[i]->cost << ", Priority: " << heap[i]->priority << "\n";
        }
    }
};

// Polynomial Operations for Billing Calculation
double calculateBilling(double treatmentDuration, double serviceCost) {
    return pow(treatmentDuration, 2) + (serviceCost * treatmentDuration);
}

// Postfix Expression Evaluation for Inventory Calculations
double evaluatePostfix(const string& expr) {
    CustomStack stack;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Convert string to double using stringstream instead of stod
            double value;
            stringstream(token) >> value;
            stack.push(PatientRecord(0, "", "", value));
        } else {
            double b = stack.peek().TreatmentCost;
            stack.pop();
            double a = stack.peek().TreatmentCost;
            stack.pop();
            double result = 0;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            stringstream resultStream;
            resultStream << result;
            stack.push(PatientRecord(0, "", "", result));
        }
    }
    return stack.peek().TreatmentCost;  // Return the final result stored in TreatmentCost
}

int main() {
    PatientLinkedList patientList;
    CustomStack undoStack;
    CircularQueue emergencyQueue(5);
    PriorityQueue priorityQueue(5);

    // Adding patients
    PatientRecord p1(101, "John Doe", "01/10/2025", 1000);  // treatment cost as a number
    patientList.insertPatient(p1);
    undoStack.push(p1);

    PatientRecord p2(102, "Jane Smith", "02/10/2025", 500);
    patientList.insertPatient(p2);
    undoStack.push(p2);

    // Display patient info
    patientList.retrievePatient(101);

    // Undo last admission
    undoStack.pop();

    // Emergency Queue (Circular)
    emergencyQueue.enqueue(p1.TreatmentCost);
    emergencyQueue.enqueue(p2.TreatmentCost);
    emergencyQueue.displayQueue();
    emergencyQueue.dequeue();

    // Priority Queue
    priorityQueue.enqueue(p1.TreatmentCost, 2);  // Priority 2
    priorityQueue.enqueue(p2.TreatmentCost, 1);  // Priority 1
    priorityQueue.displayQueue();
    priorityQueue.dequeue();

    // Billing Calculation
    double bill = calculateBilling(5, 200);  // Example: 5 days, $200 per day
    cout << "Total Billing: $" << bill << endl;

    // Postfix Expression Evaluation for Inventory
    string postfixExpr = "3 4 + 2 * 7 /"; // (3 + 4) * 2 / 7
    double inventoryCost = evaluatePostfix(postfixExpr);
    cout << "Inventory Cost: $" << inventoryCost << endl;

    return 0;
}
