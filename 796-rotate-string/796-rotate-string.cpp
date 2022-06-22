class Solution {
public:
    bool rotateString(string s, string goal) {
        
        
        if(s.size()!=goal.size())
            return false;
        
                s=s+s;

        
        int idx=s.find(goal);
        
        if(idx!=-1)
            return true;
        
        return false;
        
    }
};