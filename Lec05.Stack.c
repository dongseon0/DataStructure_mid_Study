/* ********* Stack using array
typedef int element;
typedef struct StackType{
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;

void init(StackType *s){
    s->top = -1;
}
int is_empty(StackType *s){
    return (s->top = -1);
}
int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1));
}
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "Stack is full");
        return ;
    }
    else s->stack[++(s->top)] = item;
}
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is empty");
        exit(1);
    }else return s->stack[(s->top)--];
}
*/

/* ******* Linked Stack (Stack using linked list)*
typedef int element;
typedef struct StackNode{
    element item;
    struct StackNode *link;
}StackNode;

typedef struct LinkedStackType{
    StackNode *top; //address of last node
}LinkedStackType;

void push(LinkedStackType *s, element item){
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    if(temp == NULL){
        fprintf(stderr, "Memory allocation error");
    }
    else{
        temp->item = item;
        temp->link = s->top
        s->top = temp;
    }
}
element pop(LinkedStackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is empty");
    }else{
        StackNode *temp = s->top;
        int item = s->top->item;
        free(temp);
        return item;
    }
}
*/

/* ******** Stack application : Parenthesis Check
int check_matching(char *in){
    StackType s;
    char ch, open_ch;
    int n = strlen(in); //n은 문자 개수
    init(&s);
    for(int i=0; i<n; i++){
        ch = in[i];
        switch(ch){
            case '(' : 
            case '[' :
            case '{' :
                push(&s, ch);
                break;
            case ')' : 
            case ']' :
            case '}' :
                if(is_empty(s)) return FALSE;
                //스택이 비었으면 0
                else{
                    open_ch = pop(&s);
                    //짝이 맞지 않으면 0
                    if((open_ch=='(' && ch !=')') ||
                        (open_ch=='[' && ch !=']') ||
                        (open_ch=='{' && ch !='}')){
                            return false;
                        }
                    break;
                }
        }
    }
    //다 실행했는데 스택이 비지 않았으면 0
    if(!is_empty(&s))    return false;
    return true;
}

int main(){
    if(check_matching("{ A(hi)f}")==true){
        printf("success");
    }else   printf("fail");
}

*/









