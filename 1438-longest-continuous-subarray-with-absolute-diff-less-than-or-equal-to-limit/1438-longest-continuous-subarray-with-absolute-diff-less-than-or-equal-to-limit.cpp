/*

max absolute diff of subarray = max elememnt of subarray- min element of subarray < = limit

return such subarray of longest size

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
            
        //    cout<<mn<<" "<<mx<<endl;
            
       //     cout<<j<<" "<<i<<" "<<ans<<endl;

            
            i++;
            
            if(i<n)
            st.insert({nums[i],i});
            
            else
                
                break;
            
            
        }
        
        return ans;
        
    }
};