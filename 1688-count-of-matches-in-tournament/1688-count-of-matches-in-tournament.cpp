class Solution {
public:
    // time/space: O(logn)/O(1)
    int numberOfMatches(int n) {
        int result = 0;
        while (n >= 2) {
            int matches = (n / 2);
            int losers = matches;   // `k` matches produce `k` losers
            result += matches;      // count the matches
            n -= losers;            // remove the losers
        }
        return result;
    }
};