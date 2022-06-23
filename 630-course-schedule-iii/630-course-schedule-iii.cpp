/*

Idea behind such approaches --> Move forward till you can and when you can't move leave out something from behind that will optimize the current state.

if think greedly, choose the course first whose lastDay is minimum so that we can take more and more courses in future

Now take courses one by one, 

let we have already taken x course,

Now for any course 'C2' if , time + duration (d2) > lastDay (l2)

So to include this course, we needs to decrease 'time'

To decrease its time, we needs to remove any previous course that are already taken. But how it will be benificial ?

let there is any course 'C1' that has already taken and its duration is 'd1' and its lastDay = 'l1'

Now if we remove this course 'C1' and include current course 'C2' than

   initial time t1 = time  <= l1 <= l2
   
   final time t2 = time+d2-d1
   
   Now if d1>d2 , than t2= time+d2-d1 < t1 < l1 < l2
   
   So we can include course 'C2' after removing 'C1' and it will be benifical to include 'C2' becouse after doing this, time = t2 decreases in compare to if we not include 'C2' or t2<t1
 
so possibility of adding more courese in future increases.

How to choose d1 => d1 should be maximum among all courses taken till now

use priority queue to store these
   
*/



class Solution {
public:
    int scheduleCourse(vector<vector<int>>& cour) {
        
        int n=cour.size();
        
        sort(cour.begin(),cour.end(),[](vector<int>&v1,vector<int>&v2){
          
            return v1[1]<v2[1];
            
        });
        
       
        priority_queue<int>pq;
        
        int i=0;
        
        int time=0;
        
        while(i<n){
             int d2=cour[i][0];
             int l2=cour[i][1];
            if(time+d2 > l2){
                if(pq.size()>0){
                    int d1=pq.top();
                    
                    if(d1>d2){
                        pq.pop();
                        pq.push(d2);
                        time=time-d1+d2;
                    }
                }
            }
            else{
                time+=d2;
             pq.push(d2);
            }

            i++;
        }
        
        int ans=pq.size();
        
        return ans;
    }
};