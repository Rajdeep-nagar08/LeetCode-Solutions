
        /*

should start moving from nodes having indegree =0
        
we cannot complete a course if atleast one of its predecessor course is incomplete


1(t=1) -> 2(t=10) -> 5(t=1)
                      ^
                      |
          3(t=100) -> 4(t=1)
          

First approach in mind, first complete 1 and 3 in time =100, than complete 2 and 4 in time=10 than complete 5 in time =1


Ans= max(1,100)+max(10,1)+1 = 100+10+1=111

But, this approach is wrong as we can complete them in lesser time if

we start completing 1 and 3 and as soon as 1 completed in time=1 we start doing 2 and parallely 3 is completing as it takes more time to complete

after completion of 2 we we wait for task 3 and 4 to be completed to complete task 5

task 3, 4 completed in time=101

than task 5 complted at time =102

so all task completed in time = 102 (minimum possible time)


Approach:

minTime[i] = minimum time to visit node i

Note that node is assumed to be visited in orignal sence when all its predecessors got visited

so let assume predecessors of node i are 1,2,3

let time to visit i via 1 = 4

time to visit i via 2 = 2

time to visit i via 3 = 7

clearly, all predecessors of node i got completed at  max(4,2,7)

so minimum time to complete node i = max(4,2,7)+t[i]

or minTime[i] = max(4,2,7)+t[i]

So as soon as we visit y via any node x, we update minTime[y] = max(minTime[y],minTime[x]+time[y])


Min time to visit all nodes = max(time[nodes])

*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& t) {
        
        vector<int>g[n];
        
        vector<int>indeg(n,0);
        
                
        for(auto it:rel){
            g[it[0]-1].push_back(it[1]-1);
            indeg[it[1]-1]++;
        }
        
        queue<int>q;
        
        vector<int>time(n);

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                time[i]=t[i];
            }
        }
                
        while(!q.empty()){
            
            int sz=q.size();
                        
            while(sz--){
                
                int x=q.front();
       
                q.pop();
                
                for(int y:g[x]){
                    
                    time[y]=max(time[y],time[x]+t[y]);
                    
                    indeg[y]--;
                    
                    if(indeg[y]==0)
                        q.push(y);
                    
                }
                
            }
                        
        }

        return *max_element(time.begin(),time.end());
        
    }
};