
+++
authors = ["grid47"]
title = "Leetcode 1716: Calculate Money in Leetcode Bank"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1716: Calculate Money in Leetcode Bank in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "tKK7gvPCQfs"
youtube_upload_date="2023-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/tKK7gvPCQfs/maxresdefault.jpg"
comments = true
+++



---
Hercy is saving money for his first car. He deposits money into his Leetcode bank account every day. On the first day (Monday), he deposits $1. For every subsequent day from Tuesday to Sunday, he deposits $1 more than the previous day. Every Monday, he increases his deposit by $1 compared to the previous Monday. Given a number `n`, representing the number of days Hercy saves money, return the total amount of money he has saved after the `n`th day.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `n`, which represents the number of days Hercy has saved money.
- **Example:** `Input: n = 5`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total amount of money Hercy has saved after `n` days.
- **Example:** `Output: 15`
- **Constraints:**
	- The output will be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the total amount Hercy saves in `n` days.

- 1. Initialize the deposit for the first Monday as $1.
- 2. For each day, add the deposit for that day (increasing each week).
- 3. After every 7 days, increase the deposit for the following Monday by $1.
{{< dots >}}
### Problem Assumptions ✅
- The number of days `n` is always between 1 and 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5`  \
  **Explanation:** Hercy deposits $1 on Monday, $2 on Tuesday, $3 on Wednesday, $4 on Thursday, and $5 on Friday. The total saved is 1 + 2 + 3 + 4 + 5 = 15.

- **Input:** `Input: n = 10`  \
  **Explanation:** Hercy deposits: [1, 2, 3, 4, 5, 6, 7] on the first week and [2, 3, 4, 5, 6, 7, 8] on the second week. The total saved is 37.

{{< dots >}}
## Approach 🚀
To solve this problem, we simulate Hercy's savings pattern by calculating the amount saved for each day based on the rule described.

### Initial Thoughts 💭
- We need to consider the weekly pattern of increasing deposits.
- We can simulate the saving process day by day, increasing the deposit after each week.
{{< dots >}}
### Edge Cases 🌐
- The input will always be valid as `n` will be between 1 and 1000.
- Ensure that the solution handles inputs up to the upper limit of 1000 efficiently.
- Handle cases where `n` is a multiple of 7, ensuring the weekly reset happens correctly.
- The algorithm must run in O(n) time to handle the maximum input size.
{{< dots >}}
## Code 💻
```cpp
int totalMoney(int n) {
    int s = 1, ans = 0;
    while (n > 0) {
        for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
        s++;
    }
    return ans;
}
```

This function calculates the total money accumulated over a series of weekly deposits, starting with 1 dollar in the first week, increasing by 1 dollar each subsequent week, and repeating the weekly increment for each cycle until `n` days have passed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int totalMoney(int n) {
	```
	Defines the `totalMoney` function that calculates the total money accumulated over `n` days following the specified rules.

2. **Variable Initialization**
	```cpp
	    int s = 1, ans = 0;
	```
	Initializes two variables: `s` to 1, which represents the amount of money added in each week, and `ans` to 0, which stores the total accumulated money.

3. **Loop Setup**
	```cpp
	    while (n > 0) {
	```
	Starts a while loop that continues as long as there are remaining days (`n > 0`). In each iteration, a week of money is accumulated.

4. **Inner Loop**
	```cpp
	        for (int i = 0; i < 7 && n-- > 0; ++i) ans += s + i;
	```
	Uses a for loop to simulate the accumulation of money over 7 days in a week. Each day, an increasing amount of money is added to `ans` by adding `s + i` (where `i` is the day of the week, starting at 0).

5. **Increment Week**
	```cpp
	        s++;
	```
	After each full week, the starting amount for the next week (`s`) is incremented by 1, simulating the increase in the amount of money added each subsequent week.

6. **Return Result**
	```cpp
	    return ans;
	```
	Returns the total amount of money accumulated after processing all `n` days.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of days Hercy saves money.
- **Average Case:** O(n), since we process each day once.
- **Worst Case:** O(n), as we iterate through each day from 1 to `n`.

The time complexity is O(n), as we simulate the savings for each day.

### Space Complexity 💾
- **Best Case:** O(1), as no additional space is needed except for the variables used to keep track of the total and deposits.
- **Worst Case:** O(1), since we are only using a few variables for calculation.

The space complexity is O(1), as the solution only uses a constant amount of space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/)

---
{{< youtube tKK7gvPCQfs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
