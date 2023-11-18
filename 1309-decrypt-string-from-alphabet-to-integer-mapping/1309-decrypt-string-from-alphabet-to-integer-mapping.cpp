class Solution {
public:
    
    string freqAlphabets(string s) {
        
        
        int n=s.size();
        
        int i=n-1;
        
        string ans="";
        
        while(i>=0){
            if(s[i]=='#'){
                string s1="";
                s1.push_back(s[i-2]);
                s1.push_back(s[i-1]);
                
                int no=stoi(s1);
                char ch='j'+no-10;
                ans.push_back(ch);
                i-=3;
            }
            
            else{
                
                char ch='a'+(s[i]-'0'-1);
                
                ans.push_back(ch);
                
                i--;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};