class Solution {
public:
    bool isPathCrossing(string path) {
        
        
        map<pair<int,int>,int>mp;
        
        int x=0,y=0;
        
        mp[{0,0}]++;
        
        for(char ch:path){
            if(ch=='N'){
                y++;
            }
            else if(ch=='S'){
                y--;
            }
            else if(ch=='E'){
                x++;
            }
            else{
                x--;
            }
           if(mp.count({x,y})==1){
               return true;
           }
            
            else{
                mp[{x,y}]++;
            }
        }
        
        return false;
    }
};