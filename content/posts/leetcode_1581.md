
+++
authors = ["Yasir"]
title = "Leetcode 1581: Customer Who Visited but Did Not Make Any Transactions"
date = "2020-07-01"
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

{{< highlight html >}}
SELECT v.customer_id, COUNT(v.visit_id) AS count_no_trans 
from Visits v 
LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id  
WHERE t.amount IS NULL  and t.transaction_id IS NULL
GROUP BY v.customer_id; 
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

