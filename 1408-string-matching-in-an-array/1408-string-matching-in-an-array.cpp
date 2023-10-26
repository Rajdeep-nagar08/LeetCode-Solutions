class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        
        sort(words.begin(),words.end(),[](string &s1, string &s2){
            return s1.size()<=s2.size();
        });
            
            vector<string>ans;
        int n=words.size();
            for(int i=0;i<n;i++){
                bool flag=false;
                string s1="";
                for(int j=i+1;j<n;j++){
                    s1=words[i];
                    
                    string s2=words[j];
                    
                    if(isSubstring(s1,s2)){
                        flag=true;
                        break;
                    }
                    
                }
                if(flag)
                    ans.push_back(s1);
                
                
                
            }
        
        return ans;
    }
    
    bool isSubstring(string &s1, string &s2){
        int n=s1.size(),m=s2.size();
        int p1=0,p2=0;
        
        for(int i=0;i<m;i++){
            if(i+n<=m && s2.substr(i,n)==s1) return true;
        }
        return false;
    }
};