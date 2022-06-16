class Solution {
public:
    int distributeCandies(vector<int>& can) {
        
        int n=can.size();
        
        unordered_map<int,int>mp;
        
        for(int x:can)
            mp[x]++;
        
        if(mp.size()>=n/2)
            return n/2;
        else 
            return mp.size();
    }
};