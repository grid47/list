
+++
authors = ["grid47"]
title = "Leetcode 2389: Longest Subsequence With Limited Sum"
date = "2024-03-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2389: Longest Subsequence With Limited Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Lb4Dp6gwh6g"
youtube_upload_date="2022-08-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Lb4Dp6gwh6g/maxresdefault.webp"
comments = true
+++



---
You are given an integer array `nums` of length `n` and an integer array `queries` of length `m`. For each query, return the maximum size of a subsequence that can be selected from `nums` such that the sum of its elements is less than or equal to the query value. A subsequence is derived by deleting some or no elements from the array while keeping the relative order intact.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer array `queries`.
- **Example:** `Input: nums = [1,3,5,7], queries = [6,12,18]`
- **Constraints:**
	- n == nums.length
	- m == queries.length
	- 1 <= n, m <= 1000
	- 1 <= nums[i], queries[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the maximum size of the subsequence such that its sum is less than or equal to the query value.
- **Example:** `Output: [2, 3, 4]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum size of the subsequence for each query where the sum does not exceed the query value.

- 1. Sort the array `nums` to easily select the smallest elements first.
- 2. Compute the prefix sum of the sorted array to get the cumulative sum of elements.
- 3. For each query, use binary search to find the maximum number of elements whose sum is less than or equal to the query value.
{{< dots >}}
### Problem Assumptions ✅
- Queries are independent and each query needs to be answered individually.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 5, 7], queries = [6, 12, 18]`  \
  **Explanation:** For the query 6, the subsequence [1, 3] has a sum of 4, which is the largest subsequence with a sum <= 6, hence the answer is 2. For the query 12, the subsequence [1, 3, 5] has a sum of 9, and for 18, the subsequence [1, 3, 5, 7] has a sum of 16, so the answers are [2, 3, 4].

- **Input:** `Input: nums = [2, 4, 6, 8], queries = [5]`  \
  **Explanation:** For the query 5, the largest subsequence with a sum <= 5 is [2], so the answer is 1.

{{< dots >}}
## Approach 🚀
The approach involves sorting the array `nums`, calculating the prefix sums, and using binary search to efficiently answer each query.

### Initial Thoughts 💭
- We need to find the maximum subsequence for each query where the sum is within a given limit.
- Sorting `nums` allows us to efficiently calculate the largest subsequence by accumulating smaller numbers first.
- Prefix sums can help to efficiently check the sum of any subsequence. Binary search will help find the largest valid subsequence for each query.
{{< dots >}}
### Edge Cases 🌐
- If `nums` is empty, the answer for each query is 0.
- Ensure the solution is efficient enough to handle the maximum input size of 1000 elements in `nums`.
- Handle cases where the elements of `nums` are very large or queries are much smaller than the elements.
- The binary search must work within O(log n) for each query to ensure overall efficiency.
{{< dots >}}
## Code 💻
```cpp
vector<int> answerQueries(vector<int> A, vector<int>& queries) {
    sort(A.begin(), A.end());
    vector<int> res;
    for (int i = 1; i < A.size(); ++i)
        A[i] += A[i - 1];
    for (int& q: queries)
        res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
    return res;
}
```

This function answers a series of queries based on a sorted prefix sum of an array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> answerQueries(vector<int> A, vector<int>& queries) {
	```
	Function declaration where the input is an array `A` and a reference to an array `queries`, and the return type is a vector of integers.

2. **Sort Array**
	```cpp
	    sort(A.begin(), A.end());
	```
	Sort the input array `A` in ascending order to prepare for efficient prefix sum calculation.

3. **Variable Declaration**
	```cpp
	    vector<int> res;
	```
	Declare a result vector `res` that will store the answers to the queries.

4. **Prefix Sum Calculation**
	```cpp
	    for (int i = 1; i < A.size(); ++i)
	```
	Start a loop from index 1 to calculate the prefix sum by adding each element to its previous one.

5. **Prefix Sum Update**
	```cpp
	        A[i] += A[i - 1];
	```
	Update the current element by adding the value of the previous element, thereby creating a running total.

6. **Query Processing**
	```cpp
	    for (int& q: queries)
	```
	Iterate over each query in the `queries` array.

7. **Binary Search**
	```cpp
	        res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin());
	```
	Use the `upper_bound` function to find the index of the first element greater than the current query value `q` and push it to the result vector.

8. **Return Result**
	```cpp
	    return res;
	```
	Return the result vector containing the answers to all the queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) for sorting and O(m log n) for answering queries.
- **Average Case:** O(n log n) for sorting and O(m log n) for answering queries.
- **Worst Case:** O(n log n) for sorting and O(m log n) for answering queries.

Sorting the array `nums` takes O(n log n) time, and each query can be answered in O(log n) using binary search.

### Space Complexity 💾
- **Best Case:** O(n) for storing the prefix sums and the result array.
- **Worst Case:** O(n) for storing the prefix sums and the result array.

The space complexity is O(n) due to the storage required for the prefix sum and result arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/)

---
{{< youtube Lb4Dp6gwh6g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
