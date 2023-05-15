https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

private:
    bool detect(int src, int vis[], vector<int>adj[] ){
        //detect fn using BFS
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjnode: adj[node]){
                if(!vis[adjnode]){
                    vis[adjnode]=1;
                    q.push({adjnode,node});
                }
                //else visited
                //check ki parent different or same
                else if(parent!=adjnode){
                    //cycle exists
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        //using BFS
        //assume graph has various components
        int n=V;
        int vis[n]={0};
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detect( i,vis,adj )==true){
                    return true;
                }
            }
        }
        return false;
    }
