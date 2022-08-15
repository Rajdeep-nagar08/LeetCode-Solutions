class Solution {
public:
    int romanToInt(string str) {
        
        int n=str.size();
        
        int i=0;
        
        unordered_map<string,int>mp={{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};
        
        int ans=0;
        
        string s,s1;
        
        while(i<n){
            
            if(i==n-1){
                
                string s;
                
                s.push_back(str[i]);
                
                ans+=mp[s];
                
                i++;
                
            }
            
            else{
                
                string s1;
                
                s1.push_back(str[i]);
                
                s1.push_back(str[i+1]);
                
                if(mp.count(s1)==1){
                    ans+=mp[s1];
                    i+=2;
                }
                else{
                    
                    string s;
                    
                    s.push_back(str[i]);
                    
                    ans+=mp[s];
                    
                    i++;
                }
            }
        }
        
        
        return ans;
        
    }
};