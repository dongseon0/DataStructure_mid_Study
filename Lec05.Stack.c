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


/****** Stack Application: Calculation of Formulas ******
int eval(char exp[]){
    int op1, op2, value, i =0 ;
    int len = srlen(exp);
    char ch;
    StackType s;

    init(&s);
    for(int i=0; i<len; i++){
        ch = exp[i];
        if(ch!='+' && ch!='-' && ch!='*' && ch!='/'){
            value = ch - '0'; //숫자도 char로 받기 때매 정수형으로 바꿔주는 것
            push(&s, value);
        }else{  //operator이면 두 숫자 pop하고 operate
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+': push(&s, op1 + op2); break; 
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}
void main(){
    int result = eval("82/3-32*+");
    printf("result: %d", result);

}
*/
/******* infix to postfix***
//1) operand : print
//2) operator 
//  a. stack >= current --> stack print, current store in stack
//  b. stack < current : store
//  c. ')'이면 output all operators
//  d. end면 다 꺼내기

typedef struct StackType{
    struct StackType *top;
}StackType;

int prec(char op){ //operator's priority
    switch(op){
        case '(':
        case ')':
            return 0;
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
            return 2;
    }
}

void infix_to_postfix(char exp[]){
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init(&s);
    for(int i=0; i<len; i++){
        ch = exp[i];
        switch (ch){
            case '+' :
            case '-' :
            case '*' :
            case '/' :
                while(!is_empty(&s) && (prec(ch))<=prec(peek(&s))){
                    printf("%c", pop(&s));
                }
                push(&s, ch);
                break;
            case '(':
                push(&s, ch);
                break;
            case ')':
                top_op = pop(&s);
                while(top_op!='('){
                    printf("%c", top_op);
                    top_op = pop(&s)l
                }
                break;
            default : //operand
                printf("%c", ch);
                break;
        }
    }
    while(!is_empty(&s)){
        printf("%c", pop(&s));
    }
}

void main(){
    infix_to_postfix("~~");
}
*/

typedef struct StackType{
    struct StackType *top;
}StackType;
typedef struct element{
    int r;
    int c;
}element;

element here = {1,0};
entry = {1,0};


void push_loc(StackType *s, int r, int c){
    if(r<0 ||c<0)   return;
    if(maze[r][c] != '1' && maze[r][c]!='.'){   //block이 아니고 아직 방문하지 않은 곳
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

char maze[MAZE_SIZE][MAZE_SIZE]{
    { '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },
{ '1', '1', '1', '1', '1', '1' },
};

void main(){
    int r, c;
    StackType s;
    init(&s);
    here = entry;
    while(maze[here.r][here.c]!='x'){ //'x'는 exit
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        push_loc(&s, r-1, c);//위
        push_loc(&s, r+1, c);//아래
        push_loc(&s, r, c-1);//왼
        push_loc(&s, r, c+1);//오
        if(is_empty(&s)){
            printf("fail");
            return;
        }else{
            here = pop(&s);
        }
    }
    printf("success");
}




