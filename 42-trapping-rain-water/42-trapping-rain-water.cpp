
class Solution {
public:
    int trap(vector<int>& height) {
        
      int n=height.size();
      vector<int>pref1(n);
       pref1[0]=height[0];
      
      for(int i=1;i<n;i++)
        pref1[i]=max(pref1[i-1],height[i]);
      
      vector<int>pref2(n);
      pref2[n-1]=height[n-1];
      for(int i=n-2;i>=0;i--)
        pref2[i]=max(pref2[i+1],height[i]);
      
      
      long long int ans=0;
      for(int i=0;i<n;i++){
        if(height[i]==pref1[i] || height[i]==pref2[i])
          continue;
        
        ans=ans + min(pref1[i],pref2[i])-height[i];
      }
        return ans;
    }
};