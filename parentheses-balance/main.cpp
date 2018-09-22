// Coty Hamilton : parentheses balance : 673 : cotyhamilton

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define endl '\n'

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    string str;

    stack<char> parenStack;

    bool valid;                     // flag set to break loop if unbalanced

    int numberOfLines;

    cin >> numberOfLines;

    cin.ignore();

    for(int i = 0; i < numberOfLines; i++) {

        valid = true;

        getline(cin, str);

        for(int j = 0; j < str.length() && valid; j++) {

            switch(str[j]) {

                    case '(':       // always push opening paren or bracket

                        parenStack.push(str[j]);

                    break;

                    case '[':

                        parenStack.push(str[j]);

                    break;

                    case ')':       // if stack is empty string is not balanced

                        if (parenStack.empty() || parenStack.top() != '(') {

                            valid = false;

                        }

                        else {

                            parenStack.pop();

                        }

                    break;

                    case ']':

                        if (parenStack.empty() || parenStack.top() != '[') {

                            valid = false;

                        }

                        else {

                            parenStack.pop();

                        }

                    break;

            }

        }                           // if balanced flag is true and stack is empty
                                    // the string is balanced
        cout << (valid && parenStack.empty() ? "Yes" : "No") << endl;

        parenStack = stack<char>();

    }

    return 0;

}