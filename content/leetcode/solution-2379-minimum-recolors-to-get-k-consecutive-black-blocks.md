
+++
authors = ["grid47"]
title = "Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks"
date = "2024-03-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2379: Minimum Recolors to Get K Consecutive Black Blocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "RRmSKRsT9tg"
youtube_upload_date="2022-08-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/RRmSKRsT9tg/maxresdefault.webp"
comments = true
+++



---
You are given a string `blocks` consisting of the characters 'W' and 'B', where 'W' represents a white block and 'B' represents a black block. You are also given an integer `k` representing the desired length of consecutive black blocks. You can recolor white blocks to black in one operation. The task is to determine the minimum number of operations required to ensure there is at least one occurrence of `k` consecutive black blocks.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `blocks` of length `n`, containing characters 'W' and 'B'. You are also given an integer `k` which is the desired number of consecutive black blocks.
- **Example:** `blocks = 'BBWWBWBW', k = 4`
- **Constraints:**
	- 1 <= blocks.length <= 100
	- blocks[i] is either 'W' or 'B'.
	- 1 <= k <= blocks.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations needed to ensure there is at least one occurrence of `k` consecutive black blocks.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of operations required to change some white blocks to black in order to have at least one sequence of `k` consecutive black blocks.

- 1. Traverse through the string `blocks` and count the number of black blocks in each sliding window of length `k`.
- 2. For each window, calculate the number of white blocks (W) and track the minimum number of changes required.
- 3. Return the minimum number of recoloring operations.
{{< dots >}}
### Problem Assumptions ✅
- The input string `blocks` will consist only of the characters 'W' and 'B'.
- The integer `k` is valid and will not exceed the length of the input string.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: blocks = 'BBWWBWBW', k = 4`  \
  **Explanation:** Here, the desired sequence is 4 consecutive black blocks. The minimum number of operations required to achieve this is 2, as we can change the 3rd and 6th blocks to 'B'.

- **Input:** `Input: blocks = 'WBBWWBB', k = 3`  \
  **Explanation:** In this case, the sequence already contains 3 consecutive black blocks, so no operations are needed. The result is 0.

{{< dots >}}
## Approach 🚀
To solve this problem efficiently, we can use a sliding window technique to calculate the number of black blocks in each window of size `k`. For each window, we count the number of white blocks and track the minimum count across all possible windows.

### Initial Thoughts 💭
- The problem asks for the minimum recoloring operations, so we should focus on finding the windows with the most black blocks already present.
- By using a sliding window of size `k`, we can efficiently calculate the number of black blocks in each segment and determine the minimum changes required.
{{< dots >}}
### Edge Cases 🌐
- The input string `blocks` will never be empty.
- The input string can be as large as 100 characters, so the algorithm should handle this efficiently.
- If the string already contains `k` consecutive black blocks, no operations are needed.
- Ensure that `k` is always less than or equal to the length of the input string.
{{< dots >}}
## Code 💻
```cpp
int minimumRecolors(string blocks, int k) {
int b = 0, mb = 0;
for (int i = 0; i < blocks.size(); ++i) {
    b += blocks[i] == 'B';
    if (i >= k)
        b -= blocks[i - k] == 'B';
    mb = max(b, mb);
}
return k - mb;
}
```

This function calculates the minimum number of recolors needed in a substring of length `k` in the string `blocks` to make all characters either 'B' or 'W'. It uses a sliding window approach to efficiently compute the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumRecolors(string blocks, int k) {
	```
	Defines the function `minimumRecolors` that accepts a string `blocks` representing a sequence of 'B' and 'W' and an integer `k` representing the length of the window. The function returns the minimum number of recolors needed in any substring of length `k` to make it all 'B'.

2. **Variable Initialization**
	```cpp
	int b = 0, mb = 0;
	```
	Initializes two integer variables: `b` to count the number of 'B's in the current window, and `mb` to store the maximum number of 'B's in any valid window of size `k` encountered so far.

3. **Loop Start**
	```cpp
	for (int i = 0; i < blocks.size(); ++i) {
	```
	Starts a for loop to iterate over each character in the string `blocks`. This loop will examine each position to update the count of 'B's in the current window.

4. **Count 'B's**
	```cpp
	    b += blocks[i] == 'B';
	```
	Increments the counter `b` each time a 'B' is encountered at the current position `i`.

5. **Window Size Check**
	```cpp
	    if (i >= k)
	```
	Checks if the current index `i` has reached or exceeded the window size `k`. This is to ensure that the sliding window approach begins to remove elements as it moves forward.

6. **Adjust Window**
	```cpp
	        b -= blocks[i - k] == 'B';
	```
	If the window has moved past `k`, subtracts the count of 'B' at the position `i - k` (the element that is no longer in the window).

7. **Update Max 'B' Count**
	```cpp
	    mb = max(b, mb);
	```
	Updates the maximum count of 'B's found in any window of size `k` so far by comparing the current count `b` with `mb`.

8. **Return Result**
	```cpp
	return k - mb;
	```
	Returns the minimum number of recolors required by subtracting the maximum number of 'B's found in any valid window (`mb`) from the total window size `k`. The result represents the number of 'W's that need to be recolored to 'B'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) as we only pass through the string once, adjusting the sliding window as we go.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) because we only need a fixed amount of space for counting and the sliding window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/)

---
{{< youtube RRmSKRsT9tg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
