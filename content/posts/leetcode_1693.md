
+++
authors = ["Yasir"]
title = "Leetcode 1693: Daily Leads and Partners"
date = "2020-03-10"
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

{{< highlight html >}}
# Write your MySQL query statement below
SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners FROM DailySales GROUP BY date_id, make_name;
{{< /highlight >}}

