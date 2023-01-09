class Solution {
public:
    
    bool isPossible(int n, vector<vector<int>>& edg) {
        

        vector<int>cnt(n,0);

        unordered_map<int,unordered_map<int,int>>g;
        
        vector<int>v;

        for(auto it:edg){
           
            cnt[it[0]-1]++;
            
            
            g[it[0]-1][it[1]-1]++;

            
            cnt[it[1]-1]++;
            

            g[it[1]-1][it[0]-1]++;
            
        }
        
        
        
        for(int i=0;i<n;i++){
            if(cnt[i]%2==1)
                v.push_back(i);
        }
        
        
        if(v.size()%2==1 || v.size()>4)
            return false;
      
        int n1=v.size();


        if(n1==2){
            for(int i=0;i<n;i++){
                if(i!=v[0] && i!=v[1] && g[i][v[0]]==0 && g[i][v[1]]==0 && cnt[i]%2==0)
                    return true;
            }
        }
                
        sort(v.begin(),v.end());
    
        int edgCount=0;
        
        do{
            
//             for(int x:v){
//             cout<<x+1<<" ";
//            }
            
//         cout<<endl;
                                
            
            bool flag=true;
          
            vector<int>cnt1=cnt;
        
            int i=0;

            while(i<n1-1){
              
                int u1=v[i];

                int v1=v[i+1];

                if(g[u1][v1]>0){
                    flag=false;
                    break;
                }
                i+=2;
                
            }
            
            if(flag)
                return true;
            
        }while(next_permutation(v.begin(),v.end()));
        
        
        return false;
        
    }
};