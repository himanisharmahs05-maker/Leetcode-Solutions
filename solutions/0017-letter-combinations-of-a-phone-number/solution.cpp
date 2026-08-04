class Solution {
public:
    vector<string>ans;
    string letters[10]= { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(string &digits,int idx,string current ){
        if(idx==digits.size()){
            ans.push_back(current);
            return;
        }
        int digit=digits[idx]-'0';
        for(char ch:letters[digit]){
            current.push_back(ch);

            solve(digits,idx+1,current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return{};
        }
        solve(digits,0,"");
        return ans;
        
    }
};
