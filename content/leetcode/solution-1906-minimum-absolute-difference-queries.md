
+++
authors = ["grid47"]
title = "Leetcode 1906: Minimum Absolute Difference Queries"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1906: Minimum Absolute Difference Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "H_Nrt9dOwLM"
youtube_upload_date="2021-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/H_Nrt9dOwLM/maxresdefault.jpg"
comments = true
+++



---
Given an array of integers `nums` and a list of queries, where each query is defined as a subarray `nums[li...ri]`, compute the minimum absolute difference between any two distinct elements in that subarray. If all elements in the subarray are the same, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array `nums` of integers and an array of queries where each query is represented as a pair of integers `[li, ri]`.
- **Example:** `nums = [1, 3, 4, 8], queries = [[0,1], [1,2], [2,3], [0,3]]`
- **Constraints:**
	- 2 <= nums.length <= 10^5
	- 1 <= nums[i] <= 100
	- 1 <= queries.length <= 2 * 10^4
	- 0 <= li < ri < nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element corresponds to the minimum absolute difference for the respective query.
- **Example:** `[2, 1, 4, 1]`
- **Constraints:**
	- Each element of the output should be the minimum absolute difference for the respective subarray from the queries list.

{{< dots >}}
### Core Logic 🔍
**Goal:** For each query, extract the subarray and compute the minimum absolute difference by comparing all unique pairs of elements.

- For each query, slice the array from index li to ri.
- Find the minimum absolute difference between distinct elements in that subarray.
- If all elements are the same, return -1.
{{< dots >}}
### Problem Assumptions ✅
- All numbers in `nums` are positive integers.
- The query indices are valid within the bounds of the array.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 4, 8], queries = [[0,1], [1,2], [2,3], [0,3]]`  \
  **Explanation:** The subarrays for each query are processed to calculate the minimum absolute difference for distinct elements.

{{< dots >}}
## Approach 🚀
We can efficiently calculate the minimum absolute difference for each query by leveraging the frequency of each element within the subarrays.

### Initial Thoughts 💭
- Iterating through each query and calculating the minimum difference might take time for large arrays.
- We need a strategy to process the queries efficiently.
- Precomputing frequency counts of numbers within subarrays can help optimize the solution.
{{< dots >}}
### Edge Cases 🌐
- Queries with no valid subarrays or an empty array.
- Handling cases with the maximum array size and query count.
- When all elements in a subarray are the same, the answer should be -1.
- Ensure the solution runs efficiently with the upper limits of constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {

    int prefix[100001][101] = {}, cnt[101] = {};
    
    int n = nums.size(), m = q.size();
    
    for(int i = 0; i < n; i++) {
        cnt[nums[i]]++;
        for(int j = 1; j < 101; j++) prefix[i + 1][j] = cnt[j];
    }
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        int l = q[i][0], r = q[i][1];
        int frq[101] = {};
        for(int j = 1; j < 101; j++) frq[j] = prefix[r + 1][j] - prefix[l][j];
        int prv = -1, mn = INT_MAX;
        for(int j = 1; j < 101; j++) {
            if(frq[j] == 0) continue;
            if(prv != -1 && j - prv < mn) mn = j - prv;
            prv = j;
        }
        ans.push_back(mn == INT_MAX? -1: mn);
    }
    
    return ans;
}
```

This function calculates the minimum difference between any two elements in different ranges defined by the query array 'q'. It uses a prefix sum approach to store frequency of numbers and finds the smallest difference between consecutive non-zero frequencies for each query.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {
	```
	Declares the function 'minDifference', which takes a vector of integers 'nums' and a 2D vector 'q' representing multiple queries.

2. **Prefix Array Initialization**
	```cpp
	    int prefix[100001][101] = {}, cnt[101] = {};
	```
	Initializes a 2D prefix sum array 'prefix' to store frequencies up to index 'i', and an array 'cnt' to count occurrences of each number.

3. **Size Determination**
	```cpp
	    int n = nums.size(), m = q.size();
	```
	Stores the sizes of the 'nums' and 'q' arrays, where 'n' is the length of 'nums' and 'm' is the number of queries.

4. **Prefix Calculation**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterates through the 'nums' array to calculate the frequency of each number.

5. **Count Update**
	```cpp
	        cnt[nums[i]]++;
	```
	Increments the count of the number at index 'i' in the 'nums' array.

6. **Prefix Update**
	```cpp
	        for(int j = 1; j < 101; j++) prefix[i + 1][j] = cnt[j];
	```
	Updates the 'prefix' array to store the cumulative frequency counts for each number up to index 'i'.

7. **Query Processing**
	```cpp
	    vector<int> ans;
	```
	Initializes a vector 'ans' to store the results for each query.

8. **Query Iteration**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Iterates through each query in the 2D array 'q'.

9. **Range Initialization**
	```cpp
	        int l = q[i][0], r = q[i][1];
	```
	Extracts the left and right range indices for the current query.

10. **Frequency Calculation**
	```cpp
	        int frq[101] = {};
	```
	Initializes an array 'frq' to store the frequency of each number within the current query range.

11. **Frequency Update**
	```cpp
	        for(int j = 1; j < 101; j++) frq[j] = prefix[r + 1][j] - prefix[l][j];
	```
	Calculates the frequency of each number in the range [l, r] by using the 'prefix' sum array.

12. **Variable Initialization**
	```cpp
	        int prv = -1, mn = INT_MAX;
	```
	Initializes variables 'prv' to track the previous number and 'mn' to store the minimum difference between two numbers.

13. **Finding Minimum Difference**
	```cpp
	        for(int j = 1; j < 101; j++) {
	```
	Iterates through the frequency array 'frq' to find the minimum difference between non-zero frequencies.

14. **Skip Zero Frequencies**
	```cpp
	            if(frq[j] == 0) continue;
	```
	Skips the number if its frequency is zero.

15. **Minimum Difference Update**
	```cpp
	            if(prv != -1 && j - prv < mn) mn = j - prv;
	```
	Updates the minimum difference 'mn' if the difference between 'j' and 'prv' is smaller than the current 'mn'.

16. **Update Previous Value**
	```cpp
	            prv = j;
	```
	Updates the previous number to the current number 'j'.

17. **Result Handling**
	```cpp
	        ans.push_back(mn == INT_MAX? -1: mn);
	```
	Pushes the result of the current query into the 'ans' vector. If no valid difference is found, it pushes -1.

18. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the vector 'ans' containing the results for all queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when there is only one query and the subarray has all identical elements.
- **Average Case:** O(n + m), where n is the length of the array and m is the number of queries.
- **Worst Case:** O(n * m), considering the worst-case scenario for large input sizes.

The solution processes each query independently after preprocessing the frequency data.

### Space Complexity 💾
- **Best Case:** O(1) when queries and subarrays are minimal.
- **Worst Case:** O(n + 100) for the prefix frequency array and the result storage.

The space complexity is primarily driven by the frequency array used for storing the counts of the elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-absolute-difference-queries/description/)

---
{{< youtube H_Nrt9dOwLM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
