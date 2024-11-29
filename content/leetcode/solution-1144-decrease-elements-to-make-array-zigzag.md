
+++
authors = ["grid47"]
title = "Leetcode 1144: Decrease Elements To Make Array Zigzag"
date = "2024-07-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1144: Decrease Elements To Make Array Zigzag in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given an array nums of integers. A move consists of selecting any element and decreasing it by 1. A zigzag array is an array where either every even-indexed element is greater than its adjacent elements or every odd-indexed element is greater than its adjacent elements. Your task is to return the minimum number of moves required to transform the given array into a zigzag array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums of integers.
- **Example:** `Input: nums = [3, 1, 4]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of moves required to transform the given array into a zigzag array.
- **Example:** `Output: 1`
- **Constraints:**
	- The output will be a single integer representing the minimum number of moves.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to transform the array into a zigzag array by minimizing the number of moves.

- 1. Iterate over the array and compare each element with its adjacent elements.
- 2. For each element, check if it violates the zigzag condition. If it does, calculate the number of moves to fix it.
- 3. Track the total number of moves for both the even-indexed and odd-indexed conditions.
- 4. Return the minimum number of moves required.
{{< dots >}}
### Problem Assumptions ✅
- The array may contain both small and large numbers.
- The length of the array will be between 1 and 1000.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 1, 4]`  \
  **Explanation:** In this case, we can decrease 4 to 2, resulting in the zigzag array [3, 1, 2], and the number of moves is 1.

- **Input:** `Input: nums = [6, 4, 2, 8, 10]`  \
  **Explanation:** In this case, we decrease 6 to 4 and 8 to 6, resulting in the zigzag array [4, 4, 2, 6, 10], and the number of moves is 6.

{{< dots >}}
## Approach 🚀
We can solve this problem by calculating the minimum number of moves required to fix the zigzag condition for both the even-indexed and odd-indexed conditions. For each condition, we will check each element and adjust it if necessary.

### Initial Thoughts 💭
- The problem can be solved by iterating through the array and comparing each element with its neighbors.
- A greedy approach that minimizes the number of moves for each element will work well for this problem.
{{< dots >}}
### Edge Cases 🌐
- If the array is empty, the result should be 0.
- The algorithm should be optimized to handle arrays of length 1000 efficiently.
- If all elements are the same, no moves are required.
- The solution should be efficient in terms of both time and space complexity.
{{< dots >}}
## Code 💻
```cpp
int movesToMakeZigzag(vector<int>& nums) {
    int n = nums.size(), left, right;
    vector<int> res(2, 0);
    for(int i = 0; i < n; i++) {

        left  = ( i     > 0 ) ? nums[i - 1] : 1001;
        right = ( i + 1 < n ) ? nums[i + 1] : 1001;

        res[i % 2] += max(0, nums[i] - min(left, right) + 1);
    }

    return min(res[0], res[1]);
}
```

This function computes the minimum number of moves required to convert the given array `nums` into a zigzag pattern. It calculates the required number of changes for both even and odd index positions, and then returns the smaller of the two results.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int movesToMakeZigzag(vector<int>& nums) {
	```
	This defines the function `movesToMakeZigzag`, which takes a vector of integers `nums` and returns the minimum number of moves to convert the array into a zigzag pattern.

2. **Variable Declaration**
	```cpp
	    int n = nums.size(), left, right;
	```
	Here, the variable `n` stores the size of the array `nums`, while `left` and `right` are used to store the adjacent elements for comparison when calculating the required changes for the zigzag pattern.

3. **Vector Initialization**
	```cpp
	    vector<int> res(2, 0);
	```
	This initializes a vector `res` with two elements, both set to 0. The vector will be used to store the number of changes required to convert the array into a zigzag pattern for even and odd indexed elements.

4. **Loop Initialization**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This initiates a loop that iterates through each element of the array `nums`.

5. **Left Neighbor Calculation**
	```cpp
	        left  = ( i     > 0 ) ? nums[i - 1] : 1001;
	```
	This calculates the value of the left neighbor of the current element. If `i` is greater than 0, it assigns `left` to the previous element (`nums[i - 1]`), otherwise, it assigns a large value (1001) to `left` as a default.

6. **Right Neighbor Calculation**
	```cpp
	        right = ( i + 1 < n ) ? nums[i + 1] : 1001;
	```
	This calculates the value of the right neighbor of the current element. If `i + 1` is less than `n` (the size of the array), it assigns `right` to the next element (`nums[i + 1]`), otherwise, it assigns a large value (1001) to `right` as a default.

7. **Zigzag Move Calculation**
	```cpp
	        res[i % 2] += max(0, nums[i] - min(left, right) + 1);
	```
	This line calculates the number of moves required to make the current element a part of a zigzag sequence. It updates the corresponding index in the `res` vector based on whether `i` is even or odd, and adds the minimum number of moves calculated between `left` and `right`.

8. **Final Calculation**
	```cpp
	    return min(res[0], res[1]);
	```
	This returns the minimum value between the two possible results stored in `res[0]` and `res[1]`, representing the minimum number of moves required for the zigzag pattern starting with even and odd indexed elements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the input array, as we only iterate through the array once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a constant amount of space to track the number of moves.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
