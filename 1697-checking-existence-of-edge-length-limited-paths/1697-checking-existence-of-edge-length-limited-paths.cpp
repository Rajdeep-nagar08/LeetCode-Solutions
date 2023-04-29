vector <int> parent(100005,-1);
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        for(int i = 0; i<=n; i++) parent[i] = i;
        
		// Sorting the edges array based on dist of each pair of node. 
        sort(edges.begin(),edges.end(),[](vector<int>&a, vector<int>&b){
            if(a[2]<b[2]) return true;
            return false;
        });

		// We will need the indices of query elements coz after sorting, the order will change. 
		// So we push the index in the same element vector of query.
        for(int i = 0; i<queries.size(); i++) queries[i].push_back(i);
			
		// Sorting queries based on limits. 
        sort(queries.begin(),queries.end(),[](vector<int>&a,vector<int>&b){
            if(a[2]<b[2]) return true;
            return false;
        });
        
        vector <bool> ans(queries.size(),false);
        int idx = 0;
        for(int i = 0; i<queries.size(); i++){
            // Here we loop on edges vector and join the two nodes having dist < curr_limit.
			while(idx<edges.size() and edges[idx][2]<queries[i][2]){
                join(edges[idx][0],edges[idx][1]);
                idx++;
            }
			// If the two nodes of current query has same godfather, we set this queries ans as true
            if(find(parent[queries[i][0]]) == find(parent[queries[i][1]])) ans[queries[i][3]] = true;
        }
        return ans;
    }
protected:
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void join(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a!=b) parent[b] = a;
    }
};