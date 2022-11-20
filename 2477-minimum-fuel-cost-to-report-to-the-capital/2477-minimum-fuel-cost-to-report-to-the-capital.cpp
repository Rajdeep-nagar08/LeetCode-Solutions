class Solution {
public:
     vector<vector<int>>adj;
	int par[100001];
	int child[100001];
	long long representatives[100001];
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
               
        int n = roads.size();
		adj.resize(n+1,vector<int>());
		// build the graph
		for(auto&e:roads){
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		//Run a dfs to find parent node and children count
		dfs(0,0);

		queue<int>q;
		//push all the leaves into queue.
		for(int i=0;i<=n;i++)
			if(child[i]==0)q.push(i);

		long long ans = 0;

		while(q.size()){
			auto u = q.front();
			q.pop();
			if(u==0)break;
			long long cars_needed = (representatives[u]+seats-1)/seats;
			ans+= cars_needed;
			//push all the representatives of u to parent u.
			representatives[par[u]]+=representatives[u];
			// remove node u from the graph.
			child[par[u]]--;
			//if current node has no child left it is a new leaf.
			if(child[par[u]]==0)q.push(par[u]);
		}
		return ans;
 
    }
    
   
	void dfs(int u,int p){
		child[u] = 0;
		representatives[u] = 1;
		for(int v:adj[u]){
			if(v!=p){
				par[v] = u;
				child[u]++;
				dfs(v,u);
			}
		}
	}
};