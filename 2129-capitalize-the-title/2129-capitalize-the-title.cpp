class Solution {
public:
    string capitalizeTitle(string str) {
        
        string s1;
stringstream ss(str); 
string temp;
    string ans="";
while(ss>>temp){
s1=formed(temp);
if(ans.size()==0)
    ans+=s1;
    else
        ans+=" ",ans+=s1;
}
        
   return ans;    
        
    }
    
    string formed(string str){
        int n=str.size();
        
        str[0]=toupper(str[0]);
        
        for(int i=1;i<n;i++)
            str[i]=tolower(str[i]);
        
        if(n<=2)
            str[0]=tolower(str[0]);
        
        
        return str;
    }
};