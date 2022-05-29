class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        
        vector<int>mask(n,0);
        
       for(int i=0;i<n;i++){
           string str=words[i];
           
           for(char ch:str){
               mask[i]=mask[i]|(1<<(ch-'a'));
           }
       }
        
        int mx=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if((mask[i]&mask[j])==0)
                    mx=max(mx,(int)words[i].size()*(int)words[j].size());
            }
        }
       
        return mx;
    }
};