class Solution {
public:
    string largestWordCount(vector<string>& msg, vector<string>& send) {
        
        int n=send.size();
        
        unordered_map<string,int>mp;
        
        
        int mx=-1;
        
        for(int i=0;i<n;i++){
            int c=fun(msg[i]);
            mp[send[i]]+=c;
            
            mx=max(mx,mp[send[i]]);
        }
        
        string ans="";
        
        for(auto it:mp){
            if(it.second==mx){
                if(ans<it.first){
                    ans=it.first;
                }
            }
        }
        
       return ans; 
        
    }
    
int fun(string str){    // str = asdfgh jkl asdfgh jkl
stringstream ss(str);
string word;
int count=0;
while(ss>>word)
count++;

return count;          // count = 4
}

};