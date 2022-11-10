#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


// TC : O(n)
// SC : O(2n)

class Queue {
public:
    stack<int> s1, s2;
    Queue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int t=s1.top();
        s1.pop();
        return t;
    }
    
    int top() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};


int main(){
    
    FIO;
    

    return 0;
}