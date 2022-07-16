class Solution {
public:
    
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rC, int cC) {
      
        vector<vector<int>>v;
        
        int d;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                d=abs(i-rC)+abs(j-cC);
                vector<int>v1={d,i,j};
                v.push_back(v1);
            }
        }
        
         sort(v.begin(),v.end());
        
        vector<vector<int>>ans;
        
        for(auto it:v){
            ans.push_back({it[1],it[2]});
        }
        
        return ans;
        
    }
};