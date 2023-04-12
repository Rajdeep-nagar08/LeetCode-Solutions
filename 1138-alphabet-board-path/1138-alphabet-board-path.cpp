class Solution {
public:
    
    int n;
    
    string alphabetBoardPath(string target) {
    
        
        n=target.size();
        
        unordered_map<char,pair<int,int>>mp;
        
        vector<string>v={"abcde","fghij","klmno","pqrst","uvwxy","z"};
        
        for(int i=0;i<v.size();i++){
            
            string str=v[i];
            
            for(int j=0;j<v[i].size();j++){
                mp[v[i][j]]={i,j};
            }
        }
        
        
        string ans="";
        
        int i=0;
        
        int x=0,y=0;
        
        while(i!=target.size()){
            
            if(v[x][y]==target[i]){
                ans.push_back('!');
                i++;
            }
            else{
                
                char need=target[i];
                
                int x1=mp[need].first;
                
                int y1=mp[need].second;
                
                
                
                while(x1>x && (x<4 || y==0)){
                    ans.push_back('D');
                    x++;
                }

                
                while(x1<x){
                    ans.push_back('U');
                    x--;
                }
                
                while(y1>y && (x!=5)){
                    ans.push_back('R');
                    y++;
                }
                
                while(y1<y){
                    ans.push_back('L');
                    y--;
                }
                
            }
        }
        
        return ans;
        
    }
};