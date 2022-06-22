class Solution {
public:
    int wateringPlants(vector<int>& plants, int cap) {
        
        int n=plants.size();
        
       // ith plant at dist = i, plant 0 at i=0, plant 1 at i=1
        
        int sum=0;
        
        int count=0;
        
        int i=0;
        
        while(i<n){
            sum=sum+plants[i];
            
            if(sum<=cap){
                i++;
                count++;
            }
            else{
                
               count+=i;  // move back
               count+=i+1; // come forward
                sum=plants[i];
                i++;
            
            }
        }
        
        return count;
        
    }
};