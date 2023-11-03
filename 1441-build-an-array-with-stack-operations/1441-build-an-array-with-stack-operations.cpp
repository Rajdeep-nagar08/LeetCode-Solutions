class Solution {
public:
    
    vector<string> buildArray(vector<int>& tar, int n) {
      
      // [1,n]
        
        
        // target is strictly increasing
        
        // needs to make stack== target
        
        vector<string>ans;
        
       // if any no. not present in tar, ("push","pop") for it
        
        // if any no. present in target, "push" for it
        
       // [3,4,6,7]
        
        // [push,pop,push,pop,push,push,push,pop,push,push]
        
        int start=1;
        
        for(int i=0;i<tar.size();){
            if(start==tar[i]){
                ans.push_back("Push");
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            start++;
        }
        return ans;
    }
};