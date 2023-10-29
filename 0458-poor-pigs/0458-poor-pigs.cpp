class Solution {
public:
    int poorPigs(int buckets, int timetoDie, int timetest) {
        float first=log2(buckets);
        float second=log2(int(timetest/timetoDie)+1);

        return ceil(first/second);
    }
    
};