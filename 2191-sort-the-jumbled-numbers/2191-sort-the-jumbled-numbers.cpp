class Solution {
public:
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) {
    
        sort(nums.begin(),nums.end(),[&map](int x, int y){
            string s1=to_string(x);
            string s2=to_string(y);
            for(char &ch: s1){
                ch=map[ch-'0']+'0';
            }
            for(char &ch: s2){
                ch=map[ch-'0']+'0';
            }
            int no1=stoi(s1);
            int no2=stoi(s2);
            return no1<no2;
        });
        
        return nums;
    }
};