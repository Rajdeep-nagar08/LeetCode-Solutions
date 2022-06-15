class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
      
        /*
        as we needs to remove max to max stones 
        so we always pick max piles and remove x/2 stones from it
        
        */
        
    priority_queue<int>p;

        
        int sum=0;
        for(int x:piles){
            sum+=x;
            p.push(x);
            
        }
        
        while(k>0 && p.size()>0){
            
            int t=p.top();
            p.pop();
            
            int rmv=t/2;
            sum=sum-rmv;
            int left=t-rmv;
            if(left>0)
                p.push(left);
            
            k--;
        }
        
        return sum;
        
    }
};