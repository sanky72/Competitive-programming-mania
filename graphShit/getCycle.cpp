#include<bits/stdc++.h>
int ver;
void countCycle(int **graph, bool visited[], int currNode, int start, int left, int &count){
    visited[currNode] = true;
    if(left == 0){
        visited[currNode] = false;
        if(graph[currNode][start])
            count++;
        return;
    }else{
        for(int i = 1; i<=ver; i++)
            if(graph[currNode][i] == 1 && visited[i] == false)
                countCycle(graph, visited, i, start, left -1, count);
    }
    visited[currNode] = false;
    return;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int checkCycle = 3;
    ver = n;
    int **graph = new int*[n+1];
    for(int i = 1; i<=n; i++){
        graph[i] = new int[n+1];
        for(int j = 1; j<=n; j++)
            graph[i][j] = 0;
    }
    for(int i = 0; i<m; i++){
        graph[u[i]][v[i]] = 1;
        graph[v[i]][u[i]] = 1;
    }
    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    int count = 0;
    for(int i = 1; i <= n - (3 - 1); i++){
        countCycle(graph, visited, i, i, checkCycle - 1, count);
        visited[i] = true;
    }
    return count/2;
}
