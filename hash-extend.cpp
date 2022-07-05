/*
用开放寻址法实现一个可扩容的哈希表
*/
#include <iostream>
using namespace std;

#define MAXSIZE 7
#define WORKLOAD 0.75
#define TOMBSTONE -2
#define INVALID -1

void hash_insert(int key, int value);
void hash_delete(int key);
int myhash(int key);
int hash_find(int key);
void hash_init();
void rehash();

int num=0, rehash_count=0;
typedef struct kv
{
    int key;
    int value;
} kv_t;

kv_t *hash_table;

void hash_insert(int key, int value) {
    int index = hash_find(key);
    if(hash_table[index].key!=INVALID) {
        cout<<"key existed"<<endl;
        hash_table[index].value = value;
        cout<<"new kv is "<<hash_table[index].key<<" "<<hash_table[index].value<<endl;
    }
    else {
        hash_table[index].key = key;
        hash_table[index].value = value;
        num++;
        if(num/(MAXSIZE*(rehash_count+1)) >= WORKLOAD) {
        rehash();
        }
    }
}

void hash_delete(int key) {
    int index = hash_find(key);
    if(hash_table[index].key==INVALID) {
        cout<<"delete invalid"<<endl;
    }
    else {
        hash_table[index].key = TOMBSTONE;
    }
}

int myhash(int key) {
    return key%(MAXSIZE*(rehash_count+1));
}

int hash_find(int key) {
    int index = myhash(key);
    while(hash_table[index].key!=INVALID) {
        if(hash_table[index].key==key) break;
        index = (index+1)%(MAXSIZE*(rehash_count+1));
    }
    return index;
}

void hash_init() {
    hash_table= (kv_t*)malloc(MAXSIZE*(rehash_count+1)*sizeof(kv_t));
    for(int i=0; i<MAXSIZE*(rehash_count+1); i++) {
        hash_table[i].key = -1;
    }
}

void rehash() {
    rehash_count++;
    kv_t *new_hash_table = (kv_t*)malloc(MAXSIZE*(rehash_count+1)*sizeof(kv_t));
    if(new_hash_table!=nullptr) {
        cout<<"the "<<rehash_count+1<<" time to rehash"<<endl;
    }
    for(int i=0; i<=MAXSIZE*(rehash_count); i++) {
        if(hash_table[i].key!=INVALID&&hash_table[i].key!=TOMBSTONE) {
            int new_index = myhash(hash_table[i].key);
            new_hash_table[new_index].key = hash_table[i].key;
            new_hash_table[new_index].value = hash_table[i].value;
        }
    }
    free(hash_table);
    cout<<"old table freed"<<endl;
    hash_table = new_hash_table;
    cout<<"hash table extended"<<endl;
}

int main() {
    hash_init();
    while(1) {
        int mode, key, value; //mode=0 means insert, mode=1 means delete, mode=2 means exit
        cin>>mode;
        if(mode==2) break;
        cin>>key>>value;
        if(mode==0) hash_insert(key, value);
        else hash_delete(key);
    }
    return 0;
}