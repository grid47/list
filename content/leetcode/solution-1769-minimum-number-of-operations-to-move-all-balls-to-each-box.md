
+++
authors = ["grid47"]
title = "Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "R8geTAz_yk8"
youtube_upload_date="2021-02-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/R8geTAz_yk8/maxresdefault.webp"
comments = true
+++



---
You are given a binary string `boxes` of length `n`, where each character represents whether a box is empty ('0') or contains a ball ('1'). Your task is to calculate, for each box, the minimum number of operations required to move all the balls to that particular box. An operation involves moving a ball from one box to an adjacent box.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a binary string `boxes` representing the state of boxes, where '0' means empty and '1' means a ball is present.
- **Example:** `boxes = '101'`
- **Constraints:**
	- 1 <= n <= 2000
	- boxes[i] is either '0' or '1'.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `answer` where each `answer[i]` is the minimum number of operations needed to move all the balls to the ith box.
- **Example:** `Output: [1, 1, 2]`
- **Constraints:**
	- The result should be an array of size `n`.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to calculate the minimum number of operations needed to move all balls to each box, considering the initial arrangement of the balls.

- Initialize an array `res` to store the result, with initial values set to 0.
- For each box, calculate the total number of operations required to move the balls from all other boxes to this box.
- Optimize the solution by iterating over the string twice (once from left to right and once from right to left).
{{< dots >}}
### Problem Assumptions ✅
- The input string will always have at least one box (n >= 1).
- The input will contain only '0' or '1' characters.
{{< dots >}}
## Examples 🧩
- **Input:** `boxes = '101'`  \
  **Explanation:** In this case, we calculate the operations needed for each box: 1 for the first box, 1 for the second box, and 2 for the third box.

- **Input:** `boxes = '001010'`  \
  **Explanation:** Here, we calculate the number of operations for each box, considering how far the balls need to move.

{{< dots >}}
## Approach 🚀
The problem can be solved by calculating the minimum number of moves for each box by iterating over the string in both directions.

### Initial Thoughts 💭
- The problem requires calculating how many balls need to move to each box, considering their initial positions.
- Using two sweeps (left to right and right to left) allows us to calculate the operations in linear time.
{{< dots >}}
### Edge Cases 🌐
- The input string will not be empty as per the problem constraints.
- The solution should efficiently handle strings of length up to 2000.
- If all boxes are empty, the result will be an array of zeros.
- The input will always be valid as per the problem constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> minOperations(string boxes) {
    vector<int> res(boxes.length()); 
    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
        res[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
        res[i] += ops;
        cnt += boxes[i] == '1' ? 1 : 0;
        ops += cnt;
    }
    return res;
}
```

This function calculates the minimum number of operations needed to move all the balls in a given `boxes` string. Each operation consists of moving a ball from one box to another, and the function calculates the number of operations needed for each box by processing the string from both directions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> minOperations(string boxes) {
	```
	Define the function `minOperations`, which takes a string `boxes` and returns a vector of integers. The vector represents the number of operations required for each box.

2. **Variable Initialization**
	```cpp
	    vector<int> res(boxes.length()); 
	```
	Initialize a result vector `res` with the size equal to the length of the `boxes` string. This vector will hold the number of operations for each box.

3. **Loop Initialization**
	```cpp
	    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
	```
	Start the first loop to process the `boxes` string from left to right. Variables `ops` (operations counter) and `cnt` (count of balls encountered) are initialized to 0.

4. **Result Update**
	```cpp
	        res[i] += ops;
	```
	Update the result vector `res[i]` by adding the current number of operations (`ops`) for the current box `i`.

5. **Ball Count Update**
	```cpp
	        cnt += boxes[i] == '1' ? 1 : 0;
	```
	If the current box contains a ball ('1'), increment the counter `cnt` by 1.

6. **Operations Update**
	```cpp
	        ops += cnt;
	```
	Add the number of balls encountered so far (`cnt`) to the total number of operations (`ops`).

7. **Loop Initialization**
	```cpp
	    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
	```
	Start the second loop to process the `boxes` string from right to left. Re-initialize the `ops` and `cnt` variables.

8. **Result Update**
	```cpp
	        res[i] += ops;
	```
	Update the result vector `res[i]` by adding the current number of operations (`ops`) for the current box `i`.

9. **Ball Count Update**
	```cpp
	        cnt += boxes[i] == '1' ? 1 : 0;
	```
	If the current box contains a ball ('1'), increment the counter `cnt` by 1.

10. **Operations Update**
	```cpp
	        ops += cnt;
	```
	Add the number of balls encountered so far (`cnt`) to the total number of operations (`ops`).

11. **Return Statement**
	```cpp
	    return res;
	```
	Return the `res` vector, which contains the minimum operations required for each box.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

We iterate over the string twice (once from left to right and once from right to left), so the time complexity is O(n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use additional space for the result array, which stores the number of operations for each box.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

---
{{< youtube R8geTAz_yk8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
