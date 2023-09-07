/*
        Only when source and target are separated completely by blocked squares 
        will it be impossible to reach target from source. 
        Since the len of blocked is no larger than 200, 
        the closed area will be bounded by 200*200. 
        
        
        
        https://leetcode.com/problems/escape-a-large-maze/discuss/2132711/C%2B%2B-oror-EASY-TO-UNDERSTAND-oror-Simple-Code-oror-Intuitive-Approach
        
        
*/


class Solution {
public:
  
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> block;
        int count=0;
        for(int i=0;i<blocked.size();i++)
        {
            count++;
            block.insert({blocked[i][0],blocked[i][1]});
        }
        return canReach(source,target,count,block)&&canReach(target,source,count,block);
    }
    
    
    
      bool canReach(vector<int> &source,vector<int> &target,int numBlocked,set<pair<int,int>> &block)
    {
        vector<int> dx,dy;
        dx={0,0,1,-1};
        dy={1,-1,0,0};
        int maxArea=numBlocked*(numBlocked-1)/2;
        int currArea=1;
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        q.push({source[0],source[1]});
        visited.insert({source[0],source[1]});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int new_x,new_y;
                new_x=x+dx[i];
                new_y=y+dy[i];
                if(new_x==target[0]&&new_y==target[1])
                return true;
                if(currArea>maxArea)
                return true;
                if(new_x>=0&&new_x<1e6&&new_y>=0&&new_y<1e6&&block.find({new_x,new_y})==block.end()&&visited.find({new_x,new_y})==visited.end())
                {
                    currArea++;
                    visited.insert({new_x,new_y});
                    q.push({new_x,new_y});
                }
            }
        }
        return false; 
    }
    
    
};