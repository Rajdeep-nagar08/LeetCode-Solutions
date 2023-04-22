class FindSumPairs {
public:
    
    vector<int>v1;
    
     unordered_map<int,int>mp1,mp2;
    
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        
        for(int x:nums1){
            v1.push_back(x);
        }
     
        
        for(int i=0;i<nums2.size();i++){
            mp1[i]=nums2[i];
            mp2[nums2[i]]++;
        }        
    }
    
    void add(int index, int val) {
        
        int x=mp1[index];
        
        mp1[index]+=val;
        
        mp2[x]--;
        
        mp2[x+val]++;
        
    }
    
    int count(int tot) {
       
        int ans=0;
        
        for(int i=0;i<v1.size();i++){
          
          
           ans+=mp2[tot-v1[i]]; 
           
        }
        
        return ans;
        
    }
};
