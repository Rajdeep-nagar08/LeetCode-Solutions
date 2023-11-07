class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int count=0;
        int n=dist.size();
        vector<double>time(n);
        for(int i=0;i<n;i++){
            time[i]=(ceil)((double)dist[i]/speed[i]);
        }
        sort(time.begin(),time.end());
        double currTime=0.0;

        for(int i=0;i<n;i++){
            if(time[i]>currTime)
                  count++;
            else 
                return count;
            currTime=currTime+1.0;
        }
        return count;
        }
        
};