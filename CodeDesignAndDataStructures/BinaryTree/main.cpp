#include <iostream>

struct Node
{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;

    // Constructor
    Node() {};

    // Overloaded Constructor
    Node(int value) : value(value) {}

    // Overloaded Constructor
    Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};

void PreOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
    {
        return;
    }

    std::cout << n->value << std::endl;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);
}

void PostOrderPrint(Node* n)
{
    // TODO
    if (n == nullptr)
        return;

    PreOrderPrint(n->left);
    PreOrderPrint(n->right);

    std::cout << n->value << std::endl;
}

Node* Find(Node* n, int value)
{
    // TODO
}

void Insert(Node* root, Node* nodeToInsert)
{
    // TODO 
}

void Remove(Node* root, Node* nodeToRemove)
{
    // TODO
}

int Height(Node* n)
{
    // TODO
    return 0;
}

int Depth(Node* root, Node* n)
{
    // TODO
    return 0;
}

int main(int argc, char** argv)
{
    Node root = Node(6,
        new Node(4,
            new Node(2, nullptr, nullptr),
            new Node(5, nullptr, nullptr)),
        new Node(8,
            new Node(7, nullptr, nullptr),
            new Node(9, nullptr, nullptr)));

    // TODO:
    // Test the above methods

    std::cout << "PreOrderPrint\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    std::cout << "PostOrderPrint\n";
    PostOrderPrint(&root);
    std::cout << std::endl;

    int findValue;
    std::cin >> findValue;
    std::cout << "Find\n" << Find(&root, findValue)->value << "\n\n";

    return 0;
}