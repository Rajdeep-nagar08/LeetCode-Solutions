/*

In one step, we can change any no. to any other no.

Min no. of steps to make the array alternating ?


all even index no's should be equal


all odd index numbers should also be equal



*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n= nums.size();
        
        unordered_map<int,int>even;
        
        int mxe=0;
        int no=0;
        int e=0;

        for(int i=0;i<n;i+=2){
            even[nums[i]]++;
            if(mxe<even[nums[i]]){
                mxe=even[nums[i]];
                no=nums[i];
            }
            e++;
        }
        
        
        unordered_map<int,int>odd;
        
        int mxo=0;
        int no1=0;
        int o=0;
        
        for(int i=1;i<n;i+=2){
            odd[nums[i]]++;
            
             if(mxo<odd[nums[i]]){
                mxo=odd[nums[i]];
                no1=nums[i];
            }
            o++;
        }
        
        
        // keeping max freq. no with even indexes
    
           int total1=0;
        
            total1+=e-mxe;
        
              int mxo1=0;  // max freq. of a no that is not at even index
                    
        for(auto it:odd){
            
             if(mxo1<it.second && (it.first!=no)){
                mxo1=it.second;
            }
        
        }
        
         total1+=(o-mxo1);
            
            
     // keeping max freq. no with odd indexes       
        
            int total2=0;
            
            total2+=o-mxo;
                        
            int mxe1=0;     // max freq. of a no that is not at even index


        for(auto it:even){
            if(mxe1<it.second && it.first!=no1){
                mxe1=it.second;
            }
        }
            
             total2+=(e-mxe1);
        
      //  cout<<total1<<" "<<total2<<endl;
            
        return min(total1,total2);
        
    }
};