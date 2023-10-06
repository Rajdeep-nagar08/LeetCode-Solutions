class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        
         sort(nums.begin(),nums.end(),[](int x, int y){
             
             string s1=to_string(x);
             
             string s2=to_string(y);
             
            string a=s1+s2;
             
            string b=s2+s1;
             
             for(int i=0;i<a.size();i++){
                 if(a[i]==b[i])
                     continue;
                 else if(a[i]>b[i])
                     return true;
                 
                  else
                      break;
             }
             
             return false;
         });
        
        string ans="";
        
        for(int x:nums){
            ans+=to_string(x);
        }
        
        if(ans[0]=='0')
            return "0";
        
        return ans;
        
    }
};