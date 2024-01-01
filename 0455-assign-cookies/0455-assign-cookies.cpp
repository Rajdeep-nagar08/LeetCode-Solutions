class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
     
        
        sort(g.begin(),g.end());
        
                sort(s.begin(),s.end());
        
        
        int i=0;
        
        int j=0;
        
        
        int ans=0;
        
        while(i<g.size()){
            
            while(j<s.size()){
                
                if(s[j]>=g[i]){
                    ans++;
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
return ans;
        
    }
};