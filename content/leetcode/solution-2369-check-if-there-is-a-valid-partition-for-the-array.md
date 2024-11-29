
+++
authors = ["grid47"]
title = "Leetcode 2369: Check if There is a Valid Partition For The Array"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2369: Check if There is a Valid Partition For The Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "HywUcx60BRo"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/HywUcx60BRo/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array, and you need to partition it into one or more contiguous subarrays. A partition is valid if each subarray meets one of the following conditions: 
1. The subarray contains exactly 2 equal elements. 
2. The subarray contains exactly 3 equal elements. 
3. The subarray contains exactly 3 consecutive increasing elements, where the difference between adjacent elements is 1. 
Return true if there is at least one valid partition in the array, otherwise return false.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array, where each element represents an integer in the array.
- **Example:** `nums = [3, 3, 4, 5, 6]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a boolean value: true if at least one valid partition exists, otherwise return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if there is any valid partition in the array that meets the conditions provided.

- 1. Implement a dynamic programming solution to check if each possible partition is valid.
- 2. For each position in the array, check the potential subarrays of length 2 or 3 and validate them according to the given conditions.
- 3. Use memoization to store intermediate results to optimize the solution and avoid redundant computations.
{{< dots >}}
### Problem Assumptions ✅
- The array is non-empty and has at least two elements.
- There are no additional constraints such as the elements being sorted or having specific values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 3, 4, 5, 6]`  \
  **Explanation:** In this example, the array can be partitioned into two subarrays: [3, 3] and [4, 5, 6]. Both subarrays satisfy the conditions, so the output is true.

- **Input:** `Input: nums = [1, 1, 1, 2]`  \
  **Explanation:** In this example, no valid partition exists, as no subarray meets the conditions, so the output is false.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming to check for valid subarrays and memoization to optimize the solution.

### Initial Thoughts 💭
- We need to consider each subarray of length 2 and 3.
- The problem can be optimized using dynamic programming to store intermediate results.
- A dynamic programming approach will be efficient for this problem as it reduces the number of repetitive checks for each partition.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the length of nums is guaranteed to be at least 2.
- For large inputs, ensure that the memoization technique works efficiently to avoid timeouts.
- Special cases could include arrays with repeating elements or consecutive elements that form valid partitions.
- Make sure that the input constraints are adhered to, especially for large arrays.
{{< dots >}}
## Code 💻
```cpp
int n;
vector<int> nums, memo;

bool dp(int idx) {
    if(idx == n) return true;
    
    if(memo[idx] != -1) return memo[idx];
    
    if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
        if(dp(idx + 2)) return memo[idx] = true;
    }
    
    if(idx + 2 < n) {
        if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
            if(dp(idx + 3)) return memo[idx] = true;                
        }
        if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
            if(dp(idx + 3)) return memo[idx] =true;
        }
    }

    return memo[idx] = false;
    
}

bool validPartition(vector<int>& nums) {
    this->nums = nums;
    n = nums.size();
    memo.resize(n, -1);
    return dp(0);
}
```

The complete solution checks if the given array can be partitioned into valid groups using dynamic programming.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int n;
	```
	This initializes the integer variable 'n' that will store the size of the input array 'nums'.

2. **Variable Initialization**
	```cpp
	vector<int> nums, memo;
	```
	The 'nums' vector stores the input array, while 'memo' is used to store computed results for subproblems in dynamic programming.

3. **Function Definition**
	```cpp
	bool dp(int idx) {
	```
	Defines a recursive function 'dp' that checks if a valid partition is possible starting from index 'idx'.

4. **Base Case**
	```cpp
	    if(idx == n) return true;
	```
	Base case: If the index equals the size of the array, it means the entire array has been processed and is valid.

5. **Memoization**
	```cpp
	    if(memo[idx] != -1) return memo[idx];
	```
	Check if the result for the current index 'idx' has already been computed. If so, return the stored value.

6. **Recursive Case - Pair**
	```cpp
	    if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
	```
	Checks if the current and next elements are equal, indicating a valid pair. If so, it recursively checks from the next pair.

7. **Recursive Case - Pair**
	```cpp
	        if(dp(idx + 2)) return memo[idx] = true;
	```
	If the pair is valid, the function recursively checks from the index two positions ahead.

8. **Recursive Case - Triplet**
	```cpp
	    if(idx + 2 < n) {
	```
	Checks if a triplet is possible starting at the current index.

9. **Recursive Case - Triplet**
	```cpp
	        if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
	```
	Checks if the current and the next two elements form a valid triplet (all elements equal).

10. **Recursive Case - Triplet**
	```cpp
	            if(dp(idx + 3)) return memo[idx] = true;
	```
	If the triplet is valid, the function recursively checks from the index three positions ahead.

11. **Recursive Case - Incrementing Triplet**
	```cpp
	        if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
	```
	Checks if the next two elements form a sequence incrementing by 1 (e.g., [x, x+1, x+2]).

12. **Recursive Case - Incrementing Triplet**
	```cpp
	            if(dp(idx + 3)) return memo[idx] = true;
	```
	If the sequence is valid, the function recursively checks from the index three positions ahead.

13. **Base Case - Failure**
	```cpp
	    return memo[idx] = false;
	```
	If no valid partitioning is found, return false and store the result in 'memo'.

14. **Function Definition**
	```cpp
	}
	```
	End of the 'dp' function definition.

15. **Function Definition**
	```cpp
	bool validPartition(vector<int>& nums) {
	```
	Defines the main function 'validPartition' which initializes variables and calls the 'dp' function.

16. **Function Logic**
	```cpp
	    this->nums = nums;
	```
	Assigns the input vector 'nums' to the class member 'nums'.

17. **Function Logic**
	```cpp
	    n = nums.size();
	```
	Sets the value of 'n' to the size of the input array 'nums'.

18. **Function Logic**
	```cpp
	    memo.resize(n, -1);
	```
	Resizes the memoization vector 'memo' to the size of the array 'nums', initializing all values to -1.

19. **Function Logic**
	```cpp
	    return dp(0);
	```
	Calls the 'dp' function starting from index 0 and returns the result.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array, due to the linear traversal with memoization.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the memoization table used to store intermediate results.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

---
{{< youtube HywUcx60BRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
