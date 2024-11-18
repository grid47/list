
+++
authors = ["grid47"]
title = "Leetcode 1387: Sort Integers by The Power Value"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1387: Sort Integers by The Power Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Memoization","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/sort-integers-by-the-power-value/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    map<int, int> memo;
    
    int dig(int num) {
        if(num == 1) return 0;
        if(memo.count(num)) return memo[num];
        if(num % 2 == 0)
            return memo[num] = dig(num / 2) + 1;
        return memo[num] = dig(3 * num + 1) + 1;        
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> ans;
        for(int i = lo; i <= hi; i++) {
            int tmp = dig(i);
            ans.push_back({tmp, i});
        }
        sort(ans.begin(), ans.end());
        return ans[k - 1].second;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1387.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1389: Create Target Array in the Given Order](https://grid47.xyz/leetcode/solution-1389-create-target-array-in-the-given-order/) |
| --- |
