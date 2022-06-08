    /*
        
        remove all the cars containing illegal goods, to remove cars we have
        3 choices
        
        We needs to find the minimum time to remove all cars having illigal goods
        
        Note: its not necessary to remove only illigal goods cars, we can remove any car but finally there should not be any car that have illigal goods
        
        
        => remove from front : time =1
        => remove from last : time=1
        => remove from middle : time=2
        
        
  
  if front is 1 , remove it
  if front is 0 , than two choices :
          remove 0
          remove 1 that is next to 0 if that 1 is not in last
  
  if back is 1 , remove it
  if back is 0, than two choices :
           remove 0
           remove 1 that is prev to 0
           
  */


/*

The optimal strategy will be:

Take some elements from the left
Take some elements from the right
Take the rest elements from the middle.
Now, the question is how to choose left and right parts, we can have potentially O(n^2) options and we can not check them all. Let us calculate how much we paid:

|..left..|..middle..|..right..|

For left and right we paid just their lengths. For middle we pay twice number of ones se have inside, so we have: len(left) + 2* count(middle, 1) + len(right) = len(left) + len(middle) + len(right) + 2*count(middle, 1) - len(middle) = n + count(middle, 1) - count(middle, 0).

So, in fact what we need to found is the subarray with the smallest count(middle, 1) - count(middle, 0) value. 
If we now replace all 0 with -1, it is the same as found the subarray with the smallest sum! 

Ans= n + (minimum sum subarray after replacing all 0 by -1)

So use Standard Kedan's algorithm to find this

*/
      

class Solution {
public:
    int minimumTime(string str) {

        int n=str.size();
       
        int mn=INT_MAX;
        
        int temp=0;
        
        int no;
        
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')
                no=-1;
            else
                no=1;
            
            temp=min(temp+no,no);
            mn=min(mn,temp);
        }
        
      return min(n+mn,n);
       
    }
    
};