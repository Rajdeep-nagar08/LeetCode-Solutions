class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return false;
     int c=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2){
                c++;
                if(c==3)
                    return true;
            }
            else
              c=0;
        }
        return false;
            
    }
};