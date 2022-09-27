/*
left or right kept as it is, we needs to focus on standing ones

for standing ones:
it moves to left or right , it depends on its shortest distance from right moving and left moving dominoes, if shortest distance is same , it will not move at all

---> right  |  left <----


	In this approach, you just need to find sections like this
    
	X .   .   .   . X
	i                j
    
    
	Where X can be 'R' or 'L' and in between there can be as many dots
	Now,
	 case 1:
	- If char[i] == char[j] == 'R', means all go towards right (R)
  
   case 2:
	-  char[i]  == char[j] == 'L', means all go towards Left (L)
  
  no need to consider this case:
	-  If char[i] = 'L' and char[j] = 'R', means middle part is not affected so they remain '.'
  
   case 3:
	-  If char[i] = 'R' and char[j] = 'L', then it will affect the middle part.
	   The middle_part/2 close to i will be affected by 'R' and middle_part/2 close to j will be   
	   effected by 'L'  and the middlesmost bar (if any) will be unaffected due to equal  
       
       
*/


class Solution {
public:
    string pushDominoes(string s) {
        
        int n=s.size();
    
        int i=0;
        
      while(i<n){
          
          
        // no need to change 'L' & 'R'
          
          
        if((s[i]=='L')||(s[i]=='R')){
          i++;
          continue;
        }
        
        int start=i; // => '.'
        
        while(i<n && (s[i]=='.'))
          i++;
        
        // i=> 'L' OR 'R' after '.'
          
          
         if(start==0 && i==n)
           continue;
        
        //b........e
          
          
       char b=start==0?'L':s[start-1];
          
          
       char e=i==n?'R':s[i];
      
        // case 1
          if((b=='R') && (e=='R')){
              
            for(int j=start;j<i;j++)
                
              s[j]='R';
          }
          
          
        // case 2
         else if((b=='L') && (e=='L')){
            for(int j=start;j<i;j++)
              s[j]='L';
          }
        
          
        // case 3
         else if((b=='R')&&(e=='L')){
           int l=i-start;
          int need=l/2;
           for(int j=1;j<=need;j++){
             s[start+j-1]='R';
             s[i-j]='L';
           }
        }
    
      }
      
      return s;
        
        
    }
};