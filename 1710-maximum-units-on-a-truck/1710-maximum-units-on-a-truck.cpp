class Solution {
public:
    int maximumUnits(vector<vector<int>>& bt, int sz) {
       sort(bt.begin(),bt.end(),[](vector<int>&v1,vector<int>&v2){
           return v1[1]>v2[1];
       });
        
        int i=0;
        
        int n=bt.size();
        
        int ans=0;
        
        while(i<n && sz>0){
            int c=bt[i][0];
            int pt=bt[i][1];
            
            if(sz>c){
                sz=sz-c;
                ans+=c*pt;
            }
            else{
                ans+=sz*pt;
                break;
            }
            
            i++;
        }
        
        return ans;
        
    }
};