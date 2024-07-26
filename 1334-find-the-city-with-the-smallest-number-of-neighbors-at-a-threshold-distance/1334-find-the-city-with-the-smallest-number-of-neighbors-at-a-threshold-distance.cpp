/*

needs to return the city, such that no. of cities that are reacheble from city is minimum.
and whose distance from city<= distThres

n<=100


as n<=100

so for each city, we will find its minimum distance from other cities

d[i][j]= minimum distance of i from j

d[i][j]= min(d[i][j], d[i][k]+d[k][j])

*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edg, int distThres) {
        
        vector<vector<int>>d(n, vector<int>(n,INT_MAX));
        
        for(auto it: edg){
            int i=it[0];
            int j=it[1];
            int x=it[2];
            d[i][j]=x;
            d[j][i]=x;
            d[i][i]=0;
            d[j][j]=0;
        }
        
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(d[i][k]!=INT_MAX && d[k][j]!=INT_MAX && d[i][j]>d[i][k]+d[k][j]){
                        d[i][j]=d[i][k]+d[k][j];
                    }
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<i<<"-"<<j<<" "<<d[i][j]<<endl;
        //     }
        // }
        vector<int>freq(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && d[i][j]<=distThres){
                        freq[i]++;
                }
            }
        }
        
        int mn=INT_MAX;
        
        for(int i=0;i<n;i++){
                mn=min(mn,freq[i]);
            // cout<<freq[i]<<" ";
        }
        
        // cout<<d[0][5]<<endl;
        
        for(int i=n-1;i>=0;i--){
            if(freq[i]==mn)
                return i;
        }
        
        return -1;
        
    }
};