
int mod=1e9+7;

#define lln long long int

class Solution {
public:
    int numWays(string s) {
        
        int n=s.size();
        
        int ones=0;
        
        for(char ch:s){
            if(ch=='1')
                ones++;
        }
        
        if(ones==0){
            lln x=1ll*(n-1)*(n-2);
            x=x/2;
            
            return x%mod;
        }
        
        if(ones%3!=0)
            return 0;
        
        
        lln c1=0,c2=0;
        
        ones=ones/3;
        
        int o=0;
        
        int i=0;
        
        while(i<n && o!=ones){
            if(s[i]=='1')
                o++;
            
            i++;
        }
        
        while(i<n && s[i]!='1'){
            i++;
            c1++;
        }
        
   o=0;
        
        while(i<n && o!=ones){
            if(s[i]=='1')
                o++;
            i++;
        }
        
        while(i<n && s[i]!='1'){
            i++;
            c2++;
        }
        
        
        // cout<<c1<<" "<<c2<<endl;
        
        // if(c1 && c2)
            return 1ll*(c1+1)*(c2+1)%mod;
        
//         if(c1)
//             return 1ll*(c1+1)%mod;
        
        
//         return 1ll*(c2+1)%mod;
        
        
        
    }
};