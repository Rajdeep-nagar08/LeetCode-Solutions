class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& pnt) {
        
        int n=pnt.size();
        
        sort(pnt.begin(),pnt.end());
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            if(v.size()==0){
                v.push_back({pnt[i][0],pnt[i][1]});
            }
            else{
                 int sz=v.size();
                    sz--;
                
                int x=v[sz].first;
                int y=v[sz].second;
                
                int y1=pnt[i][0];
                int x1=pnt[i][1];
                
                if(y<y1)
                   v.push_back({pnt[i][0],pnt[i][1]});
                else{
                
                    v[sz]={max(x,y1),min(y,x1)};
                }

            }
        }
        
        return v.size();
    }
};