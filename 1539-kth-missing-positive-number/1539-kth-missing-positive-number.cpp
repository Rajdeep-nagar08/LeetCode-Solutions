class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n=arr.size();
        
        vector<int>v(1001,0);
        
        for(int i=0;i<n;i++){
            v[arr[i]]=1;
        }
        
        for(int i=1;i<1001;i++){
            if(v[i]==0)
                k--;
            
            if(k==0)
                return i;
        }
      
        int i=1000;
        
        while(true){
            i++;
            k--;
            
            if(k==0)
                return i;
            
        }
        
        return -1;
    }
};