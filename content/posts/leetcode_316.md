
+++
authors = ["Crafted by Me"]
title = "Leetcode 316: Remove Duplicate Letters"
date = "2023-12-22"
description = "Solution to Leetcode 316"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-duplicate-letters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> frq(26, 0), lidx(26, 0);

        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            frq[x - 'a']++;
            lidx[x - 'a'] = i;
        }

        vector<bool> seen(26, false);
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            int cur = s[i] - 'a';            
            if(seen[cur]) continue;

            while(st.size() > 0 && st.top() > s[i] && i < lidx[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[cur] = true;
        }

        string ans = "";
        while(st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/316.md" >}}
- by gpt
        
---
{{< youtube HjvMWNHZBNI >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

