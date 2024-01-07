class Solution {
public:
    
    vector<vector<string>>ans;
    
    vector<vector<string>> solveNQueens(int n) {
    
        vector<string>v;
        
        string str="";
        
        for(int i=0;i<n;i++){
            str+=".";
        }
        
        for(int i=0;i<n;i++){
            v.push_back(str);
        }
        
        find(0,n,v);
        
       return ans;
        
    }
    
    void find(int i, int n, vector<string>v){
        
        if(i==n){
            ans.push_back(v);
            return;
        }
        
        for(int j=0;j<n;j++){            
            if(isValid(i,j,v)){       
                v[i][j]='Q';
                find(i+1,n,v);
                v[i][j]='.';
            }
        }
        
        return;
    }
    
    bool isValid(int x, int y, vector<string>&v){
        
        int n=v.size();
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='Q'){
                    if((i-j==x-y)||(i+j==x+y))
                        return false;
                    if(i==x or j==y)
                        return false;
                }
            }
        }
        
        
        return true;
        
    }
};