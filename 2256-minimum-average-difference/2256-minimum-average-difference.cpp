#define lln long long int

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        
        vector<lln>pref(n);
        
        pref[0]=nums[0];
        
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        
        lln mn=1e18;
        int idx;
        
        for(int i=0;i<n-1;i++){
    
            lln f=(pref[n-1]-pref[i]);
            lln b=(pref[i]);
            lln a1=(f/(n-1-i));
            lln a2=(b/(i+1));
                
            int avg=abs(a1-a2);
            
            if(avg<mn){
                mn=avg;
                idx=i;
             }
          //  cout<<avg<<endl;
        }
     //   cout<<mn<<endl;
      //  cout<<pref[n-1]/n<<endl;
        if((pref[n-1]/n) < mn)
            return n-1;
        
        return idx;
        
    }
};