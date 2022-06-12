


class Solution {
public:
    int n1;
    
    int mn1=INT_MAX;
    
    int distributeCookies(vector<int>& coo, int k) {
        
        
        n1=coo.size();
        
        
        vector<vector<int>>ans(k);
        
        
        solve(0,k,ans,k,coo);
        
        return mn1;
        
    }
    
    void solve(int i,int k,vector<vector<int>>&Myans,int k1,vector<int>&coo){
        
        if(i>=n1){
            
            if(k1>0)
                return;
            
            int mx1=INT_MIN;
            
             for(int j=0;j<k;j++){
                 
                 
                 vector<int>v1=Myans[j];
                 
                
                 int total=0;
                 
                  
                 if(v1.size()==0)
                     return;
                 
                 
                 for(int x:v1){
                     total+=x;
                 }
                 mx1=max(mx1,total);
             }
            
            mn1=min(mn1,mx1);
            
            return;
            
        }
        
        for(int j=0;j<k;j++){
            
            bool flag=false;
            
            if(Myans[j].size()==0){
                k1--;
                flag=true;
            }
            
            Myans[j].push_back(coo[i]);
         
            solve(i+1,k,Myans,k1,coo);
            
            
            if(flag==true)
                k1++;
                
            
          Myans[j].pop_back();
            
            
        }
        
        
    }
    

   
};

