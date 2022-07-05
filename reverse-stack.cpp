/*题目描述
翻转栈的所有元素，例如输入栈 {1,2,3,4,5}，其中 1 处在栈顶，翻转之后的栈为 {5,4,3,2,1}，
其中，5 处在栈顶，注意使用递归*/
#include<stack>
#include<iostream>
using namespace std;
void push_to_end(int x, stack<int>& stk) {
    if(stk.size()==0) {
        stk.push(x);
        return;
    }
    int temp = stk.top();
    stk.pop();
    push_to_end(x, stk);
    stk.push(temp);
    return;
}
void reverse(stack<int>& stk) {
    if(stk.size()==1) return;
    int tmp = stk.top();
    stk.pop();
    reverse(stk);
    push_to_end(tmp, stk);
    return;
}
int main() {
    stack<int> stk;
    for(int i=101; i>=1; i-=2) {
        stk.push(i);
    }
    cout<<"stack init"<<endl;
    reverse(stk);
    cout<<"reverse done"<<endl;
    while(stk.size()!=0) {
        int tmp = stk.top();
        stk.pop();
        cout<<tmp<<" ";
    }
    return 0;
}