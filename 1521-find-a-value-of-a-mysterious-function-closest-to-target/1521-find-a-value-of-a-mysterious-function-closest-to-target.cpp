 /*
       
       first we needs to find the range in which '&' of all its values
       is closest to target
       
       the bitwise and value from any starting index makes a non increasing        sequence because a&b<=a, so do a binary search for a least number which is       greater than the target.
       
       e.g 
       for array [9,12,3,7,15]
       
       continous And => [9 8 0 0 0]  (non decreasing)
       
       clearly And [0,1] >= [0,2] >= [0,3] .... 
       
       it means we can apply binary search on it to get And value closer to target
       
       */
        
    

class Solution {
public:
    
    int closestToTarget(vector<int>& arr, int target) {
    
        int n=arr.size();      
            
        int *st=constructST(arr,n);
    
        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            
/*

[l=i........mid.......h=n-1]

if And of range [i....mid] > target , than move mid towards right so that total And decrease down(as towards right , And decreases) so make l= mid+1

if And of range [i...mid]  < target , than move mid towards left so that total And increases , so make r=mid-1


*/
            
            
            int l=i;
            int h=n-1;
            
            int val;
            
            while(l<=h){
                
                int mid=(l+h)/2;
    
          val=getAnd(st,0,0,n-1,i,mid);

                 if(val>target)
                    l=mid+1;    
                else
                    h=mid-1;
            
              ans=min(ans,abs(val-target));
                
                 if(ans==0)
                    break;

            }
            
        }
        
        return ans;
        
    }
    
int getAnd(int *st,int si,int sl,int sr,int l,int r)
    
{
    
if(l<=sl && r>=sr)
return st[si];
    
if(l>sr || r<sl)
return INT_MAX;
    
int mid=(sl+sr)/2;
return (getAnd(st,2*si+1,sl,mid,l,r)&
getAnd(st,2*si+2,mid+1,sr,l,r));
    
}



int constructSTUL(int *st,int si,vector<int>&arr,int l,int r){
    
if(l==r){
st[si]=arr[l];
return arr[l];
}
    
int mid=(l+r)/2;

st[si]=(constructSTUL(st,2*si+1,arr,l,mid)
& constructSTUL(st,2*si+2,arr,mid+1,r));
    
    
return st[si];
    
}

int *constructST(vector<int>&arr,int n){

int h=(int)(ceil(log2(n)));
int max_size_st=2*(int)pow(2,h)-1;
int *st=new int[max_size_st];

constructSTUL(st,0,arr,0,n-1);

return st;
}


};