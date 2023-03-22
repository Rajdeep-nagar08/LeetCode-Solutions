#define lln long long int
class Solution {
public:
    string subStrHash(string s, int p, int mod, int k, int hash) {
        
        
        vector<lln>power(k,1);
        
        for(int i=1;i<k;i++){
            power[i]=(power[i-1]*p)%mod;
        }
    
        
        reverse (s.begin(),s.end());

        int i=0;
        
        lln make=0;
        
        string ans;

        while(i<k){
make=(make%mod + ((s[i]-'a'+1)*power[k-1-i])%mod)%mod;
            i++;
        }
        
        if((make%mod) ==(hash))
            ans=s.substr(0,k);
    
        int j=0;
        
        while(i<s.length()){
            
 make=(make%mod-((s[j]-'a'+1)*power[k-1])%mod+mod)%mod;
            
            make=(make*p)%mod;
            
            make=(make%mod + (s[i]-'a'+1)%mod)%mod;
            
            j++;
        
            if((make%mod)==(hash))
                ans= s.substr(j,k);
            
            i++;
        }
            
      reverse (ans.begin(),ans.end());
        
        return ans;
    }
    
};