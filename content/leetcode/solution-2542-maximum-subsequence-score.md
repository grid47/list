
+++
authors = ["grid47"]
title = "Leetcode 2542: Maximum Subsequence Score"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2542: Maximum Subsequence Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vJ7ZWmfO1Rw"
youtube_upload_date="2023-05-25"
youtube_thumbnail="https://i.ytimg.com/vi/vJ7ZWmfO1Rw/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays nums1 and nums2, both of size n, and a positive integer k. Your task is to select k indices from the array nums1, where the sum of the selected elements from nums1 is multiplied by the minimum element from the corresponding selected indices in nums2. The objective is to maximize this score.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays, nums1 and nums2 of length n and a positive integer k. You need to choose k indices from nums1.
- **Example:** `nums1 = [1, 3, 3, 2], nums2 = [2, 1, 3, 4], k = 3`
- **Constraints:**
	- 1 <= n <= 10^5
	- 0 <= nums1[i], nums2[j] <= 10^5
	- 1 <= k <= n

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the maximum possible score that can be achieved by selecting k indices. If no subsequence can be selected, return 0.
- **Example:** `16`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the maximum score by selecting k indices from nums1.

- 1. Create a list of pairs (nums2[i], nums1[i]) for each element.
- 2. Sort this list in descending order based on nums2 values.
- 3. Use a priority queue to select the k largest nums1 values while keeping track of their sum.
- 4. Calculate the score and update the maximum score.
- 5. Return the maximum score.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays are of equal length.
- The integer k is a valid index count for the arrays.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [2, 4, 5, 1], nums2 = [3, 6, 2, 8], k = 2`  \
  **Explanation:** The maximum score is achieved by selecting indices 1 and 3 with a score of 16. We are multiplying the sum of selected nums1 values by the minimum corresponding nums2 value.

{{< dots >}}
## Approach 🚀
The approach is to use a greedy strategy to select the k indices that maximize the score. We first sort the pairs based on the nums2 values and then calculate the score using a priority queue to maintain the sum of the k largest nums1 values.

### Initial Thoughts 💭
- We need to maximize the score based on the sum of selected nums1 values and the minimum of corresponding nums2 values.
- Sorting the pairs based on nums2 will help us maximize the score efficiently.
- Use a greedy algorithm to select the best possible subsequence based on the sorted nums2 values.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the input arrays are empty or k = 0.
- Ensure the solution works within the time limits for large values of n.
- Handle cases where the nums1 or nums2 contains only zeroes or large numbers.
- Ensure the algorithm can handle cases where the elements in nums1 and nums2 have extreme values.
{{< dots >}}
## Code 💻
```cpp
vector<pair<int, int>> nums;
int n;
priority_queue<int, vector<int>, greater<int>> pq;

long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

    n = nums2.size(); 
    for(int i = 0; i < n; i++)
        nums.push_back({nums2[i], nums1[i]});
    
    sort(nums.rbegin(), nums.rend());
    
    long long score = 0, sum = 0;

    for(auto& [n2, n1]: nums) {
        
        pq.push(n1);
        sum += n1;
        
        if(pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        
        if(pq.size() == k)
        score = max(score, sum * n2);
    }

    return score;
}
```

This is a function that calculates the maximum score by performing k operations on two lists of integers, nums1 and nums2. It uses a priority queue to maintain the largest elements and computes the score by multiplying the sum of selected elements with corresponding elements from nums2.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	vector<pair<int, int>> nums;
	```
	Here, a vector of pairs is initialized to store pairs of elements from nums1 and nums2. This will help in pairing the corresponding elements from both arrays.

2. **Variable Initialization**
	```cpp
	int n;
	```
	An integer variable 'n' is declared to store the size of the nums2 array. It will be used to iterate through the arrays.

3. **Priority Queue Initialization**
	```cpp
	priority_queue<int, vector<int>, greater<int>> pq;
	```
	A min-heap priority queue 'pq' is initialized to store elements from nums1. It is used to maintain the largest elements up to k elements.

4. **Function Definition**
	```cpp
	long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
	```
	The function 'maxScore' is defined to calculate the maximum score. It takes two vectors nums1 and nums2 and an integer k as input parameters.

5. **Size Calculation**
	```cpp
	    n = nums2.size(); 
	```
	The size of the nums2 vector is assigned to variable 'n'. This will be used to iterate over the elements of both arrays.

6. **Array Pairing**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	A loop is initiated to iterate over the elements of nums2.

7. **Array Pairing**
	```cpp
	        nums.push_back({nums2[i], nums1[i]});
	```
	For each iteration, a pair of elements from nums2 and nums1 is added to the 'nums' vector. This pairs corresponding elements from both arrays.

8. **Sorting**
	```cpp
	    sort(nums.rbegin(), nums.rend());
	```
	The 'nums' vector is sorted in descending order based on the first element of each pair. This allows us to prioritize larger elements from nums2 during the calculation.

9. **Score Initialization**
	```cpp
	    long long score = 0, sum = 0;
	```
	The variables 'score' and 'sum' are initialized. 'score' will track the maximum score, and 'sum' will keep the running sum of selected elements.

10. **Iterating Over Pairs**
	```cpp
	    for(auto& [n2, n1]: nums) {
	```
	A loop is initiated to iterate over the sorted 'nums' vector. Each pair contains elements from nums2 (n2) and nums1 (n1).

11. **Priority Queue Operations**
	```cpp
	        pq.push(n1);
	```
	The element n1 from the current pair is added to the priority queue.

12. **Sum Calculation**
	```cpp
	        sum += n1;
	```
	The value of n1 is added to the running total 'sum'. This keeps track of the sum of elements selected so far.

13. **Priority Queue Size Check**
	```cpp
	        if(pq.size() > k) {
	```
	A check is performed to ensure that the size of the priority queue does not exceed k. If it does, the smallest element is removed.

14. **Priority Queue Operations**
	```cpp
	            sum -= pq.top();
	```
	The smallest element is removed from the priority queue, and its value is subtracted from 'sum'.

15. **Priority Queue Operations**
	```cpp
	            pq.pop();
	```
	The smallest element is popped from the priority queue to maintain its size.

16. **Score Update**
	```cpp
	        if(pq.size() == k)
	```
	If the size of the priority queue equals k, the score is updated by calculating the product of the sum of selected elements and the current n2 value.

17. **Score Update**
	```cpp
	        score = max(score, sum * n2);
	```
	The score is updated by taking the maximum of the current score and the product of the sum of selected elements and n2.

18. **Return Statement**
	```cpp
	    return score;
	```
	The function returns the maximum score calculated by the algorithm.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by sorting the nums2 array, which is O(n log n).

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required for sorting and the priority queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subsequence-score/description/)

---
{{< youtube vJ7ZWmfO1Rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
