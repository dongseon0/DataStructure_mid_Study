// Heap : Complete binary tree
    // Max heap : parent >= child
    // Min heap : parent <= child

// Heap is implemented using arrays
    // Parent node of node i : i/2
    // Left child node of node i : 2i
    // Right child node of node i : 2i+1

// Insertion in Max Heap : 마지막에 넣고 그 노드의 부모와 비교
    // Time Complexity : O(log2n)
#include <stdio.h>
#define MAX_ELEMENT 200
typedef struct{
    int key;
}element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size; //how many element
}HeapType;



void insert_max_heap(HeapType *h, element item){
    int i;
    i = ++(h->heap_size);

    while((i!=1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2]; //item이 부모노드보다 클 때
        i = i/2; //부모노드로
    }
    h-> heap[i] = item;
}

//Deletion in Max Heap : the largest key value
    //Time Complexity : O(log2n) == height
element delete_max_heap(HeapType *h){
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while(child <= h->heap_size){
        //find smaller child node
        if((child < h->heap_size) && 
        (h->heap[child].key) < h->heap[child+1].key)
            child++;
        if(temp.key >= h->heap[child].key) break;
        //Move down one level
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }


// Build-Max-Heap()
// 일단 element 싹 다 array에 넣고, 그다음 max heap으로 만든다.
// Time Complexity : 
    //moving an element in the heap : O(log2n)
    //moving operation : O(n)
    //Thus, Upper Bound Time Complexity : O(n*long2n)
        // tighter bound : O(n)

        24쪽 안봄... 봐야함!!!!!!!!!!!!!!!!!!!!!!
    
// Heap Sort : sorting algorithm using heap
    // 1. Insert n elements to be sorted in max heap
    // 2. Delete root from max heap and save it in array n times
    // Time Complexity : O(n*log2n)

void heap_sort(element a[], int n){
    int i;
    HeapType h;

    //building max heap
    init(&h);
    for(i=0; i<n; i++){
        insert_max_heap(&h, a[i]); // max heap 만들고
    }
    for(i= (n-1); i>=0; i--){
        a[i] = delete_max_heap(&h); // max heap에서 꺼내면서 array 만들기
    }


}


50쪽 해야힘




}



// Huffman Code
    //optimal codeword is full binary tree
    //1. fixed-length codeword / 2. Variable-length codeword
    // 2-> 압축하고자 하는 문자열에서 자주 등장하는 문자는 짧은 비트로 표현하고 거의 등장하지 않는 문자는 긴 비트로 표현

// 트리 만들고, 알파벳 별 빈도수를 저장한 노드 생성
// 가장 작은 빈도수 + 두번째로 작은 빈도수를 가진 걸 찾아서 빈도수를 합친 수로 노드하나 만들기
// 그 노드의 왼쪽은 가장 작은 , 오른쪽은 두 번째로 작은
// 비교할 노드가 1개만 남을 때까지 반복
// 왼쪽 0, 오른쪽 1 가중치

//Node generation in binary tree
TreeNode *make_tree(TreeNode *left, TreeNode *right){
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL){
        
    }
    node->left_child = left;
    node->right_child = right;
    return node;
}

typedef struct {
           TreeNode *ptree;
           int key;
} element;

typedef struct {
           element heap[MAX_ELEMENT];
           int heap_size;
} HeapType;

//Huffman code generation
void huffman_tree(int freq[], int n){
    int i;
    TreeNode *node, *x;
    HeapType heap;
    element e, e1, e2;
    init(&heap);

    for(i=0; i<n; i++){
        e1 = delete_min_heap(&heap);
        e2 = delete_min_heap(&heap);

        // Merge two nodes
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key+e2.key;
        e.ptree = x;
        insert_min_heap(&heap, e);
    }
    e = delete_min_heap(&heap); //final huffman binary tree
    destroy_tree(e.ptree);
}