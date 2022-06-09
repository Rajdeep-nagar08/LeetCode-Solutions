class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        
        
        int i=0;
        int j=num.size()-1;
        
        while(i<j){
            if(num[i]+num[j]==target)
                return {i+1,j+1};
            else if(num[i]+num[j]<target)
                i++;
            else
                j--;
        }
        
        return {};
    }
};