// Binary Tree using Linked List
/*
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

void main(){
    TreeNode *n1, *n2, *n3;

    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));

    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    n2->data = 20;
    n2->right = NULL;
    n2->left = NULL

    n3->data = 30;
    n3->right = NULL;
    n3->left = NULL;
}

//Preorder Traversal : V-L-R
preorder(x){
    if(x!=NULL){
        print DATA;
        preorder(left);
        preorder(right);
    }

}

//Postorder Traversal
postorder(x){
    if(x!=NULL){
        postorder(left);
        postorder(right);
        print(data);

    }
}
*/

//total
/*
#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;


TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

void preorder(TreeNode *root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main(){
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
}*/

#include <stdio.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

typedef TreeNode *element;
typedef struct QueueNode{
    element item;
    struct QueueNode *link;
}QueueNode;

typedef struct QueueType{
    QueueNode *front;
    QueueNode *rear;
}QueueType;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;


void level_order(TreeNode *ptr){
    QueueType q;
    init(&q);
    if(ptr == NULL)  return ; //그냥 함수 끝내는 것

    enqueue(&q, ptr);
    while(!is_empty(&q)){
        ptr
    }





}