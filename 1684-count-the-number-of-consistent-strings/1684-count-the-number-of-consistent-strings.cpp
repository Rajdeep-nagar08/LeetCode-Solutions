class Solution {
public:
    int countConsistentStrings(string all, vector<string>& words) {
        
        vector<int>v(26,0);
        
        for(char ch:all){
            v[ch-'a']++;
        }
        
        int count=0;
        
        
        for(string str:words){
            bool flag=true;
            for(char ch:str){
                if(v[ch-'a']==0){
                    flag=false;
                    break;
                }
            }
            if(flag)
                count++;
        }
        
        return count;
    }
};