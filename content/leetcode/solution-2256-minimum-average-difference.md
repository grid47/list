
+++
authors = ["grid47"]
title = "Leetcode 2256: Minimum Average Difference"
date = "2024-03-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2256: Minimum Average Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rh8Mnj9Bd64"
youtube_upload_date="2023-06-02"
youtube_thumbnail="https://i.ytimg.com/vi/rh8Mnj9Bd64/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array `nums` of length `n`. For each index `i`, calculate the absolute difference between the average of the first `i + 1` elements and the average of the last `n - i - 1` elements. Both averages should be rounded down to the nearest integer. Your task is to find the index `i` with the minimum average difference. If there are multiple indices with the same difference, return the smallest index.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array `nums` representing the list of integers.
- **Example:** `nums = [8, 2, 5, 6, 7, 3]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the index with the minimum average difference.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the index that results in the smallest average difference, considering the left and right subarrays formed by dividing the array at each index.

- Compute the sum of the entire array `nums`.
- Iterate through each index `i` and calculate the average of the first `i + 1` elements and the last `n - i - 1` elements.
- For each index, compute the absolute difference between the two averages.
- Keep track of the minimum difference and the corresponding index.
- Return the index with the smallest difference. In case of a tie, return the smallest index.
{{< dots >}}
### Problem Assumptions ✅
- The array `nums` is non-empty.
- If the array has only one element, return 0 since there's no right subarray.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [8, 2, 5, 6, 7, 3]`  \
  **Explanation:** For each index `i`, calculate the average of the first `i + 1` elements and the last `n - i - 1` elements, and find the index with the smallest difference in averages.

- **Input:** `nums = [10]`  \
  **Explanation:** With a single element, the average difference is 0. Therefore, the result is index 0.

{{< dots >}}
## Approach 🚀
The problem can be solved by computing prefix and suffix sums efficiently to avoid recalculating sums repeatedly for each index.

### Initial Thoughts 💭
- We need to calculate averages for subarrays efficiently. Prefix sums will help us avoid recomputing sums for each subarray.
- This problem requires iterating over all indices in the array and comparing average differences.
- We can compute the total sum of the array and update the sums for the left and right subarrays incrementally as we move through the array.
{{< dots >}}
### Edge Cases 🌐
- If `nums` contains only one element, return index 0.
- For arrays with 100,000 elements, ensure the solution runs efficiently by using prefix and suffix sums.
- If all elements are the same, the average difference will always be 0.
- Handle cases where `nums` contains large numbers or a large number of elements efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumAverageDifference(vector<int>& nums) {

    typedef long long ll;
    
    ll sum = 0;
    for(int a : nums) sum += a;

    ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
    ll l = 0, r = sum;
    for(int i = 0; i < n; i++) {
        int prv = res;
        l += nums[i];
        r -= nums[i];      
        la = l / (i + 1);
        ra = (i+1==n)?0:r / (n-(i+1));
        res = min(res, abs(la - ra));
        if(prv != res) ret = i;
    }
    return ret;            
}
```

This function calculates the index where the absolute difference between the average of elements on the left and right is minimized. It computes cumulative sums on both sides of the current index, then compares the average differences at each step.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumAverageDifference(vector<int>& nums) {
	```
	The function 'minimumAverageDifference' is defined here, which takes a vector of integers 'nums' as input and returns the index where the absolute difference between the left and right average is minimized.

2. **Type Definition**
	```cpp
	    typedef long long ll;
	```
	The type 'll' is defined as 'long long' to handle large integer values without overflow.

3. **Variable Initialization**
	```cpp
	    ll sum = 0;
	```
	The variable 'sum' is initialized to zero. It will store the total sum of the elements in the 'nums' vector.

4. **Sum Calculation**
	```cpp
	    for(int a : nums) sum += a;
	```
	This loop iterates through the vector 'nums' and adds each element to 'sum', calculating the total sum of all elements.

5. **Variable Initialization**
	```cpp
	    ll n = nums.size(), res = INT_MAX, ret = 0, la = 0, ra = 0;
	```
	Here, 'n' stores the size of the 'nums' vector. 'res' is initialized to the maximum integer value to track the minimum average difference. 'ret' stores the index with the minimum difference, and 'la' and 'ra' store the left and right averages, respectively.

6. **Left and Right Sums**
	```cpp
	    ll l = 0, r = sum;
	```
	Variables 'l' and 'r' are initialized to zero and 'sum', respectively. 'l' will track the cumulative sum from the left, while 'r' starts with the total sum and will decrease as we move through the array.

7. **Iterate Through Elements**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	A loop that iterates through each element in the vector 'nums', adjusting the left and right sums and calculating the averages at each step.

8. **Store Previous Result**
	```cpp
	        int prv = res;
	```
	Stores the previous result in 'prv' for comparison later to track if the minimum result has changed.

9. **Update Left Sum**
	```cpp
	        l += nums[i];
	```
	Adds the current element 'nums[i]' to the left sum 'l'.

10. **Update Right Sum**
	```cpp
	        r -= nums[i];      
	```
	Subtracts the current element 'nums[i]' from the right sum 'r'.

11. **Calculate Left Average**
	```cpp
	        la = l / (i + 1);
	```
	Calculates the average of the left part by dividing 'l' (the sum of the left part) by the number of elements processed so far (i+1).

12. **Calculate Right Average**
	```cpp
	        ra = (i+1==n)?0:r / (n-(i+1));
	```
	Calculates the average of the right part by dividing 'r' (the sum of the remaining elements) by the number of elements left (n-(i+1)). If we're at the last element, the right average is set to zero.

13. **Update Minimum Difference**
	```cpp
	        res = min(res, abs(la - ra));
	```
	Updates 'res' to the minimum of its current value and the absolute difference between the left and right averages.

14. **Update Index of Minimum Difference**
	```cpp
	        if(prv != res) ret = i;
	```
	If the result has changed, it updates 'ret' with the current index 'i', which now holds the minimum average difference.

15. **Return Result**
	```cpp
	    return ret;            
	```
	Returns 'ret', which is the index where the absolute difference between the left and right average is minimized.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The solution only requires a single iteration through the array to compute the necessary sums and differences.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant, as we only use a few variables to keep track of sums and the minimum difference.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-average-difference/description/)

---
{{< youtube rh8Mnj9Bd64 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
