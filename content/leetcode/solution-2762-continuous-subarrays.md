
+++
authors = ["grid47"]
title = "Leetcode 2762: Continuous Subarrays"
date = "2024-02-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2762: Continuous Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Queue","Sliding Window","Heap (Priority Queue)","Ordered Set","Monotonic Queue"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "TDB2fGaYzMg"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/TDB2fGaYzMg/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed integer array 'nums'. A subarray of 'nums' is called continuous if the absolute difference between any two elements in the subarray is less than or equal to 2. Return the total number of continuous subarrays.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a single integer array 'nums'.
- **Example:** `nums = [3, 5, 4, 2]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the total number of continuous subarrays.
- **Example:** `For nums = [3, 5, 4, 2], the output is 10.`
- **Constraints:**
	- The output should be a single integer representing the count of continuous subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the total number of continuous subarrays where the absolute difference between any two elements is less than or equal to 2.

- Use a sliding window approach with two pointers, i and j.
- Track the frequency of elements within the window using a map.
- Adjust the window to ensure the condition |nums[i] - nums[j]| <= 2 is met.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always have at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [3, 5, 4, 2]`  \
  **Explanation:** The valid subarrays are of size 1, 2, and 3, totaling 10 continuous subarrays.

- **Input:** `For nums = [7, 8, 9, 10]`  \
  **Explanation:** The valid subarrays are of size 1, 2, 3, and 4, totaling 10 continuous subarrays.

{{< dots >}}
## Approach 🚀
The solution involves using a sliding window to count continuous subarrays that satisfy the condition.

### Initial Thoughts 💭
- We need to ensure that the absolute difference between any two elements in the subarray is less than or equal to 2.
- Using a sliding window approach will allow us to count valid subarrays efficiently by adjusting the window as we iterate through the array.
{{< dots >}}
### Edge Cases 🌐
- The input array will always contain at least one element, so no need to handle empty arrays.
- For large arrays (up to 10^5 elements), ensure that the solution runs efficiently.
- When all elements are the same, the entire array is valid.
- Ensure that the solution handles arrays with large values (up to 10^9) efficiently.
{{< dots >}}
## Code 💻
```cpp
long long continuousSubarrays(vector<int>& nums) {
    long long res = 0;
    int i = 0, j = 0,n=nums.size();
    map<int,int> mp;
    while(j<n) {
        mp[nums[j]]++;
        while(mp.size()>3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)
                mp.erase(nums[i]);
            i++;
        }
        long long temp = j-i+1;
        res = res + temp;
        j++;
    }
    return res;
}
```

This function calculates the total number of continuous subarrays within a given vector `nums` where the subarrays contain at most 3 distinct elements, and the difference between the maximum and minimum values in the subarray is no more than 2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long continuousSubarrays(vector<int>& nums) {
	```
	Defines the function `continuousSubarrays`, which takes a vector `nums` and returns the total count of valid continuous subarrays that satisfy the given conditions.

2. **Variable Initialization**
	```cpp
	    long long res = 0;
	```
	Initializes a variable `res` to store the result, which will hold the total number of valid subarrays.

3. **Index Initialization**
	```cpp
	    int i = 0, j = 0, n = nums.size();
	```
	Initializes the indices `i` and `j` to 0, and `n` to the size of the `nums` vector. These indices will define the current window of subarray being considered.

4. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map `mp` to track the frequency of elements in the current window. The key is the element, and the value is its count.

5. **Outer While Loop**
	```cpp
	    while(j < n) {
	```
	Starts a while loop that iterates as long as `j` is within the bounds of the vector. This loop expands the window by incrementing `j`.

6. **Map Update**
	```cpp
	        mp[nums[j]]++;
	```
	Increments the count of the current element `nums[j]` in the map `mp`.

7. **Inner While Loop (Check Validity)**
	```cpp
	        while(mp.size() > 3 || abs(mp.begin()->first - mp.rbegin()->first) > 2) {
	```
	Checks if the current subarray has more than 3 distinct elements or if the difference between the max and min elements exceeds 2. If so, reduces the window size by moving `i` forward.

8. **Adjust Map (Remove Element)**
	```cpp
	            mp[nums[i]]--;
	```
	Decrements the count of the element at index `i` in the map `mp`.

9. **Erase Element from Map**
	```cpp
	            if(mp[nums[i]] == 0)
	```
	Checks if the count of the element `nums[i]` is 0, and if so, removes it from the map `mp`.

10. **Increment Index i**
	```cpp
	                mp.erase(nums[i]);
	```
	Erases the element `nums[i]` from the map `mp`.

11. **Increment Index i**
	```cpp
	            i++;
	```
	Increments the index `i` to shrink the window from the left side.

12. **Calculate Subarray Length**
	```cpp
	        long long temp = j - i + 1;
	```
	Calculates the length of the current valid subarray, which is `j - i + 1`, and stores it in `temp`.

13. **Update Result**
	```cpp
	        res = res + temp;
	```
	Adds the length of the current valid subarray (`temp`) to the total result `res`.

14. **Increment Index j**
	```cpp
	        j++;
	```
	Increments the index `j` to expand the window to the next element.

15. **Return Result**
	```cpp
	    return res;
	```
	Returns the total number of valid subarrays stored in `res`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the length of the array. We iterate through the array with two pointers.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the map storing the frequencies of elements in the window.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/continuous-subarrays/description/)

---
{{< youtube TDB2fGaYzMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
