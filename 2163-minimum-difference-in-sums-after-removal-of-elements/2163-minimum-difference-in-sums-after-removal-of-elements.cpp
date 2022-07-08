
/*

sum1-sum2= min ,  so keep sum1 as min as possible and keep sum2 as max as possible


It is also give that all elements of sum1 lies to the left of all elements of sum2

No of elements in sum1 = n

No of elements in sum2= n

General : [......(sum1).....| ......(sum2).....]


[a,b,c,d,e  |  f,g,h,i,j,k,l,m,n,o]

sum1= a+b+c+d+e  , sum2= sum of top 5 max elements in [f,g,h,i,j,k,l,m,n,o]

ans=min(ans,sum1-sum2)


[a,b,c,d,e,f | g,h,i,j,k,l,m,n,o]

sum1= sum of top 5 min element in [a,b,c,d,e,f]

sum2= sum of top 5 max elements in [g,h,i,j,k,l,m,n,o]

ans=min(ans,sum1-sum2)


[a,b,c,d,e,f,g | h,i,j,k,l,m,n,o]

sum1= sum of top 5 min element in [a,b,c,d,e,f,g]

sum2= sum of top 5 max elements in [h,i,j,k,l,m,n,o]

ans=min(ans,sum1-sum2)


[a,b,c,d,e,f,g h | i,j,k,l,m,n,o]

sum1= sum of top 5 min element in [a,b,c,d,e,f,g.h]

sum2= sum of top 5 max elements in [i,j,k,l,m,n,o]

ans=min(ans,sum1-sum2)



[a,b,c,d,e,f,g h,i | j,k,l,m,n,o]

sum1= sum of top 5 min element in [a,b,c,d,e,f,g,h,i]

sum2= sum of top 5 max elements in [j,k,l,m,n,o]

ans=min(ans,sum1-sum2)



[a,b,c,d,e,f,g h,i,j | k,l,m,n,o]

sum1= sum of top 5 min element in [a,b,c,d,e,f,g,h,i,j]

sum2= sum of top 5 max elements in [k,l,m,n,o]

ans=min(ans,sum1-sum2)



Cleary we use max haep to store top 5 min element on left side of bar for each position of bar

And we use min heap to store top 5 max element on right side of bar for each position of bar


*/

#define lln long long int

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        
        int n=nums.size()/3;
        
        
        priority_queue<int>pq1;

        
        vector<lln>v1; 
        
// to store sum of top n min elemennts on left side of bar at each positon of bar
        
        lln sum1=0;
        
        for(int i=0;i<2*n;i++){
            sum1+=nums[i];
            pq1.push(nums[i]);
            
            if(pq1.size()>n){
                sum1-=pq1.top();
                pq1.pop();
            }
            
            if(pq1.size()==n)
           v1.push_back(sum1);

        }
        
     priority_queue<lln,vector<lln>,greater<int>>pq2;
     

// to store sum of top n max elemennts on right side of bar at each positon of bar
        
        vector<lln>v2;
        
        lln sum2=0;
        
        for(int i=3*n-1;i>=n;i--){
            sum2+=nums[i];
            
            pq2.push(nums[i]);
            
            if(pq2.size()>n){
                sum2-=pq2.top();
                pq2.pop();
            }
            
    
         if(pq2.size()==n)
          v2.push_back(sum2);
            
        }
        
        reverse(v2.begin(),v2.end());
        
        int sz=v1.size();
        
        lln ans=1e18;
        
        for(int i=0;i<sz;i++){
          //  cout<<v1[i]<<" "<<v2[i]<<endl;
            ans=min(ans,v1[i]-v2[i]);
        }
        
        return ans;
        
    }
};