class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& qr) {
        
        vector<int>ans;
        
        for(auto it:qr){
            
            
            int a=it[0];
            
            int b=it[1];
            
            
                        int a1=a,b1=b;

            int par;
            
            while(a!=b){
                if(a>b)
                    a=a/2;
                else
                    b=b/2;
            }
            
            par=a;
            
           // cout<<par<<endl;
            
            int rp=log2(par+1);
                        
            if(pow(2,rp)!=par+1)
                rp++;
            
            int ra=log2(a1+1);
                        
            if(pow(2,ra)!=a1+1)
                ra++;
            
            int rb=log2(b1+1);
            
            if(pow(2,rb)!=b1+1)
                rb++;
            
          //  cout<<ra<<" "<<rb<<" "<<rp<<endl;
            
            ans.push_back(rb-rp+ra-rp+1);
            
        }
        
        
        
        return ans;
        
        
    }
};