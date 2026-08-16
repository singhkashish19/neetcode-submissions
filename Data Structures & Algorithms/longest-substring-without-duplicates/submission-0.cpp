class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int lft = 0;
        int ans = 0;
        for(int right = 0; right < s.length(); right++){
            while(st.count(s[right])){
                st.erase(s[lft]);
                lft++;
            }
            st.insert(s[right]);
            ans = max(ans, right - lft + 1);
        }
        return ans;
    }
};
