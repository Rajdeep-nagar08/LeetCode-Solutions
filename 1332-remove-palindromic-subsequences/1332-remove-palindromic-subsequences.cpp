class Solution {
public:
    int removePalindromeSub(string s) {
        
        
        int n=s.size();
        
        /*
        
        
        if whole string is a palindrome , than ans=1
        
        otherwise ans=2 (we remove all a's in one step and all b's in second step)
        */
        
        string s1=s;
        
        reverse(s1.begin(),s1.end());
        
        if(s==s1)
            return 1;
        
        return 2;
        
        
    }
};