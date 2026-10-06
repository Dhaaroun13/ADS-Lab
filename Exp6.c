#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, height;
    struct Node *left, *right;
} Node;

int h(Node *n) { return n ? n->height : 0; }
int maxOf(int a, int b) { return (a > b) ? a : b; }

Node *newNode(int key)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T = x->right;
    x->right = y;
    y->left = T;
    y->height = 1 + maxOf(h(y->left), h(y->right));
    x->height = 1 + maxOf(h(x->left), h(x->right));
    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T = y->left;
    y->left = x;
    x->right = T;
    x->height = 1 + maxOf(h(x->left), h(x->right));
    y->height = 1 + maxOf(h(y->left), h(y->right));
    return y;
}

int getBalance(Node *n) { return n ? h(n->left) - h(n->right) : 0; }

Node *insert(Node *node, int key)
{
    int bal;

    if (!node)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);




    else
        return node;                         /* duplicates are ignored */

    node->height = 1 + maxOf(h(node->left), h(node->right));
    bal = getBalance(node);

    if (bal > 1 && key < node->left->key)       /* Left Left   */
        return rotateRight(node);
    if (bal < -1 && key > node->right->key)     /* Right Right */
        return rotateLeft(node);
    if (bal > 1 && key > node->left->key) {     /* Left Right */
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bal < -1 && key < node->right->key) {   /* Right Left */
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

void inorder(Node *root)
{
    if (root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void freeTree(Node *root)
{
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main()
{
    Node *root = NULL;
    int n, x, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    printf("Inorder Traversal (sorted keys): ");
    inorder(root);
    printf("\nPreorder Traversal (shows the balanced shape): ");
    preorder(root);
    printf("\nHeight of tree: %d\n", h(root));
    freeTree(root);
    return 0;
}
