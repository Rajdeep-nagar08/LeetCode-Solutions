class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        
        vector<string>v={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
         
        unordered_map<string,int>mp;
        
        
        for(string str:words){
            
            string s;
            
            for(char ch:str){
                int idx=ch-'a';
                s+=v[idx];
            }
            
            mp[s]++;
        }
        
        return (int)mp.size();
    }
};