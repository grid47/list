
+++
authors = ["grid47"]
title = "Leetcode 991: Broken Calculator"
date = "2024-07-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 991: Broken Calculator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "XIiLnBV664A"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi/XIiLnBV664A/maxresdefault.jpg"
comments = true
+++



---
You are given a broken calculator that displays an integer 'startValue'. In each operation, you can either multiply the number by 2 or subtract 1. Your task is to determine the minimum number of operations needed to transform 'startValue' into 'target'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, 'startValue' and 'target'.
- **Example:** `startValue = 2, target = 5`
- **Constraints:**
	- 1 <= startValue, target <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be an integer representing the minimum number of operations required to convert 'startValue' to 'target'.
- **Example:** `Output: 3`
- **Constraints:**
	- The result will always be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of operations by strategically choosing whether to subtract or multiply by 2 based on the relationship between 'startValue' and 'target'.

- If the startValue is greater than or equal to target, the only operation is to repeatedly subtract 1.
- If the target is even, it's optimal to divide the target by 2 to minimize the number of operations.
- If the target is odd, incrementing or decrementing by 1 helps make it even for the next step.
{{< dots >}}
### Problem Assumptions ✅
- The operations always aim to reach the target from the startValue with minimal steps.
{{< dots >}}
## Examples 🧩
- **Input:** `startValue = 2, target = 5`  \
  **Explanation:** Starting at 2, we can subtract twice (2 -> 1 -> 0) and then multiply by 2 to reach 5.

{{< dots >}}
## Approach 🚀
The approach is to recursively or iteratively determine the minimal steps to reach target from startValue. If the target is larger, try halving it, if smaller, increment or decrement until the value matches.

### Initial Thoughts 💭
- The problem is about reducing the difference between startValue and target using the minimum number of operations.
- We can approach this by checking if the target is greater than or less than startValue, and apply the operations accordingly.
{{< dots >}}
### Edge Cases 🌐
- This problem does not involve empty inputs.
- Ensure that the solution handles cases where startValue and target are both large (up to 10^9).
- Consider edge cases where startValue is equal to target or where startValue is much larger than target.
- The solution should handle large values efficiently.
{{< dots >}}
## Code 💻
```cpp
int brokenCalc(int startValue, int target) {
    if(startValue >= target) return startValue - target;
    
    if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
    
    return 1 + brokenCalc(startValue, target +1);
}
```

This function implements a broken calculator to transform the start value into the target value using a minimal number of operations. It uses recursive logic to either halve the target or increment it, depending on the value of the target.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int brokenCalc(int startValue, int target) {
	```
	Defines the `brokenCalc` function, which takes two integer inputs: `startValue` (the starting value) and `target` (the target value to reach).

2. **Base Case - Subtraction**
	```cpp
	    if(startValue >= target) return startValue - target;
	```
	Checks if the starting value is greater than or equal to the target value. If true, returns the difference between `startValue` and `target`, which represents the minimal number of operations needed.

3. **Recursive Case - Halving**
	```cpp
	    if(target % 2 == 0) return 1 + brokenCalc(startValue, target / 2);
	```
	Checks if the target is even. If true, recursively calls `brokenCalc` with the target halved, and adds 1 to account for the halving operation.

4. **Recursive Case - Incrementing**
	```cpp
	    return 1 + brokenCalc(startValue, target +1);
	```
	If the target is odd, the function increments the target by 1 and recursively calls `brokenCalc` with the new target, adding 1 to the operation count.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(target)) - when halving the target
- **Average Case:** O(log(target))
- **Worst Case:** O(log(target))

The time complexity is logarithmic because the target is halved at each step when it's even.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1) - The space complexity is constant, as we only need a few variables to keep track of the target and startValue.

The space complexity is constant as no extra data structures are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/broken-calculator/description/)

---
{{< youtube XIiLnBV664A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
