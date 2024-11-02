
+++
authors = ["Crafted by Me"]
title = "Leetcode 195: Tenth Line"
date = "2023-04-21"
description = "Solution to Leetcode 195"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/tenth-line/description/)

---

**Code:**

{{< highlight cpp >}}
# Read from the file file.txt and output the tenth line to stdout.
head -10 file.txt | tail -n+10 | head -1
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/195.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

