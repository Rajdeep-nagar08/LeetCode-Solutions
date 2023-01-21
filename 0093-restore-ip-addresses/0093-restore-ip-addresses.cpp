class Solution {
public:
    
            vector<string>ans;

    vector<string> restoreIpAddresses(string s) {
        
        
        int n=s.size();
        
        if(n>12)
            return {};
        
        vector<int>v;
        
        find(0,s,v);
        
        return ans;
        
    }
    
    void find(int i,string &s,vector<int>v){
        
        if(i>=s.size()){
            
            if(v.size()!=4)
                return;
            
            
            string s;
            for(int x:v){
              s+=to_string(x);
                s+=".";
            }
            
            s.pop_back();
            
            ans.push_back(s);
            
            return;
        }
        
        if(v.size()==4){
            return;
        }
        
        if(s[i]=='0'){
           v.push_back(0);
            find(i+1,s,v);
         v.pop_back();
        }
        
        
        if(s[i]=='0')
            return;
        
        int no=0;
        
        
        for(int j=i;j<s.size();j++){
           no=no*10+(s[j]-'0');
            
            if(no>255)
                break;
            
            v.push_back(no);
            
            find(j+1,s,v);
            
            v.pop_back();
            
        }
    }
};