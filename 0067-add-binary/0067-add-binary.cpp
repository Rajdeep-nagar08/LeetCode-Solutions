class Solution {
public:
    string addBinary(string a, string b) {
        
        int n1=a.length();
        int n2=b.length();
        int c=0;
        string ans="";
        int i=0;
        while(i<n1 && i<n2){
            if(a[n1-i-1]==b[n2-i-1] ){
                if(a[n1-i-1]=='1'){
                    if(c==1){
                ans.push_back('1');
                        c=1;
                    }
                    else{
                ans.push_back('0');
                        c=1;
                    }
                }
                else{
                    if(c==1){
                        ans.push_back('1');
                        c=0;
                    }
                 else{
                    ans.push_back('0');
                    c=0;
                   }
               }
            }
            else{
                if(c==1){
                    ans.push_back('0');
                    c=1;
                }
                else{
                    ans.push_back('1');
                    c=0;
                }
            }
            i++;
        }
        
       if(n2>n1){
            a=b;
           n1=n2;
        }
        while(i<n1){
            if(a[n1-i-1]=='1'){
                if(c==1){
                    ans.push_back('0');
                    c=1;
                }
                else{
                    ans.push_back('1');
                    c=0;
                }
            }
            else{
                if(c==1){
                    ans.push_back('1');
                    c=0;
                }
                else{
                    ans.push_back('0');
                    c=0;
                }
            }
            i++;
        }
        
        if(c==1)
            ans.push_back('1');
        
        reverse (ans.begin(),ans.end());
        return ans;
    }
};