// 자식 노드 없으면 Terminal node : operand
// 자식 노드 있으면 Non-Terminal node : operator
#include <stdio.h>
#include <stdlib.h>
// Formula Tree
    //using postorder traversal : left-right-root
typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL }; 
TreeNode n2 = { 4, NULL, NULL }; 
TreeNode n3 = { '*', &n1, &n2 }; 
TreeNode n4 = { 16, NULL, NULL }; 
TreeNode n5 = { 25, NULL, NULL }; 
TreeNode n6 = { '+', &n4, &n5 }; 
TreeNode n7 = { '+', &n3, &n6 };

TreeNode *exp = &n7;

int evaluate(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    if(root->left ==NULL && root->right == NULL){
        return root->data;
    }else{
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        switch(root->data){
            case '+' : return op1+op2;
            case '-' : return op1-op2;
            case '*' : return op1*op2;
            case '/' : return op1/op2;
        }
    }
}

int main(){
    printf("%d", evaluate(exp));
}

// Binary tree operation : Number of Nodes
int get_node_count(TreeNode *node){
    int count = 0;
    if(node != NULL){
        count = 1+ get_node_count(node->left) + get_node_count(node->right);
        }
        return count;
}

int get_leaf_count(TreeNode *node) {
    int count = 0; 
    if(node != NULL) {
        if( node->left==NULL && node->right==NULL ) 
        return 1;
    }else{
        count  = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;
}

int get_height(TreeNode *node) {
    int height = 0;
    if (node != NULL)
    height = 1 + max(get_height(node->left), get_height(node->right)); 
    return height;
}

// inorder predecessor : previous node at the inorder traversal (inorder 순회에서 그 전 노드)
// inorder successor : next node at the inorder traversal (inorder 순회에서 이후 노드)
// inorder : L -> V -> R

// Threaded binary Tree : saves the successor in NULL link for traversal
TreeNode *find_successor(TreeNode *p){
    //q : right pointer of p
    TreeNode *q = p->right;

    if(q == NULL || p-> is_thread ==true){
        return q;
    }

    while(q->left != NULL){
        q = q->left;
    }
    return q;
}

//Insertion in Binary Search Tree
    // 일단 search first
void insert_node(TreeNode **root, int key){
    TreeNode *p, *t;// p: parent node, t: current node TreeNode *n;// n: new node to be inserted
    t = *root;
    p = NULL;
    // Search first
    while (t != NULL) {
        if (key == t-> key) {
            printf("The same key exists in the tree.\n"); 
            return;
        }
        p=t;
        if (key < t-> key) t = t->left;
    }

    // Since the key is not in the tree, insertion is possible.
    n = (TreeNode *)malloc(sizeof(TreeNode));
    if (n == NULL) return;
    n->key = key;
    n->left = n->right = NULL;
    if (p != NULL){
        if (key < p->key){
            p->left = n; 
        }
        else p->right = n;
    }
    else *root = n;
}

// Deletion in Binary Search Tree
// 1. 지우려는 노드가 terminal node일때
// 2. 지우려는 노드의 자식노드가 한 개일때
// 3. 지우려는 노드의 자식노드가 두 개일때(both subtree)
    //--> predecessor or successor 찾기

// Deletion in binary search tree
void delete_node(TreeNode **root, int key){
    TreeNode *p, *child, *succ, *succ_p, *t;
    // search node t with key, p : t's parent
    p = NULL;
    t = *root;
    while(t != NULL && t->key != key){
        p = t;
        t = (key < t->key)? t->left : t->right;
    }

    //If t is Null, ther is no key
    if(t ==NULL){
        printf("No key in this tree");
        return ;
    }

    // Case 1 : leaf node(terminal node) : 지우고 null로 바꾸는 과정
    if((t->left == NULL) &&(t->right ==NULL)){
        if(p!= NULL){
            if(p->left ==t)
                p->left = NULL;
            else
                p->right = NULL;
        }
    }

    // Case 2 
    else if((t->left ==NULL)||(t->right ==NULL)){ //자식이 하나만 있으면
        child = (t->left != NULL)? t->left : t->right;
        if(p != NULL){
            if (p->left == t)   //t가 p의 왼쪽 노드면
                p->left = child;    // t == child
            else{
                p->right = child;
            }
        }else{
            *root = child; //parent node가 NULL인 것은 지워져야할 노드가 root노드라서
        }
    }

    // Case 3
    else{
        // Find the successor at right subtree (이후노드 찾기)
        succ_p = t;
        succ = t->right; // successor have no left child
        // Keep moving to the left and find the successor
        while(succ->left !=NULL){
            succ_p = succ;
            succ = succ->left;
        }
        if(succ_p->left == succ){
            succ_p->left = succ->right; // 자식을 끌어 올리기
        }else{
            succ_p->right = succ->right;
        }
        t->key = succ->key;
        t = succ;
    }





}