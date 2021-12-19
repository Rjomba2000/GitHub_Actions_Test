#include "tree.hpp"

template <typename T>
void MyBinaryTree<T>::deleteSubtree(node* node) {
    if (node->left) {
        deleteSubtree(node->left);
    }
    if (node->right) {
        deleteSubtree(node->right);
    }
    delete node;
}

template <typename T>
MyBinaryTree<T>::MyBinaryTree() : root(nullptr) {}

template <typename T>
MyBinaryTree<T>::~MyBinaryTree() {
    deleteSubtree(root);
}

template <typename T>
void MyBinaryTree<T>::insert(T key) {
    node* newNode = new node(key, nullptr, nullptr, nullptr);
    if (!root) {
        root = newNode;
        }
    else {
        node* temp = root;
        while (temp) {
            newNode->parent = temp;
            if (key < temp->key) {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
        }
        if (key < temp->parent->key) {
            temp->parent->left = newNode;
        }
        else {
            temp->parent->right = newNode;
        }
    }
}

template <typename T>
bool MyBinaryTree<T>::find(T key) {
    node* temp = root;
    while (temp) {
        if (key < temp->key) {
            temp = temp->left;
        }
        else if (key > temp->key) {
            temp = temp->right;
        }
        else {
            return true;
        } 
    }
    return false;
}