
/*

for each permutation of given string

we are counting no. of combinations :


*/

class Solution {
public:
    int numTilePossibilities(string str) {
        
        vector<string>v;
        
        sort(str.begin(),str.end());
        
        
        do{
            v.push_back(str);
        }while(next_permutation(str.begin(),str.end()));
        
        
        int n=str.size();
        
        unordered_set<string>st;
        
        for(int mask=1;mask<=(1<<n)-1;mask++){
            
            for(string str:v){
                
                string temp;
                
                for(int i=0;i<n;i++){
                    
                    if(mask & (1<<i)){
                        temp+=str[i];
                    }
                }
                
                st.insert(temp);
            }
        }
        
        return (int)st.size();
        
    }
};