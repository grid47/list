
+++
authors = ["grid47"]
title = "Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K"
date = "2024-06-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arr = {1, 1};
        while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        }

        set<int> cnt;
        int i = arr.size() -1;
        while(k > 0) {
            while(i >= 0 && arr[i] > k) i--;
            if(i == -1) break;
            k -= arr[i];
            cnt.insert(arr[i]);
        }
        return cnt.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1414.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1415: The k-th Lexicographical String of All Happy Strings of Length n](https://grid47.xyz/leetcode/solution-1415-the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/) |
| --- |
