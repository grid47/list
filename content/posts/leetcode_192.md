
+++
authors = ["Yasir"]
title = "Leetcode 192: Word Frequency"
date = "2024-04-20"
description = "Solution to Leetcode 192"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/word-frequency/description/)

---

**Code:**

{{< highlight html >}}
# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2 ,$1}'
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

