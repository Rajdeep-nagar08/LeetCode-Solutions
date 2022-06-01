class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
                
        vector<int>v(26,0);
        
        for(string str:words2){
            
            vector<int>v1(26,0);
            
            for(char ch:str){
                v1[ch-'a']++;
            }
            
            for(int i=0;i<26;i++){
                v[i]=max(v[i],v1[i]);
            }
        }
        
        vector<string>ans;
        
        for(string str:words1){
             vector<int>v1(26,0);
            
            for(char ch:str){
                v1[ch-'a']++;
            }
            
            bool f=true;
            
            for(int i=0;i<26;i++){
                if(v[i]>v1[i]){
                    f=false;
                    break;
                }
            }
            
            if(f)
                ans.push_back(str);
        }
        
        return ans;
    }
};