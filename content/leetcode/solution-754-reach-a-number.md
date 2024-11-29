
+++
authors = ["grid47"]
title = "Leetcode 754: Reach a Number"
date = "2024-08-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 754: Reach a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/754.webp"
youtube = "K8yXBn4cCQs"
youtube_upload_date="2020-12-28"
youtube_thumbnail="https://i.ytimg.com/vi/K8yXBn4cCQs/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/754.webp" 
    alt="A number line where the steps to reach a target number are traced, with each step glowing softly."
    caption="Solution to LeetCode 754: Reach a Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are standing at position 0 on an infinite number line. There is a destination at position target. You can make some number of moves where, on the i-th move, you take exactly i steps either left or right. The goal is to determine the minimum number of moves required to reach the target.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer target, representing the position on the number line that you want to reach.
- **Example:** `target = 4`
- **Constraints:**
	- -10^9 <= target <= 10^9
	- target != 0

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to reach the target, or -1 if it's not possible.
- **Example:** `Output: 3`
- **Constraints:**
	- The solution must be efficient for large inputs

{{< dots >}}
### Core Logic 🔍
**Goal:** To determine the minimum number of moves to reach the target by analyzing the required steps.

- 1. Convert the target to its absolute value to simplify the problem.
- 2. Calculate the smallest number of moves needed to reach or exceed the target distance.
- 3. Check if the difference between the total steps taken and the target is even, in which case the solution is valid.
- 4. Return the number of moves required to reach the target.
{{< dots >}}
### Problem Assumptions ✅
- The target value is always non-zero.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: target = 4`  \
  **Explanation:** Start at position 0. Move 1 step to the right, then 2 steps to the left, and finally 3 steps to the right to reach position 4 in 3 moves.

- **Input:** `Example 2: target = 5`  \
  **Explanation:** Start at position 0. Move 1 step to the right, then 2 steps to the right, and finally 3 steps to the right to reach position 5 in 3 moves.

{{< dots >}}
## Approach 🚀
The goal is to compute the smallest number of moves that allow us to reach the target position, by carefully analyzing the total steps taken at each stage.

### Initial Thoughts 💭
- We need to compute the minimum number of moves efficiently for large target values.
- We can calculate the smallest n such that the sum of the first n natural numbers exceeds or equals the target distance.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the target is always non-zero.
- Ensure that the solution handles cases where target is at the extreme ends of the range (-10^9 to 10^9).
- No special cases besides the minimum and maximum target values.
- The solution must handle large target values efficiently.
{{< dots >}}
## Code 💻
```cpp
int reachNumber(int target) {
    target = abs(target);
    long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
    long long sum = n * (n + 1) / 2;
    if (sum == target) return n;
    long long res = sum - target;
    if((res &1) == 0)   return n;
    else                return n + ((n&1)? 2: 1);
}
```

This function calculates the minimum number of steps required to reach a target number, starting from 0, where each step adds or subtracts a consecutive integer.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int reachNumber(int target) {
	```
	Defines the function 'reachNumber', which takes the target number and calculates the minimum steps required to reach it starting from 0.

2. **Absolute Value**
	```cpp
	    target = abs(target);
	```
	Ensures the target number is positive by converting it to its absolute value, as the problem is symmetric with respect to the direction of movement.

3. **Mathematical Calculation**
	```cpp
	    long long n = ceil((-1.0 + sqrt(1+8.0*target)) / 2);
	```
	Calculates the smallest integer 'n' such that the sum of the first 'n' integers is greater than or equal to the target using the formula derived from the quadratic equation.

4. **Sum Calculation**
	```cpp
	    long long sum = n * (n + 1) / 2;
	```
	Calculates the sum of the first 'n' integers (i.e., 1 + 2 + ... + n). This represents the total distance after 'n' steps.

5. **Exact Match Check**
	```cpp
	    if (sum == target) return n;
	```
	Checks if the sum of the first 'n' integers equals the target. If they are equal, the function returns 'n' because the target is reached exactly after 'n' steps.

6. **Difference Calculation**
	```cpp
	    long long res = sum - target;
	```
	Calculates the difference between the sum of the first 'n' integers and the target, to determine how far the sum overshoots the target.

7. **Parity Check**
	```cpp
	    if((res &1) == 0)   return n;
	```
	Checks if the difference 'res' is even. If it is, then it's possible to adjust the sum to match the target by flipping the direction of one of the steps, so the function returns 'n'.

8. **Adjust for Odd Difference**
	```cpp
	    else                return n + ((n&1)? 2: 1);
	```
	If the difference 'res' is odd, it means an additional step is needed to make the sum match the target. If 'n' is odd, add 2 steps; otherwise, add 1 step.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The solution involves simple mathematical calculations, which are constant time operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as only a few variables are used to store intermediate values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/reach-a-number/description/)

---
{{< youtube K8yXBn4cCQs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
