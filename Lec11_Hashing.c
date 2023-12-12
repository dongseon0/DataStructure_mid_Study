// Hash  Table : 가로버킷, 세로슬롯
// Collision : 키가 다른데 h(k)가 같음 -> 같은 버킷, 다른 슬롯에 저장
// Overflow : 슬롯이 꽉 찼을 때

// h(k) = k mod M

// Division function(분산..)
    // hash table size : M(prime) --> 키를 더 균등하게 분산시켜 collision 덜 발생

int hash_function(int key){
    int hash_index = key % M;
    if(hash_index <0){
        hash_index +=M;
    }
    return hash_index;
}
    //folding function : 쪼개서 더함

// When key is a string
    //using 아스키코드 / 유니코드
int hash_function(char *key/*아스키코드*/){
    int hash_index = 0;
    while(*key){
        hash_index = g *hash_index + *key++; //g = positive integer
    }
    return hash_index;
}

//Collision : different search keys, same hash address
//--> Solution : Probing & Chaining
    // 1) Linear Probing
        // Collision at h(k), investigate h(k)+1
        // not empty, 빈 곳 찾을 때까지.. h(k)+2, ....
        // h(k)로 되돌아왔다면, table is full. => Overflow
    #define KEY_SIZE10// Maximum size of search key 
    #define TABLE_SIZE13// Hash table size (prime number)
    typedef struct element {
        char key[KEY_SIZE];
    } element;

    element hash_table[TABLE_SIZE];

    // Initialize the hash table
    void init_table(element ht[]) {
            //each bucket is initialized as null
            for (int i = 0; i < TABLE_SIZE; i++)
                        ht[i].key[0] = NULL;
    }
    // Transform the string key into an integer by summing ASCII codes
    int transform(char *key) {
        int number = 0;
        while (*key)
            number += *key++;
        return number;  
    }
    // Division function ( key mod TABLE_SIZE )
    int hash_function(char *key) {
            return transform(key) % TABLE_SIZE;
    }

    #define empty(e) (strlen(e.key)==0)
    #define equal(e1, e2) (!strcmp(e1.key, e2.key)) // Add the key into the hash table
    // Collision is handled using the linear probing 
    void hash_lp_add(element item, element ht[]) {
        int i, hash_value;
        hash_value = i = hash_function(item.key); 
        while (!empty(ht[i])) {
            if (equal(item, ht[i])) {
                fprintf(stderr, "Duplicate search key\n");
                return;
            }
            i = (i + 1) % TABLE_SIZE; // Collision 생기면 다음 위치로
            if (i == hash_value) {
                        fprintf(stderr, "Table is full (overflow).\n");
                        return;
            } }
            ht[i] = item; //비면 지정
    }
    void hash_lp_search(element item, element ht[]){
        int i, hash_value;
        hash_value = i = hash_function(item.key);
        while (!empty(ht[i])) {
            if (equal(item, ht[i])) {
                fprintf(stderr, "Search success: position = %d\n", i); 
                return;
            }
            i = (i + 1) % TABLE_SIZE;
            if (i== hash_value){
                fprint(stderr, "Search key is not in hash table.\n"); 
                return;
            }

        }
    }

        // 1-2) Quadratic Probing
            //collsion occurs, --> h(k), h(k)+1, h(k)+2^2, ... 제곱씩 더함
        // 1-3) Double Hashing
            // collsion occurs, different hash function
            // step = C-(k mod C)
            // h(k), h(k)+step, h(k)+ 2*step, ...



    // 2) Chaining : use linked list in each bucket
        // Address collision and overflow with linked list
        #define equal(e1, e2) (!strcmp(e1.key, e2.key)) 
        void hash_chain_add(element item, ListNode *ht[]) {
            int hash_value = hash_function(item.key); 
            ListNode *ptr;
            ListNode *node_before = NULL;
            ListNode *node = ht[hash_value];
            for (; node; node_before = node, node = node->link){
                if (equal(node->item, item)) {
                    fprintf(stderr, "Duplicate search key\n");
                    return;
                } 
            }
            ptr = (ListNode *)malloc(sizeof(ListNode)); 
            ptr->item = item;
            ptr->link = NULL;
            if (node_before){
                node_before->link = ptr;
            }
            else{
                ht[hash_value] = ptr;
            }
        }

        void hash_chain_search(element item, ListNode *ht[]){
            ListNode *node;
            int hash_value = hash_function(item.key);
            for (node = ht[hash_value]; node; node = node->link) {
            if (equal(node->item, item)) {
                printf("Search success\n");
                return;
                }
            printf("Search failed\n");
            }
        }

        // a = (# of stored items) / hash table size = n/M
        // Hashing  : Worst : O(n)