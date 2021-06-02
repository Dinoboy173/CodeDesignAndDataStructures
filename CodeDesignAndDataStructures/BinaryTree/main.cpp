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
        std::cout << "null" << std::endl;
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

    PostOrderPrint(n->left);
    PostOrderPrint(n->right);

    std::cout << n->value << std::endl;
}

Node* Find(Node* root, int value)
{
    // TODO

    bool isFound = false;

    while (!isFound)
    {
        if (value == root->value)
            isFound = true;
        else if (value < root->value)
        {
            if (root->left != nullptr)
                root = root->left;
            else
                return nullptr;
        }
        else if (value > root->value)
        {
            if (root->right != nullptr)
                root = root->right;
            else
                return nullptr;
        }
    }

    return root;
}

void Insert(Node* root, Node* nodeToInsert)
{
    // TODO

    bool nodeIsInserted = false;

    while (!nodeIsInserted)
    {
        if (nodeToInsert->value == root->value)
            return;
        else if (nodeToInsert->value < root->value)
            if (root->left != nullptr)
                root = root->left;
            else
            {
                root->left = nodeToInsert;
                nodeIsInserted = true;
            }
        else if (nodeToInsert->value > root->value)
            if (root->right != nullptr)
                root = root->right;
            else
            {
                root->right = nodeToInsert;
                nodeIsInserted = true;
            }
    }
}

void DetatchParent(Node* childNode, Node* parentNode)
{
    if (childNode->value < parentNode->value)
    {
        parentNode->left = nullptr;
    }
    else if (childNode->value > parentNode->value)
    {
        parentNode->right = nullptr;
    }
}

Node* SplitTree(Node* root, int value)
{
    bool isFound = false;
    bool valueIsLeft;

    Node* parentNode = root;
    Node* secondTreeRoot = root;

    while (!isFound)
    {
        if (value == parentNode->value)
            isFound = true;
        else if (value < parentNode->value)
        {
            if (parentNode->left != nullptr)
            {
                if (parentNode->left->value == value)
                {
                    secondTreeRoot = parentNode->left;
                    valueIsLeft = true;
                    isFound = true;
                }
                else
                {
                    parentNode = parentNode->left;
                }
            }
            else
                return nullptr;
        }
        else if (value > parentNode->value)
        {
            if (parentNode->right != nullptr)
            {
                if (parentNode->right->value == value)
                {
                    secondTreeRoot = parentNode->right;
                    valueIsLeft = false;
                    isFound = true;
                }
                else
                {
                    parentNode = parentNode->right;
                }
            }
            else
                return nullptr;
        }
    }

    DetatchParent(secondTreeRoot, parentNode);

    return secondTreeRoot;
}

void AddDetatchedValuesBack(Node* root, Node* detatchedRoot)
{
    bool valuesAdded = false;

    if (detatchedRoot->value == root->value)
    {
        if (root->left != nullptr)
        {
            root = root->left;
            detatchedRoot->left = nullptr;
        }
        else if (root->right != nullptr)
        {
            root = root->right;
            detatchedRoot->right = nullptr;
        }
    }

    Node* tempRoot = detatchedRoot;
    Node* currentNode = detatchedRoot;

    while (!valuesAdded)
    {
        if (tempRoot == detatchedRoot)
        {
            if (detatchedRoot->left != nullptr)
                currentNode = detatchedRoot->left;
            else if (detatchedRoot->right != nullptr)
                currentNode = detatchedRoot->right;
            else
            {
                delete detatchedRoot;
                valuesAdded = true;
            }
        }

        if (currentNode->value < tempRoot->value)
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                Insert(root, currentNode);
                tempRoot->left = nullptr;
                tempRoot = detatchedRoot;
                currentNode = detatchedRoot;
            }
            else
            {
                tempRoot = currentNode;
                if (currentNode->left != nullptr)
                    currentNode = currentNode->left;
                else
                    currentNode = currentNode->right;
            }
        }
        else if (currentNode->value > tempRoot->value)
        {
            if (currentNode->right == nullptr && currentNode->left == nullptr)
            {
                Insert(root, currentNode);
                tempRoot->right = nullptr;
                tempRoot = detatchedRoot;
                currentNode = detatchedRoot;
            }
            else
            {
                tempRoot = currentNode;
                if (currentNode->right != nullptr)
                    currentNode = currentNode->right;
                else
                    currentNode = currentNode->left;
            }
        }
    }
}

void Remove(Node* root, int value) // redo entire function at home
{
    // TODO

    Node* nodeToRemove = SplitTree(root, value);

    std::cout << "Detactched Tree\n";
    PreOrderPrint(nodeToRemove);

    AddDetatchedValuesBack(root, nodeToRemove);

    std::cout << "Tree\n";
    PreOrderPrint(root);
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

    Insert(&root, new Node(3));
    Insert(&root, new Node(8));
    Insert(&root, new Node(10));

    std::cout << "PreOrderPrint\n";
    PreOrderPrint(&root);
    std::cout << std::endl;

    auto foundValue = Find(&root, 10);

    if (foundValue != nullptr)
        std::cout << "Found: " << foundValue->value << std::endl;
    else
        std::cout << "Value Not Found" << std::endl;

    Remove(&root, 6);

    //std::cout << "PreOrderPrint\n";
    //PreOrderPrint(&root);
    //std::cout << std::endl;

    return 0;
}