
+++
authors = ["Crafted by Me"]
title = "Leetcode 195: Tenth Line"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 195: Tenth Line in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String","Shell"]
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #196: Delete Duplicate Emails](https://grid47.xyz/posts/leetcode_196) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

