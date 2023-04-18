class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        
        int i=0,j=0;
        
        int n=w1.size();
        
        int m=w2.size();
        
        string ans="";
        
        while(i<n || j<m){
            if(i<n)
                ans.push_back(w1[i]);
            if(j<m)
                ans.push_back(w2[j]);
            
            i++,j++;
        }
        
        return ans;
        
    }
};