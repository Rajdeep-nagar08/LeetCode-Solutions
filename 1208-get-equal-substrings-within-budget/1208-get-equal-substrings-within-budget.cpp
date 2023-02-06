class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        
        int n=s.size();
        
        /*
        
        cost of changing s[i] to t[i] = |s[i]-t[i]|
        
        max length of substring of that can be changed so that cost <=maxCost
     
        */
     
        vector<int>pref(n,0);
        
        for(int i=0;i<n;i++){
            pref[i]=abs(s[i]-t[i]);
        }
        
        for(int i=1;i<n;i++){
            pref[i]+=pref[i-1];
        }
        
        
//         for(int i=0;i<n;i++){
//             cout<<pref[i]<<" ";
//         }
        
        int mx=0;
        
        for(int i=0;i<n;i++){
            
            int prev=0;
            
            if(i>0)
                prev=pref[i-1];
            
            int need=prev+maxCost;
            
            int i1=upper_bound(pref.begin(),pref.end(),need)-pref.begin();
            
         //   cout<<i1<<endl;
            
            i1--;
        
            mx=max(mx,i1-i+1); 
            
             
        }
        
        
   return mx;
        
    }
};