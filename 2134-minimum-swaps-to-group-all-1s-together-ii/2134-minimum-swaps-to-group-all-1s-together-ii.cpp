/*
Min swap to group all ones together => min(zeroes in the subarray and count of these zeroes = no of ones outside the subarray)

Use sliding window technique
if no of zeroes in window == no of ones outside the window, then ans=min(ans,no of zeroes in the window)

if no of zeroes in the window > no of ones outside the window , then compress the window from back side till req. condition not satisfied

otherwise move ahead


IF ARRAY IS NOT ROTATED:-

{

int ones=0;
    for(int i=0;i<n;i++){
        if(arr[i])
        ones++;
    }
    if(ones==0)
    return -1;
    
     int i=0,j=0;
     int ans=n;
     int z=0,o=0;
     
     while(i<n){
         if(arr[i]==0)
         z++;
         else
         o++;
        
        i++;
        
         while(j<=i && (z>(ones-o))){ // no of zeroes in subarray are greater
             if(arr[j])
              o--;
              else
              z--;
              j++;
         }
         
         if(z==(ones-o))
         ans=min(ans,z);     
         }
         return ans;
      }
      
      
Now what to do extra in case of rotated array

In this case move i as i=(i+1)%n , till j<n

*/




class Solution {
public:
    int minSwaps(vector<int>& arr) {
    
      int n=arr.size();
      arr.resize(2*n,0);
      
      for(int i=n;i<2*n;i++)
        arr[i]=arr[i-n];
  
      int ones=0;
    for(int i=0;i<n;i++){
        if(arr[i])
        ones++;
    }
      
    if(ones==0)
    return 0;
    
     int i=0,j=0;
     int ans=n;
     int z=0,o=0;
     
     while(i<2*n){
         if(arr[i]==0)
         z++;
         else
         o++;
        
        i++;
        
         while(j<=i && (z>(ones-o))){ //if  no of zeroes in subarray are greater
             if(arr[j])
              o--;
              else
              z--;
              j++;
         }
         
         if(z==(ones-o))
         ans=min(ans,z);     
         }
      
         return ans;
      }
};