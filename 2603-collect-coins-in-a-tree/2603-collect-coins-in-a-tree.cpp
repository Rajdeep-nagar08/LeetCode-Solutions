/*
All leaves that do not have a coin are redundant and can be deleted from the tree.


Remove the leaves that do not have coins on them, so that the resulting tree will have a coin on every leaf.


In the remaining tree, remove each leaf node and its parent from the tree. The remaining nodes in the tree are the ones that must be visited. Hence, the answer is equal to (# remaining nodes -1) * 2

*/




class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        
        
        int n=coins.size();
        
        vector<int>deg(n,0);
        
        vector<int>g[n];
        
        for(auto it:edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);  
            deg[it[0]]++;
            deg[it[1]]++;
        }
        
        // cout<<deg[1]<<endl;
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(deg[i]==1 && coins[i]==0){
                q.push(i);
        }
    }
        
        
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                for(int y:g[x]){
                    if(deg[y]>0){
                        deg[x]--;
                        deg[y]--;
                        if(deg[y]==1 && coins[y]==0)
                        q.push(y);
                    }
                }
            }
        }
        
        // cout<<deg[1]<<endl;
        
        vector<bool>vis(n,false);
            
            
            for(int i=0;i<n;i++){
                if(deg[i]==1 && coins[i]==1 && vis[i]==false){
                    deg[i]--;
                    vis[i]=true;
                    for(int y:g[i]){
                        if(deg[y]>0){
                            vis[y]=true;
                            deg[y]--;
                        }
                    }
                    
                }
            }
            
            
            int count=0;
        
//         for(int i=0;i<n;i++){
//             cout<<i<<" "<<deg[i]<<endl;
//         }
            
            for(int i=0;i<n;i++){
                if(deg[i]>1)
                    count++;
            }
            
            
            
            return max(0,(count-1)*2);
            
            
    }
};