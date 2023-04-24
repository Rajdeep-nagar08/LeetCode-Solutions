class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1)
            return stones[0];
        
        priority_queue<int>pq;
        for(int x:stones)
           pq.push(x);
        
        
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x>y)
                pq.push(x-y);
            else if(y>x)
                pq.push(y-x);
            else pq.push(0);
        }
      
        return pq.top();
    }
};