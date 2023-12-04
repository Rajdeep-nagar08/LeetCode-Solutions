class Solution {
public:
    string largestGoodInteger(string num) {
        
        
        int n=num.size();
        
        int no=0;
        int mx=-1;
        
        for(int i=0;i<=n-3;i++){
            
            int n1=(num[i]-'0');
            int n2=(num[i+1]-'0');
            int n3=(num[i+2]-'0');
            
            if(n1==n2 && n2==n3){
                no=0;
            no=(n1*10+n2);
            no=no*10+n3;
                
           mx=max(mx,no);
            }
            
            
        }
        
        if(mx==-1)
            return "";
        if(mx==0)
            return "000";
        
        string ans=to_string(mx);
        
        return ans;
        
    }
};