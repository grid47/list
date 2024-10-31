
+++
authors = ["Crafted by Me"]
title = "Leetcode 1795: Rearrange Products Table"
date = "2019-12-03"
description = "Solution to Leetcode 1795"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-products-table/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT product_id, 'store1' AS store, store1 AS price FROM Products
WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2', store2 AS price FROM Products
WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3', store3 AS price FROM Products
WHERE store3 IS NOT NULL;
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

