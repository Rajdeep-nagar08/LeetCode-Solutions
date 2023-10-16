class Solution {
public:
    bool isMatch(string s, string p) {
                
        return find(0,0,s,p);
        
    }
    
    bool find(int i, int j, string &s, string &p){
        
        if(i>=s.size() && j>=p.size())
            return true;
        
        if(i>=s.size()){
           
            while(j+1<p.size()){
                if(p[j+1]!='*')
                    return false;
                j+=2;
            }
            
            if(j<p.size())
                return false;
            
            return true;
        }
        
        if(j>=p.size())
            return false;
        
        if(j+1<p.size() && p[j+1]=='*'){
            
            // 0 times repeat
            
            bool ans=find(i,j+2,s,p);
            
            // 1 time repeat => i == j
            

            // 2 time repaet => i, i+1 == j, j
            
            
            // 3 time repeat => i, i+1, i+2 == j, j, j
            
            // ans so on
            
            
            bool match=true;
            
            for(int i1=i;i1<s.size();i1++){
                
                match = match and (s[i1]==p[j] || p[j]=='.');
                
                ans= ans | (match and find(i1+1, j+2,s,p));
                
            }
            
            return ans;
            
        }
        
        
        else if(p[j]=='.'){
            return find(i+1,j+1,s,p);
        }
        
        return (s[i]==p[j]) and find(i+1,j+1,s,p);
        
        
    }
};