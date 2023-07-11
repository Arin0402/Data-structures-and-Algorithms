// Or Number of connected components in an undirected graph.

#include <bits/stdc++.h>
using namespace std;

// steps
// 1 -> create adj list
// 2 -> apply dfs on the components
// 3 -> count the components

class Solution1
{
public:
    vector<int>* createList(vector<vector<int>> &adj,int V){
        
        vector<int> *list = new vector<int>[V];
        
        for(int i = 0 ; i < V; i++ ){
            
            for(int j = 0 ; j < V; j++){
                
                if(adj[i][j] == 1 && i != j){
                    list[i].push_back(j);                    
                }
            }
        }
        
        return list;
        
    }
    
    void dfs(int i, vector<int> list[] ,vector<int> &visited, int V ){
        
        visited[i] = true;
        
        for(auto ele : list[i]){
            
            if(visited[ele] == false) dfs(ele, list, visited, V);
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        
        
        vector<int> visited(V, false );
        
        int ans = 0;
        
        vector<int> *list = createList(adj, V);
        
        for(int i = 0 ;i < V; i++){
            
            ans += !visited[i] ? dfs(i, list, visited, V), 1: 0;
        }
        
        return ans;
    }
};

// direct solve
class Solution2
{
public:
    void dfs(int i, vector<vector<int>> &M, vector<bool> &visited)
    {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++)
            if (i != j && M[i][j] == 1 && visited[j] == 0)
                dfs(j, M, visited);
    }

    int numProvinces(vector<vector<int>> adj, int V)
    {

        if (adj.empty())
            return 0;

        int n = adj.size();

        vector<bool> visited(n, false);

        int ans = 0;
        for (int i = 0; i < n; i++)
        {

            ans += !visited[i] ? dfs(i, adj, visited), 1 : 0;
        }

        return ans;
    }
};