
+++
authors = ["Crafted by Me"]
title = "Leetcode 316: Remove Duplicate Letters"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 316: Remove Duplicate Letters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy","Monotonic Stack"]
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
---
{{< youtube HjvMWNHZBNI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #317: Shortest Distance from All Buildings](https://grid47.xyz/posts/leetcode_317) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
