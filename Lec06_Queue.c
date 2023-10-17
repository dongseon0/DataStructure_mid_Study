/* ******* Circular Queue ********

#define MAX_QUEUE_SIZE  100
typedef int element;
typedef struct QueueType{
    element queue[MAX_QUEUE_SIZE];  //int 배열
    int front, rear;
} QueueType;

void error(){
    print("error");
    exit(1);
}

//Empty state detection function
int is_empty(QueueType *q){ //매개변수 : \\QueueType 자료형 변수 q의 주소값
    return (q->front == q->rear);
}
// Full state detection function
int is_full(QueueType *q){
    return ((q->rear+1)% MAX_QUEUE_SIZE == q->front);
}

//Insert function
void enqueue (QueueType *q, element item){
    if (is_full(q))                 //full인지 확인
        error();
    q->rear = (q->rear+1)% MAX_QUEUE_SIZE; //MAX-1를 넘지않게
    q->queue[q->rear] = item;   //배열[rear]에 item 넣음
}
//delete하고 삭제한 노드 return 
element dequeue(QueueType *q){
    if(is_empty(q))             //empty인지 확인
        error();
    q->front = (q->front+1)% MAX_QUEUE_SIZE;
    return q->queue[q->front];      //노드 return
}
//peek function
element peek(QueueType *q){
    if(is_empty(q)) 
        error();
    return q->queue[(q->front+1)% MAX_QUEUE_SIZE]     //삭제없이 노드 return
}


void init(QueueType *q){
    q-> front = q->rear = 0;
}
int is_empty(QueueType *q){
    return (q->front == q->rear);
}
int is_full(QueueType *q){
    return (q->front == (q->rear+1)% MAX_QUEUE_SIZE)
}

void main(){
    QueueType q;
    init(&q);
    printf("front=%d rear=%d", q.front, q.rear );
    enqueue(&q, 1);
}*/




/* ****** Linked Queue *******
typedef int element;
typedef struct QueueNode{
    element item;
    struct QueueNode *link;
}QueueNode;
typedef struct QueueType{
    QueueNode *front;
    QueueNode *rear;
}QueueType;


void enqueue(QueueType *q, element item){
    QueueNode *temp = (Queue *)malloc(sizeof(QueueNode));   //node temp 생성, 메모리 할당
    if(temp == NULL)
        error();
    else{
        temp -> item;
        temp -> link = NULL;    //노드 초기화
        if(is_empty(q)){
            q->front = temp;
            q->rear = temp;
        }else{
            q->rear->link = temp;
            q->rear -> temp;
        }
    }
}

element dequeue(QueueType *q){
    QueueType *temp = q->front;
    element item;
    if(is_empty(q))
        error();
    else{
        item = temp ->item;
        q->front = q->front->link;
        if(q->front == NULL)   //node가 하나 밖에 없었으면
            q-> rear = NULL;
        free(temp);
        return item;
    }
}
element peek(QueueType *q){
    if(is_empty(q)) error();
    else{
        return (q->front->item);
    }

}
void main(){
    QueueType q;
    init(&q);
}
*/

/* *********  Deque(Double-ended Queue)  ************
typedef int element;
typedef struct DlistNode{
    element data;
    struct DlistNode *llink;
    struct DlistNOde *rlink;
}DlistNode;

typedef struct DequeType{
    DlistNode *head;
    DlistNode *tail;
} DequeueType;
//Insertion
DlistNode *create_node(DlistNode *llink, element item, DlistNode *rlink){
    DlistNode *node = (DlistNode *)malloc(sizeof(DlistNode));   
    if(node == NULL) error();
    node->llink = llink;
    node->data = item;
    node->rlink = rlink;
    return node;
}

void add_rear(DequeueType *dq, element item){
    DlistNode *new_node = create_node(dq->tail, item, NULL);
    if(is_empty(dq))
        dq->head = new_node;
    else
        dq->tail->rlink = new_node;
    dq->tail = new_node;
}


void add_front(DequeueType *dq, element item){
    DlistNode *new_node = create_node(NULL, item, dq->head);
    if(is_empty(dq))
        dq->tail = new_node;    //head=tail=NULL인 상태의 빈 dq
    else
        dq->head->llink = new_node;
    dq->head = new_node;
}

element delete_rear(DequeueType *dp){
    element item;
    DlistNode *removed_node;

    if(is_empty(dq)) error();
    else{
        removed_node = dq->tail;
        item = removed_node->data;
        dq->tail = dq->tail->llink;
        free(removed_node);
        if(dq->tail == NULL){ //If removing , empty
            dq->head = NULL;
        }else{
            dq->tail->rlink = NULL;
        }
        return item;
    }
}

element delete_front(DequeueType *dq){
    element item;
    DlistNode *removed_node;

    if(is_empty(dq)) error();
    else{
        removed_node = dq -> head;
        item = removed_node -> data;
        dq->head = dq->head->rlink;
        free(removed_node);
        if(dq->head == NULL)
            dq->tail = NULL;
        else        
            dq->head->llink = NULL;
    }
    return item;
}
*/
/* ********* Buffer *********
QueueType buffer;

// Producer process
producer(){
    while(1){
        Produce data;
        while (lock(buffer)!= SUCCESS){
            if(!is_full(buffer)){
                enqueue(buffer, data);
            }
            unlock(buffer);
        }
    }
// consumer process
consumer(){
    while(1){
        while(lock(buffer)!= SUCCESS)
        if(!is_empty(buffer)){
            data =  dequeue(buffer);
            Consume data;
        }
        unlock(buffer);
    }
}
}
*/
/********* Simulation **********/
//수정필요 

#define MAX_QUEUE_SIZE  100


typedef struct element{
    int id;
    int arrival_time;
    int service_time;
}element;   //Costumer structure

typedef struct QueueType{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}QueueType;

QueueType queue;

double random(){
    return random();
}
void enqueue(QueueType *q, element item){
    QueueNode *temp = (Queue *)malloc(sizeof(QueueNode));   //node temp 생성, 메모리 할당
    if(temp == NULL)
        error();
    else{
        temp -> item;
        temp -> link = NULL;    //노드 초기화
        if(is_empty(q)){
            q->front = temp;
            q->rear = temp;
        }else{
            q->rear->link = temp;
            q->rear -> temp;
        }
    }
}


int duration = 10;
double arrival_prob = 0.7;
int max_serv_time = 5;
int clock;

int customers;
int served_customers;
int waited_time;

int is_customer_arrived(){
    if (random() < arrival_prob)
        return 1;
    else    return 0;
}

void insert_customer(int arrival_time){
    element customer;   //customer 구조체(element형)

    customer.id = customers++;
    customer.arrival_time = arrival_time;
    customer.service_time = (int)(max_serv_time * random())+1; // 왜 +1?
    enqueue(&queue, customer);
    printf("Customer %d comes in %d minutes, Service time is %d minutes.",
        customer.id, customer.arrival_time, customer.service_time);
}
int remove_customer(){
    element customer;
    int service_time = 0;
    if(is_empty(&queue))    return 0;
    service_time = customer.service_time -1;
    served_customers++;
    waited_time += clock - customer.arrival_time;
    printf("Customer %d starts service in %d minutes. Wait time was %d minutes.", 
        customer.id, clock, clock-customer.arrival_time);
    return service_time;
}

void print_stat(){
    printf("Number of customers served = %d", served_customers);
    printf("Total wait time = %d minutes", waited_time);
    printf("Average wait time per person = %f minutes",
        (double) waited_time / served_customers);
    printf("Number of customers still waiting = %d", 
        customers - served_customers);
}

void main(){
    int service_time = 0;
    clock = 0;
    while(clock<duration){
        clock++;
        printf("Current time=%d\n", clock);
        if(is_customer_arrived()){
            insert_customer(clock); //clock이 arrival time
        }

        if(service_time >0){    //service이 finish or not
            service_time--;
        }
        else{
            service_time = remove_customer(); //return service_time(how long it takes)
        }
    }

print_stat();
}