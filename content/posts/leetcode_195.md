
+++
authors = ["Yasir"]
title = "Leetcode 195: Tenth Line"
date = "2024-04-15"
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

{{< highlight html >}}
# Read from the file file.txt and output the tenth line to stdout.
head -10 file.txt | tail -n+10 | head -1
{{< /highlight >}}

