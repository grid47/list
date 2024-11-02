
+++
authors = ["Crafted by Me"]
title = "Leetcode 1581: Customer Who Visited but Did Not Make Any Transactions"
date = "2020-07-05"
description = "Solution to Leetcode 1581"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description/)

---

**Code:**

{{< highlight cpp >}}
SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
from Visits v 
LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id  
WHERE t.amount IS NULL  and t.transaction_id IS NULL
GROUP BY v.customer_id; 
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

