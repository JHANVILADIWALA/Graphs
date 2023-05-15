https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

private:
   bool check(int start,int n,vector<int>adj[],int color[]){
        queue<int>q;
	    q.push(start);
	    
	    color[start]=0;
	    while(!q.empty()){
	         int node=q.front();
	         q.pop();
	         //neighbours
	         for(auto it:adj[node]){
	             if(color[it]==-1){//adj node is not colored
	                 //give opp color of node
	                 color[it]=!color[node];
	                 q.push(it);
	             }
	             else if(color[it]==color[node]){//violates
	                 return false;
	             }
	         }
	    }
	    return true;
	    
   }
public:
	bool isBipartite(int n, vector<int>adj[]){
	    //bipartite: graph colored with 2 clrs st no 2 adj have same
	    //even cycle or tree --> bipartite
	    //odd cycle--->never bipartite
	    //vis--->clr matrix => -1= not clred
	    
	    //BFS
	    int color[n];
	    for(int i=0;i<n;i++)color[i]=-1;
	   for(int i=0;i<n;i++){
	       if(color[i]==-1){//not colored
	         if(check(i,n,adj,color)==false)return false;
	       }
	   }
	   return true;
	}
