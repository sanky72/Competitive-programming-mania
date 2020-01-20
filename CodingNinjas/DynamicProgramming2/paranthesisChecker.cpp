#include<bits/stdc++.h>
using namespace std;
int main(){
  stack<char> sandas;
  string s;
  cin>>s;
  int flag = 0;
  for(int i = 0; i<s.size(); i++){
    if(s[i] == '[' || s[i] == '}' || s[i] == ')' ){
        sandas.push(s[i]);
    }
    else{
        if(s[i] == ']' ){
            if(sandas.top() == '['){
                sandas.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
         if(s[i] == '}' ){
            if(sandas.top() == '{'){
                sandas.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
        if(s[i] == ')' ){
            if(sandas.top() == '('){
                sandas.pop();
            }
            else{
                flag = 1;
                break;
            }
        }
    }
  }
  if(s.empty() == 0){
    if(flag == 1){

    }
  }

}
