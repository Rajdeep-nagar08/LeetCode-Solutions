class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        /*
        
        speed = 1 unit/sec
        
        if two ants collide, they change their directions
        
        if any ant reaches one end of the plank, it will fall immediately
        
        return the time when all ants fall down
        
        
     if two ants collide, they change their directions == NO change in direction of ant, they crossover each oter
     
     so its simple
     
     ans= position of ant which is farthest from its opposite corner
       

        
        */
    
        int l=left.size();
    
        int r=right.size();
    
        int ans=INT_MIN;
        
       if(l>0) 
       ans=max(ans,*max_element(left.begin(),left.end()));
    
        if(r>0)
        ans=max(ans,n-*min_element(right.begin(),right.end()));
    
    return ans;

        
    }
};