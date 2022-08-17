/*

max absolute diff of subarray = max elememnt of subarray- min element of subarray < = limit

Using sliding window technique

as we can have multiple occurenece of same element, we use multiset to store elements of a window {no,index}

min element of window = top element of multiset
max element = last element of multiset


*/

#define pp pair<int,int>

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        int i=0,j=0;
        
        int n=nums.size();
       
        int ans=1;
        
        multiset<pair<int,int>>st;
        
        int mn,mx;
        
        while(i<n){
            
            st.insert({nums[i],i});
            
            auto it1=*st.begin();
            mn=it1.first;
            
            auto it2=*st.rbegin();
            mx=it2.first;
            
            if(mx-mn<=limit){
                ans=i+1;
            }
            else{
                break;
            }
            
            i++;
            
        }
        
        
        while(i<n){
            
             auto it1=*st.begin();
            mn=it1.first;
            
            auto it2=*st.rbegin();
            mx=it2.first;
            
            if(mx-mn>limit){
                
               while(j<i){
                   
                   st.erase({nums[j],j});
                   
                   j++;
                   
            auto it1=*st.begin();
            mn=it1.first;
            
            auto it2=*st.rbegin();
            mx=it2.first;
                   
                   if(mx-mn<=limit)
                       break;
                   
                   
               } 
                
            }
           

            ans=max(ans,i-j+1);
   
            i++;
            
            if(i<n)
            st.insert({nums[i],i});
            
            else
                
                break;
            
            
        }
        
        return ans;
        
    }
};