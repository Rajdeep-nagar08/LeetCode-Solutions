class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       
        int n=s.size();
        
        vector<vector<int>>v(26);
        
        for(int i=0;i<n;i++){
            int no=s[i]-'a';
            
            v[no].push_back(i);
        }
      
        int count=0;
        
        
        for(string str:words){
            
            bool f=true;
            
            int start=0;

            
            for(char ch:str){
                
                int no=ch-'a';
                
       int idx=lower_bound(v[no].begin(),v[no].end(),start)-v[no].begin();
                
           if(idx>=v[no].size() || idx<0)
           {
               f=false;
               break;
           }
                
             start=v[no][idx]+1;
                
                
            }
            
            if(f==true)
               count++;
            
        }
       
        
        return count;
        
    }
    
};
    