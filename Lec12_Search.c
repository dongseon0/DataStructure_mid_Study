// Search - in unordered array, in ordered array
// 순차탐색 하나하나 맞는지 대조
// Time Complexity : O(n)
int seq_search(int key, int low, int high) {
    int i;
    for (i = low; i <= high; i++)
        if (list[i] == key) return i;
    return -1;
}

// Improved Sequential Search
    // save search key at the end of list
int seq_search2(int key, int low, int high) {
    int i;
    list[high + 1] = key;
    for (i = low; list[i] != key; i++)
        ;
    if (i == (high + 1)) return -1;
    else return i;
}

// Binary Search
    //  Search in ordered array
    // Time Complexity : O(log2n)
    // 반 잘라서 왼, 오
int search_binary2(int key, int low, int high) {
    int middle;
    while (low <= high) { // when there are elements to be checked
        middle = (low + high) / 2;
        if (key == list[middle]) return middle; // search success
        else if (key > list[middle]) low = middle + 1; //go to right sub-array else high = middle - 1; // go to left sub-array
    }
    return -1; // search fail
}

// Indexed Sequential Search
// Index table
    // increase efficiency of sequential search
    // Stores data in index table 'Regularly'
    // n/m 간격으로 떨어져있는 원소와 인덱스를 인덱스 테이블에 저장
    // Time Complexity : O(m+(n/m))
        // m : index table size
        // n : size of main data list

#define INDEX_SIZE 4 //index table size 
#define INPUT_SIZE 18 //input data size
typedef struct itable{
    int key;
    int index;
} itable;
itable index_list[INDEX_SIZE];
int *list;

int seq_search(int key, int low, int high){
    int i;
    for(i = low; i<=high; i++){
        if(list[i] == key){
            return 1;
        }
    }
    return -1;
}

void generate_index_table(){
    int step = ceil((float)INPUT_SIZE)/(float)INDEX_SIZE);
    for(int i = 0; i< INDEX_SIZE; i++){
        index_list[i].index = i*step;
        index_list[i].key = list[i*step];
    }
}

int search_index(int key){
    int i, low, high;
    if(key<list[0] || key>list[INPUT_SIZE -1]){
        return -1;
    }
    for(i=0; i< INDEX_SIZE; i++){
        if(index_list[i].key <= key && index_list[1].key > key)
            break;
    }

    if(i== INDEX_SIZE){
        return -1;
    }else if(i== INDEX_SIZE -1){
        low = index_list[i].index;
        high = INPUT_SIZE-1;
    }else{
        low = index_list[i].index;
        high = index_list[i+1].index;
    }
    return seq_search(key, low, high);

}