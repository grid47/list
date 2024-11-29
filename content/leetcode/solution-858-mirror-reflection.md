
+++
authors = ["grid47"]
title = "Leetcode 858: Mirror Reflection"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 858: Mirror Reflection in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Geometry","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fUa0LRtSlz0"
youtube_upload_date="2021-02-01"
youtube_thumbnail="https://i.ytimg.com/vi/fUa0LRtSlz0/maxresdefault.jpg"
comments = true
+++



---
In a special square room with mirrors on all four walls, except for the southwest corner, there are receptors at three other corners, numbered 0, 1, and 2. A laser ray is fired from the southwest corner and hits the east wall at a certain distance from the 0th receptor. Given the side length of the square room, p, and the distance q from the 0th receptor on the east wall where the laser ray meets, return the number of the receptor the ray hits first after bouncing around the room.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two integers: p, the length of the side of the square room, and q, the distance from the southwest corner to where the laser first meets the east wall.
- **Example:** `Input: p = 4, q = 2`
- **Constraints:**
	- 1 <= q <= p <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** The function should return an integer representing the receptor number (0, 1, or 2) where the laser ray first reaches after bouncing off the walls.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine which receptor the laser ray hits first, considering how it reflects off the walls of the square room.

- Step 1: Check the divisibility of both p and q by 2 and repeatedly divide them by 2 until one of them is odd.
- Step 2: Use the formula `1 - p%2 + q%2` to determine the receptor number.
- Step 3: Return the receptor number.
{{< dots >}}
### Problem Assumptions ✅
- The room is always square.
- The input values p and q are valid and guarantee that the ray will eventually meet a receptor.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: p = 4, q = 2`  \
  **Explanation:** In this example, the laser first meets the east wall at a distance of 2 from the 0th receptor. After bouncing, the ray reaches receptor 1, as it is reflected back towards the wall.

{{< dots >}}
## Approach 🚀
To solve the problem efficiently, we utilize a mathematical approach that simplifies the conditions for determining the receptor. By reducing the values of p and q iteratively through division, we arrive at a formula that can quickly calculate the receptor number.

### Initial Thoughts 💭
- The problem can be reduced by dividing both p and q by 2 when they are even.
- The solution involves manipulating the parity of p and q to deduce which receptor the ray meets.
{{< dots >}}
### Edge Cases 🌐
- N/A: Inputs are guaranteed to meet the constraints.
- For large values of p and q, the solution still works within time limits due to efficient reduction of the values.
- When p equals q and both are odd, the ray will hit receptor 2.
- The values of p and q will always satisfy the input constraints.
{{< dots >}}
## Code 💻
```cpp
int mirrorReflection(int p, int q) {
    while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
    return 1 - p%2 + q%2;
}
```

This function calculates the mirror reflection of two points `p` and `q` after repeatedly halving their values when both are even.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int mirrorReflection(int p, int q) {
	```
	The function `mirrorReflection` takes two integers `p` and `q` as input and returns the mirror reflection based on the conditions in the while loop.

2. **While Loop**
	```cpp
	    while( p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
	```
	The `while` loop repeatedly halves both `p` and `q` (using right shift operator) as long as both are even. This effectively reduces the problem size until at least one of them becomes odd.

3. **Return Statement**
	```cpp
	    return 1 - p%2 + q%2;
	```
	After exiting the loop, the function returns a value based on the parity of `p` and `q`. It checks if `p` is odd and `q` is odd and returns an appropriate result based on the mirror reflection rules.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log p), as the values of p and q are halved iteratively until one of them becomes odd.
- **Average Case:** O(log p), due to the iterative halving process.
- **Worst Case:** O(log p), because the division operation continues until one of p or q is odd.



### Space Complexity 💾
- **Best Case:** O(1), since no additional space is needed beyond the input values.
- **Worst Case:** O(1), as only a few variables are used to calculate the result.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/mirror-reflection/description/)

---
{{< youtube fUa0LRtSlz0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
