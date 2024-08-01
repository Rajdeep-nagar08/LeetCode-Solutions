class Solution {
public:
    int countSeniors(vector<string>& details) {
       
        
        // age = [12,13] index
        
        int ans=0;
        
        for(string str: details){
        
            string s1=str.substr(11,2);
            
            int x=stoi(s1);
            if(x>60)
                ans++;
        }
        return ans;
    }
};