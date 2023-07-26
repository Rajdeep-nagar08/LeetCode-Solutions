/*
while making new friends, traverse the whole restriction array and check whether any restriction is breaking or not (either directly or indirectly) :- => for each new friends=>check for each restriction=>checking whether it is breaking or not using dfs on existing friends and new pair of friend [TC: O(n*n*n) =>> TLEEE]

Using Disjoint Set Union:

already friends => [!!!!!!]=>head=x1 , [?????]=> head=y1 , [%%%%%]=> head=z1

for New friend pair ={p,q}
if we include this pair, then find head of p and q if they are already in any friend circle

let head of p=> x1 , head of q=>z1
(note: if there heads are equal , it means they are already in same friend circle, so there is no problem to make them direct friends, they will no break any restriction as they are not making relationship out of their friend circle)

As x1!=z1 it means both {p,q} are not friends till now (as they are in different friend circles)

So after friendship between p and q , there will be friendship between both (x1 and z1 friend circles)

so before making p,q as friends , we traverse the whole restriction array and check there should not be any restriction between any persion of x1 and any person of z1, if any restriction found then they can't be friends

=>>>>>> checking restrictions as: let restriction pair is (a,b) , head of a=>x1, head of b=>y1
No problem (we can make (p,q) as friends)

let head of a=>z1 , head of b=>x1 , it mean we cant make p,q as friends, because if make them as friend then there will be indirect friendship between a,b

TC=> for each friend request=> check each restriction pair in O(1) using union find

=> O(n*n)
*/




class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& req) {
    
        vector<bool>ans;
        
        vector<int>head(n,-1);
     
        for(auto& it:req){
            
            int h1=find(head,it[0]);
            
            int h2=find(head,it[1]);
            
            bool friends=false;
            
            if(h1==h2){
                friends=true;// already friends
            }
            
            else
            {   
                friends=true;
                
                for(int i=0;i<rest.size();i++){
                    int h3=find(head,rest[i][0]);
                    int h4=find(head,rest[i][1]);
                    
        if((h3==h1 && h4==h2)||(h3==h2 && h4==h1)){
            friends=false;
            break;
           }
        else
           friends=true;
                    
              }
            
       if(friends==true)  //no restriction, make them friends
           head[h2]=h1;
          }
        ans.push_back(friends);
        }
     
        return ans;
            
    }
    
    int find(vector<int>&head,int i){
        if(head[i]<0)
            return i;
        
        return head[i]= find(head,head[i]);
    }
    
};
