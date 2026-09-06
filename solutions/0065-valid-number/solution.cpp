class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        bool digit = false, dot = false, exp = false, expDigit = true;

        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        for (; i < n; i++) {
            if (isdigit(s[i])) {
                digit = true;
                if (exp) expDigit = true;
            }
            else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp || !digit) return false;
                exp = true;
                expDigit = false;
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] != 'e' && s[i - 1] != 'E')
                    return false;
            }
            else {
                return false;
            }
        }

        return digit && expDigit;
    }
};
