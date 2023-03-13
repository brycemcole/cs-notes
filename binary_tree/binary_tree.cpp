#include <iostream>

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        Node* temp = root;
        while (temp != nullptr) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    return;
                }
                temp = temp->left;
            }
            else {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    return;
                }
                temp = temp->right;
            }
        }
    }

    void printInorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }

    void printPreorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        std::cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }

    void printPostorder(Node* node) {
        if (node == nullptr) {
            return;
        }
        printPostorder(node->left);
        printPostorder(node->right);
        std::cout << node->data << " ";
    }

    void printInorder() {
        printInorder(root);
        std::cout << std::endl;
    }

    void printPreorder() {
        printPreorder(root);
        std::cout << std::endl;
    }

    void printPostorder() {
        printPostorder(root);
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(85);
    return 0;
}