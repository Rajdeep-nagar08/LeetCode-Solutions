/*
clearly,
deviation will be min if (difference btw max and min value is min)

Note if no is odd=> we can maximize it only once becouse after multiplying by 2 it becomes even

so first maximize all odd no's of array by single traversal

now we are left with even no's , minimize all even no's

keep track of ans during both cases
*/

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
    int ans=INT_MAX;
        
        int mn=INT_MAX,mx=INT_MIN;
        // miximizing all odd no's
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1)
                nums[i]=nums[i]*2;
            
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
            
        }
        
        ans=min(ans,mx-mn);
  
        // minimizing all even no's that are max among all
        
        priority_queue<int>pq; // max heap
     
        
        for(int x:nums)
           pq.push(x);
        
        while(pq.top()%2==0){
            int x=pq.top();
            pq.pop();
            
            ans=min(ans,x-mn);
            
            x=x/2;
            
            mn=min(mn,x);
            
            pq.push(x);
        }
        
        ans=min(ans,pq.top()-mn);
        
        return ans;
        
        
    }
        
      
};