
+++
authors = ["grid47"]
title = "Leetcode 2917: Find the K-or of an Array"
date = "2024-01-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2917: Find the K-or of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jNPKX6McyCg"
youtube_upload_date="2023-10-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jNPKX6McyCg/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums` and an integer `k`. We define the **K-or** operation as follows: for each bit position, the bit in the result will be set to 1 if at least `k` numbers in the array `nums` have a 1 in that position. Return the **K-or** of the array `nums`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `k`.
- **Example:** `nums = [6, 15, 9, 8, 7, 14], k = 4`
- **Constraints:**
	- 1 <= nums.length <= 50
	- 0 <= nums[i] < 231
	- 1 <= k <= nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the **K-or** of the array `nums`.
- **Example:** `Output: 14`
- **Constraints:**
	- The result must be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** We need to find the bitwise OR of all bits that appear in at least `k` numbers from `nums`.

- Iterate through each bit position from 0 to 30 (since nums[i] < 2^31).
- For each bit position, count how many numbers have that bit set to 1.
- If the count is greater than or equal to `k`, set that bit in the result.
{{< dots >}}
### Problem Assumptions ✅
- The array contains at least 1 element.
- k is always less than or equal to the number of elements in `nums`.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [6, 15, 9, 8, 7, 14], k = 4`  \
  **Explanation:** For each bit position, we check how many numbers have that bit set to 1. In this example, the result is 14 because the 2nd, 3rd, and 4th bits appear in at least 4 numbers.

{{< dots >}}
## Approach 🚀
We use bitwise operations to determine which bits appear in at least `k` numbers in the array.

### Initial Thoughts 💭
- We are dealing with bitwise operations, and the solution involves counting the number of 1s in each bit position.
- This problem can be solved efficiently by iterating through each bit position and counting how many numbers have a 1 at that position.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one element.
- If `nums` contains the maximum number of elements (50), the solution will still perform efficiently.
- When `k == 1`, the result will be the bitwise OR of all elements.
- We assume that the constraints are within the range of the problem.
{{< dots >}}
## Code 💻
```cpp
int findKOr(vector<int>& nums, int k) {
    int ans = 0; // Initialize the answer to 0.
    
    for (int i = 0; i < 31; i++) {
        // Bit position represented by 2^i.
        int rep = (1 << i); 
        int cnt = 0; // Initialize a counter to count set bits at this position.

        // Iterate through the input vector 'nums'.
        for (auto ele : nums) {
            if (rep & ele) {
                // If the i-th bit is set in 'ele', increment the count.
                cnt++;
            }
        }

        // If the count of set bits at this position is greater than or equal to 'k', set the corresponding bit in the answer.
        if (cnt >= k) {
            ans = ans | rep;
        }
    }

    return ans; // Return the final answer, which is the result of the OR operation on selected bits.
}
```

This function performs a bitwise OR operation on the selected bits after counting the set bits for each bit position and checking if the count is greater than or equal to 'k'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int findKOr(vector<int>& nums, int k) {
	```
	Defines the function 'findKOr' that takes a vector of integers and an integer k as input.

2. **Variable Initialization**
	```cpp
	    int ans = 0; // Initialize the answer to 0.
	```
	Initializes the answer variable 'ans' to 0.

3. **Loop Setup**
	```cpp
	    for (int i = 0; i < 31; i++) {
	```
	Begins a loop to iterate through 31 possible bit positions.

4. **Bitwise Shift**
	```cpp
	        int rep = (1 << i); 
	```
	Performs a left bitwise shift to calculate the value of 2^i and assigns it to 'rep'.

5. **Variable Initialization**
	```cpp
	        int cnt = 0; // Initialize a counter to count set bits at this position.
	```
	Initializes a counter 'cnt' to track the number of set bits at the current position.

6. **Loop through Input**
	```cpp
	        for (auto ele : nums) {
	```
	Begins a loop to iterate through each element in the 'nums' vector.

7. **Conditional Check**
	```cpp
	            if (rep & ele) {
	```
	Checks if the i-th bit of the element 'ele' is set using a bitwise AND operation.

8. **Increment Counter**
	```cpp
	                cnt++;
	```
	Increments the counter 'cnt' if the i-th bit of 'ele' is set.

9. **Conditional Check**
	```cpp
	        if (cnt >= k) {
	```
	Checks if the count of set bits at the current bit position is greater than or equal to 'k'.

10. **Bitwise OR**
	```cpp
	            ans = ans | rep;
	```
	Performs a bitwise OR operation to set the corresponding bit in 'ans'.

11. **Return Statement**
	```cpp
	    return ans; // Return the final answer, which is the result of the OR operation on selected bits.
	```
	Returns the final result of the OR operation on selected bits.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * 31), where n is the number of elements in `nums`.
- **Average Case:** O(n * 31)
- **Worst Case:** O(n * 31)

We iterate over each bit position (31 positions) for each element in the array.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1), since the space used is constant.

We only use a few variables to track the result and bit counts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-k-or-of-an-array/description/)

---
{{< youtube jNPKX6McyCg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
