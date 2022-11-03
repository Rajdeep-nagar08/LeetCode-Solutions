class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        
        int n=words.size();
        
        unordered_map<string,int>mp;
        
        for(string str:words){
            mp[str]++;
        }
        
        vector<int>v;
        
        int ans=0;
        
        int mxOdd=0;
        
        int odd=0;
        
        int evn=0;
        
        for(auto it:mp){
            
            string s1=it.first;
            
         //   cout<<s1<<" "<<mp[s1]<<endl;
            
            string s2=s1;
            
            reverse(s2.begin(),s2.end());
            
            if(s1==s2){
                if(mp[s1]%2==0)
                    ans+=2*mp[s1];
                else{
                    mxOdd=max(mxOdd,mp[s1]);
                    odd+=(mp[s1]-1);
                }
            }
            else{
                if(mp.count(s2)==1){
                    ans+=(min(mp[s1],mp[s2]))*4;
                    
                    mp.erase(s2);
                }
            }
        }
            
        
        ans+=mxOdd*2;
        
        if(mxOdd-1>=0)
        odd-=(mxOdd-1);
        
        ans+=odd*2;
        
        return ans;
        
    }
};