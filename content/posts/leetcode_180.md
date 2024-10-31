
+++
authors = ["Crafted by Me"]
title = "Leetcode 180: Consecutive Numbers"
date = "2024-05-05"
description = "Solution to Leetcode 180"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

