
+++
authors = ["Yasir"]
title = "Leetcode 180: Consecutive Numbers"
date = "2024-04-30"
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

{{< highlight html >}}
import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    unq_col1 = (logs.num.diff() == 0)
    unq_col2 = (logs.num.diff().diff() == 0)
    scp = logs[unq_col1 & unq_col2][["num"]]
    e = scp.drop_duplicates()
    res = e.rename(columns={'num':'ConsecutiveNums'})
    return res
{{< /highlight >}}

