/*

we needs to focus on first and the second number

if 1st and 2nd no. fatched successfully, than we can fatch other numbers easily

dp[i][j]= Is there exist a valid sequence if 1st number is of length i and second number of length j

i<=9 , j<=9

*/

#define lln long long int
class Solution {
public:
    int n;
    bool isAdditiveNumber(string num) {
        
        n=num.size();
        
        
       for(int i=1;i<=min(9,n-1);i++){   // i= length of n1
           
           if(num[0]=='0' && i>1)
               break;
           
           for(int j=1;i+j<=min(18,n);j++){   // j= length of n2
               string s1=num.substr(0,i);
               string s2=num.substr(i,j);
               
               if(s2[0]=='0' && s2.size()>1)
                   break;
               
               lln n1=stoll(s1);
               lln n2=stoll(s2);
               
               string sum=to_string(n1+n2);
               
               if(i+j<n){
               bool b=isValid(n2,sum,i+j,num);
         //    cout<<n1<<" "<<n2<<" "<<b<<endl;
               if(b)
                   return true;
               }
           }
       }
        return false;
    }
    
    bool isValid(lln b,string& sum,int idx,string num){
        
        int len=sum.size();
        
        if(idx==n)
            return true;
        
        if(len+idx-1>n-1)
            return false;
        
        string s=num.substr(idx,len);
        
        if(sum!=s)
            return false;
        
        lln c=stoll(sum);
        
        sum=to_string(b+c);
        
        return isValid(c,sum,idx+len,num);
        
    }
    
};