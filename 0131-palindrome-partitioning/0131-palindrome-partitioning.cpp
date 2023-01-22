class Solution {
public:
    
    vector<vector<string>>ans;
    
    vector<vector<string>> partition(string s) {
        
        
        
        int n=s.size();
        
        
        
        vector<string>temp;
        
        find(0,s,temp);
        
        return ans;
    }
    
    void find(int i,string s,vector<string>temp){
        
        if(i>=s.size()){
            if(temp.size()>0){
                ans.push_back(temp);
            }
            
            return;
        }
        
        
        string s1;
        
        for(int j=i;j<s.size();j++){
            s1+=s[j];
            if(isPalind(s1)){
                temp.push_back(s1);
                find(j+1,s,temp);
                
                temp.pop_back();
            }
        }
    }
    
    bool isPalind(string s){
        
        int n=s.size();
        
        int i=0,j=n-1;
        
        while(i<j){
            if(s[i]!=s[j])
                return false;
            
            i++,j--;
        }
        
        return true;
    }
};