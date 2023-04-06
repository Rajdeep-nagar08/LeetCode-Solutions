class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
      

        int n=s.size();
        
        vector<vector<int>>v;
        
        int i=0;
        
        while(i<n){
            
            int i1=i;
            
            i++;
            
            while(i<n && (s[i]==s[i1]))
                i++;
            
            int i2=i-1;
            
            if(i2-i1+1>=3){
                v.push_back({i1,i2});
            }
        }
        
        sort(v.begin(),v.end());
        
        return v;
        
    }
};