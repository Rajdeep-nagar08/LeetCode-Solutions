#define lln long long int
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    
        vector<lln>indeg(n,0);
        
        for(auto it:roads){
           indeg[it[0]]++;
          indeg[it[1]]++;

        }
        
        sort(indeg.rbegin(),indeg.rend());
        
        lln p=n;
        
        lln ans=0;
        
        for(lln x:indeg){
            ans+=1ll*x*p;
            p--;
        }
        
        return ans;
        
    }
};