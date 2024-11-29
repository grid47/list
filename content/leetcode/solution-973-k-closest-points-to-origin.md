
+++
authors = ["grid47"]
title = "Leetcode 973: K Closest Points to Origin"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 973: K Closest Points to Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Divide and Conquer","Geometry","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "IGRUukbD6p8"
youtube_upload_date="2024-01-11"
youtube_thumbnail="https://i.ytimg.com/vi_webp/IGRUukbD6p8/maxresdefault.webp"
comments = true
+++



---
Given an array of points on a 2D plane, find the k closest points to the origin (0, 0) based on Euclidean distance. If multiple points have the same distance, any order is acceptable.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of points on the X-Y plane and an integer k.
- **Example:** `points = [[2, -1], [1, 2], [-3, -4]], k = 2`
- **Constraints:**
	- 1 <= k <= points.length <= 10^4
	- -10^4 <= xi, yi <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** An array of k points that are closest to the origin.
- **Example:** `[[1, 2], [2, -1]]`
- **Constraints:**
	- The answer may be returned in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the k points with the smallest Euclidean distances from the origin.

- Calculate the Euclidean distance for each point from the origin.
- Sort the points by distance in ascending order.
- Return the first k points.
{{< dots >}}
### Problem Assumptions ✅
- The input points array is valid and non-empty.
- The integer k is always less than or equal to the length of the points array.
{{< dots >}}
## Examples 🧩
- **Input:** `points = [[-1, -1], [2, 2], [4, 5]], k = 1`  \
  **Explanation:** The closest point is [-1, -1] because it has the smallest Euclidean distance to the origin.

- **Input:** `points = [[2, -1], [1, 2], [-3, -4]], k = 2`  \
  **Explanation:** The two closest points are [1, 2] and [2, -1] because their distances are smaller than [-3, -4].

{{< dots >}}
## Approach 🚀
Use a priority queue to efficiently find the k smallest distances.

### Initial Thoughts 💭
- The problem involves finding the k smallest distances.
- Sorting all distances is inefficient for large inputs.
- Using a priority queue (max-heap) to maintain the k closest points ensures efficient processing.
{{< dots >}}
### Edge Cases 🌐
- k = 0, no points should be returned.
- Maximum constraint of points and k, ensuring efficient handling.
- All points have the same distance to the origin.
- Handle cases where k equals the length of the points array.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    for(auto it : pts) {
        pq.push(it);
    }
    
    vector<vector<int>> ans;
    while(k--) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
```

This function finds the 'k' closest points to the origin from a list of points. It uses a priority queue to store points based on their distance from the origin and returns the closest 'k' points.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
	```
	Defines the function `kClosest`, which takes a 2D vector of points and an integer 'k', and returns the 'k' closest points from the origin.

2. **Priority Queue Declaration**
	```cpp
	    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	```
	Declares a priority queue `pq` that stores points in a specific order determined by the comparison function `cmp`, allowing efficient extraction of the closest points.

3. **Loop Over Points**
	```cpp
	    for(auto it : pts) {
	```
	Iterates through all the points in the input vector `pts` to add them to the priority queue.

4. **Push to Priority Queue**
	```cpp
	        pq.push(it);
	```
	Pushes each point from `pts` into the priority queue to sort the points according to the comparison criteria defined by `cmp`.

5. **Answer Vector Declaration**
	```cpp
	    vector<vector<int>> ans;
	```
	Declares a 2D vector `ans` to store the closest points as they are extracted from the priority queue.

6. **Extract Closest Points**
	```cpp
	    while(k--) {
	```
	Begins a loop to extract the 'k' closest points from the priority queue. This continues until 'k' points are extracted.

7. **Push Closest Point**
	```cpp
	        ans.push_back(pq.top());
	```
	Adds the top point from the priority queue (the closest point) to the `ans` vector.

8. **Pop Closest Point**
	```cpp
	        pq.pop();
	```
	Removes the top point from the priority queue after it is added to the `ans` vector.

9. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the `ans` vector containing the 'k' closest points to the origin.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log k)
- **Average Case:** O(n log k)
- **Worst Case:** O(n log k)

Iterate through n points, maintaining a heap of size k.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

Heap size is limited to k elements.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-closest-points-to-origin/description/)

---
{{< youtube IGRUukbD6p8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
