class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1;
        string s2;
        for(int i=0;i<s.length();i++){
            if((s[i]=='#')&&(s1.size()==0)){
                continue;
            }
            if(s[i]=='#'){
                s1.pop_back();
            }else{
                s1.push_back(s[i]);
            }
            
        }
        
        
        for(int i=0;i<t.length();i++){
            if((t[i]=='#')&&(s2.size()==0)){
                continue;
            }
            if(t[i]=='#'){
                s2.pop_back();
            }else{
                s2.push_back(t[i]);
            }
        }
                
        cout<<s1<<" "<<s2<<endl;
        
        if(s1.length()!=s2.length()){
            return false;
        }
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
};

/*

"xywrrmp"
"xywrrmu#p"


xywrrmp xywrrm

*/