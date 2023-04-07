#define lln long long int

int mod=1e9+7;

lln dp[1001][1001];

class Solution {
public:
    unordered_set<char>st;
    
    int n;
    
    vector<int>v;  // i (non prime, prime)

    int beautifulPartitions(string s, int k, int minl) {
        
        n=s.size();
        
        st={'2','3','5','7'};
        
        if(st.count(s[0])!=1 || (st.count(s[n-1])==1))
            return 0;
        
        
        memset(dp,-1,sizeof(dp));
        
        v.push_back(-1);
        
        for(int i=1;i<n-1;i++){
            if((st.count(s[i])==0) && (st.count(s[i+1])==1))
                v.push_back(i);
        }
        
        v.push_back(n-1);  // last non prime

        
        return find(0,k,minl)%mod;
        
    }
    
    int find(int i, int k, int minl){
        
        if(i>=v.size()-1)
        {
                        
            if(k==0)
                return 1;
            
            return 0;
        }
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        lln count=0;
        
        for(int j=i+1;j<v.size();j++){
            
            if(v[j]-v[i]>=minl && (k>0)){
                count+=find(j,k-1,minl);
            }
            
        }
        
        
        return dp[i][k]=count%mod;
        
    }
};