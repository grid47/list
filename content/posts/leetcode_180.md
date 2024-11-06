
+++
authors = ["Crafted by Me"]
title = "Leetcode 180: Consecutive Numbers"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 180: Consecutive Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Database"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/consecutive-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    unq_col1 = (logs.num.diff() == 0)
    unq_col2 = (logs.num.diff().diff() == 0)
    scp = logs[unq_col1 & unq_col2][["num"]]
    e = scp.drop_duplicates()
    res = e.rename(columns={'num':'ConsecutiveNums'})
    return res
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/180.md" >}}
---
{{< youtube _nU4hBwsyTE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #181: Employees Earning More Than Their Managers](https://grid47.xyz/posts/leetcode_181) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
