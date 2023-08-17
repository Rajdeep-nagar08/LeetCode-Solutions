/*

sort the arary on the basis of attack values

Now make an array "maxR" to store greatest element to the right for defense values

Now for each index i

find index idx using binary search for next greater attack value for present attack value

From that index to last index , if there is any defence value that is greater than current defence value 

it means there exist any character that has both attack and defense levels strictly greater than this character's attack and defense levels So

count++

*/

// class Solution {
// public:
//     int numberOfWeakCharacters(vector<vector<int>>& prop) {
        
//         int n=prop.size();
        
//         sort(prop.begin(),prop.end());
        
//         vector<int>maxR(n);
        
//         maxR[n-1]=prop[n-1][1];
        
//         for(int i=n-2;i>=0;i--){
//             maxR[i]=max(prop[i][1],maxR[i+1]);
//         }

//         int count=0;
//         vector<int>v;
        
//         for(int i=0;i<n;i++){
            
//             int a=prop[i][0];
            
//             v={a,INT_MAX};
            
//             int idx=upper_bound(prop.begin(),prop.end(),v)-prop.begin();
           
//             if(idx>=n || idx<0)
//                 continue;
            
//             if(maxR[idx]>prop[i][1])
//                 count++;
          
//         }
        
//       return count;
        
//     }
// };
    


class Solution
{
public:
     //handling the edge case while sorting
     static bool comp(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
          {
               return a[1] > b[1];
          }
          return a[0] < b[0];
     }
     int numberOfWeakCharacters(vector<vector<int>> &properties)
     {
          sort(properties.begin(), properties.end(), comp); //sorting the array
          int mtn = INT_MIN;                                //max till now while moving from right
          int ans = 0;

          for (int i = properties.size() - 1; i >= 0; i--)
          {
               if (properties[i][1] < mtn) // if the second parameter is also less increase the ans
                    ans++;
               mtn = max(mtn, properties[i][1]);
          }
          return ans;
     }
};
    
     