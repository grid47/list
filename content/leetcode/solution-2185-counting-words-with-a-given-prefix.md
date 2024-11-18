
+++
authors = ["grid47"]
title = "Leetcode 2185: Counting Words With a Given Prefix"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2185: Counting Words With a Given Prefix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "8yMcHvAw2Q8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/counting-words-with-a-given-prefix/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int prefixCount(vector<string>& words, string s) {
        int cnt = 0;
        for(string x: words) {
            if(x.size() < s.size()) continue;
            bool flag = true;
            for(int i = 0; i < s.size(); i++) {
                if(x[i] != s[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2185.md" >}}
---
{{< youtube 8yMcHvAw2Q8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2186: Minimum Number of Steps to Make Two Strings Anagram II](https://grid47.xyz/leetcode/solution-2186-minimum-number-of-steps-to-make-two-strings-anagram-ii/) |
| --- |
