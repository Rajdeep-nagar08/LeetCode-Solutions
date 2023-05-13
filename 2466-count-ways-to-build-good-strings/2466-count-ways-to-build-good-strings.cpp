class Solution {
public:
    
   // unordered_map<i,unordered_map<string,int>>st;
    
    #define lln long long int
    
    int l,r;
    
    int mod=1e9+7;
    
   //  unordered_set<int>st;

    lln dp[300007];
    
    int countGoodStrings(int low, int high, int zero, int one) {
    
//         st.clear();
        
//         for(int i =0; i< 10 ; i++){
//             st.insert(i);
//         }

        dp[0]=1;
        
        for(int i=0;i<=high+10; i++){
            
            dp[i+zero]%=mod;
            
            dp[i+zero]+=dp[i];
            
             dp[i+one] %= mod;
            
             dp[i+one]+=dp[i];
            
        }
        
        long long ans = 0;

        for(int i=low; i<=high; i++){
            ans = (ans+dp[i])%mod;
        }

        return ans;
        
        
    }
    
};
    
    /*
        string str="";
        
        l=low;
        
        r=high;
        
        find(0,zero,one,str);
        
        return st.size();
        
        
    }
    
    void find(int i,int z,int o,string &str){
        
        if(str.size()>r)
            return;
        
        if(str.size()>=l && str.size()<=r)
            st.insert(str);
        
        
        
        string s1=str;
        
        for(int j=0;j<z;j++){
            s1+="0";
        }
        
        find(i+z,z,o,s1);
        
         string s2=str;
        
        for(int j=0;j<o;j++){
            s2+="1";
        }
        
        find(i+z,z,o,s2);
        
        
    }
};

*/