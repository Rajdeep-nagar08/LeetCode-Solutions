class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      
      int n=gas.size();
      int sum=0;
      for(int i=0;i<n;i++)
        sum+=gas[i]-cost[i];
      
      if(sum<0)
        return -1;
      
      int g;
      
      for(int i=0;i<n;i++){
        g=0;
        for(int j=i;j<=i+n;j++){
          g=g+gas[j%n]-cost[j%n];
          
          if(g<0){
            i=j%n;  
            /* 
            we are updating i as its useless to start before index j%n becouse for that cases also          we will get g<0 because here g=sum of gas we have when we start our journey from i =>j , so skip them
            */
            
            break;
          }
          
        }
        if(g>=0)
          return i;
      }
      return -1;
      
    }
  
};