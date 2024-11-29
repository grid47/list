
+++
authors = ["grid47"]
title = "Leetcode 985: Sum of Even Numbers After Queries"
date = "2024-07-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 985: Sum of Even Numbers After Queries in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Simulation"]
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
Given an integer array nums and an array of queries, each of which is in the form [value, index], you need to apply each query by adding value to nums[index] and return the sum of even numbers in the updated nums array after each query.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array nums of integers and an array of queries, where each query consists of a value to be added to nums at a specific index.
- **Example:** `nums = [5, 7, 9, 10], queries = [[2, 0], [-5, 1], [4, 0], [6, 3]]`
- **Constraints:**
	- 1 <= nums.length <= 10^4
	- -10^4 <= nums[i] <= 10^4
	- 1 <= queries.length <= 10^4
	- -10^4 <= value <= 10^4
	- 0 <= index < nums.length

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query, return the sum of even numbers in nums after the query has been applied.
- **Example:** `Output: [12, 7, 12, 14]`
- **Constraints:**
	- The output should be an array of integers representing the sum of even numbers after each query.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to modify the nums array with each query and compute the sum of even values in the updated array.

- Initialize a sum variable to hold the sum of even numbers in nums.
- Iterate over each query and modify the appropriate value in nums.
- After modifying nums, update the sum of even numbers based on the updated value.
{{< dots >}}
### Problem Assumptions ✅
- Each query modifies nums at a specific index, and the sum of even values is updated immediately after each modification.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [5, 7, 9, 10], queries = [[2, 0], [-5, 1], [4, 0], [6, 3]]`  \
  **Explanation:** In this example, we modify nums in place for each query and compute the sum of even values after each query.

{{< dots >}}
## Approach 🚀
We can keep track of the sum of even values in nums and update it after each query, adjusting for the even/odd status of the modified value.

### Initial Thoughts 💭
- We need to efficiently update the sum of even values after each query without recalculating from scratch.
- By adjusting the sum based on whether the modified value is even or odd, we can avoid unnecessary recalculations.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where nums has only one element.
- Consider large arrays and large values for nums and queries.
- Handle cases where the modified number becomes even or odd due to the addition.
- Ensure the solution is efficient enough to handle the maximum constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& qs) {
    vector<int> res = {};
    int sum = accumulate(begin(A), end(A), 0, [](int s, int a) {
        return s + (a % 2 == 0? a : 0);
    });
    for(auto &q: qs) {
        if(A[q[1]] %2 == 0) sum-=A[q[1]];
        A[q[1]] += q[0];
        if(A[q[1]]%2 == 0) sum+=A[q[1]];
        res.push_back(sum);
    }
    return res;
}
```

This function `sumEvenAfterQueries` takes an array `A` and a list of queries `qs`. It modifies the array based on the queries and computes the sum of even elements after each update. The result is stored in `res` and returned.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& qs) {
	```
	Defines the function `sumEvenAfterQueries`, which takes an array `A` and a list of queries `qs`, returning a vector of integers with the sum of even elements after each query.

2. **Initialize Result Vector**
	```cpp
	    vector<int> res = {};
	```
	Initializes an empty vector `res` that will store the results after each query, representing the sum of even elements in the array.

3. **Initialize Sum of Even Elements**
	```cpp
	    int sum = accumulate(begin(A), end(A), 0, [](int s, int a) {
	```
	Calculates the initial sum of all even elements in the array `A` using the `accumulate` function and a lambda to check if an element is even.

4. **Lambda for Even Sum**
	```cpp
	        return s + (a % 2 == 0? a : 0);
	```
	This lambda function adds the element `a` to the sum `s` if `a` is even (`a % 2 == 0`), otherwise it adds 0.

5. **Iterate Over Queries**
	```cpp
	    for(auto &q: qs) {
	```
	Begins a loop to iterate over the list of queries `qs`. Each query contains an update to the array `A`.

6. **Remove Even Value from Sum**
	```cpp
	        if(A[q[1]] %2 == 0) sum-=A[q[1]];
	```
	If the element at the index specified by `q[1]` is even, it is subtracted from the sum of even numbers before applying the query.

7. **Apply Query**
	```cpp
	        A[q[1]] += q[0];
	```
	Updates the element in the array `A` at the index `q[1]` by adding the value `q[0]` from the current query.

8. **Add Even Value to Sum**
	```cpp
	        if(A[q[1]]%2 == 0) sum+=A[q[1]];
	```
	After updating the element, if the element at index `q[1]` is even, it is added back to the sum of even numbers.

9. **Store the Sum After Query**
	```cpp
	        res.push_back(sum);
	```
	After processing the query, the current sum of even numbers is added to the result vector `res`.

10. **Return Result**
	```cpp
	    return res;
	```
	Returns the result vector `res`, which contains the sum of even elements after each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for each query if the update does not affect the even/odd status.
- **Average Case:** O(1) for each query as we only adjust the sum.
- **Worst Case:** O(n) if we recalculate the sum of even numbers after each query (though this is avoidable).

Each query is processed in constant time if we manage the sum of even numbers efficiently.

### Space Complexity 💾
- **Best Case:** O(n) for storing the nums array.
- **Worst Case:** O(n) for storing the nums array.

The space complexity is O(n) where n is the size of the nums array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
