
+++
authors = ["grid47"]
title = "Leetcode 2652: Sum Multiples"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2652: Sum Multiples in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "A1BNPgQSHz8"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/A1BNPgQSHz8/maxresdefault.webp"
comments = true
+++



---
Given a positive integer 'n', find the sum of all integers between 1 and 'n' (inclusive) that are divisible by 3, 5, or 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer 'n' where 1 <= n <= 1000.
- **Example:** `Input: n = 12`
- **Constraints:**
	- 1 <= n <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the sum of all numbers in the range [1, n] that are divisible by 3, 5, or 7.
- **Example:** `Output: 45`
- **Constraints:**
	- The sum will always be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to sum all numbers divisible by 3, 5, or 7 from 1 to n.

- Step 1: Iterate over all integers from 1 to n.
- Step 2: For each number, check if it is divisible by 3, 5, or 7.
- Step 3: If divisible, add it to the sum.
- Step 4: Return the total sum.
{{< dots >}}
### Problem Assumptions ✅
- The input 'n' is a valid positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 7`  \
  **Explanation:** The numbers divisible by 3, 5, or 7 in the range [1, 7] are 3, 5, 6, and 7. The sum is 3 + 5 + 6 + 7 = 21.

- **Input:** `Input: n = 10`  \
  **Explanation:** The numbers divisible by 3, 5, or 7 in the range [1, 10] are 3, 5, 6, 7, 9, and 10. The sum is 3 + 5 + 6 + 7 + 9 + 10 = 40.

{{< dots >}}
## Approach 🚀
The approach is straightforward: Iterate over the numbers from 1 to n, checking divisibility, and adding the valid numbers to the sum.

### Initial Thoughts 💭
- We need to check divisibility for three numbers (3, 5, 7).
- This can be done by checking each number in the range [1, n].
- An efficient approach would involve iterating through the numbers, checking divisibility, and keeping a running total.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that n will always be at least 1, so there are no empty inputs.
- The input n can go up to 1000, which requires handling a larger range efficiently.
- Consider the case where n is a small value like 1, where no numbers are divisible by 3, 5, or 7.
- Ensure the solution works efficiently for the upper limit of n = 1000.
{{< dots >}}
## Code 💻
```cpp
int sumOfMultiples(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++)
        if((i % 3 == 0) || (i% 5 == 0) || (i % 7 == 0))
            sum += i;
    return sum;
}
```

This function calculates the sum of all numbers from 1 to 'n' that are divisible by 3, 5, or 7.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int sumOfMultiples(int n) {
	```
	This line defines the function 'sumOfMultiples', which takes an integer parameter 'n' and will return the sum of multiples of 3, 5, or 7.

2. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	This initializes the 'sum' variable to 0, which will be used to accumulate the sum of the multiples.

3. **Loop Setup**
	```cpp
	    for(int i = 1; i <= n; i++)
	```
	This starts a loop from 1 to 'n', iterating through each number in this range.

4. **Conditional Check**
	```cpp
	        if((i % 3 == 0) || (i% 5 == 0) || (i % 7 == 0))
	```
	This condition checks if 'i' is divisible by 3, 5, or 7. If true, the number is added to the sum.

5. **Summation**
	```cpp
	            sum += i;
	```
	If the condition is met, this adds 'i' to the 'sum'.

6. **Return Statement**
	```cpp
	    return sum;
	```
	This line returns the calculated sum of the multiples.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear, as we check each number for divisibility.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because we only need a few extra variables to store the sum and loop index.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-multiples/description/)

---
{{< youtube A1BNPgQSHz8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
