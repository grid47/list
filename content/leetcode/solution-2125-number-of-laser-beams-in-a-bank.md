
+++
authors = ["grid47"]
title = "Leetcode 2125: Number of Laser Beams in a Bank"
date = "2024-04-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2125: Number of Laser Beams in a Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","String","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
    public:
    int numberOfBeams(vector<string> bank) {

        int res = 0, m = bank.size(), n = bank[0].size();

        int cnt = 0, prv = 0;
        for (auto b : bank) 
        {
            cnt = 0;
            for(int i = 0; i < n; i++)
                if (b[i] == '1') cnt++;
            if(cnt > 0) {
                res += prv * cnt;
                prv = cnt;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2125.md" >}}
---
{{< youtube KLeKv59LAFY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2126: Destroying Asteroids](https://grid47.xyz/leetcode/solution-2126-destroying-asteroids/) |
| --- |
