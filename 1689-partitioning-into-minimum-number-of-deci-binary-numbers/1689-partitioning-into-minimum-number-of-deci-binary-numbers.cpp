/*
we needs to find out the minimum numbers of deci binary numbers needed to form given number

=  max integer in the number

*/


class Solution {
public:
    int minPartitions(string n) {
        
        int ans=0;
        
        for(char ch:n){
            ans=max(ans,ch-'0');
        }
        
        return ans;
    }
};