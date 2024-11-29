
+++
authors = ["grid47"]
title = "Leetcode 1630: Arithmetic Subarrays"
date = "2024-05-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1630: Arithmetic Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "EIBRvGNsG64"
youtube_upload_date="2020-10-25"
youtube_thumbnail="https://i.ytimg.com/vi/EIBRvGNsG64/maxresdefault.jpg"
comments = true
+++



---
A sequence of numbers is called arithmetic if it consists of at least two elements, and the difference between every two consecutive elements is the same. Given an array of integers `nums` and two arrays `l` and `r` representing `m` range queries, determine whether the subarray `nums[l[i], ..., r[i]]` can be rearranged to form an arithmetic sequence.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers `nums`, and two arrays `l` and `r` representing `m` range queries. Each query defines a range in `nums` as `[l[i], r[i]]`.
- **Example:** `nums = [1, 2, 5, 3, 7], l = [0, 1, 2], r = [2, 3, 4]`
- **Constraints:**
	- n == nums.length
	- m == l.length
	- m == r.length
	- 2 <= n <= 500
	- 1 <= m <= 500
	- 0 <= l[i] < r[i] < n
	- -10^5 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of booleans, where each boolean represents whether the corresponding subarray can be rearranged into an arithmetic sequence.
- **Example:** `[true, false, true]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** For each range in the queries, check if the subarray can be rearranged to form an arithmetic sequence.

- For each query, extract the subarray defined by l[i] and r[i].
- Sort the subarray.
- Check if the difference between each consecutive element is constant.
- If it is constant, the subarray can be rearranged to form an arithmetic sequence; otherwise, it cannot.
{{< dots >}}
### Problem Assumptions ✅
- All input arrays are non-empty.
- The length of `l` and `r` arrays is equal to `m`.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [1, 2, 5, 3, 7], l = [0, 1, 2], r = [2, 3, 4]`  \
  **Explanation:** The first query extracts the subarray [1, 2, 5], which can be rearranged as [1, 2, 5], forming an arithmetic sequence.

{{< dots >}}
## Approach 🚀
To check if a subarray can be rearranged into an arithmetic sequence, sort the subarray and check the differences between consecutive elements.

### Initial Thoughts 💭
- We can sort the subarray to make checking for differences easier.
- If all differences between consecutive elements are the same, the sequence is arithmetic.
- Sorting the subarray and checking the differences allows us to validate if a rearranged sequence is arithmetic.
{{< dots >}}
### Edge Cases 🌐
- Check for cases where the subarray contains only one element.
- Ensure the algorithm handles large arrays efficiently.
- Consider cases where elements are negative or the range is small.
- Ensure that input constraints are met and the algorithm can process the largest inputs.
{{< dots >}}
## Code 💻
```cpp
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> res;
    for (auto i = 0, j = 0; i < l.size(); ++i) {
        vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
        sort(begin(n), end(n));
        for (j = 2; j < n.size(); ++j)
            if (n[j] - n[j - 1] != n[1] - n[0])
                break;
        res.push_back(j == n.size());
    }
    return res;
}
```

This function checks whether the subarrays defined by the indices in vectors 'l' and 'r' are arithmetic subarrays. It sorts the subarrays and compares the differences between consecutive elements to determine if they form an arithmetic progression.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
	```
	Define the function 'checkArithmeticSubarrays' that takes three parameters: a vector of integers 'nums', and two vectors 'l' and 'r' which specify the start and end indices of subarrays to check.

2. **Variable Initialization**
	```cpp
	    vector<bool> res;
	```
	Initialize a vector 'res' to store the boolean results indicating whether each corresponding subarray is an arithmetic subarray.

3. **Loop Constructs**
	```cpp
	    for (auto i = 0, j = 0; i < l.size(); ++i) {
	```
	Start a loop to iterate over the indices in vector 'l' and process each subarray defined by 'l[i]' and 'r[i]'.

4. **Subarray Extraction**
	```cpp
	        vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
	```
	Extract the subarray from 'nums' starting at index 'l[i]' and ending at index 'r[i]' (inclusive) into the vector 'n'.

5. **Sorting**
	```cpp
	        sort(begin(n), end(n));
	```
	Sort the extracted subarray 'n' to ensure the elements are in ascending order, which is necessary for checking arithmetic progression.

6. **Loop Constructs**
	```cpp
	        for (j = 2; j < n.size(); ++j)
	```
	Start a loop to compare consecutive elements in the sorted subarray 'n', beginning at index 2 (the third element).

7. **Conditional Statements**
	```cpp
	            if (n[j] - n[j - 1] != n[1] - n[0])
	```
	Check if the difference between the current element and the previous element is not equal to the difference between the first two elements of the sorted subarray. If it is not, the subarray is not arithmetic.

8. **Loop Constructs**
	```cpp
	                break;
	```
	If the difference condition is violated, break out of the inner loop as the subarray is not arithmetic.

9. **Vector Operations**
	```cpp
	        res.push_back(j == n.size());
	```
	Push a boolean value into 'res' indicating whether the entire subarray 'n' satisfies the arithmetic progression condition (i.e., the loop completed without breaking).

10. **Return Statement**
	```cpp
	    return res;
	```
	Return the vector 'res' containing the results for each subarray: 'true' if the subarray is arithmetic, 'false' otherwise.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for each query, where n is the length of the subarray.
- **Average Case:** O(n log n) for each query.
- **Worst Case:** O(n log n) for each query.

The sorting operation dominates the time complexity, and it is done for each query.

### Space Complexity 💾
- **Best Case:** O(1) if no extra space is used.
- **Worst Case:** O(n) for storing the subarray in memory.

The space complexity is determined by the size of the subarray stored for sorting.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/arithmetic-subarrays/description/)

---
{{< youtube EIBRvGNsG64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
