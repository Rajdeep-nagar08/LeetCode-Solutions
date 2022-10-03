/*

time needs to remove the ith balloon = time[i]

min. time needs to make the rope colorful

No two consecutive ballon of same color


*/

class Solution {
public:
    int minCost(string col, vector<int>& time) {
      
        
        int n=col.size();
        
        int i=0;
        
        int ans=0;
        
        while(i<n){
            
            char ch=col[i];
            
            int mx=-1;
            
            int sum=0;
            
            int cnt=0;
            
            while(i<n && col[i]==ch){
                sum+=time[i];
                mx=max(mx,time[i]);
                cnt++;
                i++;
            }
            
            if(cnt>1){
                ans+=(sum-mx);
            }
        }
        
        
        return ans;
        
    }
};