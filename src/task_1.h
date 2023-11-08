 /*
 * Author: Muhammad Xayrullayev
 * Date: 4/11/2023
 * Name: Muhammad Xayrullayev
 */
 #include <iostream>

using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;

    Node() : key(0), data(0), next(nullptr) {}

    Node(int k, int d) : key(k), data(d), next(nullptr) {}
};

class Stack {
public:
    Node* top;

    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            Node* temp = pop();
            delete temp;
        }
    }

    bool ifNodeExists(Node* n) {
        Node* temp = top;
        bool exist = false;
        while (temp != nullptr) {
            if (temp->key == n->key) {
                exist = true;
                break;
            }
            temp = temp->next;
        }
        return exist;
    }

    void push(Node* n) {
        if (top == nullptr) {
            top = n;
        } else if (ifNodeExists(n)) {
            cout << "Node already exists, enter a different Key value" << endl;
        } else {
            Node* temp = top;
            top = n;
            n->next = temp;
            cout << "Pushed successfully" << endl;
        }
    }

    Node* pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return nullptr;
        } else {
            Node* temp = top;
            top = top->next;
            return temp;
        }
    }

    Node* topElement() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return nullptr;
        } else {
            return top;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int task_1() {
    Stack s1;
    int option, key, data;

    do {
        cout << "What operation would you like to perform? Enter 0 to exit." << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. Top()" << endl;
        cout << "4. IsEmpty" << endl;
        cin >> option;

        Node* newNode = nullptr;

        switch (option) {
        case 1:
            cout << "Enter key and data for the new node: ";
            cin >> key >> data;
            newNode = new Node(key, data);
            s1.push(newNode);
            break;

        case 2:
            newNode = s1.pop();
            if (newNode != nullptr) {
                cout << "Popped Node: key = " << newNode->key << ", data = " << newNode->data << endl;
                delete newNode;
            }
            break;

        case 3:
            newNode = s1.topElement();
            if (newNode != nullptr) {
                cout << "Top Node: key = " << newNode->key << ", data = " << newNode->data << endl;
            }
            break;

        case 4:
            if (s1.isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack is not empty." << endl;
            }
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}
