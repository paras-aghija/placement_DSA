#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for(char c : s){
            if(c=='(' or c=='{' or c=='[') v.push(c);
            else{
                if(v.empty()) return 0;
                if(c==')'){
                    if(v.top()=='(') v.pop();
                    else return 0;
                }
                else if(c=='}'){
                    if(v.top()=='{') v.pop();
                    else return 0;
                }
                else if(c==']'){
                    if(v.top()=='[') v.pop();
                    else return 0;
                }
            }
        }
        return v.empty();
    }
};



int main(){
    
    FIO;
    

    return 0;
}