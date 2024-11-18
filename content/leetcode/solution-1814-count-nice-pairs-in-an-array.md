
+++
authors = ["grid47"]
title = "Leetcode 1814: Count Nice Pairs in an Array"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1814: Count Nice Pairs in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "qUNprFiUKyw"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/count-nice-pairs-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, long> mp;
        for(auto &n: nums) mp[n - rev(n)]++;
        
        int mod = 1000000007;
        long count = 0;
        
        for(auto &it: mp) 
        count = (count + (it.second * (it.second - 1))/ 2) % mod;
        
        return count;
    }

    int rev(int x) {
        int revNum = 0;
        while(x) revNum = revNum * 10 + (x%10), x /= 10;
        return revNum;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1814.md" >}}
---
{{< youtube qUNprFiUKyw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1816: Truncate Sentence](https://grid47.xyz/leetcode/solution-1816-truncate-sentence/) |
| --- |
