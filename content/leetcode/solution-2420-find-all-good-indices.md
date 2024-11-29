
+++
authors = ["grid47"]
title = "Leetcode 2420: Find All Good Indices"
date = "2024-03-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2420: Find All Good Indices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3JIMkdeoF1c"
youtube_upload_date="2022-09-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3JIMkdeoF1c/maxresdefault.webp"
comments = true
+++



---
Given an integer array nums of size n and a positive integer k, find all good indices in the array. An index i is considered good if: The k elements just before it are in non-increasing order, and the k elements just after it are in non-decreasing order. Return a list of all good indices in increasing order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array nums of integers and a positive integer k.
- **Example:** `nums = [3,2,2,2,5,6,2], k = 2`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^6
	- 1 <= k <= n / 2

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing all good indices sorted in increasing order.
- **Example:** `Output: [2, 3]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the indices where the k elements before and after it satisfy the non-increasing and non-decreasing conditions, respectively.

- 1. Initialize two arrays dp1 and dp2, where dp1 tracks the length of non-increasing subsequences before each index and dp2 tracks non-decreasing subsequences after each index.
- 2. Traverse the array to fill dp1 and dp2.
- 3. Loop through the indices from k to n-k and check the conditions for good indices.
- 4. Collect and return the indices that satisfy the conditions.
{{< dots >}}
### Problem Assumptions ✅
- The array will contain at least 3 elements, and the value of k will be such that k <= n / 2.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 2, 2, 2, 5, 6, 2], k = 2`  \
  **Explanation:** Indices 2 and 3 are good because the elements before them form non-increasing sequences and the elements after them form non-decreasing sequences.

{{< dots >}}
## Approach 🚀
The solution involves filling two arrays (dp1 and dp2) to track the lengths of non-increasing and non-decreasing subsequences. The final step is checking which indices satisfy the good index conditions.

### Initial Thoughts 💭
- We need to efficiently track sequences of non-increasing and non-decreasing elements.
- We can use dynamic programming to build the dp1 and dp2 arrays and check for good indices by iterating over the array.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees that n will be at least 3, so this case does not need to be handled.
- The algorithm should handle the maximum input size (up to 100,000 elements) efficiently.
- If no indices satisfy the conditions, return an empty array.
- Ensure the solution runs within time limits for large inputs (O(n) time complexity).
{{< dots >}}
## Code 💻
```cpp
vector<int> goodIndices(vector<int>& a, int k) {
    int n = a.size();
    vector<int> dp1(n + 1, 1), dp2(n + 1, 1), ans;

    for(int i = 1; i < n; i++)
        if(a[i -1] >= a[i]) dp1[i] = dp1[i - 1]+1;
    for(int i = n -2; i > 0; i--)
        if(a[i] <= a[i +1]) dp2[i] = dp2[i +1]+1;

    for(int i = k; i< n-k; i++)
    if(dp1[i-1] >= k && dp2[i+1] >=k)
    ans.push_back(i);

    return ans;
}
```

This function finds all indices in a given array where a specific condition holds, based on a sliding window defined by the parameter 'k'. It utilizes two dynamic programming arrays to track decreasing and increasing subsequences.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> goodIndices(vector<int>& a, int k) {
	```
	This line defines the function 'goodIndices', which takes a vector of integers 'a' and an integer 'k'. It returns a vector of integers representing the indices where the condition holds.

2. **Variable Initialization**
	```cpp
	    int n = a.size();
	```
	This line initializes 'n' to store the size of the input vector 'a'.

3. **Dynamic Programming Arrays Initialization**
	```cpp
	    vector<int> dp1(n + 1, 1), dp2(n + 1, 1), ans;
	```
	Here, two dynamic programming arrays, 'dp1' and 'dp2', are initialized to size 'n + 1' with all elements set to 1. 'dp1' will track the length of decreasing subsequences from the left, while 'dp2' will track increasing subsequences from the right. The vector 'ans' will store the valid indices.

4. **First Loop**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	This loop iterates over the array starting from the second element (index 1). It updates the 'dp1' array based on whether the current element is less than or equal to the previous one.

5. **Update dp1**
	```cpp
	        if(a[i -1] >= a[i]) dp1[i] = dp1[i - 1]+1;
	```
	If the current element 'a[i]' is less than or equal to the previous element 'a[i-1]', 'dp1[i]' is updated to the value of 'dp1[i-1]' + 1, indicating the continuation of a decreasing subsequence.

6. **Second Loop**
	```cpp
	    for(int i = n -2; i > 0; i--)
	```
	This loop iterates over the array from the second last element to the second element. It calculates the 'dp2' array based on the condition of the next element being greater than or equal to the current element.

7. **Update dp2**
	```cpp
	        if(a[i] <= a[i +1]) dp2[i] = dp2[i +1]+1;
	```
	If the current element 'a[i]' is less than or equal to the next element 'a[i+1]', 'dp2[i]' is updated to the value of 'dp2[i+1]' + 1, indicating the continuation of an increasing subsequence.

8. **Third Loop**
	```cpp
	    for(int i = k; i< n-k; i++)
	```
	This loop iterates over indices 'i' from 'k' to 'n-k', ensuring that we have enough elements on both sides of the current index for comparison.

9. **Condition for Valid Indices**
	```cpp
	    if(dp1[i-1] >= k && dp2[i+1] >=k)
	```
	This condition checks if the current index 'i' can form a valid index based on the lengths of the decreasing subsequence before it (dp1[i-1]) and the increasing subsequence after it (dp2[i+1]). Both need to be greater than or equal to 'k'.

10. **Store Valid Indices**
	```cpp
	    ans.push_back(i);
	```
	If the index satisfies the condition, it is added to the 'ans' vector.

11. **Return**
	```cpp
	    return ans;
	```
	The function returns the 'ans' vector, which contains all the valid indices.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only traverse the array a few times.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we use two additional arrays (dp1 and dp2) of size n.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-good-indices/description/)

---
{{< youtube 3JIMkdeoF1c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
