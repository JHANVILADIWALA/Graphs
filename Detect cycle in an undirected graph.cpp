https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

private:
    bool dfs(int node,int parent, int vis[], vector<int>adj[] ){
        //detect fn using DFS
       vis[node]=1;
       for(auto adjnode: adj[node]){
           if(!vis[adjnode]){
               if(dfs(adjnode,node,vis,adj)==true)return true;
           }
           //visited
           else if( parent!=adjnode ){
               return true;
           }
       }
       return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        //using DFS
        //assume graph has various components
        int n=V;
        int vis[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj )==true){
                    return true;
                }
            }
        }
        return false;
    }
