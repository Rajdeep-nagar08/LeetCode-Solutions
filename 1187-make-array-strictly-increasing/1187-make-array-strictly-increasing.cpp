class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
      sort(arr2.begin(),arr2.end());
      
      unordered_map<int,int>mp{{-10,0}};   
      
        /* 
        
        at each arr1[i] we have two choices
        
        either include it (if including it makes subarray increasing)
        
        or
        
        replace it with just greater no. from array2
        
        to store information of valid subarrays till now,As:-
      (last no of  valid subarray ->no of operations till now or no of digits of arr2 used till now)
      e.g valid subarray x1 < x2 < y3 < x4 < y5 where (y3 and y5 taken from arr2)
          for this store {y5 , 2}
          
          
          
      */
      
      for(int no1: arr1){  
        
        unordered_map<int,int>temp;
        
        for(const auto it: mp){
          
          if(it.first < no1){   // no need to do selection from array2
            
            if(temp.find(no1)==temp.end()) 
               temp[no1]=it.second;
            else
               temp[no1]=min(temp[no1],it.second);
            
          }
            
    //now do selection from array2 / replace no1 by suitable digit from arr2 to make the subarray increasing
            
            auto no2= upper_bound(arr2.begin(),arr2.end(),it.first);
            
            if(no2!=arr2.end()){
              
            if(temp.find(*no2)==temp.end())
               temp[*no2]= it.second +1;   
            else
               temp[*no2]=min(temp[*no2],it.second +1);
          }
        }    
          
          
      
        if(temp.empty())
          return -1;
          
        mp=temp;
        
      }
      
      int mn=INT_MAX;
      for(const auto &x:mp)
        mn=min(mn,x.second);
      
      return mn;
       
    }
};