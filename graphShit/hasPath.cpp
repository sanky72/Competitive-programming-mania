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

void bfs(int ** edges, int n, bool * visited, queue<int> q)
{
    while(!q.empty())
    {
        int x = q.front();
        visited[x] = true;
        //cout << x << " ";
        q.pop();
        for(int i = 0; i < n; i++)
        {
            if(edges[x][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
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
    queue<int> q;
    int val1, val2, flag = 0;
    cin>>val1>>val2;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            q.push(i);
            bfs(edges, n, visited, q);
            q.pop();
        }
        if(visited[val1]){
            if(visited[val2]){
                flag = 1;
                break;
            }
            else{
                break;
            }
        }
        else{
            if(visited[val2]){
                break;
            }
            else{
                continue;
            }
        }
    }
    if(flag)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}

