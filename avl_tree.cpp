#pragma once

#include "avl_tree.h"
#include <iostream>

Node* insert(int val, Node* node){
    if (node == nullptr)
        return new Node(val);
    if (val < node->val)
        node->left = insert(val, node->left);
    else
        node->right = insert(val, node->right);

    return balance(node);
}

Node* Remove(Node* p, int k){
    if (p == nullptr)
        return 0;
    if (k < p->val){
        p->left = Remove(p->left, k);
    }
    else
        if (k > p->val){
            p->right = Remove(p->right, k);
        }
        else{
            Node* left = p->left;
            Node* right = p->right;
            delete p;
            if (right == nullptr)
                return left;
            Node* min = FindMin(right);
            min->right = RemoveMin(right);
            min->left = left;
            return balance(min);
        }
    return balance(p);
}

Node* RemoveMax(Node* p){
    if (p->right == nullptr)
        return p->left;
    p->right = RemoveMax(p->right);
    return balance(p);
}

Node* RemoveMin(Node* p){
    if (p->left == nullptr)
        return p->right;
    p->left = RemoveMin(p->left);
    return balance(p);
}

int Height(Node* p){
    return p ? p->height : 0;
}

int BFactor(Node* p){
    return Height(p->right) - Height(p->left);
}

void FixHeight(Node* p){
    int h_left = Height(p->left);
    int h_right = Height(p->right);
    p->height = (h_left > h_right ? h_left : h_right) + 1;
}


Node* RotateRight(Node* p){
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    FixHeight(p);
    FixHeight(q);
    return q;
}

Node* RotateLeft(Node* q){
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    FixHeight(q);
    FixHeight(p);
    return p;
}

Node* balance(Node* p){
    FixHeight(p);
    if (BFactor(p) == 2){
        if (BFactor(p->right) < 0)
            p->right = RotateRight(p->right);
        return RotateLeft(p);
    }
    if (BFactor(p) == -2){
        if (BFactor(p->left) > 0)
            p->left = RotateLeft(p->left);
        return RotateRight(p);
    }
    return p;
}

Node* FindMin(Node* p){
    return p->left ? FindMin(p->left) : p;
}
