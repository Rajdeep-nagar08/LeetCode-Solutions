class Solution {
public:
    int countBalls(int lowL, int highL) {
        
       unordered_map<int,int>mp;
        int ans=0;
        string str;
        for(int i=lowL;i<=highL;i++){
            str=to_string(i);
            int sum=0;
            for(char ch:str){
                sum+=ch-'0';
            }
            mp[sum]++;
            ans=max(ans,mp[sum]);
        }
        
        return ans;
        
    }
};