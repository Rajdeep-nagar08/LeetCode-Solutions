#define lln long long int

class Solution {
public:
    
    vector<vector<int>> findPrimePairs(int n) {
        
        
        vector<lln>Prime(n+1,1);

        sieve(Prime,n);
        
       vector<vector<int>>ans;        
                
        for(int i=0;i<=n/2;i++){
            if(Prime[i] && Prime[n-i]){
                vector<int>v1={i,n-i};
                ans.push_back(v1);
            }
        }
    
               
               sort(ans.begin(),ans.end());
               
               return ans;
    }
    
    
    

void sieve(vector<lln>&Prime,int n){
Prime[0]=Prime[1]=0;  // not prime
for(lln i=2;i*i<=n;i++){
if(Prime[i]==1)
{
for(int j=i*i;j<=n;j+=i)
    Prime[j]=0;
}}}

    
    
};