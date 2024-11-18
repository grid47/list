
+++
authors = ["grid47"]
title = "Leetcode 316: Remove Duplicate Letters"
date = "2024-10-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 316: Remove Duplicate Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-duplicate-letters/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/316.webp" 
    alt="A series of letters gently disappearing from a word, leaving only the unique letters softly glowing."
    caption="Solution to LeetCode 316: Remove Duplicate Letters Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
---
{{< youtube HjvMWNHZBNI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #318: Maximum Product of Word Lengths](https://grid47.xyz/leetcode/solution-318-maximum-product-of-word-lengths/) |
| --- |
