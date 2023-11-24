#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isBalanced(string s) {
  /*WRITE YOUR CODE HERE*/
  stack<char> st;

  for (int i = 0; i < s.size(); i++) {
    if ((s[i]=='(') || (s[i]=='[') || (s[i]=='{')){
      st.push(s[i]);
    } else {
      if (st.empty()){
        return false;
      }

      char ch2 = st.top();
      if ((ch2=='(' && s[i]==')') || (ch2=='[' && s[i]==']') || (ch2=='{' && s[i]=='}')) {
        st.pop();
      } else {
        return false;
      }
    }
  }

  //* check balanced
  if (st.empty()){
    return true;
  } else {
    return false;
  }
}

int main() {
  string s;
  cin >> s;
  while (s != "-1") {
    if(isBalanced(s)) {
      cout << "Parentheses are balanced" << endl;
    } else {
      cout << "Parentheses are not balanced" << endl;
    }
    cin >> s;
  }
    
}
