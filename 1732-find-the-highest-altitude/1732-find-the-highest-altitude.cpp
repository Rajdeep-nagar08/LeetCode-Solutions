class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        
        
        int mx=max(0,gain[0]);
        
        int n=gain.size();
        
        
        for(int i=1;i<n;i++){
            gain[i]=gain[i-1]+gain[i];
            
            mx=max(mx,gain[i]);
        }
        
        return mx;
    }
};