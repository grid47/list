
+++
authors = ["grid47"]
title = "Leetcode 1027: Longest Arithmetic Subsequence"
date = "2024-07-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1027: Longest Arithmetic Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "-NIlLdVKBFs"
youtube_upload_date="2020-10-10"
youtube_thumbnail="https://i.ytimg.com/vi/-NIlLdVKBFs/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers, you need to return the length of the longest subsequence where the difference between consecutive elements is constant. A subsequence is derived by deleting some elements without changing the order of the remaining elements. A sequence is considered arithmetic if the difference between consecutive elements remains the same.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single array of integers.
- **Example:** `nums = [5,10,15,20]`
- **Constraints:**
	- 2 <= nums.length <= 1000
	- 0 <= nums[i] <= 500

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is a single integer representing the length of the longest arithmetic subsequence in the given array.
- **Example:** `Output: 4`
- **Constraints:**
	- The arithmetic subsequence is derived by deleting some elements without changing the order.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the length of the longest subsequence with a constant difference between consecutive elements. This can be done using dynamic programming.

- 1. Use dynamic programming with a hash map to track the longest arithmetic subsequences for each difference between pairs of elements.
- 2. Iterate through each pair of elements in the array and compute the difference.
- 3. Update the hash map with the longest subsequence length for the calculated difference.
- 4. Keep track of the longest subsequence found during the iteration.
{{< dots >}}
### Problem Assumptions ✅
- The input array has at least 2 elements.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [5,10,15,20]`  \
  **Explanation:** In this example, the difference between each consecutive pair of elements is 5. The entire array forms an arithmetic subsequence with length 4.

- **Input:** `Input: nums = [10, 5, 15, 25, 30]`  \
  **Explanation:** Here, the longest arithmetic subsequence is [5, 15, 25] with a difference of 10, so the output is 3.

{{< dots >}}
## Approach 🚀
We can solve this problem using dynamic programming (DP) where we maintain a hash map for each element to store the length of the longest subsequence for each difference encountered.

### Initial Thoughts 💭
- The problem involves finding subsequences, which suggests a dynamic programming approach.
- The use of hash maps allows us to efficiently track the longest subsequences for each difference, reducing redundant calculations.
{{< dots >}}
### Edge Cases 🌐
- An array with fewer than 2 elements should not be given (based on the constraints).
- The solution must efficiently handle arrays with up to 1000 elements.
- If all elements are the same, the longest arithmetic subsequence is the entire array, since the difference is 0.
- The array will not contain values outside the range 0 to 500.
{{< dots >}}
## Code 💻
```cpp
int longestArithSeqLength(vector<int>& nums) {
    
    int n = nums.size();
    vector<unordered_map<int, int>> mp;
    mp.resize(n);
    int res = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int d = nums[j] - nums[i];
            if(mp[j].count(d)) mp[i][d] = max(mp[i][d], mp[j][d] + 1);
            else mp[i][d] = max(mp[i][d], 2);
            res = max(mp[i][d], res);
        }
    }
    return res;
}
```

This function computes the length of the longest arithmetic subsequence in the array using dynamic programming with a difference-based map for efficient tracking.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int longestArithSeqLength(vector<int>& nums) {
	```
	Define the function `longestArithSeqLength` which calculates the length of the longest arithmetic subsequence in the given array.

2. **Initialize Size**
	```cpp
	    int n = nums.size();
	```
	Store the size of the input array `nums` into the variable `n`.

3. **Data Structure Initialization**
	```cpp
	    vector<unordered_map<int, int>> mp;
	```
	Declare a vector of unordered maps to store the difference and its count for each element in the array.

4. **Resize Vector**
	```cpp
	    mp.resize(n);
	```
	Resize the vector of unordered maps to the size of the input array.

5. **Initialize Result**
	```cpp
	    int res = 1;
	```
	Initialize the result variable `res` to 1, as the minimum possible arithmetic subsequence length is 1.

6. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over the array elements with index `i` as the end of a potential arithmetic subsequence.

7. **Inner Loop**
	```cpp
	        for(int j = 0; j < i; j++) {
	```
	Iterate over previous elements with index `j` to calculate the difference `d` between elements at indices `j` and `i`.

8. **Calculate Difference**
	```cpp
	            int d = nums[j] - nums[i];
	```
	Calculate the difference `d` between elements at indices `j` and `i`.

9. **Update Map**
	```cpp
	            if(mp[j].count(d)) mp[i][d] = max(mp[i][d], mp[j][d] + 1);
	```
	If the difference `d` exists in the map for index `j`, update the map for index `i` with the incremented count of the subsequence.

10. **Initialize Difference**
	```cpp
	            else mp[i][d] = max(mp[i][d], 2);
	```
	If the difference `d` does not exist in the map for index `j`, initialize it with a value of 2.

11. **Update Result**
	```cpp
	            res = max(mp[i][d], res);
	```
	Update the result `res` to the maximum length found so far.

12. **Return Result**
	```cpp
	    return res;
	```
	Return the length of the longest arithmetic subsequence.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

The time complexity is O(n^2) due to the nested loop over pairs of elements.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n^2)

The space complexity is O(n^2) due to the hash maps storing subsequences for each difference.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-arithmetic-subsequence/description/)

---
{{< youtube -NIlLdVKBFs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
