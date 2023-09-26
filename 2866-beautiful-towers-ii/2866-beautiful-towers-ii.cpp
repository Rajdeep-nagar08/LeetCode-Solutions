
#define lln long long int

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& v) {
        

         lln ans = 0;
        
        vector<pair<lln,lln>>v1;
        
        int n = v.size();
        
        for(int i=0;i<n;i++){
            
            v1.push_back({v[i],i});
        }
        
        sort(v1.rbegin(),v1.rend());
        
        int m=v1.size();
     
    for(int i1 = 0; i1 < min(m,150); i1++) {
        
        lln prev = v[v1[i1].second];

        lln ans1 = v[v1[i1].second]; 
    

        int count=0;
        
        for(int j = v1[i1].second - 1; j >= 0; j--) {
            
            prev = min(prev, 1ll*v[j]);
            
            
            ans1 += prev;
            
            count++;
            
        }

        prev = v[v1[i1].second];
        
        for(int j = v1[i1].second + 1; j < n; j++) {
            prev = min(prev, 1ll*v[j]);
            ans1 += prev;
            count++;
        }

        ans = max(ans, ans1);
    }
    
    return ans;

        
        
    }
};