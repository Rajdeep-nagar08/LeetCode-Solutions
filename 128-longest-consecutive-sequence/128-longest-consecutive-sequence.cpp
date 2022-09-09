/*

keeping all consecutive elements in one set :

to create set I'm using DSU

ans= size of largest set

*/

class Solution {
public:
    
    unordered_map<int,int>representative;

            unordered_map<int,int>size;
    
      int ans=1;

    int longestConsecutive(vector<int>& nums) {
        
        
        int n=nums.size();
        
        if(n==0)
            return 0;
        
        
        representative.clear();
        
        size.clear();
        
        for(int x:nums){
          representative[x]=x;
          size[x]=1;
        }
        
        /*
        
        +1 aur -1 difference wale numbers ko ekk hi set m rakhte h

         DSU ka use karte hue
         
         */
        
            
        for(int i=0;i<n;i++){
            
            if(representative.count(nums[i]-1)==1){
                
                int r1=find(nums[i]-1);
                
                int r2=find(nums[i]);
                
                combine(r1,r2);
                
           
                
            }
            
            if(representative.count(nums[i]+1)==1){
                
                int r1=find(nums[i]+1);
                
                int r2=find(nums[i]);
                
                combine(r1,r2);
           
            }
            
     }
        
     
        return ans;
        
    }
    
  
    int find(int u)
{
    if(u == representative[u])
        return u;
    
    else
        return representative[u] = find(representative[u]);
}

void combine (int u, int v)
{
    u = find(u);
    v = find(v);
    
    if(u == v)
        return;
    
    else
    {
        if(size[u] > size[v])
        {
            representative[v] = u;
            size[u] += size[v];
            
            ans=max(ans,size[u]);
        }
        
        else
        {
            representative[u] = v;
            size[v] += size[u];
            
            ans=max(ans,size[v]);
        }
    
    }
}
    
};