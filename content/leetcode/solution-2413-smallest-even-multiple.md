
+++
authors = ["grid47"]
title = "Leetcode 2413: Smallest Even Multiple"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2413: Smallest Even Multiple in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "MTdr8qNSWf8"
youtube_upload_date="2022-09-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MTdr8qNSWf8/maxresdefault.webp"
comments = true
+++



---
Given a positive integer 'n', return the smallest positive integer that is a multiple of both 2 and 'n'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer 'n'.
- **Example:** `n = 7`
- **Constraints:**
	- 1 <= n <= 150

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest integer that is a multiple of both 2 and 'n'.
- **Example:** `Output: 14`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the smallest integer that is divisible by both 2 and 'n'.

- 1. Check if 'n' is already divisible by 2.
- 2. If 'n' is even, return 'n'.
- 3. If 'n' is odd, return 'n * 2' because the next multiple of both 2 and 'n' will be twice 'n'.
{{< dots >}}
### Problem Assumptions ✅
- The input is a positive integer.
- The problem ensures that 'n' is always between 1 and 150.
{{< dots >}}
## Examples 🧩
- **Input:** `n = 7`  \
  **Explanation:** For 'n' = 7, the smallest multiple of both 2 and 7 is 14. For 'n' = 6, since 6 is already divisible by 2, the result is 6.

{{< dots >}}
## Approach 🚀
The solution uses a simple check to determine if 'n' is already divisible by 2. If not, we double 'n' to get the smallest multiple of both 2 and 'n'.

### Initial Thoughts 💭
- The smallest multiple of both 2 and any integer can be obtained by checking if the number is even.
- If the number is odd, we just need to multiply it by 2.
- This approach is straightforward and runs in constant time, making it very efficient.
{{< dots >}}
### Edge Cases 🌐
- The input will always be a positive integer as per the problem constraints.
- The input is constrained to a maximum of 150, so there are no concerns regarding large inputs.
- If 'n' is 1, the smallest multiple of both 2 and 1 is 2.
- Make sure the solution handles both even and odd numbers correctly.
{{< dots >}}
## Code 💻
```cpp
int smallestEvenMultiple(int n) {
    return n % 2 == 0? n: n * 2;
}
```

This function returns the smallest even multiple of a given number 'n'. If 'n' is already even, it returns 'n'; otherwise, it returns 'n' multiplied by 2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int smallestEvenMultiple(int n) {
	```
	Function declaration for 'smallestEvenMultiple'. It takes an integer 'n' as input.

2. **Return Statement**
	```cpp
	    return n % 2 == 0? n: n * 2;
	```
	The function checks if 'n' is even. If true, it returns 'n'; otherwise, it returns 'n' multiplied by 2 to make it even.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant because only a few arithmetic operations are needed.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, requiring only a small amount of space to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/smallest-even-multiple/description/)

---
{{< youtube MTdr8qNSWf8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
