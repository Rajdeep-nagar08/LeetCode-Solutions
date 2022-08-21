class Solution {
public:
    string largestPalindromic(string num) {
        
    
        unordered_map<char,int>mp;
        

        for(char ch:num){
            mp[ch]++;
            
           
        }
        
    
        string s1,s2;
        
        
        vector<pair<char,int>>v;
        
        int count;
        char ch;
        
        
        for(auto it:mp){
            
            count=it.second;
            
             ch=it.first;
            
            v.push_back({ch,count});
            
        }
        
        
        sort(v.rbegin(),v.rend());
        
        
        
        
        for(auto it:v){
            
            count=it.second;
            
            ch=it.first;
         
            
            if((ch=='0') && (s1.size()==0))
                break;
                
            if(count%2)
                count--;
        
                int need=count/2;
                
                while(need>0){
                    s1+=ch;
                    s2+=ch;
                    need--;
                }

        }
        
           
        for(auto it:v){
            
            count=it.second;
            
             ch=it.first;
            
            if(count%2){
               
                s1+=ch;
                
                break;
            }   
            
        }
    
            
    
        reverse(s2.begin(),s2.end());
        
        
        s1+=s2;
        
        if(s1.size()==0 && (mp['0']>0))
            s1="0";      
        
        return s1;

        
    }
};