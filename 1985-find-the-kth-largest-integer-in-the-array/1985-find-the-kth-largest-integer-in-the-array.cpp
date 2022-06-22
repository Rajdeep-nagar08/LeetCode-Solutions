class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        int n=nums.size();
        
        
        // sorting array in increasing order
        
        sort(nums.begin(),nums.end(),[](string &a,string &b){
            
            
            int n1=a.size();
            int n2=b.size();
            
            if(n1==n2)
                return a<b;
            
            else
                return n1<n2;
            
            /*
            if(n1<n2)
                return true;
            
            else if(n1>n2)
                return false;
           
            
            int i=0;
            
            int no1,no2;
            
            while(i<n1){
                no1=a[i]-'0';
                no2=b[i]-'0';
               // cout<<no1<<" "<<no2<<endl;
                if(no1>no2)
                    return false;
                i++;
            }
            
            return true;
            
            */
            
        });
        
        
        for(string x:nums){
            cout<<x<<" ";
        }
        
             int idx=n-k;
        
        return nums[idx];
        
        
    }
};