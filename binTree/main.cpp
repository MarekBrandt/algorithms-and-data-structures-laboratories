#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>

class Node
{
public:
    Node *left, *right, *parent;
    int key;
    Node(int key) : left(NULL), right(NULL), key(key)
    {
        this->parent = NULL;
    }
};

void insert(Node *N, int key)
{
    if (N->key == key)
        return;
    if (N->key < key)
        if (N->right)
            insert(N->right, key);
        else
        {
            N->right = new Node(key);
            N->right->parent = N;
        }
    else
    if (N->left)
        insert(N->left, key);
    else
    {
        N->left = new Node(key);
        N->left->parent = N;
    }
}

Node* search(Node* N, int key)
{
    if (N == NULL)
        return NULL;
    if (N->key == key)
        return N;
    if (N->key < key)
        return search(N->right, key);
    return search(N->left, key);
}

int height(Node* N)
{
    int lHeight, rHeight;

    if(N != NULL)
    {
        lHeight = height(N->left);
        rHeight = height(N->right);

        if (lHeight > rHeight)
            return lHeight+1;
        return rHeight+1;
    }
    return 0;
}

void wierzcholki(Node* N)
{
    if (N != NULL)
    {
        wierzcholki(N->left);

        std::cout << N->key << " ";

        wierzcholki(N->right);
    }
}

void doKorzenia(Node* N)
{
    if (N != NULL) {

        std::cout << N->key << " ";

        doKorzenia(N->parent);
    }
}

void ileDoKorzenia(Node* N, int &pieter)
{
    if (N != NULL)
    {
        pieter++;

        ileDoKorzenia(N->parent, pieter);
    }
}

void preOrder(Node* N)
{
    if (N != NULL)
    {
        std::cout << N->key << " ";

        preOrder(N->left);
        preOrder(N->right);
    }
}

void sumaLisci(Node* N, int &suma)
{
    if (N != NULL)
    {
        sumaLisci(N->left, suma);
        sumaLisci(N->right, suma);
        if(N->left == NULL && N->right == NULL)
            suma += N->key;
    }
}

void maxKey(Node* N)
{
    if (N != NULL)
    {
        maxKey(N->right);
        if(N->right == NULL)
            std::cout << N->key;
    }
}

void minKey(Node* N)
{
    if (N != NULL)
    {
        minKey(N->left);
        if(N->left == NULL)
            std::cout << N->key;
    }
}

void next(Node* N)
{
    if(N->right != NULL)
        return minKey(N->right);
    Node* out = N->parent;
    while (out != NULL && N == out->right) {
        N = out;
        out = out->parent;
    }
    if(out != NULL)
    {
        std::cout << out->key;
        return;
    }
    std::cout << "-";
}

void liscie(Node* N)
{
    if (N != NULL)
    {
        liscie(N->left);
        liscie(N->right);
        if(N->right == NULL && N->left == NULL)
        {
            std::cout << N->key << " ";
        }
    }
}

void rozmiar(Node* N, int &rozmiar_r)
{
    if (N != NULL)
    {
        rozmiar(N->left, rozmiar_r);
        rozmiar(N->right, rozmiar_r);
        rozmiar_r++;
    }
}

int main()
{
    char cmd;
    int key;
    int heightOfTree;
    Node *root = NULL, *out;

    while (scanf("%c %d", &cmd, &key) > 0)
    {
        if (cmd == 'I')
            if (root != NULL)
                insert(root, key);
            else
                root = new Node(key);
        else if (cmd == 'S')
            out = search(root, key);
        else if (cmd == 'H')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                heightOfTree = height(out) - 1;
                printf("%d\n",heightOfTree);
            }
        }
        else if (cmd == 'O')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                wierzcholki(out);
                printf("\n");
            }
        }
        else if (cmd == 'P')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                doKorzenia(out);
                printf("\n");
            }
        }
        else if (cmd == 'D')
        {
            int pieter = 0;
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                ileDoKorzenia(out, pieter);
                printf("%d\n", pieter);
            }
        }
        else if (cmd == 'E')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                preOrder(out);
                printf("\n");
            }
        }
        else if (cmd == 'V')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                int suma = 0;
                sumaLisci(out, suma);
                printf("%d\n", suma);
            }
        }
        else if (cmd == 'X')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                maxKey(out);
                printf("\n");
            }
        }
        else if (cmd == 'N')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                next(out);
                printf("\n");
            }
        }
        else if (cmd == 'L')
        {
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                liscie(out);
                printf("\n");
            }
        }
        else if (cmd == 'R')
        {
            int rozmiar_r = 0;
            out = search(root, key);
            if (out == NULL)
            {
                printf("-\n");
            }
            else
            {
                rozmiar(out, rozmiar_r);
                printf("%d\n", rozmiar_r);
            }
        }
    }
    return 0;
}