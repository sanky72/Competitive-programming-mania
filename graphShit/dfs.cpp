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

void dfs(int **edges, int n, bool *visited, int curr){
    //cout<<curr<<endl;
    visited[curr] = true;
    for(int i = 0; i<n; i++){
        if(edges[curr][i] == 1 && visited[i] == false)
            dfs(edges, n, visited, i);
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

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(edges, n, visited, i);
        }
    }
    return 0;
}
