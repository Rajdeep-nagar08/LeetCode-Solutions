/*

Create two UnionFinds par1, par2 

We should take type 3 edges first, then type 1 and 2.

If two nodes are already connected, we increment the rmv (no. of edges to be removed). Otherwise we connect them and increase their size (no. of edges in dsu)

In the end, if dsu1 size==n-1 && dsu2 size == n-1 meaning that the graph is all connected for both Alice and Bob, we return ans; otherwise return -1.


*/

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edg) {
        
     vector<int>par1(n),par2(n);
      
     int size1=0,size2=0;  // no. of edges in dsu1, dsu2
    
        for(int i=0;i<n;i++){
            par1[i]=i;
            par2[i]=i;
        }
        
        int rmv=0;
        
        for(auto it:edg){
            if(it[0]==3){
                
                int u=it[1]-1;
                
                int v=it[2]-1;
                
                if(isConnected(u,v,par1)){ 
                    
                    //both are already in par1 and par2 indirectly
                    // we can remove this edge
                    rmv++;
                    continue;
                }
                
                // including in both par1 and par2
                
                 join(u,v,par1,size1);
                
                join(u,v,par2,size2);
            }
        }
        
              //  cout<<size1<<" "<<size2<<endl;

        
         for(auto it:edg){
             
            if(it[0]==1){    
                
                int u=it[1]-1;
                
                int v=it[2]-1;
                
                if(isConnected(u,v,par1)){  // already in par1
                    rmv++;
                    continue;
                }
                
                join(u,v,par1,size1);
                
            }
        }
        
       // cout<<size1<<endl;
        
        if(size1!=n-1)
            return -1;
        
        
         for(auto it:edg){
            if(it[0]==2){    
                
                int u=it[1]-1;
                
                int v=it[2]-1;
                
                if(isConnected(u,v,par2)){  // already in par2
                    rmv++;
                    continue;
                }
                
                join(u,v,par2,size2);
                
            }
        }
        
        
    //    cout<<size2<<endl;

        if(size2!=n-1)
            return -1;
        
        
        return rmv;
        
        
    }
    
      void join(int u,int v,vector<int>&par,int &size){
        
          int p1=findPar(u,par);
          
          int p2=findPar(v,par);
          
          if(p1==p2)
              return;
          
        par[p1]=p2;
        
        size++;
    }
    
    
  
    int findPar(int u,vector<int>&par){
        if(par[u]==u)
            return u;
        
        par[u]=findPar(par[u],par);
        
        return par[u];
    }
    
    
      bool isConnected(int u,int v,vector<int>&par){
        return findPar(u,par)==findPar(v,par);
    }
    
    
   
};