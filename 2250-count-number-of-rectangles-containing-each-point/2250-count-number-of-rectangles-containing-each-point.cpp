class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rec, vector<vector<int>>& p) {
    
        // max height =100
        
        // store all the points that comes under this height
        
      vector<vector<int>>v(101);
        
        for(int i=0;i<rec.size();i++){
            
            int y=rec[i][1];
            
            int x=rec[i][0];
            
            v[y].push_back(x);
        }
        
        for(auto &it:v){
            sort(it.begin(),it.end());
        }
        
        
        vector<int>ans;
        
        for(int i=0;i<p.size();i++){
            
            int count=0;

            
            int x=p[i][0];
            
            int y=p[i][1];
            
            for(int j=y;j<=100;j++){
                
                int idx=lower_bound(v[j].begin(),v[j].end(),x)-v[j].begin();
                
                count+=v[j].size()-idx;
            }
            
            ans.push_back(count);
        }
        
        return ans;
    }
};