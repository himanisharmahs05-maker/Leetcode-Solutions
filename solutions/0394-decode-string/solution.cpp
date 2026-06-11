class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0');
            }
            else if (c == '[') {
                countStack.push(currNum);
                stringStack.push(currStr);

                currNum = 0;
                currStr = "";
            }
            else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();

                string temp = currStr;

                currStr = stringStack.top();
                stringStack.pop();

                while (repeat--) {
                    currStr += temp;
                }
            }
            else {
                currStr += c;
            }
        }

        return currStr;
    }
};
