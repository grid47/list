
+++
authors = ["grid47"]
title = "Leetcode 2602: Minimum Operations to Make All Array Elements Equal"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2602: Minimum Operations to Make All Array Elements Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "UGx5NwAqXZk"
youtube_upload_date="2023-03-26"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UGx5NwAqXZk/maxresdefault.webp"
comments = true
+++



---
You are given an array nums consisting of positive integers. You are also given an array queries, and for each query, you need to determine the minimum number of operations required to make all elements of nums equal to the query value. The allowed operation is to either increase or decrease an element by 1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums and an integer array queries. The nums array represents the initial state of the numbers, and the queries array contains the target values to which the elements of nums should be transformed.
- **Example:** `nums = [3,1,6,8], queries = [1,5]`
- **Constraints:**
	- 1 <= nums.length, queries.length <= 100000
	- 1 <= nums[i], queries[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of size m, where each element of the output corresponds to the minimum number of operations needed to transform all elements of nums to the corresponding query value.
- **Example:** `[14, 10]`
- **Constraints:**
	- Output array size will be the same as the queries array size.

{{< dots >}}
### Core Logic 🔍
**Goal:** To calculate the minimum operations required to make all elements of nums equal to the target value from the queries array.

- Sort the nums array to ensure efficient calculation of the operations needed for each query.
- For each query value, calculate how many operations are needed to change each element of nums to the query value by iterating through the sorted nums array.
- Use prefix sum arrays to efficiently compute the total number of operations for each query.
{{< dots >}}
### Problem Assumptions ✅
- The array nums may be unsorted, and queries may contain any target values within the specified constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3,1,6,8], queries = [1,5]`  \
  **Explanation:** For the query 1, we need to make the array [3, 1, 6, 8] equal to [1, 1, 1, 1] using the minimum number of operations. For each element of nums, we compute the number of operations required to make it 1 and sum them up. The result is 14.

{{< dots >}}
## Approach 🚀
Sort the nums array and use prefix sums to optimize the computation of the operations for each query value.

### Initial Thoughts 💭
- We need to minimize the total operations for each query value by making efficient calculations for each target.
- Using sorted nums array and prefix sums will reduce the computational complexity when processing each query.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where nums or queries arrays are empty.
- Ensure that the algorithm efficiently handles large inputs where n and m are close to 10^5.
- Check for cases where all elements in nums are already equal to the query value.
- Ensure the algorithm handles values of nums[i] and queries[i] up to 10^9 efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<long long> ans(q.size(), 0);
    vector<long long> pre(n, 0);
    pre[0] = nums[0];
    for(int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + nums[i];
    
    for(int i = 0; i < q.size(); i++) {
        auto it = lower_bound(nums.begin(), nums.end(), q[i]);
        if(it == nums.end()) {
            ans[i] = (long long)q[i] * n - pre[n - 1];
        } else {
            int idx = it - nums.begin();
            long long right = pre[n - 1] - ((idx > 0)?pre[idx - 1]: 0);
            long long left  = idx > 0? pre[idx - 1] : 0;
            ans[i] = (long long)q[i] * idx - (long long)left + (long long)right - (long long)q[i] * ((long long)n - idx);
        }
    }
    return ans;
}
```

This function calculates the minimum operations needed based on given queries and the list of numbers. It calculates prefix sums and uses binary search to handle each query efficiently.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
	```
	This line declares the `minOperations` function which takes two vectors of integers: `nums` (the list of numbers) and `q` (the queries to be processed).

2. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the `nums` vector to facilitate efficient processing of queries using binary search.

3. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Store the size of the `nums` vector in variable `n`.

4. **Result Vector Initialization**
	```cpp
	    vector<long long> ans(q.size(), 0);
	```
	Initialize a vector `ans` of size equal to the number of queries (`q`), all elements set to 0.

5. **Prefix Sum Initialization**
	```cpp
	    vector<long long> pre(n, 0);
	```
	Initialize a prefix sum vector `pre` of size `n` (size of `nums`), with all elements set to 0.

6. **First Prefix Sum Calculation**
	```cpp
	    pre[0] = nums[0];
	```
	Set the first element of the prefix sum array `pre` to the first element of `nums`.

7. **Prefix Sum Iteration**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	Loop through the remaining elements of `nums` to compute the cumulative sum in the `pre` array.

8. **Prefix Sum Calculation**
	```cpp
	        pre[i] = pre[i - 1] + nums[i];
	```
	For each element `i`, add the current element of `nums` to the previous prefix sum and store it in `pre[i]`.

9. **Query Processing Loop**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Start a loop to process each query in `q`.

10. **Binary Search for Lower Bound**
	```cpp
	        auto it = lower_bound(nums.begin(), nums.end(), q[i]);
	```
	Use `lower_bound` to find the first position in `nums` where the value is greater than or equal to the query value `q[i]`.

11. **End Condition Check**
	```cpp
	        if(it == nums.end()) {
	```
	Check if the iterator `it` has reached the end of the vector, meaning no element in `nums` is greater than or equal to `q[i]`.

12. **No Valid Element Found**
	```cpp
	            ans[i] = (long long)q[i] * n - pre[n - 1];
	```
	If no valid element is found, calculate the result for this query based on the entire sum of the `nums` vector and store it in `ans[i]`.

13. **Element Found**
	```cpp
	        } else {
	```
	If a valid element is found, process it further.

14. **Index Calculation**
	```cpp
	            int idx = it - nums.begin();
	```
	Calculate the index `idx` of the element found by `lower_bound`.

15. **Right Side Calculation**
	```cpp
	            long long right = pre[n - 1] - ((idx > 0)?pre[idx - 1]: 0);
	```
	Calculate the sum of the elements to the right of `idx` using the prefix sum array `pre`.

16. **Left Side Calculation**
	```cpp
	            long long left  = idx > 0? pre[idx - 1] : 0;
	```
	Calculate the sum of the elements to the left of `idx` using the prefix sum array `pre`.

17. **Final Answer Calculation**
	```cpp
	            ans[i] = (long long)q[i] * idx - (long long)left + (long long)right - (long long)q[i] * ((long long)n - idx);
	```
	Calculate the final answer for this query based on the left and right sums and store it in `ans[i]`.

18. **Return Result**
	```cpp
	    return ans;
	```
	Return the result vector `ans`, which contains the answers for all queries.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n + m log n)
- **Average Case:** O(n log n + m log n)
- **Worst Case:** O(n log n + m log n)

Sorting nums takes O(n log n) time, and processing each query requires O(log n) due to binary search on the sorted nums array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We store the prefix sums and the sorted nums array, requiring O(n) space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/)

---
{{< youtube UGx5NwAqXZk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
