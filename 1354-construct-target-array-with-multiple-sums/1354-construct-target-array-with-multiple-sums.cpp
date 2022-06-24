   /*
        
        array of 1's of same size
        
        each time , replace any element of this array by sum of this array
        
        Is it possible to make this array equals to target array ?
        
        We move in reverse direction, 
        
        max element of array must be formed by sum of all elements
        
        so we replace it by , maxElement-sum of rest elements
        
        we do so till all elements not equals to 1, 
        
        If multiple operations were done on same element we have to do this same operation multiple times. Insted we can just return pq.top() % sum.
        
Broader Explanation: 

If the sum and replace operation was done at a single position multiple times then in that case the sum of remaining numbers were added multiple times to the number. 
So to get back the old number we have to substract the remaining sum from the same top element over and over again untill the element becomes less than the remaining sum and any ither element becomes the top value.

So the ultimate old value which will not be the top, is the remainder i.e. pq.top() % sum. In this way we can save pq.top() / sum iterations in each step. This saves the code from running into TLE
        
        */
        
#define lln long long int
class Solution {
public:
    bool isPossible(vector<int>& tar) {
         
        int n=tar.size();
        
        lln sum=0;
        
       priority_queue<lln>pq;

        for(int x:tar){
            sum+=x;
            pq.push(x);
        }
        
        while(pq.top()!=1){
            lln mx=pq.top();
            pq.pop();
            lln rest=sum-mx;
            
            if(rest<=0)
                return false;
            
            lln prev=mx-rest;
            
            if(prev<1)
                return false;
            
            prev=prev%rest;
            
            if(prev==0 && rest!=1)
                return false;
            
            pq.push(prev);
            
            sum=sum-mx+prev;

        }  
       
       return true;
  }
    
};