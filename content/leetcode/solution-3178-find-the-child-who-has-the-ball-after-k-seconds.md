
+++
authors = ["grid47"]
title = "Leetcode 3178: Find the Child Who Has the Ball After K Seconds"
date = "2023-12-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3178: Find the Child Who Has the Ball After K Seconds in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "JX-J9LZxqvk"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi_webp/JX-J9LZxqvk/maxresdefault.webp"
comments = true
+++



---
You are given two positive integers, `n` and `k`. There are `n` children numbered from 0 to `n - 1`, standing in a queue from left to right. Initially, child 0 holds a ball and the direction of passing the ball is towards the right. After each second, the child holding the ball passes it to the next child in the queue. If the ball reaches the first or last child, the direction of passing the ball reverses. You need to determine which child will have the ball after `k` seconds.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integers, `n` (the number of children) and `k` (the number of seconds after which the ball will be passed).
- **Example:** `Example 1:
Input: n = 4, k = 3
Output: 1
Explanation: After 3 seconds, the ball will be with child 1.`
- **Constraints:**
	- 2 <= n <= 50
	- 1 <= k <= 50

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of the child who will hold the ball after `k` seconds.
- **Example:** `Example 2:
Input: n = 5, k = 6
Output: 2
Explanation: After 6 seconds, the ball will be with child 2.`
- **Constraints:**
	- The output will be an integer between 0 and n-1, inclusive.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the passing of the ball for `k` seconds and track which child holds it.

- Initialize the ball at child 0, and the direction of passing the ball as right (towards child 1).
- For each second, check if the ball should change direction (i.e., if the ball reaches the first or last child).
- Update the ball's position accordingly and repeat until `k` seconds have elapsed.
{{< dots >}}
### Problem Assumptions ✅
- The ball passes to the next child every second.
- The ball's direction is reversed when it reaches the first or last child.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1:`  \
  **Explanation:** For `n = 4` and `k = 3`, the ball starts at child 0 and moves to child 1 after 1 second. After 2 seconds, it moves to child 2. After 3 seconds, it moves back to child 1. Therefore, the output is 1.

- **Input:** `Example 2:`  \
  **Explanation:** For `n = 5` and `k = 6`, the ball starts at child 0 and moves right until child 4. After 5 seconds, it reverses direction and moves back to child 1. Finally, after 6 seconds, it reaches child 2. Hence, the output is 2.

- **Input:** `Example 3:`  \
  **Explanation:** For `n = 3` and `k = 2`, the ball moves from child 0 to child 1 after 1 second and then to child 2 after 2 seconds. Therefore, the output is 2.

{{< dots >}}
## Approach 🚀
We can simulate the ball passing process by iterating through each second and tracking the ball's position. We need to reverse the direction whenever the ball reaches the first or last child.

### Initial Thoughts 💭
- The problem is based on a simple simulation of the ball passing process.
- We need to keep track of the ball's position and change direction when it reaches the ends of the queue.
- We can use a simple loop to simulate the passing of the ball for `k` seconds and update the direction when the ball reaches the ends.
{{< dots >}}
### Edge Cases 🌐
- There are no edge cases for empty inputs, as `n` and `k` are always provided.
- The algorithm should handle the maximum constraints efficiently, with `n` and `k` up to 50.
- When `n = 2` and `k = 1`, the ball will move from child 0 to child 1 and then reverse direction back to child 0.
- The simulation approach should run in O(k) time, which is efficient for the input size.
{{< dots >}}
## Code 💻
```cpp
int numberOfChild(int n, int k) {
    int up = false, idx = 0;
    for(int i = 0; i < k; i++) {

        if (idx == n - 1 || idx == 0) up = !up;

        if (up) idx++;
        else    idx--;

    }
    return idx;
}
```

This function calculates the final position of a child moving back and forth within a boundary of `n` positions over `k` steps.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int numberOfChild(int n, int k) {
	```
	This is the function definition for `numberOfChild` which takes two parameters: `n` (total positions) and `k` (steps to move).

2. **Variable Initialization**
	```cpp
	    int up = false, idx = 0;
	```
	The variables `up` (to determine the direction) and `idx` (current position) are initialized.

3. **Loop Initialization**
	```cpp
	    for(int i = 0; i < k; i++) {
	```
	A loop is initiated to iterate over `k` steps.

4. **Direction Change**
	```cpp
	        if (idx == n - 1 || idx == 0) up = !up;
	```
	The direction of movement (`up`) is toggled if the position reaches either boundary (`0` or `n-1`).

5. **Position Update - Up**
	```cpp
	        if (up) idx++;
	```
	If moving 'up', increment the position (`idx`).

6. **Position Update - Down**
	```cpp
	        else    idx--;
	```
	If not moving 'up', decrement the position (`idx`).

7. **Return Final Position**
	```cpp
	    return idx;
	```
	The function returns the final position (`idx`) after all `k` steps.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k)
- **Average Case:** O(k)
- **Worst Case:** O(k)

The time complexity is O(k), as we need to simulate the ball passing process for `k` seconds.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as we only need to store the current position and direction of the ball.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/)

---
{{< youtube JX-J9LZxqvk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
