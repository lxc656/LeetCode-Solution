/*
手写一个小根堆，并且简单测试了下
*/
#include<iostream>
#define MAXSIZE 1000000
using namespace std;
int heap[MAXSIZE], size = 0;

void up(int index) {
    int parent_index = index/2;
    while(parent_index >= 1){
        if(heap[parent_index]>heap[index]) {
        int t = heap[index];
        heap[index] = heap[parent_index];
        heap[parent_index] = t;
        index = parent_index;
        }
        else {
            break;
        }
    }
}

void down(int index) {
    while(index<=size){
        int left_child = index*2;
        int right_child = index*2+1;
        int smaller_one;
        if(left_child<=size&&right_child<=size){
            smaller_one = 
            heap[left_child]<heap[right_child]? left_child:right_child;
        }
        else if(left_child<=size&&right_child>size){
            smaller_one = left_child;
        }
        else if(left_child>size&&right_child<=size){
            smaller_one = right_child;
        }
        else{
            break;
        }
        if(heap[index]>heap[smaller_one]) {
            int t = heap[smaller_one];
            heap[smaller_one] = heap[index];
            heap[index] = t;
            index = smaller_one;
        }
        else{
            break;
        }
    }
}

void heap_insert(int x) {
    heap[++size] = x;
    up(size);
}

int heap_pop() {
    int ans = heap[1];
    heap[1] = heap[size--];
    down(1);
    return ans;
}

void heap_init() {
    for(int i=1; i<=6; i++) {
        heap[++size] = 7-i;
    }
    for(int i=1; i<=size; i++) {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    for(int i=size/2; i>=1; i--) {
        down(i);
    }
}

int main() {
    heap_init();
    for(int i=1; i<=size; i++) {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    heap_insert(7);
    for(int i=1; i<=size; i++) {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    cout<<heap_pop()<<endl;
    cout<<heap_pop()<<endl;
}