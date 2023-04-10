class Solution {
public:
    bool isValid(string s) {
stack<char>st;
string exp=s;
for(int i=0;exp[i]!='\0';i++)
{

if(exp[i]=='[' || exp[i]=='(' || 
   exp[i]=='{'){
st.push(exp[i]);
}
 else if(st.size()>0){
if(exp[i]==']' && st.top()=='[')
st.pop();


else if(exp[i]==')' && st.top()=='(')
st.pop();

else if(exp[i]=='}' && st.top()=='{')
st.pop();
     else
         return false;
 }
    else
        return false;

}

if(st.empty()==1)
return true;
    else
        return false;
    }
};