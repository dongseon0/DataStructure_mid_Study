//Factorial Programming
int factorial(int n){
    if(n<=1) return(1);
    else return (n*factorial(n-1));
}
int factorial_iter(int n){
    int k,v =1;
    for(k=n; k>0; k--){
        v *=k;
    }
    return(v);
}
//x를 n번 곱함(iteration)
double slow_power(double x, int n){
    double r =1.0;
    for(int i=0; i<n; i++){
        r*=x;
    }
    return r;
}
//O(log 2 n)
double power(double x, int n){
    if(n==0)    return 1;
    else if ((n%2)==0){
        return power(x*x, n/2);
    }else{
        return x*power(x*x,(n-1)/2);
    }
}
// 나중에 하고..
fib_iter(int n){
    if()
}

//하노이탑
//Move n discs stacked on the bar 'from' to 'to' using 'tmp'
/*
void hanoi_tower(int n, char from, char tmp, char to){
    if(n==1){
        printf("Move 1 disc from %c to %c", from, to);
    }else{
        hanoi_tower(n-1, from, to, tmp);
        printf("Move disc %d from %c to %c", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}
*/


