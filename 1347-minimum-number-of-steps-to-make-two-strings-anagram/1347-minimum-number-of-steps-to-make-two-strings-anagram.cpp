class Solution {
public:
    
    int n,m;
    
    int minSteps(string s, string t) {
    
        n=s.size();
        
        m=t.size();
      
        unordered_map<char,int>mp1,mp2;
        
        for(int i=0;i<n;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        
        int cnt=0;
        
        for(auto it:mp1){
            if(mp2[it.first]>0){
               int x=it.second;
                
               int y=mp2[it.first];
                
               cnt+=min(x,y); 
            }
        }
        
        return n-cnt;
        
    }
};