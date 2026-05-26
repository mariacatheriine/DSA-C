#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void inorderRecursive(Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}
void preorderRecursive(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}
void postorderRecursive(Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}
void inorderIterative(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}
void preorderIterative(Node* root) {
    if (root == NULL)
        return;
    Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        Node* current = stack[top--];
        printf("%d ", current->data);
        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}
void postorderIterative(Node* root) {
    if (root == NULL)
        return;
    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        Node* current = stack1[top1--];
        stack2[++top2] = current;
        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }
    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("Recursive Inorder: ");
    inorderRecursive(root);
    printf("\n");
    printf("Recursive Preorder: ");
    preorderRecursive(root);
    printf("\n");
    printf("Recursive Postorder: ");
    postorderRecursive(root);
    printf("\n");
    printf("Iterative Inorder: ");
    inorderIterative(root);
    printf("\n");
    printf("Iterative Preorder: ");
    preorderIterative(root);
    printf("\n");
    printf("Iterative Postorder: ");
    postorderIterative(root);
    printf("\n");
    return 0;
}