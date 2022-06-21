/*

we needs to cover more and more distance,

2 bulidings ke bich ke difference ko hame bricks ya ladders ki help se cover karna h, 

ladder ki help se ham badi se badi building par chadd sakte h

so kisi bhi index i tak jo bhi 'l' maximum building hongi unper ham 'l' ladders se chadenge 

Note: ham atleast kisi bhi 'l' buildings par chad sakte h, isliye hame vha tak move kar sakte h jha tak top 'l' buildings ke alawa jo buildings h unper ham given bricks ki help se chadd sake

*/



class Solution {
public:
    int furthestBuilding(vector<int>& ht, int b, int l) {
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        int n=ht.size();
        
        int i=0;
        
        while(i<=n-2 && l>0){
            if(ht[i+1]-ht[i]>0){
                pq.push(ht[i+1]-ht[i]);
                l--;
            }
            i++;
        }
        
        int count=0;
        
        while(i<=n-2){
            if(ht[i+1]-ht[i]>0){
                pq.push(ht[i+1]-ht[i]);
                count+=pq.top();
                if(count<=b){
                    pq.pop();
                }
                else 
                    break;
            }
            i++;
        }
        
        return i;
    }
};