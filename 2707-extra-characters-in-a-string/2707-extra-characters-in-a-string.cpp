//  dp[i] = min no of chars left if fixing strings of [i...n-1]


int dp[51];

unordered_map<string,int>mp;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        
         mp.clear();
        
        memset(dp,-1,sizeof(dp));
        
        
        for(string str:dict){
            mp[str]++;
        }
        
        return find(0, s);
        
    }
    
    
    int find(int i, string&str){
        if(i>=str.size())
            return 0;
        
        string s="";
        
        int mn=100;
        
        if(dp[i]!=-1)
            return dp[i];
        
        for(int j=i;j<str.size();j++){
            s+=str[j];
            
            int count=0;
            
            if(mp.count(s)!=1){
                count=s.size();
            }
            
            int next=find(j+1,str);
            
            count+=next;
            
            mn=min(mn,count);
            
        }
        
        return dp[i]=mn;
    }
};