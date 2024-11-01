
+++
authors = ["Crafted by Me"]
title = "Leetcode 178: Rank Scores"
date = "2024-05-08"
description = "Solution to Leetcode 178"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rank-scores/description/)

---

**Code:**

{{< highlight cpp >}}
SELECT
  Score,
  (SELECT count(distinct Score) FROM Scores WHERE Score >= s.Score) `Rank`
FROM Scores s
ORDER BY Score desc;
{{< /highlight >}}


{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/178.md" >}}
- by gpt
        
---
{{< youtube wmummY2FDa4 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

