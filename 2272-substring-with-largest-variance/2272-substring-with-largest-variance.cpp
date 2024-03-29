/*

varience = largest difference btw freq. of any 2 chars in the string

largest varience among all possible substrings of string str

s = "aababbb"

largest varience is 3, for substring = "babbb"

if our string have only two chars like "aababbb"

choosig 'a' and 'b' 

repplace a=> 1, b=> -1

1 1 -1 1 -1 -1 -1

now ans corresponds to this string is => max contigous subarray sum such that it should containe atleat single -1

(this can be found out as -:

    on each -1
    
    temp => maxSumTowrds its left + (-1) + maxSum towards its right
    
    this can be done using pref and suff sum sum and max array formation
)



so for any general string

we have atmost 26 different chars in it

so each time we choose two chors among 26 and replace one by +1 and other by -1


*/

class Solution {
public:
    int largestVariance(string s) {
        
        
        int n=s.size();
        
        unordered_map<char,int>mp;
        
        for(char ch:s){
            mp[ch]++;
        }
        
        int mx=0;
        
        for(auto it1:mp){  // 26
            
            for(auto it2:mp){  // 26
                
                char ch1=it1.first;
                
                char ch2=it2.first;
                
                if(ch1==ch2)
                    continue;
                
                
                vector<int>v;
                
                for(char ch:s){
                    if(ch==ch1)
                        v.push_back(1);
                else if(ch==ch2)
                    v.push_back(-1);
                
            }
            
            
            ///  call kadans
            
            int mx1=kadans(v);  // O(n)
        
        
        
        mx=max({mx,mx1});
        
       // cout<<ch1<<" "<<ch2<<" "<<mx1<<" "<<mx2<<endl;

            
        }
            
    }
    
    return mx;
    
        
    }
    
    int kadans(vector<int>&a){
        
       int n=a.size();
        
        vector<int>pref(n);
        
        pref[0]=a[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+a[i];
        }
        
        vector<int>mxr(n);
        
        mxr[n-1]=pref[n-1];
        
        for(int i=n-2;i>=0;i--){
            mxr[i]=max(mxr[i+1],pref[i]);
        }
        
          vector<int>suff(n);
        
        suff[n-1]=a[n-1];
        
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+a[i];
        }
        
        vector<int>mxl(n);
        
        mxl[0]=suff[0];
        
        for(int i=1;i<n;i++){
            mxl[i]=max(mxl[i-1],suff[i]);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(a[i]==1)
                continue;
            
            int right=mxr[i]-pref[i];
            
            int left=mxl[i]-suff[i];
            
            int total=left+right-1;
            
            ans=max(ans,total);
        }
        
        return ans;
        
        
   }
};