class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto tkn : tokens){
            if(tkn == "+" || tkn == "-" || tkn == "*" || tkn == "/" ){
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if(tkn == "+") st.push(num1 + num2);
                else if (tkn == "-") st.push(num1 - num2);
                else if (tkn == "*") st.push(num1 * num2);
                else st.push(num1 / num2);
                
            }
            else{
                st.push(stoi(tkn));
            }
        }
        return st.top();
        
    }
};