#define lln long long int
class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        
       int n=nums.size();
        
        
        /*
        
        let
        
        nums[k] < nums[j]
        
        count of valid i's => c1= no's in a range [0....j] that are smaller then nums[k]
        
        
        count of valid l's => c2= no's in a range [k....n-1] that are greater then nums[j]
        
        
        corresponding ans= c1*c2
        

        */
    
        
        vector<vector<int>>pref(n,vector<int>(n,0));
        
        // pref[i][j] = count of no's in a range [i......j] that are smaller then nums[j] 
        
        // clearly c1=pref[0][k]-pref[j][k] 
        
        vector<vector<int>>suff(n,vector<int>(n,0));

        
        // suff[i][j] = count of no's in a range [i...j] that are greater then nums[i]
        
        // clearly c2=suff[j][n-1]-suff[j][k]
        
     
        for(int j=0;j<n;j++){
            
            int c=0;
            
            for(int i=j-1;i>=0;i--){
                
                if(nums[i]<nums[j])
                    c++;
                
                pref[i][j]=c;
            }
        }
        
        
        
        for(int i=0;i<n;i++){
            
            int c=0;
            
            for(int j=i+1;j<n;j++){
                
                if(nums[j]>nums[i])
                    c++;
                
                suff[i][j]=c;
            }
        }
        
        
        lln ans=0;
        
        for(int j=1;j<n;j++){
            
            for(int k=j+1;k<n-1;k++){
                
                if(nums[k]<nums[j]){
                    
                    lln c1=pref[0][k]-pref[j][k];  // [0...j-1]
                    
                    
                    lln c2=suff[j][n-1]-suff[j][k];  //[k+1...n-1] 
                    
                    ans+=c1*c2;
                }
            }
        }
        
        return ans;
    }
};