
+++
authors = ["Yasir"]
title = "Leetcode 1484: Group Sold Products By The Date"
date = "2020-10-05"
description = "Solution to Leetcode 1484"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/group-sold-products-by-the-date/description/)

---

**Code:**

{{< highlight html >}}
SELECT sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date ASC;
{{< /highlight >}}

