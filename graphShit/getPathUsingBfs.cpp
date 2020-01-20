#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i <= (b); i++)
ll modi = 1000000007;
int val1, val2;
vector<int> bfs(int ** edges, int n, bool * visited, queue<int> q)
{
    map<int, int> mp;
    bool done = false;
    while(!q.empty() && !done)
    {
        int x = q.front();
        visited[x] = true;
        q.pop();
        if(x == val2){
           mp[val2] = x;
           break;
        }
        for(int i = 0; i < n; i++)
        {
            if(edges[x][i] == 1 && visited[i] == false)
            {
                if(i == val2){
                    mp[val2] = x;
                    done = true;
                    break;
                }

                q.push(i);
                visited[i] = true;
                mp[i] = x;

            }
        }
    }
    if(!done){
      vector<int> vec;
      return vec;
    }
    else{
        int current  = val2;
        vector<int> vec;
        vec.pb(val2);
        while(current != val1){
              current = mp[current];
              vec.pb(current);
        }
        return vec;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, e;
    cin >> n >> e;
    int ** edges = new int *[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    cin>>val1>>val2;
    queue<int> q;
    q.push(val1);
    vector<int> vec;
    vec = bfs(edges, n, visited, q);
    if(vec.empty()){
    }
    else{
        for(int i = 0; i<vec.size(); i++){
            cout<<vec[i]<<" ";
        }
    }


    return 0;
}
