/*

 sort all friends by incoming time
        
        clearly let current time = t1 (incoming time of ith friend)
        
        remove all friends from pq1 (min heap of {out time, seat occupied}) 
        
        whose outgoing time <= t1 as well as push there seat back to pq2 (min heap)
        
        give smallest empty seat to current friend
        
        */



class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar) {
       
        
        
        int n=times.size();
        
        
        int t=times[tar][0];
        
        
        sort(times.begin(),times.end());
      
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        
        // min heap {outtime, seatno}
        
        
        priority_queue<int,vector<int>,greater<int>>pq2;
        
        // min heap {empty seat}
        
    
        for(int t=0;t<=n;t++){
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