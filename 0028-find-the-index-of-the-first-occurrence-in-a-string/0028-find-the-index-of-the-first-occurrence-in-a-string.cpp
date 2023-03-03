#define d 26

#define lln long long int

class Solution {
public:
    int strStr(string text, string pat) {
        
        int p=19260817;

        
int lt=text.size();
int lp=pat.size();

vector<int>powr(lt,1);

for(int i=1;i<lt;i++)
  powr[i]=(powr[i-1]*26)%p;
        
int i,j,k;
int hp=0;
int hw=0;


for(i=0;i<lp;i++){
hw = ((hw * d) % p + (text[i] - 'a')) % p;
 hp = ((hp * d) % p + (pat[i] - 'a')) % p;
}


for(i=0;i<=lt-lp;i++){
if(hp==hw){
for(k=0;k<lp;k++){
if(text[i+k]!=pat[k])
break;
}
if(k==lp)
    return i;
cout<<"pattern found at index "<<i<<endl;

}

if(i<lt-lp){
hw = ((hw - (lln) powr[lp - 1] * (text[i] - 'a')) % p + p) % p;
hw = (hw * d + (text[i+lp] - 'a')) % p;
           
}
    
}
        
    return -1;
        
    }
};