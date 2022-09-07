class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        arr[0]=1;
        
        for(int i=0;i<=n-2;i++){
            
            if(arr[i+1]-arr[i]>1){
                arr[i+1]=arr[i]+1;
            }
        }
        
        return arr[n-1];
        
    }
    
};