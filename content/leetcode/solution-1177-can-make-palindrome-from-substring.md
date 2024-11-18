
+++
authors = ["grid47"]
title = "Leetcode 1177: Can Make Palindrome from Substring"
date = "2024-07-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1177: Can Make Palindrome from Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "tCr-y-1P2J8"
youtube_upload_date="2024-06-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/tCr-y-1P2J8/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/can-make-palindrome-from-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        vector<bool> ans;
        
        vector<int> pt(1,0);
        int mask = 0;
        
        for(int i = 0; i < s.length(); i++) {
        pt.push_back(mask ^= 1 << (s[i] - 'a'));
        }
        
        
        for(int i = 0; i < q.size(); i++) {
        
auto &v = q[i];

  
int cnt = __builtin_popcount(pt[v[1]+1] ^ pt[v[0]]);

    ans.push_back(cnt/2 <= v[2]);
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1177.md" >}}
---
{{< youtube tCr-y-1P2J8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1186: Maximum Subarray Sum with One Deletion](https://grid47.xyz/leetcode/solution-1186-maximum-subarray-sum-with-one-deletion/) |
| --- |
