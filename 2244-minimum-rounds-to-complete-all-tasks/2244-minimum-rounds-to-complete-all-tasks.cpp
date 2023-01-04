class Solution {
public:
    int minimumRounds(vector<int>& t) {
        
        
        unordered_map<int,int>mp;
    
        for(int x:t){
            mp[x]++;
        }
    
        priority_queue<int>pq;
        
        for(auto it:mp){
            pq.push(it.second);
        }
        
        int count=0;
        
        while(pq.size()>0){
            int x=pq.top();
            pq.pop();
            
            if(x<2)
                return -1;
           
            else if(x==3 || x==2){
                count+=1;
            }
            
            
            else if(x==4){
                count+=2;
            }
            
            else if(x>4){
                x=x-3;
                count++;
                pq.push(x);
            }
        }
        
        return count;
    }
};