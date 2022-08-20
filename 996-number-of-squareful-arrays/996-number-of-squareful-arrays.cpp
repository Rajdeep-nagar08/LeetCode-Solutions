
class Solution {
public:
    
    int n;
    
    int count=0;
    
    set<vector<int>>st1;
    
    int sq(int num){
        int tem = sqrt(num);
        return tem*tem == num;
    }
    void fun(int prev,unordered_set<int> &st,unordered_map<int,int> &mp){
        
        if(!st.size()){ 
            count++;
            return;
        }
        
        
        // cout<<"f"<<endl;
        auto st1=st;
        
      for(auto val:st1){
          
          if(prev == -1 or sq(val+prev)){
              mp[val]--;
              
              if(!mp[val]){
                  
               //   cout<<val<<endl;
                  
                  if(st.count(val))
                  st.erase(val);
                  
              }
              
              fun(val,st,mp);
              mp[val]++;
              if(mp[val]==1){
                //  cout<<val<<endl;
                  st.insert(val);
              }
             
          }
      }
    }
    
    int numSquarefulPerms(vector<int>& nums) {
        
        n=nums.size();
        
       
        unordered_set<int>st;
        for(auto val:nums){
            st.insert(val);
        }
        unordered_map<int,int> mp;
        
        for(auto val:nums)
            mp[val]++;
        
        fun(-1,st,mp);
        
        return count;
        
        // find(0,0,temp,nums);
        
       // return (int)st1.size();
        
    }
    
    void find(int i,int mask,vector<int>&temp,vector<int>nums){
        
        if(i>=n){
            
            st1.insert(temp);
        
            return;
        }
        
        for(int j=0;j<n;j++){
            
            if(mask & (1<<j))
                continue;
            
            if(temp.size()==0 ){
            
                temp.push_back(nums[j]);
                
                find(i+1,mask|(1<<j),temp,nums);
                
                temp.pop_back();
                   
                
            }
            
            else{
                
                int no1=temp.back();
                
                int no2=nums[j];
                
                int x=sqrt(no1+no2);
                
                if(x*x==no1+no2){
                    
                temp.push_back(nums[j]);
                
                
                find(i+1,mask|(1<<j),temp,nums);
                
                temp.pop_back();
                
                    
                }
            }
            
        }
    }
      
};