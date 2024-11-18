
+++
authors = ["grid47"]
title = "Leetcode 1980: Find Unique Binary String"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1980: Find Unique Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aHqn4Dynd1k"
youtube_upload_date="2021-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/aHqn4Dynd1k/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/find-unique-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; i++)
        ans += nums[i][i] == '0'? '1':'0';
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1980.md" >}}
---
{{< youtube aHqn4Dynd1k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1981: Minimize the Difference Between Target and Chosen Elements](https://grid47.xyz/leetcode/solution-1981-minimize-the-difference-between-target-and-chosen-elements/) |
| --- |
