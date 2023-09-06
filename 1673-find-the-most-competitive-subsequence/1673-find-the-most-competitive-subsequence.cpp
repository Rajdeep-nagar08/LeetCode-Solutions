/*
Intuition
Use a mono incrasing stack.


Explanation
Keep a mono incrasing stackas result.
If current element a is smaller then the last element in the stack,
we can replace it to get a smaller sequence.

Before we do this,
we need to check if we still have enough elements after.
After we pop the last element from stack,
we have stack.size() - 1 in the stack,
there are A.size() - i can still be pushed.
if stack.size() - 1 + A.size() - i >= k, we can pop the stack.

Then, is the stack not full with k element,
we push A[i] into the stack.

Finally we return stack as the result directly.

*/


class Solution {
public:
    
    vector<int> mostCompetitive(vector<int>& A, int k) {
        stack<int> st;
        for (int i = 0; i < A.size(); ++i) {
            while (!st.empty() && st.top() > A[i] && st.size() - 1 + A.size() - i >= k)
                st.pop();
            if (st.size() < k)
                st.push(A[i]);
        }
        
        vector<int>ans;
        
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};