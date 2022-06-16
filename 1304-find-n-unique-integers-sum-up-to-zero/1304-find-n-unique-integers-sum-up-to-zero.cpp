class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>ans;
        
        if(n%2==1){
            ans.push_back(0);
            n--;
        }
        
        int need=n/2;
        
        int no=1;
        
        while(need>0){
            ans.push_back(no);
                        ans.push_back(-no);
            need--;
            no++;
        }
        
        return ans;
    }
};