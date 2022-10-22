
       class Solution {
public:
    string minWindow(string s, string t)
    {
        
        unordered_map<char,int>mp1;
        
        unordered_map<char,int>mp2;
        
        for(auto it: t)
        {

            mp1[it]++;
        }
                
        int count=0;
        
        int i=0; // starting
        
        int j=0; // ending pointer
        
        int answer=INT_MAX;
        
        string m="";

        while(j<s.size())
        {
            mp2[s[j]]++;
    
        // agar match hoga to count++ karenge but number required hona chaiye 
            
            if(mp2[s[j]]<=mp1[s[j]])
            {
                count++;
            }
            
            if(count==t.size()) // valid window mil gya h ab usse chota khojna h 
            {
                
                while(mp2[s[i]]>mp1[s[i]] || mp1[s[i]]==0) // kabtk sliding window ko chota karenege jabtk required frequency se jyda mil rhi hogi 
                    
                {
                    if(mp2[s[i]]>mp1[s[i]])
                    {
                        mp2[s[i]]--;
                    }
                    
                    i++;
                }
                
                if(j-i+1<answer)
            
                {
                answer=j-i+1; // chota string mila to update karenge 
                m=s.substr(i,answer);
                
                
            
                }
            
                
                
                
            }
            
            
      
           j++; 
            
            
        }
        
        return m;
        
    }
};
        
   