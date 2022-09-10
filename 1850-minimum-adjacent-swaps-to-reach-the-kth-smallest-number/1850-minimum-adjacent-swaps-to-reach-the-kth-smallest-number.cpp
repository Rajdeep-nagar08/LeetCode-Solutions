/*

min no of adjacent digit swaps to find kth smallest number

next permutation is always just greater number

so 

ans= min no of adjacent swaps to make the given string equals to its next kth permutation

*/


class Solution {
public:
    int getMinSwaps(string num, int k) {
        
       string need=num;
        
        
        while(k--){
            next_permutation(need.begin(),need.end());
        }
        
        
        return find(num,need);
        
    }
    
    
    
  int find(string s1,string s2){

    // s1=>s2

    int n=s1.size();

    int i=0;

    int count=0;

    while(i<n){

       if(s2[i]!=s1[i]){
        int k=i;
          while(i<n && s2[k]!=s1[i]){
            i++;
          }
          int j=i-1;

          while(j>=k){
             swap(s1[i],s1[j]);
             i--,j--;
             count++;
          }
          i=k+1;
       }
       else
        i++;
    }

      
      return count;
   // cout<<count<<" "<<s1<<" "<<s2;

  }

    
};