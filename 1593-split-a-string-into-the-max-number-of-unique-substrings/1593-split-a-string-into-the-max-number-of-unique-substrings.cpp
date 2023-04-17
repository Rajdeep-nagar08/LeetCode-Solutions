class Solution {
public:
    
    int n;
    
    unordered_map<string,int>mp;
    
    int ans=0;
    
    int maxUniqueSplit(string s) {
        
        
        n=s.size();
        
        
        find(0,s,0);
        
        return ans;
        
    }
    
    void find(int i,string &str,int cnt){
        if(i>=n){
            ans=max(ans,cnt);
            return;
        }
        
        string s="";
        
        for(int j=i;j<n;j++){
            s.push_back(str[j]);
            if(mp[s]==0){
                mp[s]++;
                find(j+1,str,cnt+1);
                mp[s]--;
            }
        }
    }
};