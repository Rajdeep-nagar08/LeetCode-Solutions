

#define pp pair<pair<int,int>,int>

#define p pair<int,int>

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        //  {free time, weight, server no}  ===> min heap
        priority_queue<pp,vector<pp>, greater<pp>>pq_busy;
        
        
        // {weight, server no}  ====> min heap
        priority_queue<p, vector<p>, greater<p>>pq_free;
        
        
        vector<int>ans(tasks.size());
        
        for(int i=0;i<servers.size();i++){
            
        pq_free.push({servers[i],i});
            
        }
        
        
        int t=0;
        
        int count=0;
        
        for(int i=0;i<tasks.size();i++){
            
            
             // making all servers free whose finshing time <=t (current time)
                
                while(pq_busy.size()>0 and pq_busy.top().first.first<=t){
                    pp pp1= pq_busy.top();
                    pq_busy.pop();
                    pq_free.push({pp1.first.second,pp1.second});
                }
                
            
            
            if(pq_free.size()==0){  
                
        // no free server, all servers are busy, so we needs to wait till any busy server that become free as soon as possible (minimum free time) and change 't' accordingly
                
                  pp pp1= pq_busy.top();
                            
                
                  int t1=pq_busy.top().first.first;
                
                // If multiple servers become free at the same time, then multiple tasks from the queue will be assigned.
                
                  count+= t1-t;
                      
                // current time becomes to the free time of this server
                      
                   t= t1;

                // free all servers whose finish time ==t
                   while(pq_busy.size()>0 and pq_busy.top().first.first==t){
                    pp pp1= pq_busy.top();
                    pq_busy.pop();
                    pq_free.push({pp1.first.second,pp1.second});
                   }
                
                 
                // getting minimum weight free server
                
                p p1=pq_free.top();
                
                pq_free.pop();
                
                int wht=p1.first;

                int idx=p1.second;
                
                int finish_time=t+tasks[i];
                
                ans[i]=idx;
                
                // making it busy
                pq_busy.push({{finish_time,wht},idx});
                   
                
            }
            
            else {
                
                // getting minimum weight free server
                
                p p1=pq_free.top();
                
                pq_free.pop();
                
                int wht=p1.first;

                int idx=p1.second;
                
                int finish_time=t+tasks[i];
                
                ans[i]=idx;
                
                // making it busy
                pq_busy.push({{finish_time,wht},idx});
                
            
            }
            
            if(count>0)
                count--;
            else
                t++;
            
              
        }
        
        return ans;
        
    }
};