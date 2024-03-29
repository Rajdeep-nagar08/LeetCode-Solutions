
/*

observation:

if [.....(min......max).....]

is some no. are duplicates inside this range then some no's are also missing from this range so we can easily convert those duplicate no's to the missing no's also we can convert the no's outside the range to missing no's inside the range so our smallest and the greatest no will remain unchanged

as max-min==n-1


 consider nums[i] as smallest one then finding the max-> nums[j] such that
   nums[j]-nums[i]=n-1, so except this range from nums[i] to nums[j]
   we need
   to update other elements of count-> n-(j-i) to make 
   the present range continous

*/


class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        
        int n=nums.size();
        
        unordered_map<int,int>mp;
        
        for(int x:nums){
            mp[x]++;
        }
        
        nums.clear();
        
        for(auto it:mp){
            nums.push_back(it.first);
        }
        
        sort(nums.begin(),nums.end());
        
        int i=0;
        
        int j=0;
        
        int ans=n;
        
        while(i<nums.size()){
                       
            
            while(j<nums.size() && (nums[j]-nums[i]<n-1))
                j++;
           
          //  cout<<i<<" "<<j<<" "<<n-(j-i)<<endl;
            
            if(j<nums.size() && (nums[j]-nums[i]==n-1))
              ans=min(ans,n-(j-i+1)),j++;
            
             else if(j<nums.size() && (nums[j]-nums[i]>n-1))
              ans=min(ans,n-(j-i+1)+1);
            
            else
                
                ans=min(ans,n-(j-i+1)+1);
            
            
            
            i++;
                   
        }
        
        return ans;

    }
};