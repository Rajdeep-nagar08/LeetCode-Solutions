#define lln long long int
class Solution {
public:
    long long minimumTime(vector<int>& dist, int hour) {
       
        
       lln l=1;
       lln h=1e14;
      
      lln mid;
      lln ans=-1;
      
      while(l<=h){
         mid= (l+h)/2;
        
          lln x=isValid(mid,dist,hour);
          
        if(x>=hour) {          // for this mid , time <= hour
           ans=x;
            h=mid-1;
        }
        
        else
         l=mid+1;
    
      }
        
      return l;
    }
  
 // checking if its possible to reach on time if we set speed of all trains=mid or no
  
    lln isValid(lln mid,vector<int>&dist,lln hour){
      
       // lln time=0;
         lln time=0.00;
        int n=dist.size();
        
      for(int i=0;i<n;i++)
        time+= (mid/dist[i]);
      
  //    time+= (double(mid)/(double(disr[n-1])));
    /*  
        if(time>hour)
          return false;
      
      return true;*/
        return time;
        
    // }
    
    }
};