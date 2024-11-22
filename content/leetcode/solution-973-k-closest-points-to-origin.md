
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
+++



---
**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] * a[0] + a[1] * a[1] > b[0]* b[0] + b[1] * b[1];
    }
};

class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the `k` closest points to the origin (0, 0) in a 2D plane from a given list of points. Each point is represented as a pair of integers `[x, y]`. The solution should return the `k` closest points based on their Euclidean distance to the origin. The Euclidean distance between a point `(x, y)` and the origin `(0, 0)` is calculated as:

\[
\text{distance} = \sqrt{x^2 + y^2}
\]

However, instead of calculating the exact distance, we can work with the squared Euclidean distance to simplify computations. This approach avoids the computational cost of taking square roots and produces the same ordering of points by distance.

The task is to return the `k` points with the smallest squared Euclidean distance.

### Approach

The problem can be efficiently solved using a **priority queue** (or heap) with a custom comparator. The steps to solve the problem are as follows:

1. **Use a Priority Queue (Min-Heap)**: 
   - We can leverage a **max-heap** to keep track of the `k` closest points. Since we need to find the closest points, the max-heap will allow us to efficiently remove the farthest point when the heap exceeds size `k`.
   - The heap stores the points based on their squared distance from the origin.
   
2. **Custom Comparator**:
   - A custom comparator is defined to compare points based on their squared Euclidean distance. The comparator returns `true` if the squared distance of the first point is greater than that of the second, ensuring that the point with the greater distance is pushed out when the heap exceeds size `k`.

3. **Push Points to the Heap**:
   - Iterate through the list of points and push each point onto the heap. If the size of the heap exceeds `k`, remove the point with the greatest distance from the origin.

4. **Extract the Closest Points**:
   - Once the heap contains the `k` closest points, extract them and return them as the result.

### Code Breakdown (Step by Step)

```cpp
class cmp {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
    }
};
```

1. **Custom Comparator**:
   - The `cmp` class defines a custom comparator for comparing two points based on their squared Euclidean distance from the origin.
   - The `operator()` method is overloaded to return `true` if the squared distance of point `a` is greater than the squared distance of point `b`. This ensures that the max-heap stores the point with the largest squared distance at the top of the heap.

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
```

2. **Priority Queue Initialization**:
   - The `priority_queue` `pq` is declared to store points. The queue is sorted using the custom comparator `cmp`.
   - The type `vector<vector<int>>` represents the priority queue holding the points, where each point is a vector of two integers `[x, y]`.

```cpp
        for (auto it : pts) {
            pq.push(it);
        }
```

3. **Push Points into the Heap**:
   - The `for` loop iterates over each point `it` in the `pts` list.
   - Each point is pushed onto the priority queue `pq`. The comparator ensures that the points are ordered by their squared Euclidean distance from the origin.

```cpp
        vector<vector<int>> ans;
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
```

4. **Extract Closest Points**:
   - After all points are pushed onto the heap, we create an empty vector `ans` to store the result.
   - The `while (k--)` loop runs `k` times, popping the top element from the priority queue (which contains the farthest point) and adding it to the result vector `ans`.
   - The `pq.top()` gives the point with the smallest squared distance, and `pq.pop()` removes that point from the heap.

```cpp
        return ans;
    }
};
```

5. **Return the Result**:
   - After extracting the `k` closest points, we return the `ans` vector, which contains the `k` points closest to the origin.

### Complexity

- **Time Complexity**:
   - **Pushing Points to the Heap**: Each point is pushed onto the priority queue. In the worst case, we push all `n` points onto the heap, and each `push` operation takes `O(log n)` time. So, the time complexity for this step is `O(n log n)`.
   - **Extracting the k Closest Points**: Extracting the top `k` points from the heap takes `O(k log n)` time because each `pop` operation takes `O(log n)` time. 
   - Therefore, the overall time complexity is **O(n log n)**, where `n` is the number of points in the input list `pts`.

- **Space Complexity**:
   - The space complexity is dominated by the space used to store the priority queue and the result vector. In the worst case, the priority queue stores all `n` points, and the result vector stores `k` points. 
   - Therefore, the space complexity is **O(n)**, where `n` is the number of points in the input list `pts`.

### Conclusion

This solution efficiently solves the problem of finding the `k` closest points to the origin by leveraging a max-heap (priority queue) with a custom comparator. By utilizing the heap, we can ensure that we always have the closest points stored at the top of the heap, and efficiently remove the farthest points when necessary. This approach has a time complexity of **O(n log n)** and a space complexity of **O(n)**, making it suitable for problems where we need to efficiently find the closest `k` elements based on a distance metric.

[`Link to LeetCode Lab`](https://leetcode.com/problems/k-closest-points-to-origin/description/)

---
{{< youtube IGRUukbD6p8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
