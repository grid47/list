
+++
authors = ["grid47"]
title = "Leetcode 365: Water and Jug Problem"
date = "2024-10-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 365: Water and Jug Problem in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Depth-First Search","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/365.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/365.webp" 
    alt="A set of water jugs being filled and emptied, with the optimal solution softly glowing as it reaches the target amount."
    caption="Solution to LeetCode 365: Water and Jug Problem Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two jugs with capacities x and y liters, and an infinite supply of water. You need to determine whether you can measure exactly target liters of water using the following operations: fill, empty, and pour water between the jugs.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of three integers: x, y, and target, representing the capacities of the two jugs and the target amount of water to measure.
- **Example:** `x = 3, y = 5, target = 4`
- **Constraints:**
	- 1 <= x, y, target <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be true if it is possible to measure exactly the target amount of water, otherwise false.
- **Example:** `Input: x = 3, y = 5, target = 4
Output: true`
- **Constraints:**
	- The output should be true or false based on the feasibility of measuring the target amount of water.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if it is possible to measure exactly the target amount of water using the given operations on the two jugs.

- 1. If the total capacity of both jugs is less than the target, return false.
- 2. If either jug has the exact target capacity, return true.
- 3. If the sum of the two jugs' capacities is equal to the target, return true.
- 4. Otherwise, check if the target is divisible by the greatest common divisor (gcd) of the two jug capacities.
{{< dots >}}
### Problem Assumptions ✅
- The solution assumes that the jugs can be manipulated by filling, emptying, and pouring until the target amount is reached or proven impossible.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: x = 3, y = 5, target = 4
Output: true`  \
  **Explanation:** You can measure 4 liters by filling and transferring water between the two jugs. Follow the steps to achieve the target of 4 liters.

{{< dots >}}
## Approach 🚀
The solution uses the greatest common divisor (gcd) method to determine whether the target amount can be measured by checking the mathematical conditions for each jug capacity.

### Initial Thoughts 💭
- The gcd of the jug capacities plays a key role in determining whether it's possible to measure the target.
- We need to ensure the target is either directly achievable or divisible by the gcd of the two jug capacities.
{{< dots >}}
### Edge Cases 🌐
- If x, y, or target is 0, return false.
- Ensure the solution handles inputs up to 1000 efficiently.
- When x or y equals the target, return true.
- The constraints guarantee that inputs will always be within the range of 1 to 1000.
{{< dots >}}
## Code 💻
```cpp
bool canMeasureWater(int x, int y, int z) {
    if(x + y < z) return false;
    if(x == z || y == z || x + y == z) return true;
    return z % gcd(x, y) == 0;
}

int gcd(int a, int b) {
    return b == 0? a: gcd(b, a%b);
}
```

The `canMeasureWater` function checks if it's possible to measure exactly `z` units using two jugs with capacities `x` and `y`. It uses the mathematical principle that the target amount `z` must be a multiple of the greatest common divisor (GCD) of `x` and `y` for it to be possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Declaration**
	```cpp
	bool canMeasureWater(int x, int y, int z) {
	```
	This line declares the method `canMeasureWater`, which takes three integers `x`, `y`, and `z`, representing the capacities of the two jugs and the target amount of water to measure.

2. **Conditional Check**
	```cpp
	    if(x + y < z) return false;
	```
	Checks if the sum of the two jugs' capacities is less than the target `z`. If so, it returns `false` because it’s impossible to measure `z` units of water.

3. **Conditional Check**
	```cpp
	    if(x == z || y == z || x + y == z) return true;
	```
	Checks if either jug can directly hold the target amount of water (`z`) or if the sum of both jugs' capacities equals `z`. In either case, it returns `true`.

4. **Mathematical Condition**
	```cpp
	    return z % gcd(x, y) == 0;
	```
	Returns `true` if `z` is divisible by the greatest common divisor (GCD) of `x` and `y`, which is a key condition for measuring exactly `z` units using the two jugs.

5. **Blank Line**
	```cpp
	
	```
	This is a blank line for readability, separating the main method from the helper function `gcd`.

6. **Helper Method Declaration**
	```cpp
	int gcd(int a, int b) {
	```
	This line declares a helper method `gcd` to calculate the greatest common divisor (GCD) of two integers `a` and `b` using the Euclidean algorithm.

7. **Recursive Call**
	```cpp
	    return b == 0? a: gcd(b, a%b);
	```
	This line uses the Euclidean algorithm to calculate the GCD recursively. If `b` is 0, it returns `a` as the GCD; otherwise, it recursively calls `gcd` with `b` and `a % b`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log(min(x, y))) for calculating gcd.
- **Average Case:** O(log(min(x, y))) for gcd and conditional checks.
- **Worst Case:** O(log(min(x, y))) for gcd calculation.

The gcd computation takes logarithmic time relative to the smaller jug capacity.

### Space Complexity 💾
- **Best Case:** O(1) as no extra space is used.
- **Worst Case:** O(1) as no additional data structures are required.

The space complexity is constant because only a few variables are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/water-and-jug-problem/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
