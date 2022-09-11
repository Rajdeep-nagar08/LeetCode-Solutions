class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& map) {
        
        
        return find(s,sub,map);
        
        
    }
    
    
     bool find(string s, string sub, vector<vector<char>>& map) {
    
        int m=s.length();
        
        int n=sub.length();
        
         
         if(m<n)
            return false;
         
         
           unordered_map<char,unordered_map<char,int>>myMap;
         
        
        for(auto it1:map){
            
            
            
            myMap[it1[0]][it1[1]]++;
            
            
            
        }
        
        
        int i=0;    
         
         
         
    
        while(i+n<=m){
            
    
            bool Myflag=true;
            
            
             int j=0;   
            
             int k=i;
            
           
            
            while(j<n){
               
                if(s[k]==sub[j]){
                    j++;
                    k++;
                }
                
                else if((myMap[sub[j]].count(s[k])==1)){
                    j++;
                    k++;
                }
                
                else{
                    
                    Myflag=false;
                    break;
                }
                    
            }
            
             if(Myflag)
                return true;
            
            i++;
            
        }
        
        return false;
    
    }
};