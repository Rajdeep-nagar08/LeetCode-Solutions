class Solution {
public:
    int maxScore(string s) {
        
        
        int n=s.size();
        
        // score = no of zero in left + no of ones in right
        
        vector<int>pref(n);
        pref[0]=s[0]=='0'?1:0;
        
        for(int i=1;i<n;i++){
            pref[i]=s[i]=='0'?pref[i-1]+1:pref[i-1];
        }
        
        int ans=INT_MIN;
        
        for(int i=1;i<n;i++){
            int prevz=pref[i-1];
            int nextZ=pref[n-1]-prevz;
            int nexto=(n-i)-nextZ;
            ans=max(ans,prevz+nexto);
        }
        return ans;
    }
};