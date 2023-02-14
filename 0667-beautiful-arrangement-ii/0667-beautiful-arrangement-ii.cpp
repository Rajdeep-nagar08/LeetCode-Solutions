class Solution {
public:
    vector<int> constructArray(int n, int k) {
        
        vector<int>ans;
       
        int l=1;
        
        int d=l+k;
        
        int mx=-1;
        
        while(k>=0){
            ans.push_back(l);
            mx=max(mx,l);
            k--;
            n--;
            l++;
            
            if(k>=0){
                ans.push_back(d);
                mx=max(mx,d);
                n--;
                d--;
                k--;
            }
        }
        
        
        mx++;
        
                
        while(n>0){
            
            ans.push_back(mx);
            
            mx++;
            
            n--;
        }
        
        
        return ans;
    }
};