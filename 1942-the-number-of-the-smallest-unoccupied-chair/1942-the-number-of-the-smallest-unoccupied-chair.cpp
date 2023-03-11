class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar) {
       
        
        
        int n=times.size();
        
        
        int t=times[tar][0];
        
        
        sort(times.begin(),times.end());
        
        // for(auto it:times){
        //     cout<<"("<<it[0]<<" "<<it[1]<<")";
        // }
        
        
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        
        priority_queue<int,vector<int>,greater<int>>pq2;
        
        
        for(int t=0;t<=1e6;t++){
            pq2.push(t);
        }
        
        
        for(int i=0;i<n;i++){
           
            int inc=times[i][0];
            
            int out=times[i][1];
            
            while(pq1.size()>0 && pq1.top().first<=inc){
             
                    pq2.push(pq1.top().second);

                    pq1.pop();
                
                
            }
            
              
            if(times[i][0]==t)
                return pq2.top();
            
            
            pq1.push({out,pq2.top()});
            
            pq2.pop();
            
           
            
            
        }
        
        
        
        return -1;
        
        
    }
};