class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            
            else
            
                return false;
            
   }
        return true; // kabhi else me gya hi nhi
    }
    
    
    
    bool validPalindrome(string s) {
    
        
        int start=0;
        int end=s.size()-1;
        while(start<end)
        {
           if(s[start]==s[end])
           {
            start++;
            end--;
           }
            else
            {
             
            return isPalindrome(s,start+1,end)|| isPalindrome(s,start,end-1);
            }
        }
        return true; // pointer kabhi else me gya hi nhi 
            
        
        
    }
};