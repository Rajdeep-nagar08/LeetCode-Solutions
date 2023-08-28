class Solution:
    def romanToInt(self, s: str) -> int:
        
        mp={'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        ans=0
        prev=0
        i=len(s)-1
        while i>=0:
            no=mp[s[i]]
            if no>=prev:
                ans+=no
            else:
                ans-=no
            prev=no
            i=i-1
        return ans
        