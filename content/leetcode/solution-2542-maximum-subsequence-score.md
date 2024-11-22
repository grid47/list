
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
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
};
{{< /highlight >}}
---

### Problem Statement

The problem is to maximize the score of a pair of sequences, `nums1` and `nums2`, by selecting exactly `k` elements from both arrays. The score is calculated by multiplying the sum of the selected elements from `nums1` by the corresponding element in `nums2` at the same index. The goal is to compute the maximum possible score that can be achieved by selecting exactly `k` elements from the arrays.

### Approach

The approach involves leveraging sorting and a priority queue (min-heap) to efficiently select the `k` largest values from `nums1` while ensuring that we maintain the largest possible sum for these elements. Here's a step-by-step breakdown of the solution:

1. **Pairing and Sorting**: 
   - We begin by pairing the elements of `nums1` and `nums2` as tuples, where each pair is `(nums2[i], nums1[i])`. This allows us to treat the values of `nums2` as weights for the corresponding elements of `nums1`. 
   - The next step is to sort these pairs in descending order based on the values of `nums2`. This sorting step ensures that we prioritize higher weights (`nums2[i]`) when making selections, which can maximize the score.

2. **Priority Queue (Min-Heap)**: 
   - We use a priority queue (min-heap) to keep track of the `k` largest values from `nums1`. The reason we use a min-heap is that it allows us to efficiently remove the smallest element whenever we exceed the `k` selections.

3. **Iterating through Sorted Pairs**: 
   - For each pair `(n2, n1)`, where `n2` is from `nums2` and `n1` is from `nums1`, we push `n1` (the corresponding value from `nums1`) into the priority queue and add it to the `sum` of selected values from `nums1`.
   - If the size of the priority queue exceeds `k`, we remove the smallest element (the root of the min-heap) and subtract it from the `sum`. This ensures that only the `k` largest elements are retained in the heap.
   
4. **Maximizing the Score**: 
   - After adding an element to the heap and updating the `sum`, we check if the size of the heap is exactly `k`. If it is, we compute the score by multiplying the current sum of selected elements from `nums1` with the value `n2` from `nums2` (which is the weight for these elements). We keep track of the maximum score observed so far.
   
5. **Returning the Result**: 
   - After iterating through all the pairs, the maximum score is returned as the result.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Data Structures
```cpp
vector<pair<int, int>> nums;
int n;
priority_queue<int, vector<int>, greater<int>> pq;
```
In this part of the code, we initialize the data structures:
- `nums`: a vector of pairs to store the elements of `nums2` and `nums1` as tuples.
- `n`: an integer to store the size of the arrays.
- `pq`: a priority queue (min-heap) to store the `k` largest values from `nums1`.

#### Step 2: Pairing and Sorting the Elements
```cpp
n = nums2.size(); 
for(int i = 0; i < n; i++)
    nums.push_back({nums2[i], nums1[i]});
    
sort(nums.rbegin(), nums.rend());
```
Here, we:
- Pair each element from `nums2` with its corresponding element from `nums1`.
- Store the pairs in `nums`, with the first element of each pair being from `nums2` and the second being from `nums1`.
- Sort the pairs in descending order based on the values of `nums2` (i.e., the first element of each pair).

#### Step 3: Initialize Variables for Score and Sum
```cpp
long long score = 0, sum = 0;
```
We initialize two variables:
- `score`: to keep track of the maximum score found during the iteration.
- `sum`: to store the sum of the selected elements from `nums1` as we iterate through the pairs.

#### Step 4: Iterating Through the Sorted Pairs and Building the Heap
```cpp
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
```
In this part, we:
- Iterate through each pair `(n2, n1)` in the sorted `nums` vector.
- Push `n1` (the corresponding value from `nums1`) into the priority queue and add it to the `sum`.
- If the size of the priority queue exceeds `k`, we remove the smallest element (the root of the min-heap) and subtract it from the `sum`. This ensures that we always retain the `k` largest elements in the priority queue.
- If the size of the priority queue is exactly `k`, we compute the score by multiplying the current `sum` with `n2` and update `score` to the maximum value.

#### Step 5: Returning the Maximum Score
```cpp
return score;
```
Finally, after iterating through all the pairs, we return the `score`, which holds the maximum possible score computed during the iteration.

### Complexity Analysis

#### Time Complexity:
- **Sorting**: The sorting step takes `O(n log n)` where `n` is the number of elements in `nums2` (or `nums1`).
- **Priority Queue Operations**: Each insertion and removal operation on the priority queue takes `O(log k)`, and since we process each element once, the total time for priority queue operations is `O(n log k)`.
- **Overall Time Complexity**: The overall time complexity is dominated by the sorting step and the priority queue operations, resulting in a total time complexity of `O(n log n + n log k)`. This is efficient for large inputs.

#### Space Complexity:
- **Storing Pairs**: The space required to store the pairs in `nums` is `O(n)`.
- **Priority Queue**: The space used by the priority queue is `O(k)` because it holds at most `k` elements at any time.
- **Overall Space Complexity**: The overall space complexity is `O(n + k)`.

### Conclusion

This solution efficiently computes the maximum score by:
- Pairing elements of `nums1` and `nums2` and sorting them based on the values of `nums2` to prioritize higher weights.
- Using a priority queue to maintain the `k` largest values from `nums1`, ensuring that we always compute the best possible sum for each possible selection of `k` elements.
- The algorithm runs in `O(n log n + n log k)` time, which is optimal for large inputs.

By combining sorting and a priority queue, the solution is both time and space efficient, making it a robust approach for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-subsequence-score/description/)

---
{{< youtube vJ7ZWmfO1Rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
