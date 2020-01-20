#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll modi = 1000000007;
int arr[10001][2], n;

int solve(int i, int cap, int ass){
    if(i>=n){
        return 0;
    }
    //selecting cap
    ll cost, option2, option1;
    if(cap<n/2)
       option1 = arr[i][0] + solve(i+1, cap+1, ass);
    if(ass<n/2)
       option2 = arr[i][1] + solve(i+1, cap, ass);
    cost = min(option1, option2);
    return cost;
}

int main(){
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>arr[i][0]>>arr[i][0];
    }
    ll cost = 0;
    cout<<solve(0,0,0);
}
