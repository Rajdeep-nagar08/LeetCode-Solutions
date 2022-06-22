class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int dur) {
        
        
        int n=ts.size();
        
        int ans=0;
        
        int start=ts[0],end=ts[0]+dur-1;;
        
        int i=1;
        
        while(i<n){
            if(end<ts[i]){
                start=ts[i];
                end=ts[i]+dur-1;
                ans+=dur;
            }
            else{
               
                ans+=ts[i]-start;
                
                 start=ts[i];
                end=ts[i]+dur-1;
            }
            
            cout<<ans<<endl;
            
            i++;
        }
        
        ans+=dur;
        
        return ans;
    }
};