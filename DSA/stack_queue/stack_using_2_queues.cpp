#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


class Stack {
    queue<int> q[2];
    int c;
   
public:
    
    Stack() {
        c=0;
    }


    int getSize() {
        return q[c].size();
    }

    bool isEmpty() {
        return q[c].empty();
    }

    void push(int e) {
        q[1-c].push(e);
        while(!q[c].empty()){
            q[1-c].push(q[c].front());
            q[c].pop();
        }
        c = 1-c;
    }

    int pop() {
        if(q[c].empty()) return -1;
        int t = q[c].front();
        q[c].pop();
        return t;
    }

    int top() {
        return q[c].empty() ? -1 : q[c].front();
    }
};


int main(){
  
  FIO;
  Stack S;
  S.push(1);
  S.push(2);
  S.push(3);
  cout<<S.top();
  S.pop();
  cout<<S.top();
  cout<<S.getSize();

  return 0;
}
