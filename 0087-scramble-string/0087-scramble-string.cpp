  
        
        /*
        
        
        have two choices, either keep both part same or swap them
        
        so think about dp
        
        
        dp[str1_str2] = Is str1 is scrembel to str2 ?
        
        */
      

unordered_map<string,bool>dp;

class Solution {
public:
    bool isScramble(string s1, string s2) {
    
        string str=s1+" "+s2;
        
       
        
           if(s1==s2)
               return true;
        
        if(s1.compare(s2)==0)
            return true;
        
           if((int)s1.size()<=1 && (s1!=s2))
               return false;
        
         if(dp.count(str)==1)
            return dp[str];
        
        bool flag=false;
        
        int n=s1.size();
        
        // [(k)(n-k)] == [(k)(n-k)]
        // [(k)(n-k)] == [(n-k)(k)]
        for(int k=1;k<n;k++){
            
            flag=flag || (isScramble(s1.substr(0,k),s2.substr(0,k)) && (isScramble(s1.substr(k),s2.substr(k))))
                ||
                (isScramble(s1.substr(0,k),s2.substr(n-k)) && (isScramble(s1.substr(k),s2.substr(0,n-k))));
            
        }
        
        return dp[str]=flag;
        
    }
    
    

};