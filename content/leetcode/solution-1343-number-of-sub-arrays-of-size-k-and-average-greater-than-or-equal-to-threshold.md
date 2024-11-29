
+++
authors = ["grid47"]
title = "Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold"
date = "2024-06-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "D8B4tKxMTnY"
youtube_upload_date="2023-02-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/D8B4tKxMTnY/maxresdefault.webp"
comments = true
+++



---
Given an array of integers arr and two integers k and threshold, return the number of subarrays of size k whose average is greater than or equal to the threshold.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers and two integers, k and threshold.
- **Example:** `arr = [1,3,5,7,9,10,12], k = 3, threshold = 7`
- **Constraints:**
	- 1 <= arr.length <= 10^5
	- 1 <= arr[i] <= 10^4
	- 1 <= k <= arr.length
	- 0 <= threshold <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of subarrays of size k whose average is greater than or equal to the threshold.
- **Example:** `For arr = [1,3,5,7,9,10,12], k = 3, threshold = 7, the output will be 4.`
- **Constraints:**
	- The answer will be a non-negative integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count how many subarrays of size k have an average greater than or equal to the threshold.

- 1. Use a sliding window of size k to calculate the sum of each subarray.
- 2. Compute the average by dividing the sum of the subarray by k.
- 3. Count the number of subarrays whose average is greater than or equal to the threshold.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one subarray of the given size k.
- The array elements and threshold are non-negative integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: arr = [1, 3, 5, 7, 9, 10, 12], k = 3, threshold = 7`  \
  **Explanation:** Subarrays of size 3 are checked, and their averages are compared to the threshold to count the valid subarrays.

- **Input:** `Example 2: arr = [2, 2, 2, 2, 5, 5, 5, 8], k = 3, threshold = 4`  \
  **Explanation:** The subarrays are evaluated based on their averages, and only those meeting or exceeding the threshold are counted.

{{< dots >}}
## Approach 🚀
To solve the problem, we can use a sliding window technique to efficiently compute the sum of each subarray of size k and check if the average is greater than or equal to the threshold.

### Initial Thoughts 💭
- A sliding window approach ensures we only calculate the sum of each subarray once and adjust it as we move through the array.
- The sliding window approach is efficient and avoids recalculating the sum from scratch for each subarray, making it optimal for large arrays.
{{< dots >}}
### Edge Cases 🌐
- There are no empty arrays, as the length of arr is always at least 1.
- For large inputs, the solution should be efficient and run in O(n) time where n is the length of the array.
- The threshold value may be 0, in which case all subarrays with positive values will have an average greater than or equal to the threshold.
- The array will contain only positive integers, and the subarray size k will always be valid.
{{< dots >}}
## Code 💻
```cpp
int numOfSubarrays(vector<int>& arr, int k, int th) {
    int cnt = 0, sum = 0;
    th = th * k;
    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }
    cnt += sum >= th;
    for(int i = k; i < arr.size(); i++) {
        sum += arr[i];
        sum -= arr[i - k];
        if(sum >= th) cnt++;
    }
    return cnt;
}
```

This function calculates the number of subarrays of length `k` whose average value is at least `th`. It uses a sliding window technique to efficiently compute the sum for each subarray.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numOfSubarrays(vector<int>& arr, int k, int th) {
	```
	Defines the function that takes an array, window size `k`, and a threshold value `th` as inputs and returns the count of subarrays meeting the criteria.

2. **Variable Initialization**
	```cpp
	    int cnt = 0, sum = 0;
	```
	Initializes `cnt` to track the number of valid subarrays and `sum` to store the current window's sum.

3. **Threshold Adjustment**
	```cpp
	    th = th * k;
	```
	Converts the threshold to the total sum equivalent for a subarray of size `k` by multiplying it with `k`.

4. **Initial Window**
	```cpp
	    for(int i = 0; i < k; i++) {
	```
	Starts a loop to calculate the sum of the first window of size `k`.

5. **Sum Update**
	```cpp
	        sum += arr[i];
	```
	Adds the current element to the sum for the first window.

6. **Initial Count Check**
	```cpp
	    cnt += sum >= th;
	```
	Checks if the initial window meets the threshold and increments `cnt` if true.

7. **Sliding Window Loop**
	```cpp
	    for(int i = k; i < arr.size(); i++) {
	```
	Begins the sliding window process to check subsequent windows.

8. **Window Update Add**
	```cpp
	        sum += arr[i];
	```
	Adds the next element in the array to the current window's sum.

9. **Window Update Remove**
	```cpp
	        sum -= arr[i - k];
	```
	Removes the element that is sliding out of the window from the sum.

10. **Count Check**
	```cpp
	        if(sum >= th) cnt++;
	```
	Checks if the updated window's sum meets the threshold and increments `cnt` if true.

11. **Return Result**
	```cpp
	    return cnt;
	```
	Returns the final count of subarrays meeting the threshold criteria.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the number of elements in the array.
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only traverse the array once while maintaining a sliding window.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we only need a few extra variables to track the sum and count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/)

---
{{< youtube D8B4tKxMTnY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
