
#define lln long long int

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        
        
        int n=nums1.size();
        
        
        int m=nums2.size();
        
        unordered_map<lln,int>mp1,mp2;
        
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp1[1ll*nums1[i]*nums1[j]]++;
            }
        }
        
        
        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                mp2[1ll*nums2[i]*nums2[j]]++;
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            ans+=mp2[1ll*nums1[i]*nums1[i]];
            
        }
        
        
         for(int i=0;i<m;i++){
            
            ans+=mp1[1ll*nums2[i]*nums2[i]];
            
        }
        
        
        return ans;
        
    }
};