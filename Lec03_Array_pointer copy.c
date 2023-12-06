/*** polynomial representation 1 in arrays (store all term)

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
}polynomial;
polynomial a = {5, {10, 0, 0, 0, 6, 3}};

#include <stdio.h>
#define MAX(a,b) (a>b)? a:b
#define MAX_DEGREE 101
typedef struct {
    int degree;
    float coef[MAX_DEGREE]; //float형 배열 coef
}polynomial;

polynomial poly_add1(polynomial A, polynomial B){
    polynomial C;
    int Apos, Bpos, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);
    while  (Apos<=A.degree && Bpos<=B.degree)
        if(degree_a > degree_b){
            C.coef[Cpos++]= A.coef[Apos++];
            degree_a--;
        }else if( degree_a == degree_b ){ 
            C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++]; 
            degree_a--; 
            degree_b--;
        }
        else{
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
        return C;
}
main(){
    polynomial a = { 5, {3, 6, 0, 0, 0, 10} };
    polynomial b = { 4, {7, 0, 5, 0, 1} };
    polynomial c;
    c = poly_add1(a, b);
}
*/

/**** polynomial representation in arrays (store non-zero term)
#define MAX_TERMS 101
struct {
    float coef;
    int expon;
}terms[MAX_TERMS]= {{8,3}, {7,1}, {1,0},{10,3}, {3,2},{1,0} };
int avail=6;//avail에 넣음
//compare two integers
char compare(int a, int b){
    if(a>b) return '>';
    else if(a==b) return'=';
    else return '<';
}
//avail 자리에 수를 넣는 함수
void attach(float coef, int expon){
    if(avail>MAX_TERMS){
        fprintf(stderr, "TOO MANY TERMS");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].expon = expon; //avail 한 칸 다음으로
}
//C=A+B
poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
    float tempcoef;
    avail = *Cs; //avail은 Cs를 가리키는 포인터
    while(As<=Ae && Bs<=Be){
        switch(compare(terms[As].expon, terms[Bs].expon)){
            case '>':
                attach(terms[As].coef, terms[As].expon);
                As++;
            case '=': 
                tempcoef = terms[As].coef + terms[Bs].coef;
                if( tempcoef ){
                    attach(tempcoef,terms[As].expon);
                    As++; 
                    Bs++; 
                    break;
                }
            case '<': 
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
    }

    //남은 것들 copy and paste
    for(; As<=Ae; As++){
        attach(terms[As].coef, terms[As].expon);
    }
    for(; Bs<=Be; Bs++){
        attach(terms[Bs].coef, terms[Bs].expon);
    *Ce = avail-1;
    }

    void main(){
        int Cs, Ce;
        poly_add2(0,2,3,5,&Cs, &Ce);
    }
}*/

/******** Sparse Matrix(all elements)
#include <stdio.h>
#define ROWS 3
#define COLS 5
//Addition
void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int c[ROWS][COLS]){
    int r, c;
    for(r=0; r<ROWS; r++){
        for(c=0;c<COLS;c++){
            c[r][c] = A[r][c]+B[r][c];
        }
    }
}*/
/******** Sparse Matrix (only non-zero elements)*/
#include <stdio.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10
typedef struct{
    int row;
    int col;
    int value;
}element;
typedef struct SparseMatrix{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms; //number of elements(non-zero values)
}SparseMatrix;
//Addition

//이거 이해가 안됨....

SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b){
    SparseMatrix c;
    int ca=0, cb=0, cc=0; //index indicating (non-zero)terms in each array
    //array a, array b의 크기가 같은지 확인
    if(a.rows!=b.rows || a.cols!= b.cols){
        fprintf(stderr, "Size Error");
        exit(1);
    }
    c.rows = a.rows;
    c.cols = a.cols;
    c.terms = 0;

    while(ca<a.terms && cb<b.terms){
        int inda = a.data[ca].row * a.cols + a.data[ca].col;
        int indb = b.data[cb].row * b.cols = b.data[cb].col;
    //if array 'a' entry is in front
    if(inda < indb){
        c.data[cc++] = a.data[ca++];

    }else if (inda == indb){
        if((a.data[ca].value + b.data[cb].value ! = 0)){
            c.data[cc].row = a.data[ca].row;
            c.data[cc].col = a.data[ca].col; 
            c.data[cc++].value = a.data[ca++].value + b.data[cb++].value;
        }else
            ca++;  cb++;
    //if array 'b' entry is in front
    }else{ 
        c.data[cc++] = b.data[cb++];
    }
}
    //copy and paste
        for(; ca< a.terms;){
            c.data[cc++] = a.data[ca++];
        }
        for(; cb< b.terms;){
            c.data[cc++] = b.data[cb++];
        }
        c.terms = cc;
        return c;
    }

main(){
    SparseMatrix m1 = {{{1,1,5},{2,2,9}}, 3, 3, 2};
    SparseMatrix m2 = {{{0,0,5},{2,2,9}}, 3, 3, 2};
    SparseMatrix m3;
    m3 = sparse_matrix_add2(m1, m2);
}
*/
/*
void swap(int *px, int *py){
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}*/

/*
main(){
    struct{
        int i;
        float f;
    }s, *ps;
    ps = &s;
    //주소로 access이면 ->사용
    ps->i = 2;
    ps->f = 3.14;
    //데이터로 access이면 .사용
    (*ps).i = 2;
    (*ps).f = 3.14;
}*/

//Dynamic Memory Allocation
/*
int *pi;
pi = (int*)malloc(sizeof(int));
-
-
free(pi); // pi를 free해주지 않으면 메모리에 저장됨.

//ex
int pi[10];
pi = (int*)malloc(sizeof(int)*10); //size

*/

//Memory Allocation of 2D Array
void main(){
    int row = 3;
    int col = 3;
    int **m2 = (int *)malloc(sizeof(int *)*row);
    for(int i=0; i<row; i++){
        m2[i]= (int *)malloc(sizeof(int)*col); //expand column dimension
    }
    int count = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            m2[i][j] = ++count;
            prinf_s("%d", m2[i][j]);
        }
    }
}















