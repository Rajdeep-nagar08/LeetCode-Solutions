class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        if digits == "":
            return []
    
        ans=[]
        
        mp={}
        
        mp[2]=['a','b','c']
        mp[3]=['d','e','f']
        mp[4]=['g','h','i']
        mp[5]=['j','k','l']
        mp[6]=['m','n','o']
        mp[7]=['p','q','r','s']
        mp[8]=['t','u','v']
        mp[9]=['w','x','y','z']
        
        self.find(0,digits,mp,ans,"")
        
        return ans;
    
    def find(self,i,dig,mp,ans,temp):
        
        if i>=len(dig):
            ans.append(temp)
            return
        
        for ch in mp[int(dig[i])]:
            temp+=ch
            self.find(i+1,dig,mp,ans,temp)
            temp=temp[:-1]
        
        