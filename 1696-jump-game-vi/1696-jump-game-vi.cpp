/*
        
        In one move, at most k steps forward
        
        
        Score of any path = sum of all values visited in the path
        
        Needs to find Maximum score possible

        As we have multiple choices for next jump, so we can think about dp
        
        dp[i] = max score if moving from index i to last index
        
        
        we have k choices for next move (for each index i)


        Ans=dp[0]
        
        T.C= O(n*k)
        
        It gives TLEEEEEEEEE
        
        */


/*

(optimization using deque)

dp[i] = max score possible if start moving from index i and reaches to index 
last index n-1


dp[i]= nums[i] + max(dp[i+1],dp[i+2],.....dp[i+k])

we use deque to keep track of max among these next k values

ans= dp[0]

*/

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
         int n=nums.size();
        
         vector<int>dp(n);

         dp[n-1]=nums[n-1];

         deque<int>dq;
        
         dq.push_back(n-1);
        
         for(int i=n-2;i>=0;i--){
             
          dp[i]=nums[i];
           
             
        //Now jumping from previous greatest index j to index i (Note index j should lies in range of i)

          if(dq.size()>0) {
              int j=dq.front();
              if(j-i>k)
                  dq.pop_front();
          }
              
             
              if(dq.size()>0){
                  int j=dq.front();
                dp[i]+=dp[j];
              }
             
    // Updating deque to push index of dp[i] to it ( NOTE: keep that index at front of deque whose value is max)
             
          while(dq.size()>0 && (dp[i]>=dp[dq.back()]))
              dq.pop_back();
             
             
             dq.push_back(i);
             
         
         }
        
        
        return dp[0];
        
        
    }
        
    
};

    
 /*

Approach 2 (using deque) : 

dp[i] = max score if we ends at index i and starts moving from index 0

Ans= dp[n-1]

dp[i]=nums[i] +  max(dp[0],dp[1],dp[2]....,dp[i-1])  Considering that 

all indexes [0,1,2,3,...i-1] lies in range of i (as we can only jump upto k steps forward)

max among last k values  , can be found out in conastant time using deque)

Let we have calculated dp[0] , dp[1] , dp[2] , dp[3]

As soon as we caluculating them we store them in deque , front of deque = max among all these

Than for dp[4] = nums[4] + max(dp[0],dp[1],dp[2],dp[3])
               = nums[4] + front of deque
               
Than for further indexes we update deque by pushing index '4' corresponding to value dp[4] 




class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
         int n=nums.size();
        
         vector<int>dp(n);

         dp[0]=nums[0];

         deque<int>dq;
        
         dq.push_back(0);
        
        
         for(int i=1;i<n;i++){

             
          dp[i]=nums[i];
           
             
        //Now jumping from previous greatest index j to index i (Note index j should lies in range of i)

          if(dq.size()>0) {
              int j=dq.front();
              if(i-j>k)
                  dq.pop_front();
          }
              
             
              if(dq.size()>0){
                  int j=dq.front();
                dp[i]+=dp[j];
              }
             
    // Updating deque to push index of dp[i] to it ( NOTE: keep that index at front of deque whose value is max)
             
          while(dq.size()>0 && (dp[i]>=dp[dq.back()]))
              dq.pop_back();
             
             
             dq.push_back(i);
             
         
         }
        
        
        return dp[n-1];
        
        
    }

};

*/


