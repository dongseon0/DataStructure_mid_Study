// Stability : relative position with same key value is not changing

// Selection Sort
    // left list : sorted data
    // right list : unordered data
    // 순서 : Right list가 empty일 때까지,
        // right list의 첫번째 요소와 가장 작은 요소를 바꾼다

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(int list[], int n){
    int i, j, least, temp;
    for(i=0; i<n-1; i++){
        least = i;
        for(j=i+1; j<n; j++){
            if(list[j]<list[least]) least = j; //right의 최솟값 찾기
        }
        SWAP(list[i], list[least], temp);
    }
}

// Insertion Sort
    // insert a new record in right place of sorted part
    // 순서 : right의 요소를 left(sorted)의 맞는 자리에 insert
        //right에서 요소 꺼내서 left의 요소들과 하나하나 대조
    // Time Complexity : O(n^2)
void insertion_sort(int list[], int n){
    int i, j, key;
    for(i - 1; i<n; i++){
        key = list[i];
        for(j=i-1; j>=0 && list[j]>key; j--){
            list[j+1] = list[j];
        }
        list[j+1] = key;
    }
}

// Bubble Sort
    // n번 iteration, adjacent data끼리 sorting 반복 후 마지막은 고정
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) ) 
void bubble_sort(int list[], int n){
    int i, j, temp;
    for(i = n-1; i>0; i--){
        for(j=0; j<i; j++){
            if(list[j]>list[j+1]){
                SWAP(list[j], list[j+1], temp);
            }
        }
    }
}

// Merge Sort   - stable
    // divide + conquer(Sort) + combine
    // 순서 : equal size로 나누고 sort
    //Time Complexity : O(n*log2n)
void merge(int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left; j = mid +1; k=left;
    //merge arrays
    while(i<=mid && j<= right){
        if(list[i] <= list[j]){
            sorted[k++] = list[i++];
        }else{
            sorted[k++] = list[j++];
        }
    }
    if(i>mid){// 오른쪽 arr에 남아있을때
        for(l = j; l<=right; l++){
            sorted[k++] = list[l];
        }
    }else{
        for (l = i; l<=mid; l++){
            sorted[k++] = list[l];
            }
    }
    for(l = left; l<=right; l++){
        list[l] = sorted[l];
    }
}

void merge_sort(int list[], int left, int right){
    int mid;
    if(left<right){
        mid = (left+right)/2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right); 
        merge(list, left, mid, right);
    }
}

// Quick Sort   - unstable
    // pivot 기준 작으면 left, 크면 right
    // Time Complexity : 
        // Best : O(nlog2n)
        // Worst : O(n^2)

int partition(int list[], int left, int right){
    int pivot, temp;
    int low, high;

    low = left+1;
    high = right;
    pivot = list[left]; //first element를 pivot으로
    while(low<high){
        while(low<right && list[low]<pivot){ //pivot보다 큰 애서 멈춤
            low++;
        }
        while (high > left && list[high]>pivot){//pivot보다 작은 애서 멈춤
            high--;
        }
        if(low<high){
        SWAP(list[low], list[high], temp);//둘이 바꾸기
        }
    }
    SWAP(list[left], list[high], temp); //pivot을 중간에
    return high;
}

//Better solution for partition
    // 배열 맨 마지막을 pivot으로
    36쪽


// Non Comparison sorting

// Counting Sort
    //배열 A : 숫자 섞여있는 배열
    //배열 C 's index : 숫자, value : index 빈도수
    //배열 B 's index : value -1에 배열 C 's index를 넣고  
        // 배열 C에 value-1
    //--> 결과는 B
       //  for j=n-1 downto 0 쓰는 이유 : stable하려고
    // Time Complexity : O(n+k) (n : data수, k : range수)


// Radix Sort : sort for each digit
    // digit : 자릿수 == segment
    // LSD부터 sort
    // Time Complexity : O(d(n+k))
                    //==> HO(b/r(n+2^r)) 
                    // b/r == # of segment
                    // r: bit of each segment
                    // digit == segment

#define BUCKETS 10
#define DIGITS 4
void radix_sort(int list[], int n) {
    int i, b, d, factor = 1; 
    QueueType queues[BUCKETS];
    for (b = 0; b<BUCKETS; b++) 
        init(&queues[b]); // Initialize queues

    for (d = 0; d<DIGITS; d++) {
        for (i = 0; i<n; i++){ // Add the data into queues
            enqueue(&queues[(list[i]/factor)% BUCKETS], list[i]);
        }

        for(b=i=0; b<BUCKETS;b++){
            while(!is_empty(&queus[b])){
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= BUCKETS;  //process next segment(digit)
        //(25/1) % 10 = 5
        //(25/10) % 10 = 2
    }
}