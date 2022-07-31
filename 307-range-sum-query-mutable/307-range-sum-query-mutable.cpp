 
class NumArray {
public:
vector<int>BIT;
 int n;
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        
        BIT.resize(n+1,0);
        
        for(int i=0;i<n;i++)
         upd(i+1,nums[i]);
       
    }
    
    void update(int index, int val) {
      int diff=val-sumRange(index,index);
        upd(index+1,diff);
    }
    
    
    int sumRange(int left, int right) {
        left++;
        right++;
      return query(right)-query(left-1);
    }
    
   
 int query(int x) {
     
    // return sum of prefix from [1.....x]

    int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += BIT[x];

     return sum;
   }
    
     void upd(int index,int val){
         
      for(; index <= n; index += index&-index)
        BIT[index] += val;

     }

};

