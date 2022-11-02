#define lln long long int

// It can be shown that if n1 * n2 % k == 0, then gcd(n1, k) * gcd(n2, k) % k == 0


class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        
      unordered_map<lln,lln>mp;
    
     lln ans=0;
        
        for(int i=0;i<nums.size();i++){
            lln g1=__gcd(nums[i],k);
            
          for(auto it:mp){
              lln g2=it.first;
              int count=it.second;
              if(g1*g2%k==0)
                  ans+=count;
          }
            mp[g1]++;
        }
        
        return ans;
    }
};