class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        
        int n=cp.size();
        
        /*
        
        k1 card from the begining + k2 card from the end
        
        sum of card is max possible
        
        ka+k2=k
    
        */
         
        
        int ans=INT_MIN;
        
        int sum=0;
        
        int i=0;
        
        while(i<k){
            sum+=cp[i];
            i++;
        }
        
        ans=max(ans,sum);
        
        if(k==n)
            return ans;
        
        i--;
        
        int j=n-1;
        
        while(i>=0){
            sum=sum-cp[i]+cp[j];
            ans=max(ans,sum);
            i--,j--;
        }
        
        return ans;
    }
};