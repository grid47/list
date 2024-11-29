
+++
authors = ["grid47"]
title = "Leetcode 2770: Maximum Number of Jumps to Reach the Last Index"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2770: Maximum Number of Jumps to Reach the Last Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "_al08ON26RA"
youtube_upload_date="2023-07-09"
youtube_thumbnail="https://i.ytimg.com/vi/_al08ON26RA/maxresdefault.jpg"
comments = true
+++



---
Given an array nums of integers and a target value, find the maximum number of jumps needed to reach the last index. A jump from index i to index j is valid if j > i and the difference nums[j] - nums[i] lies within the range [-target, target]. If it is impossible to reach the last index, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array nums of size n and an integer target.
- **Example:** `Input: nums = [2, 5, 9, 6, 2, 3], target = 3`
- **Constraints:**
	- 2 <= nums.length == n <= 1000
	- -10^9 <= nums[i] <= 10^9
	- 0 <= target <= 2 * 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer representing the maximum number of jumps to reach the last index, or -1 if it is not possible.
- **Example:** `Output: 2 for nums = [2, 5, 9, 6, 2, 3], target = 3`
- **Constraints:**
	- Output should be -1 if no valid jumping sequence exists.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the maximum number of valid jumps to reach the last index of nums.

- Use dynamic programming to calculate the maximum jumps starting from index 0.
- For each index i, check all valid jumps to indices j > i where nums[j] - nums[i] lies within [-target, target].
- Memoize results to optimize repeated calculations.
{{< dots >}}
### Problem Assumptions ✅
- All input values are valid and within the given constraints.
- The nums array is not empty, and target is a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [2, 5, 9, 6, 2, 3], target = 3`  \
  **Explanation:** Jump from index 0 to index 2, then from index 2 to index 5. The total number of jumps is 2.

- **Input:** `Input: nums = [10, 15, 20, 25], target = 1`  \
  **Explanation:** It is impossible to reach the last index, so the output is -1.

{{< dots >}}
## Approach 🚀
The problem can be solved using dynamic programming with memoization to explore all valid jumping paths efficiently.

### Initial Thoughts 💭
- Each index can potentially jump to multiple future indices based on the target constraint.
- Dynamic programming is suitable to optimize repeated subproblems.
- Memoize the maximum jumps from each index to avoid redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- Not applicable, as nums always contains at least two elements.
- Test with nums of size 1000 and large target values to ensure efficiency.
- Test cases with nums having repeated values and small target values.
- Ensure correctness for edge cases like nums = [1, 2], target = 0.
{{< dots >}}
## Code 💻
```cpp

int target, n;
vector<int> memo, nums;

int dp(int idx) {
    
    if(idx == n - 1) return 0;
    
    if(memo[idx] != INT_MIN) return memo[idx];
    
    int ans = INT_MIN;
    for(int i = idx + 1; i < n; i++) {
        if(abs(nums[i] - nums[idx]) <= target) {
            ans = max(ans, dp(i) + 1);
        }
    }
    // cout << idx << " " << ans << "\n";
    return memo[idx] = ans;
}

int maximumJumps(vector<int>& nums, int target) {

    n = nums.size();
    this->target = target;
    this->nums = nums;
    memo.resize(n, INT_MIN);
    int ans = dp(0);
    return ans <= 0? -1: ans;

}
```

The code implements a dynamic programming solution to find the maximum number of valid jumps between elements in a list. The function `maximumJumps` returns the maximum number of valid jumps possible given a target difference. The helper function `dp` computes the number of jumps recursively with memoization.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int target, n;
	```
	Declare the integer variables `target` to store the target value and `n` to store the number of elements in `nums`.

2. **Variable Declaration**
	```cpp
	vector<int> memo, nums;
	```
	Declare a vector `nums` to store the input numbers and a vector `memo` to store intermediate results for memoization.

3. **Base Case**
	```cpp
	int dp(int idx) {
	```
	Define the function `dp` that takes an index `idx` and returns the maximum jumps possible from that index.

4. **Base Case Check**
	```cpp
	    if(idx == n - 1) return 0;
	```
	Check if we are at the last index; if so, return 0 because no further jumps are possible.

5. **Memoization Check**
	```cpp
	    if(memo[idx] != INT_MIN) return memo[idx];
	```
	Check if the result for the current index is already computed (i.e., not `INT_MIN`). If so, return the stored result from `memo`.

6. **Initialization**
	```cpp
	    int ans = INT_MIN;
	```
	Initialize the variable `ans` to `INT_MIN` to track the maximum number of jumps from the current index.

7. **Loop Through Elements**
	```cpp
	    for(int i = idx + 1; i < n; i++) {
	```
	Start a loop from the next index (`idx + 1`) to the end of the list to explore potential valid jumps.

8. **Condition Check**
	```cpp
	        if(abs(nums[i] - nums[idx]) <= target) {
	```
	Check if the absolute difference between the current element and the element at index `idx` is less than or equal to the target value.

9. **Recursive Call**
	```cpp
	            ans = max(ans, dp(i) + 1);
	```
	If the condition is satisfied, recursively call `dp(i)` to find the maximum jumps from index `i`, and add 1 for the current jump. Update `ans` with the maximum value.

10. **Memoization**
	```cpp
	    return memo[idx] = ans;
	```
	Store the computed value of `ans` in `memo[idx]` for future use and return the value.

11. **Initialization**
	```cpp
	int maximumJumps(vector<int>& nums, int target) {
	```
	Define the `maximumJumps` function and pass `nums` and `target` as parameters.

12. **Variable Assignment**
	```cpp
	    n = nums.size();
	```
	Assign the size of the `nums` vector to `n`.

13. **Variable Assignment**
	```cpp
	    this->target = target;
	```
	Assign the `target` parameter to the class-level `target` variable.

14. **Variable Assignment**
	```cpp
	    this->nums = nums;
	```
	Assign the input `nums` vector to the class-level `nums` vector.

15. **Initialization**
	```cpp
	    memo.resize(n, INT_MIN);
	```
	Resize the `memo` vector to the size of `n`, initializing all values to `INT_MIN` to indicate uncomputed values.

16. **Call DP Function**
	```cpp
	    int ans = dp(0);
	```
	Call the `dp` function starting from index 0 and store the result in `ans`.

17. **Return Statement**
	```cpp
	    return ans <= 0? -1: ans;
	```
	Return `-1` if `ans` is less than or equal to 0, indicating no valid jumps. Otherwise, return the computed number of jumps.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

For each index, up to n iterations are required to check all valid jumps.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

Space is used for memoization of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/)

---
{{< youtube _al08ON26RA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
