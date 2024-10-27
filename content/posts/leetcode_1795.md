
+++
authors = ["Yasir"]
title = "Leetcode 1795: Rearrange Products Table"
date = "2019-11-29"
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

{{< highlight html >}}
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

