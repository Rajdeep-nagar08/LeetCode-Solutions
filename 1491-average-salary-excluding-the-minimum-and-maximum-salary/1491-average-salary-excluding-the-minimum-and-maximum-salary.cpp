class Solution {
public:
    double average(vector<int>& sal) {
        
        int n=sal.size();
        
        int mn=*min_element(sal.begin(),sal.end());
        
        int mx=*max_element(sal.begin(),sal.end());
        
        int sum=0;
        
        for(int x:sal){
            sum+=x;
        }
        
        return double((double)(sum-mn-mx)/(double(n-2)));
        
    }
};