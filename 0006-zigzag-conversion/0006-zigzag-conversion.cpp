class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        if(n==1 || n==0 || numRows==1|| n<=numRows)
            return s;
        
        string row[numRows];
        for(int i=0;i<numRows;i++)
            row[i]="";
        
        int j=0;
        bool flag;
        for(int i=0;i<s.length();i++){
            row[j]=row[j]+s[i];
             if(j==0)
                 flag=true;
             if(j==numRows-1)
                 flag=false;
            
            if(flag==true)
                j++;
            else
                j--;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
            ans=ans+row[i];
        
        return ans;
    }
};