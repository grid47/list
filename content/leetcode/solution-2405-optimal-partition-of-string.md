
+++
authors = ["grid47"]
title = "Leetcode 2405: Optimal Partition of String"
date = "2024-03-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2405: Optimal Partition of String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1Zx7gEznzfI"
youtube_upload_date="2023-04-04"
youtube_thumbnail="https://i.ytimg.com/vi/1Zx7gEznzfI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/optimal-partition-of-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool checkBit(int &flag, int &n) {
        return flag & (1<< n);
    }

    void setBit(int &flag, int & n) {
        flag |= (1<<n);
    }

    int partitionString(string s) {
        int flag = 0, ans = 1;
        for(auto c: s) {
            int n = c - 'a';
            if(checkBit(flag, n)) {
                flag = 0;
                ans++;
            }
            setBit(flag, n);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2405.md" >}}
---
{{< youtube 1Zx7gEznzfI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2406: Divide Intervals Into Minimum Number of Groups](https://grid47.xyz/leetcode/solution-2406-divide-intervals-into-minimum-number-of-groups/) |
| --- |
