#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;



class Queue {
public:
    
    vector<int> v;
    int f, b;
    Queue(): v(5000) {
        // Implement the Constructor
        f = -1;
        b = -1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return f==b;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v[++b] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        return (f==b) ? -1 : v[++f];
    }

    int front() {
        // Implement the front() function
        
        return (f==b) ? -1 : v[f+1];
    }
};

int main(){
    
    FIO;
    

    return 0;
}