
class Solution {
public:
    int minimumTimeToInitialState(string& w, int k) {

        int n = w.length();
        
        
// we just need to find a position k * res, where it matches at least n - k * res first characters of the string.        

     vector<int>z(n,0);  // z function
        
         // z[i]= longest substring of string s , starting from ith index that matches with the prefix of s

     int l=0,r=0;

     int i=1;

     while(i<n){
     if(i<=r)
     z[i]=min(r-i+1,z[i-l]);

     while(w[z[i]]==w[z[i]+i] && z[i]+i <n){
       z[i]++;
     }

     if(z[i]+i-1 > r){
       l=i;
       r=z[i]+i-1;
     }
     i++;
     }

        

        for (int i = 1; i <=n ; ++i) {
            
            long long m = 1ll*i * k;
            
            
            int left= n-m;
            
                if(m>=n)
                continue;

            bool flag = true;

            
            int l=z[m];
            
            if(l>=left)
                return i;
            
        }

        if(n%k==0)
            return n/k;
        
        return (n/k)+1;
    }
    
    

    
};
