int dx[4]={1,-1,0,0};

int dy[4]={0,0,1,-1};

#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q1) {
        
        int n=grid.size();
        
        int m=grid[0].size();
        
       vector<pair<int,int>>v;
        
        vector<int>ans(q1.size());
        
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        for(int i=0;i<q1.size();i++){
            v.push_back({q1[i],i});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        
        int cnt=0;
      
        pq.push({grid[0][0],{0,0}});
        
        vis[0][0]=true;
        
        for(auto it:v){
            
            int val=it.first;
            
            int idx=it.second;
              
            while(pq.size()>0){
                
                    int no=pq.top().first;
                
                    int x=pq.top().second.first;
                    
                    int y=pq.top().second.second;
                    
                if(no>=val)
                    break;
                
                    pq.pop();
                    
                    cnt++;
                
                    for(int i=0;i<4;i++){
                        
                        int x1=x+dx[i];
                        
                        int y1=y+dy[i];
                        
        if(x1>=0 && y1>=0 && x1<n && y1<m && vis[x1][y1]==false){
          
            vis[x1][y1]=true;
            
            pq.push({grid[x1][y1],{x1,y1}});
        }
                    
    }
                
          
}
            
            ans[idx]=cnt;
           
        }
        
        return ans;
    }
};