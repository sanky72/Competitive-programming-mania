/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int T;
    cin>>T;
    while(T--){
        ll n, k;
        cin>>n>>k;
        char arr[n][k];
        vector<set<ll> > vec(n);
        int flag = 0; bool flag2 = true;
        for(int i = 0; i<n; i++){
            for(ll j = 0; j<k; j++){
                cin>>arr[i][j];
                if(arr[i][j] == 'M'){
                    vec[i].insert(j);
                    flag = 1;
                }
            }
            if(flag == 0){
                flag2 = false;
            }
            flag == 0;
        }
        if(flag2 == false)cout<<-1<<endl;
        else{
        ll minMoves = INT_MAX, nowMoves = 0;
        for(int col = 0; col<k; col++){
            nowMoves = 0; ll r, l;
            //cout<<"the col is "<<col<<endl;
           for(int row = 0; row<n; row++){
              // cout<<"the row is "<<row<<endl;
               set<ll>::iterator it = vec[row].lower_bound(col);
               //cout<<"the it value is "<<*it<<endl;
               if(*it == col){
                 //   cout<<"im at 1"<<endl;
                r = 0;
                l = 0;
               }
               else if( it == vec[row].end()){
                   //cout<<"at 2"<<endl;
                 r = *(--it);
                 l = *(vec[row].begin());
                 r = col - r;
                 l = l - 0 + (k - col);
               }
               else if( it == vec[row].begin()){
                   //cout<<"at 3"<<endl;
                l = *(vec[row].begin());
                r = *(vec[row].end()--);
                r = k-1 - r + col+1;
               }
               else{
                  // cout<<"at 4"<<endl;
                l = *it;
                l = l - col;
                r = *(--it);
                //cout<<"the value of r is "<<r<<endl;
                r = col - r;
               }
               //cout<<"the l and r are "<<r<<" "<<l<<endl;
               nowMoves += min(l, r);
               //cout<<"the newmoves is "<<nowMoves<<endl;
           }
           minMoves = min(nowMoves, minMoves);
           //cout<<endl;
           //cout<<endl;
        }
        cout<<minMoves<<endl;
    }
    }
}
