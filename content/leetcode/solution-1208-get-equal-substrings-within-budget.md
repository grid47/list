
+++
authors = ["grid47"]
title = "Leetcode 1208: Get Equal Substrings Within Budget"
date = "2024-07-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1208: Get Equal Substrings Within Budget in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3lsT1Le526U"
youtube_upload_date="2024-05-28"
youtube_thumbnail="https://i.ytimg.com/vi/3lsT1Le526U/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/get-equal-substrings-within-budget/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int equalSubstring(string s, string t, int mxc) {
        vector<int> nums(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            nums[i] = abs(s[i] - t[i]);
        }
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            mxc -= nums[i];
            while(mxc < 0) {
                mxc += nums[j++];
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1208.md" >}}
---
{{< youtube 3lsT1Le526U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1209: Remove All Adjacent Duplicates in String II](https://grid47.xyz/leetcode/solution-1209-remove-all-adjacent-duplicates-in-string-ii/) |
| --- |
