/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
      
      int l=1;
      int h=n;
      while(l<=h){
        int mid=(h-(h-l)/2);
        if(guess(mid)==0)
          return mid;
        else if(guess(mid)<0)
          h=mid-1;
        else
          l=mid+1;
      }
    
        return l;
    }
};