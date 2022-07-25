class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int>ans;
        
        for(int i=left;i<=right;i++){
            if(check(i))
                ans.push_back(i);
        }
        
        return ans;
    }
    
    bool check(int no){
        string str=to_string(no);
        
        for(char ch:str){
            int n=ch-'0';
            if(n==0 || (no%n))
                return false;
        }
        return true;
    }
};