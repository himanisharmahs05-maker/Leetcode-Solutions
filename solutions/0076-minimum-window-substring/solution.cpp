class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";

        unordered_map<char,int>need,window;

        for(char c:t){
            need[c]++;
        }
        int left=0;
        int minlen=INT_MAX;
        int count=0;
        int start=0;

        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;

            if(need.count(c)&& window[c]<=need[c]){
                count++;
            }
            while(count==t.size()){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                char x=s[left];
                window[x]--;

                if(need.count(x)&& window[x]<need[x]){
                    count--;
                }
                left++;

            }
        }
        if(minlen==INT_MAX){
            return "";
        }
        return s.substr(start,minlen);
    }
};
