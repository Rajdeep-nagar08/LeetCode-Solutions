/*

using left and right array

left[i]= min cost to remove all 1's from 0 to i 

if(s[i]=='1')
  left[i] = min(left[i-1]+2(cost to remove it directly),i+1 (cost to remove all from 0 to i to remove i))
  
  
 similarly

right[i]= min cost to remove s[i] if s[i]=='1' from right side

if(s[i]=='1')
  right[i]= min(right[i+1]+2 , n-i)
  
  Ans = min(left[i],right[i+1]) for all i
  
  */

class Solution {
public:
    int minimumTime(string s) {
        
        
        int n=s.size();
        
        vector<int>left(n);
        
        left[0]=s[0]=='1'?1:0;
        
        for(int i=1;i<n;i++){
            if(s[i]=='1')
                left[i]=min(left[i-1]+2,i+1);
            else
                left[i]=left[i-1];
        }
        
         vector<int>right(n);
        
           right[n-1]=s[n-1]=='1'?1:0;
        
        for(int i=n-2;i>=0;i--){
            if(s[i]=='1')
                right[i]=min(right[i+1]+2,n-i);
            else
                right[i]=right[i+1];
        }
        
        int ans=min(left[n-1],right[0]);
        
         for(int i=0;i<=n-2;i++){
             
          ans=min(ans,left[i]+right[i+1]);   
      }

        
        return ans;
    }
};