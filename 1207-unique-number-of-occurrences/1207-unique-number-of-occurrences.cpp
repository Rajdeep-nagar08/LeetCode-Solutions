class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      int n=arr.size();
        sort(arr.begin(),arr.end());
        int temp=arr[0];
        int l=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=temp){
                temp=arr[i];
                l++;
            }
        }
        vector<int> v(l,0);
        int k=0;
        temp=arr[0];
        for(int i=0;i<n;i++){
            if(temp!=arr[i]){
                k++;
                temp=arr[i];
            }
            v[k]++;
        }
    
        sort(v.begin(),v.end());
        for(int i=0;i<l-1;i++){
            if(v[i]==v[i+1]){
                return false;
            }
        }
        return true;  
    }
};