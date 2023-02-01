class Solution {
public:
    string gcdOfStrings(string s1, string s2) {

       string ans="";
        string temp="";
        
    for(int i=0;i<s1.length();i++)
    {
       temp.push_back(s1[i]);
    
       bool b= check(temp,s1,s2);
        if(b)
      ans=temp;

    }
     return ans;
    }
     
     bool check(string &temp, string &s1, string &s2){
         
         int l=temp.length();
         int l1=s1.length();
         int l2=s2.length();
         
         if(l>l1 || l>l2 || l1%l || l2%l)
             return false;
         
         int i=0,j=0;
         while(i<l && j<l1){
             if(temp[i]!=s1[j])
                 return false;
             i++,j++;
             if(i==l)
                 i=0;
         }
         
         i=0,j=0;
         while(i<l && j<l2){
             if(temp[i]!=s2[j])
                 return false;
             i++,j++;
             if(i==l)
                 i=0;
         }
         return true;
         
     }
};