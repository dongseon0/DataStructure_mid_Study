/*
//List using Array
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
    int list[MAX_LIST_SIZE];
    int length;
} ArrayListType;

void init(ArrayListType *L){
    L->length = 0;
}

int is_empty(ArrayListType *L){
    return L->length == 0;
}

int is_full(ArrayListType *L){
    return L->length = MAX_LIST_SIZE;
}

void add(ArrayListType *L, int position, element item){
    if( !is_full(L) && (position >=0) && (position <= L->length)){
        int i;
        for(i=(L->length-1); i>=position; i--)
            L->list[i+1] = L->list[i];
        L->list[position] = item;
        L->length++;
    }
}

element delete(ArrayListType *L, int position){
    int i;
    element item;
    if(position<0 || position >= L->length) error();
    item = L->list[position];
    for(i=position; i<(L->length-1); i++){
        L->list[i] = L->list[i+1];
    }
    L->length--;
    return item;
}

/*************** Simple Linked List **************
typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;
/* // Node generation
ListNode *p;
p = (ListNode*)malloc(sizeof(ListNode));




void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if (*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }else{
        new_node->link = p->link;
        p->link = new_node;

    }
}
void insert_first(ListNode **phead, ListNode *new_node){
    if (*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }else{
        new_node->link = *phead;
        *phead = new_node;
    }
}
void insert_last(ListNode **phead, ListNode *new_node){
    if (*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }else{
        new_node ->link = NULL;
        struct ListNode *last = *phead; //head가 가리키는 변수 p를 last
        while(last->link !=NULL){//last의 링크를 타고 last의 link가 null인 노드까지
            last = last->link;
        }
        last->link = new_node;
    }
}

void remove_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if(*phead == NULL){
        printf("blank");
    }else{
        if(p==NULL) error();
        else{
            p->link = removed->link;
            free(removed);
        }
    }

}
void remove_first(ListNode **phead, ListNode *removed){
    if(*phead == NULL){
        printf("blank");
    }else{
        *phead = (*phead)->link
        free(removed);
    }
}

//Visit operation
//iteration
void display(ListNode *head){
    ListNode *p = head;
    whie(p!= NULL){
        p = p->link;
    }
}
//recursion
void display_recur(ListNode *head){
    ListNode *p = head;
    whie(p!= NULL){
        display_recur(p->link);
    }
}
//Search operation
ListNode *search(ListNode *head, int x){
    ListNode *p;
    p = head; //p라는 포인터가 head를 가리킨다.
    while(p!= NULL){
        if(p->data == x)    return p;
        p = p->link;
    }
    return p;
}
//Merge Operation
ListNode *concat(ListNode *head1, ListNode *head2){
    ListNode *p;
    if(head1 =NULL) return head2;
    else if(head2 =NULL) return head1;
    else{
        p = head1;
        while(p->link !=NULL)   p= p->link;
        p->link = head2;
        return head1;
    }
}
//Reverse Operation
ListNode *reverse(ListNode *head){ //*head == **phead
    ListNode *p, *q, *r;
    p = head; //head가 가리키는 노드의 값을 p에 넣어주고
    q = NULL;
    while(p!= NULL){
        r=q;
        q=p;
        p=p->link;
        q->link = r;
    } return q;
}



/*************** Circular Linked List **************/
void insert_first(ListNode **phead, ListNode *node){
    if(*phead ==NULL){
        *phead = node;
        node->link = node; //혼자도는 single node..
    }else{
        node->link = (*phead)->link;
        (*phead)->link = node;

    }
}

void insert_end(ListNode **phead, ListNode *node){
    if(*phead ==NULL){
        *phead = node;
        node->link = node; //혼자도는 single node..
    }else{
        node->link = (*phead)->link;    //node의 link가 마지막 가리킴
        (*phead)->link = node; //node를 붙임
        *phead = node; //헤드 포인터가 가리키는 것이 node

    }
}

/*************** Doubly Linked List **************
typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
}DlistNode;

void init(DlistNode *phead){
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert_node(DlistNode *before, DlistNode *new_node){
    new_node->llink = before;
    new_node->rlink = before->rlink;
    before->rlink = new_node;
}
void dremove_node(DlistNode *phead_node, DlistNode *removed){
    if(removed == phead_node)   return; // blank list
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}
void main(){
    DlistNode head_node;
    DlistNode *p[10];

    init(&head_node);
    for(int i=0; i<5; i++){
        p[i] = (DlistNode *)malloc(sizeof(DlistNode));
        p[i]->data = i;
        dinsert_node(&head_node, p[i]);
    }

}
*/


/*
typedef struct ListNode{
    int coef;
    int expon;
    struct ListNode *link;
}ListNode;

typedef struct ListHeader{
    int length;
    ListNode *head;
    ListNode *tail;
}ListHeader;

void init(ListHeader *plist){
    plist->length = 0;
    plist->head = plist->tail = NULL;
}

void insert_node(ListHeader *plist, int coef, int expon){
    ListNode *temp = (ListHeader *)malloc(sizeof(ListNode));
    if(temp==NULL) error();
    temp->coef = coef;
    temp_>expon = expon;
    temp ->link = NULL;
    if(plist->tail == NULL){
        plist->head = plist->tail = temp;
    }else{
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->length++;
}

void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3){
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    while(a && b){
        if(a->expon == b->expon){
            sum = a->coef +b->coef;
            if(sum!=0){
                insert_node_last(plist3, sum, a->expon);    
            }
            a= a->link; b= b->link;
        }else if(a->expon > b->expon){
            insert_node_last(plist3, a->coef, a->expon);
            a= a->link;
        }else{
            insert_node_last(plist3, b->coef, b->expon);
            b= b->link;

        }
    }
    for(; a!=NULL; a=a->link){
        insert_node_last(plist3, a->coef, a->expon);
    }
    for(; b!=NULL; b= b->link){
        insert_node_last(plist3, b->coef, b->expon);
    }

void poly_print(ListHeader *plist){
    ListNode *p = plist->head;
    for(; p; p=p->link){
        printf("%d %d\n", p->coef, p->expon);
    }
}
}*/


/******* List ADT ********/
typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *link;

} ListNode;


typedef struct{
    ListNode *head;
    int length;
} ListType;

ListType list1;

int is_empty(ListType *list){
    if(list->head == NULL) return 1;
    else return 0;
}

int get_length(ListType *list){
    return list->length;
}

//return node pointer of pos in the list.
ListNode *get_node_at(ListType *list, int pos){
    ListNode *tmp_node = list->head;
    if(pos<0) return NULL;
    for(int i=0; i<pos; i++){
        tmp_node = tmp_node->link;
        return tmp_node;    // pos 노드 리턴
    }
}

void add(ListType *list, int position, element data){
    ListNode *p;
    if((position >=0) && (position <= list->length)){
        ListNode *node = (ListNode *)malloc(sizeof(ListNode));
        node->data = data;
        p = get_node_at(list, position-1);
        insert_node(&(list->head), p, node);
        list->length++;
    }
}

void delete(ListType *list, int pos){
    if(!is_empty(list) && (pos>=0) && (pos<list->length)){
        ListNode *p = get_node_at(list, pos-1);
        ListNode *removed = get_node_at(list, pos);
        remove_node(&(list->head), p, removed);
        list->length--;
    }
}


//Return the data at the 'pos'
element get_entry(ListType *list, int pos){
    ListNode *p;
    if(pos>= list->length||pos<0) error();
    p = get_node_at(list, pos);
    return p->data;
}

void display(ListType *list){
    ListNode *node = list->head;
    for(int i=0; i<list->length; i++){
        printf("%d", node->data);
        node = node->link;
    }
    printf("\n");
}

int is_in_list(ListType *list, element item){
    ListNode *p;
    p= list->head;
    while((p!=NULL)){
        if(p->data ==item){
            break;
            p= p-> link;
        }
    if(p==NULL) return FALSE;
    else return TRUE;

    }
}