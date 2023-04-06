class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        
        
        vector<int>v(50,0);
        
        v[0]=1;
        
        v[1]=1;
        
        v[2]=2;
        
        for(int i=3;i<45;i++){
            v[i]=v[i-1]+v[i-2];
        }
        
        
//         for(int x:v){
//             cout<<x<<" ";
//         }
        
//         cout<<endl;
        
        
        // cout<<v[44]<<endl;
        
        
        int ans=0;
        
        while(k>0){
            
            int i=upper_bound(v.begin(),v.end(),k)-v.begin();
            
            i--;
            
            k=k-v[i];
            
            ans++;
        }
        
        return ans;
        
    }
};