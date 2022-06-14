class Solution {
public:
    bool checkIfPangram(string st) {
        
        vector<int>v(26,0);
        
        for(char ch:st){
            v[ch-'a']++;
        }
        
        for(int x:v){
            if(x==0)
                return false;
        }
        
        return true;
        
    }
};