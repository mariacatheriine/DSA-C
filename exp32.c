#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char word[50];
    char meaning[100];
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
Node* createNode(char* word, char* meaning) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    strcpy(newNode->meaning, meaning);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, char* word, char* meaning) {
    if (root == NULL) {
        return createNode(word, meaning);
    }
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = insert(root->left, word, meaning);
    }
    else if (cmp > 0) {
        root->right = insert(root->right, word, meaning);
    }
    return root;
}
Node* search(Node* root, char* word) {
    if (root == NULL) {
        return NULL;
    }
    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        return root;
    }
    if (cmp < 0) {
        return search(root->left, word);
    }
    return search(root->right, word);
}
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, char* word) {
    if (root == NULL) {
        return root;
    }
    int cmp = strcmp(word, root->word);
    if (cmp < 0) {
        root->left = deleteNode(root->left, word);
    }
    else if (cmp > 0) {
        root->right = deleteNode(root->right, word);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        strcpy(root->word, temp->word);
        strcpy(root->meaning, temp->meaning);
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}
void updateMeaning(Node* root, char* word, char* newMeaning) {
    Node* temp = search(root, word);
    if (temp != NULL) {
        strcpy(temp->meaning, newMeaning);
        printf("Meaning updated successfully\n");
    }
    else {
        printf("Word not found\n");
    }
}
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorderTraversal(root->right);
    }
}
int main() {
    Node* root = NULL;
    int choice;
    char word[50];
    char meaning[100];
    while (1) {
        printf("\n1. Insert Word\n");
        printf("2. Delete Word\n");
        printf("3. Search Word\n");
        printf("4. Update Meaning\n");
        printf("5. Display Dictionary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter word: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';
                printf("Enter meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0';
                root = insert(root, word, meaning);
                break;
            case 2:
                printf("Enter word to delete: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';
                root = deleteNode(root, word);
                break;
            case 3:
                printf("Enter word to search: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';
                Node* result = search(root, word);
                if (result != NULL)
                    printf("Meaning: %s\n", result->meaning);
                else
                    printf("Word not found\n");
                break;
            case 4:
                printf("Enter word to update: ");
                fgets(word, sizeof(word), stdin);
                word[strcspn(word, "\n")] = '\0';
                printf("Enter new meaning: ");
                fgets(meaning, sizeof(meaning), stdin);
                meaning[strcspn(meaning, "\n")] = '\0';
                updateMeaning(root, word, meaning);
                break;
            case 5:
                printf("\nDictionary Contents:\n");
                inorderTraversal(root);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}