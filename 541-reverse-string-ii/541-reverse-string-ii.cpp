class Solution {
public:
    string reverseStr(string s, int k) {
        
       int n=s.size();
        
        string ans="";
        
        int i=0;
        
        while(i<n){
        
            if(i+k-1>n)
            {
                string s1=s.substr(i);
                reverse(s1.begin(),s1.end());
                ans+=s1;
            }
            else{
                string s1=s.substr(i,k);
                reverse(s1.begin(),s1.end());
                ans+=s1; 
            }
        
            i+=k;
            
            int k1=k;
            
            while(k1 && i<n){
                ans.push_back(s[i]);
                i++;
                k1--;
            }
        }
        
        return ans;
    }
};