class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int n=arr.size();
            
        int count=n/4;
        
        int i=0;
        int k=0;
        while(i<n){
            int x=arr[i];
            k=0;
            while(i<n && arr[i]==x){
                i++;
                k++;
            }
            if(k>count)
                return x;
        }
        return -1;
    }
};