#include<bits/stdc++.h>
using namespace std;

class DSU
{
   public:
   vector<int>parent,rank;
   DSU(int n)
   {
         parent.resize(n,-1);
		 rank.resize(n,1);
		 for(int i=0;i<n;i++)
             parent[i]=i;
   }
    
    
   int find(int i)
   {
	   if(parent[i]==i)
           return i;
       
	   return parent[i]=find(parent[i]);
   }
    
   void union_rank(int u,int v)
   {
	   int pu=find(u),pv=find(v);
       
	   if(pu!=pv)
	   {
		   if(rank[pu]<rank[pv])
		   {
			   parent[pu]=pv;
			   rank[pv]+=rank[pu];
		   }
		   else
		   {
			   parent[pv]=pu;
			   rank[pu]+=rank[pv];
		   }
	   }
   }
};


class Solution {
public:
     
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
          vector<vector<int>>edgeList;
         vector<int>indeg(n,0);
        
          for(int i=0;i<n;i++)
          {
              int l=leftChild[i],r=rightChild[i];
              if(l!=-1)
              {
                  indeg[l]++;
                  edgeList.push_back({i,l});
              }
              if(r!=-1)
              {
                  indeg[r]++;
                  edgeList.push_back({i,r});
              }
          }
        
        int c=0;
        
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                cout<<i<<endl;
                c++;
            }
        }
        
        if(c>1)
            return false;
        
        if(c==0)
            return false;
        
          DSU dsu(n);
        
          for(auto edge:edgeList)
          {
              int pu=dsu.find(edge[0]),pv=dsu.find(edge[1]);
              if(pu!=pv)
              {
                  dsu.union_rank(pu,pv);
              }
              else return false;
          }
          return true;
    }
};