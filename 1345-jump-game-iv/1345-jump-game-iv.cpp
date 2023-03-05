/*
At each node , we have three paths to move, we need to find out the path through which we can reaches to last node in minimum steps, 
So From each node we can run bfs to all three paths and as soon as we reaches to last node we return the no of steps taken
*/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>>mp;
        int n=arr.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        
        int ans=0;
        
        queue<int>q;
        q.push(0);//index
        vis[0]=1;
        while(!q.empty()){
            
            int sz=q.size();
            
            while(sz--){
                
            int n1=q.front();
            q.pop();
            
            if(n1==n-1)
                return ans;
            
            if(n1-1 >=0 && vis[n1-1]==-1){
                if(n1-1==n-1)
                return ans+1;
                vis[n1-1]=1;
                q.push(n1-1);
            }
            if(n1+1<=n-1 && vis[n1+1]==-1){
                if(n1+1==n-1)
                return ans+1;
                vis[n1+1]=1;
                q.push(n1+1);
            }
            
                if(mp.count(arr[n1])>0){
            for(int &x:mp[arr[n1]]){
                if(vis[x]==-1 && x!=n1){
                    if(x==n-1)
                    return ans+1;
                    vis[x]=1;
                    q.push(x);
                }
              }
              mp.erase(arr[n1]);
                }
                
          }
            ans++;
        }
        
      return ans;
    }
};