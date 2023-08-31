class Solution {
public:
    int countDistinct(vector<int>& v, int k, int p) {
        
        int i=0,j=0,ans=0;
        
        int n=v.size();
        
        return SlidingWindow(v,k,p);
    }
    

int SlidingWindow(vector<int>&a,int k,int p)
{
int i=0,j=0,n=a.size(),res=0;
    
unordered_set<string>us;
    
while(j<n)
{
    
if(a[j]%p == 0)
    k--;
    
while(k<0 && j>=i)
{
if(a[i]%p == 0)
    k++;
    
i++;
}
    
res=res+j-i+1;
    
updateMap(us,i,j,a,p,k);
    
j++;
    
}
        
return us.size();
    
    
}
    
    
void updateMap(unordered_set<string>&us,int p,int q,vector<int>v,int p1,int k1)
{
if(p>q)
    return ;
    
string temp="";
    
for(int i=q;i>=p;i--)
{   
    temp = temp + to_string(v[i]) + " ";
        
    us.insert(temp);
   }
}


        
};