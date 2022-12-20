class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        

        int n=rooms.size();
        
        queue<int>q;
        
        vector<bool>vis(n,false);
        
        vis[0]=true;
        
        for(int x:rooms[0]){
            vis[x]=true;
            q.push(x);
        }
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front();
                q.pop();
                for(int y:rooms[x]){
                    if(vis[y]==false){
                        vis[y]=true;
                        q.push(y);
                    }
                }
            }
        }
        
        for(bool f:vis){
            if(f==false)
                return false;
        }
        
        return true;
        
    }
};