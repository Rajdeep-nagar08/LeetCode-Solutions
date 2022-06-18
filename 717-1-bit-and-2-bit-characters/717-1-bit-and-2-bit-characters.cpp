class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n=bits.size();
        
        if(bits[n-1]!=0)
            return false;
        
        int i=0;
                
        while(i<=n-2){
            if(bits[i]==0){
                i++;
            }
            else if(i==n-2)
                return false;
            
            else
                i+=2;
        }
        
        return true;
    }
};