class Solution {
public:
    int maxRepOpt1(string text) {
       
        
        int n=text.size();
        
        vector<vector<int>>pref(n,vector<int>(26,0));
        
        pref[0][text[0]-'a']++;
        
        for(int i=1;i<n;i++){
            
            if(text[i]==text[i-1])
                pref[i][text[i]-'a']+=pref[i-1][text[i-1]-'a']+1;
            
            else
                pref[i][text[i]-'a']++;
   
        }
        
        
         vector<vector<int>>suff(n,vector<int>(26,0));
        
        suff[n-1][text[n-1]-'a']++;
        
        for(int i=n-2;i>=0;i--){
            
            vector<int>freq(26,0);
            
            if(text[i]==text[i+1])
                freq[text[i]-'a']+=suff[i+1][text[i+1]-'a']+1;
            
            else
                freq[text[i]-'a']++;
            
            suff[i]=freq;
   
        }
        
        unordered_map<char,int>mp;
        
        for(char ch:text){
            mp[ch]++;
        }
        
        int mx=1;
        
        for(int i=1;i<=n-2;i++){
            
            
    if(text[i]!=text[i-1] && (text[i]!=text[i+1]) && (text[i-1]==text[i+1])){
        
        int total=mp[text[i+1]];
        
        int avl=pref[i-1][text[i-1]-'a']+suff[i+1][text[i+1]-'a'];
        
        if(avl==total){
            
           mx=max(mx,total);
            
        }
        
        else{
            
            mx=max(mx,avl+1);
        }
        
        
    }
            
            else{
                
    mx=max(mx,pref[i][text[i-1]-'a']+suff[i][text[i+1]-'a']-1);
                
    
    int prevF=mp[text[i-1]];
                
    int avlp=pref[i-1][text[i-1]-'a'];
                
    if(avlp<prevF)
        mx=max(mx,avlp+1);
                
                
    int nextF=mp[text[i+1]];
    
    int avln=suff[i+1][text[i+1]-'a'];
                
    if(avln<nextF)
        mx=max(mx,avln+1);
                
   
            }
            
            
        }
        
        
        mx=max({mx,suff[0][text[0]-'a'],pref[n-1][text[n-1]-'a']});
        
        
        return mx;
        
        
    }
};