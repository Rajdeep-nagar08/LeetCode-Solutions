/*

Needs to maximize total score !

Initial score = 0

if(power>=tokens[i]){   then we have a choice as
power=power-tokens[i] 
score++
}

if(score>1){    then we have a choice as 
power=power+tokens[i]
score--
}


Ans= Max possible score can be collected by using some or all tokens in any order

(strategy)

kam token dekar 1 score gain karo fir uss score ko dekar jyda token gain karo fir unn jyda tokens ko dekar jyda score gain karo



*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n=tokens.size();
        
        
        sort(tokens.begin(),tokens.end());
        
        
        // kam score ------- max score
        int score=0;
        
        int i=0,j=n-1;
        
        int ans=0;
        
        if(n==0 ||  power<tokens[0])
            return 0;
        
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                ans=max(ans,score);
                i++;
            }
            else if(score>0){
                power+=tokens[j];
                score--;
                j--;
            }
            else
                break;
        }
        
        return ans;
        
    }
};