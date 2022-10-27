
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        /*
        
        NOTE: needs to move all bits at a same time
        
        
        each 1 cell moves to 30*30 => 30*30*30 => check on 30*30
        
        T.C = 30*30*30*30*30 = > 27*9*10000 = 243*1e5 
        
        
        */
     
        
        vector<pair<int, int>>v1;
        vector<pair<int, int>>v2;
        
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img2.size(); j++){
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        
        int ans=0;
        
        map<pair<int, int>, int>m;
        
        for(auto i:v1){
            for(auto j:v2){
                int x=i.first-j.first;
                int y=i.second-j.second;
                m[{x,y}]++;
                ans=max(ans, m[{x,y}]);
            }
        }
        return ans;
        
    }
};