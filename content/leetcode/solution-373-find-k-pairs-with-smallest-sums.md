
+++
authors = ["grid47"]
title = "Leetcode 373: Find K Pairs with Smallest Sums"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 373: Find K Pairs with Smallest Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/373.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/373.webp" 
    alt="A series of pairs of numbers, with the smallest sum softly glowing as each pair is tested."
    caption="Solution to LeetCode 373: Find K Pairs with Smallest Sums Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two sorted integer arrays `nums1` and `nums2` and an integer `k`, return the k pairs with the smallest sums. Each pair consists of one element from `nums1` and one element from `nums2`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two sorted arrays, `nums1` and `nums2`, and an integer `k`.
- **Example:** `Input: nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 10^5
	- -10^9 <= nums1[i], nums2[i] <= 10^9
	- nums1 and nums2 are sorted in non-decreasing order.
	- 1 <= k <= 10^4
	- k <= nums1.length * nums2.length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of the `k` pairs with the smallest sums.
- **Example:** `Output: [[1, 2], [1, 4], [1, 6]]`
- **Constraints:**
	- The pairs must be returned in non-decreasing order of their sums.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the `k` smallest sum pairs efficiently, leveraging the sorted order of the input arrays.

- 1. Initialize a priority queue (min-heap) to track the smallest sums.
- 2. Push the first pair from each element in `nums1` and the first element in `nums2` into the priority queue.
- 3. Continue popping the smallest pairs and pushing the next possible pairs until `k` pairs are found.
{{< dots >}}
### Problem Assumptions ✅
- The arrays `nums1` and `nums2` are both sorted in non-decreasing order.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums1 = [1, 7, 11], nums2 = [2, 4, 6], k = 3
Output: [[1, 2], [1, 4], [1, 6]]`  \
  **Explanation:** The smallest pairs are (1, 2), (1, 4), and (1, 6) because their sums are 3, 5, and 7, respectively.

- **Input:** `Input: nums1 = [1, 1, 2], nums2 = [1, 2, 3], k = 2
Output: [[1, 1], [1, 1]]`  \
  **Explanation:** The first two pairs are (1, 1) and (1, 1) because their sums are both 2.

{{< dots >}}
## Approach 🚀
We use a priority queue to keep track of the smallest sum pairs and efficiently find the k smallest pairs.

### Initial Thoughts 💭
- We are given two sorted arrays, which suggests that we can efficiently use a priority queue to find the smallest pairs.
- Using a min-heap (priority queue) will allow us to efficiently extract the smallest sums and generate the next potential pairs.
{{< dots >}}
### Edge Cases 🌐
- If either of the arrays `nums1` or `nums2` is empty, the result should be an empty list.
- For large arrays, the solution should efficiently compute the k smallest pairs without exceeding time limits.
- If `k = 1`, the output should be the pair with the smallest sum.
- Ensure that the priority queue is efficiently managed to avoid excessive computational overhead.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    int n1 = nums1.size(), n2 = nums2.size();
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
    for(int i = 0; i < n1 && i < k; i++) {
        pq.push({nums1[i] + nums2[0], nums1[i], nums2[0], 0});
    }
    while(!pq.empty() && ans.size() < k) {
        auto it = pq.top();
        pq.pop();
        ans.push_back({it[1], it[2]});
        if(it[3] == n2 - 1) continue;            
        it[0] = it[1] + nums2[it[3] + 1];
        it[2] = nums2[it[3] + 1];
        it[3] = it[3] + 1;
        pq.push(it);
    }
    return ans;
}
```

This function returns the k smallest sum pairs from two sorted arrays `nums1` and `nums2` using a min-heap (priority queue). It pushes the sum of the first element from `nums1` with each element from `nums2` into the priority queue and pops the smallest sums while iterating through the arrays.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	```
	This line declares the function `kSmallestPairs`, which takes two vectors `nums1` and `nums2` and an integer `k` to find the k smallest sum pairs.

2. **Variable Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	A vector `ans` is declared to store the k smallest sum pairs that will be returned by the function.

3. **Variable Initialization**
	```cpp
	    int n1 = nums1.size(), n2 = nums2.size();
	```
	The sizes of `nums1` and `nums2` are stored in `n1` and `n2` respectively to avoid repeatedly calculating their sizes.

4. **Priority Queue Initialization**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
	```
	A min-heap (priority queue) `pq` is initialized, which will store vectors containing the sum of pairs and the corresponding elements from `nums1` and `nums2`.

5. **Loop Iteration**
	```cpp
	    for(int i = 0; i < n1 && i < k; i++) {
	```
	This loop iterates over `nums1` and adds the first element of each pair from `nums1[i]` and `nums2[0]` into the priority queue.

6. **Priority Queue Push**
	```cpp
	        pq.push({nums1[i] + nums2[0], nums1[i], nums2[0], 0});
	```
	The sum of `nums1[i]` and `nums2[0]` is pushed into the priority queue along with the corresponding elements and the index `0` (representing the first element of `nums2`).

7. **Loop Condition**
	```cpp
	    while(!pq.empty() && ans.size() < k) {
	```
	The while loop continues as long as there are elements in the priority queue and the number of pairs found is less than `k`.

8. **Priority Queue Pop**
	```cpp
	        auto it = pq.top();
	```
	The smallest sum pair is popped from the priority queue.

9. **Priority Queue Pop**
	```cpp
	        pq.pop();
	```
	The smallest element is removed from the priority queue after it has been retrieved.

10. **Answer Update**
	```cpp
	        ans.push_back({it[1], it[2]});
	```
	The pair `it[1]` and `it[2]` (the elements from `nums1` and `nums2`) is added to the result `ans`.

11. **Condition Check**
	```cpp
	        if(it[3] == n2 - 1) continue;            
	```
	If the index `it[3]` has reached the last element of `nums2`, the loop continues to the next iteration without making any changes, as no further pairs are available from `nums2` for this particular element of `nums1`.

12. **Element Update**
	```cpp
	        it[0] = it[1] + nums2[it[3] + 1];
	```
	The sum of `it[1]` (current element of `nums1`) and the next element of `nums2` is updated in the vector.

13. **Element Update**
	```cpp
	        it[2] = nums2[it[3] + 1];
	```
	The next element of `nums2` is updated in the vector `it`.

14. **Index Update**
	```cpp
	        it[3] = it[3] + 1;
	```
	The index `it[3]` is incremented to reflect the movement to the next element of `nums2`.

15. **Priority Queue Push**
	```cpp
	        pq.push(it);
	```
	The updated vector is pushed back into the priority queue to continue processing.

16. **Return Statement**
	```cpp
	    return ans;
	```
	The result `ans`, containing the k smallest pairs, is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(k log k)
- **Average Case:** O(k log k)
- **Worst Case:** O(k log n2)

In the worst case, we push and pop from the priority queue for `k` pairs, each involving logarithmic operations in relation to the size of the second array `nums2`.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The space complexity is determined by the storage used for the priority queue and the resulting pairs.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
