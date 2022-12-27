class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rk, int add) {
        
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        
        int n=cap.size();
        
        
        for(int i=0;i<n;i++){
          pq.push(cap[i]-rk[i]);
        }
        
        
        int count=0;
        
        while(add>0 && pq.size()>0){
      
            int x=pq.top();
            pq.pop();
        
            
            if(x<=add){
               add=add-x;
               count++;
            }
            else
                break;
        
        }
        
        return count;
        
    }
};