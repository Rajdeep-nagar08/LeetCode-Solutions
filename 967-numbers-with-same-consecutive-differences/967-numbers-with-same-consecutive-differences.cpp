/*

abs(no[i]-no[i+1])=k

length of no=n

*/

#define lln long long int

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        
        vector<int>ans;
        
        
        queue<string>q;
        
        for(int i=1;i<=9;i++){
            q.push(to_string(i));
        }
        
        n--;
        
        while(!q.empty() && n){
            
            int sz=q.size();
            
            while(sz--){
                
                string str=q.front();
                
                q.pop();
                
                int n1=str.size();
                
                char ch=str[n1-1];
                
                int no=ch-'0';
                
               // cout<<ch<<" "<<no<<endl;
                
                                
                if(no+k<=9){
                    string s1=to_string(no+k);
                    q.push(str+s1);
                }  
                
                
                if(no-k>=0 && k!=0){
                    string s1=to_string(no-k);
                    q.push(str+s1);
                }
                
                  
            }
            
            n--;
            
        }
        
        
        while(q.size()>0){
            
            string s=q.front();
            
            q.pop();
            
            int dig=stoi(s);
            
            ans.push_back(dig);
            
        }
        
        
        return ans;
        
    }
};