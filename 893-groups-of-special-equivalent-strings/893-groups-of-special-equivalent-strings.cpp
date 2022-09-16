class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
       
                
        /*
        
        swap (even <=> even) OR (odd <=> odd) indexes
        
        
        no. of sets of string such that each string is pairwise equivalent to other
        
        
        basically we needs to focus on chars at even and odd positions only
        
        
        str1   ===  str2
        
        if (chars at even position of str1 == chars at even position of str2)
        
        if(chars at odd position of str1 == chars at odd position of str2)
        
        order of chars do not matter
        
        */
        
        
      unordered_map<string ,unordered_map<string,int>>mp;  
        
        // chars at even pos => (char at odd pos , count of such strings)
        
        
        for(string str:words){
            
            string even,odd;
            
            for(int i=0;i<str.size();i++){
                
                if(i%2==0)
                    even+=str[i];
                else
                    odd+=str[i];
            }
            
            sort(even.begin(),even.end());
            
            sort(odd.begin(),odd.end());
                        
            mp[even][odd]++;
            
        }
        
        
        int ans=0;
        
        for(auto it:mp){
         
          ans+=it.second.size();
            
        }
        
        return ans;
        
    }
};