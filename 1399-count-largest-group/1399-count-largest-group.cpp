class Solution {
public:
    int countLargestGroup(int n) {
        
        
        unordered_map<int,vector<string>>mp;
        
        int mx=1;
        
        for(int i=1;i<=n;i++){
            string str=to_string(i);
            int sum=0;
            for(char ch:str){
                sum+=(ch-'0');
            }
            mp[sum].push_back(str);
            mx=max(mx,(int)mp[sum].size());
        }
        
        int count=0;
        for(auto it:mp){
            if(it.second.size()==mx)
                count++;
        }
        return count;
    }
};