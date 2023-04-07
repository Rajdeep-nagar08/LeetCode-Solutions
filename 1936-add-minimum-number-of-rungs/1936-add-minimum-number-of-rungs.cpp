class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        
        
        int n=rungs.size();
        
                int ans=0;

        
        if(dist==1){
            
            
        if(rungs[0]!=0)
        ans+=rungs[0]-1;
            
            for(int i=1;i<n;i++){
                ans+=rungs[i]-rungs[i-1]-1;
            }
            
            return ans;
        }
        
        
        
        if(rungs[0]-0>dist)
        ans+=(rungs[0]-0)/dist-(rungs[0]%dist?0:1);
        
        for(int i=1;i<n;i++){
            if(rungs[i]-rungs[i-1]>dist)
            ans+=(rungs[i]-rungs[i-1])/dist-((rungs[i]-rungs[i-1])%dist?0:1);
        }
        
        return ans;
    }
};