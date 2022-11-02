class Solution {
public:
    
    
    unordered_map<string,int>mp;
    
    bool flag=false;
      
    int ans=INT_MAX;
    
    vector<char>v={'A','G','C','T'};
    
    int minMutation(string start, string end, vector<string>& bank) {
        
        
        for(string str:bank){
            mp[str]++;
        }
        
        mp[start]++;
        
        int step=0;
        
        find(0,start,end,step);
    
        if(flag)
        return ans;
        
        return -1;
    }
    
    void find(int k,string &start,string &end,int step){
        if(k>=8 || (start==end)){
            if(start==end){
            flag=true;
            ans=min(ans,step);
            }
            return;
        }
        
        
        for(int i=0;i<8;i++){
           
              for(int j=0;j<4;j++){
            if(start[i]!=v[j]){
                
                char ch=start[i];

                start[i]=v[j];
                
                if(mp[start]>0){
                   // cout<<start<<endl;
                find(k+1,start,end,step+1);
                }
                    
                start[i]=ch;
   
            }
        }
        
            
        }
        
      
        
    }
};