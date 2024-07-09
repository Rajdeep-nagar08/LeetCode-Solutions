class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        sort(arr2.begin(),arr2.end());
        
        int n=arr1.size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int x=arr1[i]+d;
            
            int y=arr1[i]-d;
            
            int i1=lower_bound(arr2.begin(),arr2.end(),y)-arr2.begin();
            
            if(i1<arr2.size()&&i1>=0 && arr2[i1]<=x && arr2[i1]>=y)
                continue;
                        
            ans++;
        }
        
        return ans;
        
    }
};