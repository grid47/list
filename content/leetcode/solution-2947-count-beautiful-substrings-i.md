
+++
authors = ["grid47"]
title = "Leetcode 2947: Count Beautiful Substrings I"
date = "2024-01-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2947: Count Beautiful Substrings I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","String","Enumeration","Number Theory","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "AnuZGQmVPQM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-beautiful-substrings-i/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char c) { return st.find(c) != st.end(); }
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            int vow = 0, con = 0;
            for(int j = i; j < s.size(); ++j) {
                (isVowel(s[j]))? vow++: con++;
                if(vow == con && (vow*con)%k == 0) ans++;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2947.md" >}}
---
{{< youtube AnuZGQmVPQM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2948: Make Lexicographically Smallest Array by Swapping Elements](https://grid47.xyz/leetcode/solution-2948-make-lexicographically-smallest-array-by-swapping-elements/) |
| --- |
