#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* right;
    struct Node* left;
};

// Function to create a new node in the binary search tree
struct Node* create_node(int item) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = item;
    return new_node;
}

// Function to insert a value into the binary search tree
struct Node* insert_node(struct Node* root, int item) {
    if (root == NULL)
        return create_node(item);
    if (item < root->data)
        root->left = insert_node(root->left, item);
    else if (item > root->data)
        root->right = insert_node(root->right, item);

    return root;
}

// In-order traversal to print the sorted elements
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int input_size = 1000;
    int data_maxval = 10000;

    // Generate an input data randomly
    int *input = (int *)malloc(sizeof(int) * input_size);
    for (int i = 0; i < input_size; i++)
        input[i] = rand() % data_maxval;

    // Build the binary search tree
    struct Node* root = NULL;
    for (int i = 0; i < input_size; i++)
        root = insert_node(root, input[i]);

    // Print the sorted result using in-order traversal
    printf("Result: ");
    inorderTraversal(root);

    return 0;
}
