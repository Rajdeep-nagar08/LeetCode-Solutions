class Solution {
public:
    int maxVowels(string s, int k) {
        
        int n=s.size();
        
        set<char>st={'a','e','i','o','u'};
        
        int count=0;
        
        int i=0;
        
        while(i<k){
            if(st.count(s[i])==1){
                count++;
            }
            i++;
        }
        
        int ans=count;
        
        // cout<<ans<<endl;
        
        int j=0;
        
        while(i<n){
            
            if(st.count(s[j])==1){
                count--;
            }
            
            j++;

            if(st.count(s[i])==1){
                count++;
            }
            
            i++;

            
            ans=max(ans,count);
            
            // cout<<ans<<endl;
            
        }
        
        return ans;
        
    }
};