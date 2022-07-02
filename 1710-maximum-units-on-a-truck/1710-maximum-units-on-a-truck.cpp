class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        if(a[1]!=b[1])
        return a[1]>b[1];
        else
            return a[0]>b[0];
        
        
    }
    int maximumUnits(vector<vector<int>>& bt, int n) {
        sort(bt.begin(),bt.end(),comp);
        
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cout<<bt[i][j]<<" ";
            }
            cout<<endl;
        }
        
        */
        
        int ans=0;
        int i=0;
        int j=0;
        
        while(j<bt.size()){
            
            if(i+bt[j][0]<n){
            i+=bt[j][0];
            ans+=(bt[j][0]*bt[j][1]);
            }
            
  else{
       int y=n-i;
        ans+=y*bt[j][1];
        return  ans;
          }
            
            j++;
            
        }

            return ans;
    }
};