// Expend from center method

class Solution {
public:
    string longestPalindrome(string s) {
        
      string ans="";
        
        string pal;
        
        int n=s.size();
        
       for(int i=0;i<n;i++){
           
           pal=check(i,s,false);

           
           if(pal.size()>ans.size())
               ans=pal;
           
           if(i<=n-2){
            pal=check(i,s,true);

           
           if(pal.size()>ans.size())
               ans=pal;
           }
           
       } 
        return ans;
        
    }
    
    string check(int i,string& str,bool isEven){
        
        int n=str.size();
        
        int i1,j1;
                
        bool flag=true;
        
        if(isEven)
            i1=i,j1=i+1;
        else
            i1=i,j1=i;
        
        if(j1>=n)
            flag=false;
        
        while(i1>=0 && j1<n){
            if(str[i1]!=str[j1]){
                break;
            }
            else
                i1--,j1++;
        }
        
        i1++,j1--;
        
       string s=str.substr(i1,j1-i1+1);
        
        return s;
    }
};