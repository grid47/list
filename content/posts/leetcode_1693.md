
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1693: Daily Leads and Partners"
date = "2020-03-12"
description = "Solution to Leetcode 1693"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/daily-leads-and-partners/description/)

---

**Code:**

{{< highlight cpp >}}
# Write your MySQL query statement below
SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners FROM DailySales GROUP BY date_id, make_name;
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

