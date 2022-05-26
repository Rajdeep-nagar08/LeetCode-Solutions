class Solution {
public:
    string longestNiceSubstring(string s) {
        
        int i=0;
        
        vector<string>sub;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string str=s.substr(i,j-i+1);
                sub.push_back(str);
            }
        }
        
        string ans="";
        
        for(string str:sub){
            
            int sz=str.size();
            
              bool f=true;

            for(int i=0;i<sz;i++){
                char c1=str[i];
                char c2=rev(c1);
                bool f1=false;
                for(int j=0;j<sz;j++){
                    if(str[j]==c2){
                        f1=true;
                        break;
                    }
                }
                
                if(f1==false){
                    f=false;
                    break;
                }
                
            }
            if(f && (ans.size()<str.size()))
                    ans=str;
        }
        
        return ans;
    }
    
    
    
    char rev(char &c){
        char c1;
        if(c<=90){
            c1=tolower(c);
        }
        else
            c1=toupper(c);
        
        return c1;
    }
};