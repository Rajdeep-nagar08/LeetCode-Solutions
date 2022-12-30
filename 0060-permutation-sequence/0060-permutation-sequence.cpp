class Solution {
public:
    string getPermutation(int n, int k) {
        
        
        vector<int>fact(n+1);
                
        fact[1]=1;
        
        for(int i=2;i<=n;i++){
            fact[i]=fact[i-1]*i;
        }
    
         string str;
        
        for(int i=1;i<=n;i++){
            str.push_back(i+'0');
        }
               
        string ans;
        
        while(true){
       
             n=str.size();
            
            if(n==1)
                break;
            
            if(k>fact[n])
            {
                if(k%fact[n]==0)
                    k=fact[n];
                else
                k=k%fact[n];
            }

            int i=k/fact[n-1]+(k%fact[n-1]==0?0:1);
            
            i--;
                           
            ans.push_back(str[i]);
    
            string s;
            
            for(int i1=0;i1<n;i1++){
                if(i1!=i)
                    s.push_back(str[i1]);
            }
            
            str=s;
                        
        }
        
        ans.push_back(str[0]);
        
        
        return ans;
    }
    
};