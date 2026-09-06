#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsBracketMatch(string str) {
    if (str.empty()) {
        cout << "传入的str为空" << endl;
        return true;
    }
    
    stack<char> S;
    for (char c : str) {
        if (c == '(' || c == '{' || c == '[') {
            S.push(c);
        }
        if (c == ')' || c == '}' || c == ']') {
            if (S.empty()) return false;
            if (c == ')' && S.top() != '(') return false;
            if (c == ']' && S.top() != '[') return false;
            if (c == '}' && S.top() != '{') return false;
            S.pop();
        }
        
    }
    return S.empty();
}

int main() {
    string tests[] = {
    "()", "()[]{}", "{[()]}", "{[]()}",
    "(]", "([)]", "(", ")", ""
    };
    bool expected[] = {1, 1, 1, 1, 0, 0, 0, 0, 1};

    for (int i = 0; i < 9; i++) {
        bool result = IsBracketMatch(tests[i]);
        cout << "\"" << tests[i] << "\" -> " << result
            << " (预期 " << expected[i] << ") "
            << (result == expected[i] ? "✅" : "❌") << endl;
    }
}