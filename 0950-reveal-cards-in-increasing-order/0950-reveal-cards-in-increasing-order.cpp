class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      
        int n=deck.size();
    
        vector<int>ans(n);
        
        sort(deck.begin(),deck.end());
        
        int i=0;
                
                
        queue<int>q;
        
        for(int i=0;i<n;i++){
            q.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans[q.front()]=deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
    
        
        return ans;
    }
};