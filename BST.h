#pragma once
#include "Record.h"
#include <iostream>
using namespace std;

struct Node {
    Record data;
    Node* left;
    Node* right;
    Node(const Record& r) : data(r), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* Insert(Node* node, const Record& r) {
        if (!node) return new Node(r);
        if (r.value < node->data.value)
            node->left = Insert(node->left, r);
        else
            node->right = Insert(node->right, r);
        return node;
    }

    void PrintAbove(Node* node, double threshold) {
        if (!node) return;
        PrintAbove(node->left, threshold);
        if (node->data.value >= threshold) {
            cout << node->data.id << " | " << node->data.country << " | " << node->data.value << endl;
        }
        PrintAbove(node->right, threshold);
    }

public:
    BST() : root(nullptr) {}

    void Insert(const Record& r) {
        root = Insert(root, r);
    }

    void PrintRecordsAbove(double threshold) {
        PrintAbove(root, threshold);
    }
};
