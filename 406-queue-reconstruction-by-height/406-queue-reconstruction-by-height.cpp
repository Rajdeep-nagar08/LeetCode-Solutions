 
        /*
        
        rearrange the persons such that
        
        [h,k]   k peoples in front (toward left of it) of it has height >=h
        
        
        for any pair [h,k]
        
        there must be k pairs that have height >=h 
        
        
        real position(index) of shortest person = k
        
        Than position of second shortest person = its k
        
Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.

For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.


        
input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
sort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
step1: [[7,0]]
step2: [[7,0], [7,1]]
step3: [[7,0], [6,1], [7,1]]
step4: [[5,0], [7,0], [6,1], [7,1]]
step5: [[5,0], [7,0], [5,2], [6,1], [7,1]]
step6: [[5,0], [7,0], [5,2], [4,4], [6,1], [7,1]]
        
        */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
     
        
        int n=p.size();
        
        sort(p.begin(),p.end(),[](vector<int>&p1,vector<int>&p2){
            if(p1[0]>p2[0])
                return true;
            else if(p1[0]==p2[0])
                return p1[1]<p2[1];
            else
                return false;
        });
        
        
        // this can be done by insert function of vector
        /*
        
std::vector::insert() is a built-in function in C++ STL which inserts new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.

Time Complexity – Linear O(N)


        vector vec = { 10, 20, 30, 40 };

// inserts 3 at front
auto it = vec.insert(vec.begin(), 3);
// inserts 2 at front
vec.insert(it, 2);

int i = 2;
// inserts 7 at i-th index
it = vec.insert(vec.begin() + i, 7);


*/
        
             
             for(int i=1;i<n;i++){
                
                 int idx=p[i][1];
                 
                 if(i==idx)
                     continue;
                 
                 int h=p[idx][0],k=p[idx][1];
                 int h1,k1;
                 for(int j=idx+1;j<=i;j++){
                     h1=p[j][0];
                     k1=p[j][1];
                     p[j][0]=h;
                     p[j][1]=k;
                     h=h1,k=k1;
                 }
                 
                 p[idx][0]=h,p[idx][1]=k;
                 
             }
             
             
             return p;
            
        
      }
};