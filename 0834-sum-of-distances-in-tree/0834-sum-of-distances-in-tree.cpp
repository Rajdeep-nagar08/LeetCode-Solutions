class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        
        /*
        
        dist[x] = distance of x from all other nodes
        =
        distance of x from nodes under x + disance of x from nodes not under x
        
        =
        
        Sigma(1+dist[childrens of x]) + 
        
        */
        
        vector<int>g[n];
        
        for(auto it:e){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        
        vector<int>nodes(n,0);  // nodes[x]= no of nodes under x
        vector<int>ans1(n,0);  // ans1[x]= sum of distances of all nodes under x from x, clearly for x---->y, ans1[x]=nodes[y]+ans1[y]
        
        vector<int>ans2(n,0);  // ans2[x]=sum of diastances of all nodes from x = ans1[x]+(sum of distances of all nodes that are not under x from x + (n-nodes[x])) = ans1[x]+(partial ans for x + (n-nodes[x]))
        
        // note : partial ans for root node=0
        
    //Now for x----->y , partial ans for y=sum of distances of all nodes that are not under y from node y= ans2[x]-(ans1[x]+nodes[y])
        
        
        dfs1(0,-1,g,nodes);
        dfs2(0,-1,g,nodes,ans1);
        dfs3(0,-1,0,g,nodes,ans1,ans2);
        
        return ans2;
        
    }
    
    void dfs1(int x,int par,vector<int>g[],vector<int>&nodes){
      
        int count=1;
        
        for(int y:g[x]){
            if(y!=par){
              dfs1(y,x,g,nodes);
              count+=(nodes[y]);
            }
        }
        nodes[x]=count; 
    } 
    
    void dfs2(int x,int par,vector<int>g[],vector<int>&nodes,vector<int>&ans1){
      
        int d1=0;
        
        for(int y:g[x]){
            if(y!=par){
              dfs2(y,x,g,nodes,ans1);
              d1+=(nodes[y]+ans1[y]);
            }
        }
        ans1[x]=d1; 
    } 
    
    
    void dfs3(int x,int par,int partial_ans,vector<int>g[],vector<int>&nodes,vector<int>&ans1,vector<int>&ans2){
      
    ans2[x]=ans1[x] + (partial_ans+((int)ans2.size()-nodes[x]));
        
        for(int y:g[x]){
            if(y!=par){
              dfs3(y,x,ans2[x]-ans1[y]-nodes[y],g,nodes,ans1,ans2);
            }
        }
    } 
};