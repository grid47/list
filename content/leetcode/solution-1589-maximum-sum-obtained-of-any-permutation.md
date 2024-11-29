
+++
authors = ["grid47"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2024-06-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1589: Maximum Sum Obtained of Any Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TyZ_FFGIZgs"
youtube_upload_date="2020-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/TyZ_FFGIZgs/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers nums and a list of requests, where each request specifies a range in the array. The ith request asks for the sum of all elements from nums[starti] to nums[endi], inclusive. Your task is to determine the maximum total sum of all requests for any permutation of nums.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of integers nums, and a list of requests. Each request consists of two integers [starti, endi] representing a range in nums. The length of nums can be up to 10^5, and the number of requests can be as large as 10^5.
- **Example:** `Input: nums = [1, 3, 2, 4], requests = [[0, 1], [1, 3]]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5
	- 1 <= requests.length <= 10^5
	- 0 <= starti <= endi < n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible sum of all request sums for any permutation of the nums array, modulo 10^9 + 7.
- **Example:** `Output: 21`
- **Constraints:**
	- The output should be an integer representing the maximum possible total sum modulo 10^9 + 7.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum total sum of the request sums for any permutation of nums by efficiently calculating the contributions of each element to the total sum based on the request ranges.

- 1. Create an array of length n, where each element corresponds to the number of times it is included in a request range.
- 2. Sort the nums array in increasing order and the request contributions in decreasing order.
- 3. Multiply each element of nums with its corresponding contribution and sum the results.
{{< dots >}}
### Problem Assumptions ✅
- The requests are well-formed, with starti <= endi.
- All elements in nums are distinct and non-negative.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 3, 2, 4], requests = [[0, 1], [1, 3]]`  \
  **Explanation:** The permutation [4, 3, 2, 1] gives the maximum total sum for the requests. The first request sums nums[0] + nums[1] = 4 + 3 = 7 and the second request sums nums[1] + nums[2] + nums[3] = 3 + 2 + 1 = 6. The total sum is 7 + 6 = 13.

{{< dots >}}
## Approach 🚀
We can solve this problem by treating the requests as intervals that increase the frequency of certain elements in nums. The elements of nums that appear in many requests should be assigned larger values to maximize the total sum. By sorting both the nums array and the request contributions, we can efficiently compute the result.

### Initial Thoughts 💭
- We need to calculate how often each element of nums is included in the request ranges.
- Sorting both nums and the request contributions in a way that matches higher frequencies with higher values will give the maximum sum.
- The problem boils down to sorting the frequency of requests and the values in nums to pair them optimally.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where nums has only one element or there are no requests.
- Ensure the solution can handle the largest possible input sizes efficiently.
- Handle cases where all values in nums are zero, or where the ranges in requests are minimal (e.g., starti == endi).
- Ensure the solution works within the provided time and space constraints.
{{< dots >}}
## Code 💻
```cpp
int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
    int n = nums.size();
    long long res = 0;
    vector<long long> cnt(n, 0);
    for(auto& r: req) {
        cnt[r[0]]++;
        if(r[1] + 1 < n)
            cnt[r[1] +1]--;
}
    
    for(int i = 1; i < n; i++)
        cnt[i] += cnt[i -1];
    sort(nums.begin(), nums.end());
    sort(cnt.begin(), cnt.end());
    for(int i = 0; i < n; i++)
        res +=  ((long long) nums[i] * cnt[i]);
    
    return res % 1000000007;
    }
```

This function computes the maximum sum of values within the ranges specified in `req` after modifying `nums`. The final result is taken modulo 1000000007.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
	```
	This line defines the function `maxSumRangeQuery` that takes two arguments: a vector of integers `nums` and a 2D vector `req` representing the ranges for computation.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	This initializes the variable `n` to store the size of the `nums` array.

3. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	Here, we initialize `res` to 0. This will hold the final result of the sum after performing the necessary calculations.

4. **Array Initialization**
	```cpp
	    vector<long long> cnt(n, 0);
	```
	We create a vector `cnt` initialized to zeros. This will keep track of the frequency of range updates for each index in `nums`.

5. **Loop (Outer)**
	```cpp
	    for(auto& r: req) {
	```
	This loop iterates over each range in the `req` vector. Each range is represented by the indices `r[0]` and `r[1]`.

6. **Range Update**
	```cpp
	        cnt[r[0]]++;
	```
	This line increments the value at index `r[0]` in the `cnt` vector, indicating that the range starting at `r[0]` is updated.

7. **Conditional Update**
	```cpp
	        if(r[1] + 1 < n)
	```
	This checks if the end of the range `r[1]` is within bounds. If true, we need to decrement the value just after the range.

8. **Range Update**
	```cpp
	            cnt[r[1] +1]--;
	```
	This line decrements the value just after the range `r[1] + 1`, signaling the end of the range effect.

9. **Prefix Sum**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	This loop starts the prefix sum operation on the `cnt` array, which accumulates the range counts.

10. **Prefix Sum Update**
	```cpp
	        cnt[i] += cnt[i -1];
	```
	This line adds the previous value of `cnt[i-1]` to `cnt[i]`, effectively accumulating the range counts.

11. **Sorting**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	This sorts the `nums` array in ascending order to align the highest values with the most frequent ranges.

12. **Sorting**
	```cpp
	    sort(cnt.begin(), cnt.end());
	```
	This sorts the `cnt` array to match the corresponding frequencies with the sorted `nums` array.

13. **Final Computation Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	This loop computes the final result by multiplying each value in `nums` by the corresponding frequency in `cnt`.

14. **Final Computation**
	```cpp
	        res +=  ((long long) nums[i] * cnt[i]);
	```
	This line adds the product of the sorted values in `nums` and their corresponding frequencies in `cnt` to the result `res`.

15. **Modulo Operation**
	```cpp
	    return res % 1000000007;
	```
	After computing the total sum, we return the result modulo 1000000007 to avoid overflow and meet the problem's requirements.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n) - Sorting nums and cnt arrays takes O(n log n).
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The most expensive operation is sorting the nums and cnt arrays.

### Space Complexity 💾
- **Best Case:** O(n) - The space complexity is primarily determined by the storage of the cnt array and nums.
- **Worst Case:** O(n) - Storing the cnt array and intermediate results requires O(n) space.

The space complexity is linear, proportional to the size of nums and the request list.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/)

---
{{< youtube TyZ_FFGIZgs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
