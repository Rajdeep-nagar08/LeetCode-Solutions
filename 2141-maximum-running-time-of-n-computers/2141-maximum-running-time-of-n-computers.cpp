
/*

ith batter can run a computer for batt[i] minutes

Max no of minutes we can run all the computers

Clearly

after a fix time we cannot charge all computers, we needs to find that highest time

and before that time we can charge all the computers

we can find this max time by applying binary search on the range of minutes becouse charging all computers at any time in a range of times is a monotonic function

[charging(t=1)......charging(t=x) notChargging(t=x+1).....notCharging(t=1e9)]

Ans=t=x

But how to check whether all computers can be charged or not charged till any fix time t ?

to run all computers for time t:
     total time we needed= t*no of computers
     
     no for any battery of amount = x, we can use it = min(x,t) minutes
     so we calcu;ate available time from all batteries
     
     if available time >= total time, than it is possible to charge all computers for time t


*/


#define lln long long int
 
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batt) {
        
        
        lln l=0;
        
        lln h=0;
        for(int x:batt){
            h+=x;
        }
        
        lln ans=0;
        
        while(l<=h){
            lln mid=(l+h)/2;
            
            if(isValid(n,mid,batt)){
                ans=mid;
                l=mid+1;
            }
            
            else
                h=mid-1;
        }
        
        return ans;
    }
    
     bool isValid(int n,lln mid,vector<int>&batt){
         
         lln totalTime=1ll*mid*n;
         
         lln avlTime=0;
         
         for(lln x:batt){
             avlTime+=min(x,mid);
         }
         
         if(avlTime>=totalTime)
             return true;
         
         return false;
     }
};