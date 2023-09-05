/*
The count is the number of node that can be put in the tree. The initial value is 1, which means there can be a root.

When adding a node, count--;

When adding a non-NULL node (node!="#"), it means we obtains two more leafs, then count +=2.

The final count should be equal to 0
*/
/*
class Solution {
public:
    bool isValidSerialization(string preorder) {
      //We use stringstream to split the string by commas.
      
        stringstream ss(preorder);
        string curr;
        int count = 1;
        while (getline(ss, curr, ',')) {
            count--;
            if (count < 0) return false;
            if (curr != "#") count += 2;
        }
          if(count==0)
            return true;
      return false;
    }
};

*/
class Solution {
public:
    bool isValidSerialization(string preorder) {
    
      int n=preorder.size();
      if(n==0)
        return false;
      
      int count=1;
      int i=0;
      while(i<n){
        if(preorder[i]==',')
          i++;
        else{
          count--;
          if(count<0)
            return false;
          
          if(preorder[i]!='#'){
            count=count+2;
            while(preorder[i]!=',' && i<n)
              i++;
          }
          i++;
        }
      }
      if(count==0)
        return true;
      return false;
      
    }
};