#pragma once

class Node{
    public:
        int val;
        Node* left;
        Node* right;
        int height;

        Node(int val, Node* left = nullptr, Node* right = nullptr) : val(val), left(left), right(right), height(1)
        {}
};

Node* insert(int val, Node* node);

Node* Remove(Node* p, int k);

Node* RemoveMax(Node* p);

Node* RemoveMin(Node* p);

int Height(Node* p);

int BFactor(Node* p);

void FixHeight(Node* p);

Node* RotateRight(Node* p);

Node* RotateLeft(Node* q);

Node* balance(Node* p);

Node* FindMin(Node* p);
