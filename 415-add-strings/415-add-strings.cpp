class Solution {
public:
    string addStrings(string s1, string s2) {
       
        int n1=s1.size();
        
        int n2=s2.size();
        
        string ans;
        
        int c=0;
        
        int i=n1-1,j=n2-1;
        
        while(i>=0 && j>=0){
            int a=s1[i]-'0';
            int b=s2[j]-'0';
            int sum=a+b+c;
            c=sum/10;
            sum=sum%10;
            char ch=sum+'0';
            ans+=ch;
            i--,j--;
        }
        
        
        while(i>=0){
            int a=s1[i]-'0';
             int sum=a+c;
            c=sum/10;
            sum=sum%10;
            char ch=sum+'0';
            ans+=ch;
            i--;
        }
        
        while(j>=0){
            int b=s2[j]-'0';
            int sum=b+c;
            c=sum/10;
            sum=sum%10;
            char ch=sum+'0';
            ans+=ch;
            j--;
        }
        
        if(c>0){
            ans+=(c+'0');
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};