class Solution {
public:
    bool isPalindrome(string s) 
    {
        
        if(s==" ")
        {
            return true;
        }
        
        int left=0;
        int right= s.size()-1;
        
        while(left<right)
        {
            if(!isAlphanumeric(s[left]))
            {
                left++;
            }
            else if(!isAlphanumeric(s[right]))
            {
                right--;
            }
            else if(lowercase(s[left])!=lowercase(s[right]))
                    {
                        return false;
                    }
                    
                    
            else
                    {
                        left++;
                        right--;
                    }
        }
                    return true;
        
        
        
    }
                    
                    
     private :bool isAlphanumeric(char c)
                    {
                        return('a'<=c && c<='z')||('A'<=c && c<='Z')||('0'<=c && c<='9');
                    }
                    
                    
                    private :char lowercase(char c)
                    {
                        if((c>='a' && c<='z')||(c>='0'&&c<='9'))
                        {
                            return c;
                        }
                        
                        return (char)((int)c+32);
                    }
};