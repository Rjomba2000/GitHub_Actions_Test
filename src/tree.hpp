#pragma once

template <typename T>
class MyBinaryTree {
private:
    struct node {
        T key;
        node* parent;
        node* left;
        node* right;
    };

    void deleteSubtree(node* node);

    node* root;

public:
    MyBinaryTree();
    ~MyBinaryTree();

    void insert(T key);
    bool find(T key);
};