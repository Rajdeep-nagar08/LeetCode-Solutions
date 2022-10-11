class Solution {
public:
string breakPalindrome(string p) {
        
        size_t sz = p.size();
        if (sz <= 1) return "";
        
        for (size_t i=0; i < sz/2; i++) {
            if (p[i] > 'a')  {
                p[i] = 'a';
                return p;
            }
        }
        
        p[sz-1] = 'b';
        return p;
    }
};