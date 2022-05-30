class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        
        
        int n=v.size();
        
        string ans=v[0];
        
        for(int i=1;i<n;i++){
            lcp(v[i],ans);
        }
        return ans;
    }
    
    void lcp(string &s1,string &s2){
        int n1=s1.size();
        int n2=s2.size();
        
        string s="";
        
        int i=0,j=0;
        
        while(i<n1 && j<n2 && s1[i]==s2[j]){
            s.push_back(s1[i]);
            i++,j++;
        }
        
        s2=s;
    }
};