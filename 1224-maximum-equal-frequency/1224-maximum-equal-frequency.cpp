
    
        /*
        
         [0.......i]
         
         Case1: all no's have same frequency except one no. that has frequency =1 ,we will remove this no. to make all no's with same frequency
         
         Case2: all no's have same frequency= f,  except one no. that has frequency = f+1, we will remove its one occuracncy to make frequency of all no's equal
         
         
         1<= nums[i] <= 10^5
         
         
         Brute Force Approach : 
         At each index [0...i] we check frequency of each distinct no. till now and determine ans accordingly
         
         
         
         
         we needs to keep track of minimum and maximum frequncy and count of no's that have frequncy == minimum frequnecy and count of no's that have frequncy== maimum frequncy
         
         
         Valid Prefix 1 as per CASE1: 
         
         let at index i (total no's till now = i+1)
         
         if min frequency = 1, and count of such numbers =1
         
         maximum frequncy = x, and count of such numbers = c1
         
         clearly : as total no's = i+1
         1*1 + x*c1= i+1
         c1= i/x
         
         
         Valid Prefix 2 as per CASE2:         
         

         if maximum frequency = x, and count of such numbers =1

         if min frequnecy = x-1, and count of such no's = y
         
         clearly : as total no's = i+1
         
         x*1 + (x-1)*y = i+1
         
         y= (i+1-x)/(x-1)
         


          2 CORNER CASE:
  
  
     
            // 1,2,3,4,5,6 each no appeared once
            if(minFreq==1 and maxFreq==1 and countMin==i+1 and countMax==i+1)
                ans=i+1;
            
            // 1,1,1,1,1,1,  same no. repeat
            if(minFreq==i+1 and countMin==1 and maxFreq==i+1 and countMax==1)
                ans=i+1;
         
*/
        

class Solution {
public:
    
    int n;
    
    int maxEqualFreq(vector<int>& nums) {
        
        
        n=nums.size();
        
        int minFreq=0, countMin=0;
        
        int maxFreq=0, countMax=0;
        
        int ans=1;  // always
        
        unordered_map<int,int>freq;  // no => freq
        
        map<int,set<int>>mp;  // freq => no's
        
        for(int i=0;i<n;i++){
            
            
            if(freq.count(nums[i])==0){
                
                freq[nums[i]]++;
                
                mp[1].insert(nums[i]);
                
            }
            else{
                
                int f=freq[nums[i]];
                
                mp[f].erase(nums[i]);
                
                if(mp[f].size()==0)
                    mp.erase(f);
                
                freq[nums[i]]++;
                
                mp[f+1].insert(nums[i]);
                
            }
            
            auto it1=mp.begin();
            
            minFreq=it1->first;
            
            countMin=it1->second.size();
            
            auto it2=mp.end();
            
            it2--;
            
            maxFreq=it2->first;
            
            countMax=it2->second.size();
            
            /////// checking case1
            
    if(i%maxFreq==0 and (i/maxFreq==countMax) and minFreq==1 and countMin==1){
                ans=i+1;
            }
            
            if(maxFreq-1!=0 and (i+1-maxFreq)%(maxFreq-1)==0 and ((i+1-maxFreq)/(maxFreq-1))==countMin and countMax==1 and minFreq==maxFreq-1){
                ans=i+1;
            }
            
            
            // 1,2,3,4,5,6 each no appeared once
            if(minFreq==1 and maxFreq==1 and countMin==i+1 and countMax==i+1)
                ans=i+1;
            
            // 1,1,1,1,1,1,  same no. repeat
            if(minFreq==i+1 and countMin==1 and maxFreq==i+1 and countMax==1)
                ans=i+1;
            
            
        }
        
        
      return ans;
        
        
    }
};