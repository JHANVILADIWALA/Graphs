https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

private:
    bool dfs( int node,int col,int color[] , vector<int>adj[]){
        color[node]=col;
        
        //neighbours
        for(auto it : adj[node] ){
            if(color[it]==color[node]){ //same color
                return false;
            }
            else if(color[it]==-1){
                //not colored =>color it with opp color
               if( dfs(it, !color[node], color,adj)==false)return false;
            }
        }
        return true;
        
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	     //dfs
	     //tc  O( V+2E )
	     //sc  O (V)
	     int color[V];
	     for(int i=0;i<V;i++)color[i]=-1;
	     for(int i=0;i<V;i++){
	         if(color[i]==-1){
	             //not colored
	             if( dfs( i,0,color,adj) ==false )return false;
	         }
	     }
	     return true;
	}
