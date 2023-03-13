#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
    Node *head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void add(int data) {
        Node *new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        size++;
    }

    void remove(int data) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            return;
        }
        if (prev == nullptr) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        delete temp;
        size--;
    }

    void print() {
        if (head == nullptr) {
            std::cout << "empty linked list";
        } else {
            Node *temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
        std::cout << "\n";
        }
    }

    int getSize() {
        return size;
    }
};


int main() {
    LinkedList nums;
    while (true) {
        int x;
        std::cout << "enter a number: ";
        std::cin >> x;
        if (x == 0) {
            break;
        }
        nums.add(x);
    }
    nums.remove(3);
    nums.print();    
}