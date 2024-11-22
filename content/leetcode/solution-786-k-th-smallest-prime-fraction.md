
+++
authors = ["grid47"]
title = "Leetcode 786: K-th Smallest Prime Fraction"
date = "2024-08-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 786: K-th Smallest Prime Fraction in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/786.webp"
youtube = "sJdJTXhxqjo"
youtube_upload_date="2021-04-07"
youtube_thumbnail="https://i.ytimg.com/vi/sJdJTXhxqjo/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/786.webp" 
    alt="A set of fractions where the kth smallest prime fraction is found, glowing softly as it is identified."
    caption="Solution to LeetCode 786: K-th Smallest Prime Fraction Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;

        for(int i = 0; i < n; i++)
        pq.push(make_pair(-1.0*arr[i]/arr[n - 1], make_pair(i, n - 1)));
        int i, j;        
        while(k--) {
            auto p = pq.top().second; pq.pop();
            i = p.first;
            j = p.second;
            pq.push(make_pair(-1.0*arr[i]/arr[j-1], make_pair(i, j - 1)));
        }
        return vector<int>{arr[i], arr[j]};
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the **k-th smallest fraction** that can be formed by taking two numbers from a sorted array `arr`. The numerator of the fraction is an element of the array, and the denominator is another element of the array, such that the numerator is less than the denominator. Given a sorted array `arr` of distinct integers, and an integer `k`, we are to return the **k-th smallest fraction** from all possible fractions that can be formed.

### Approach

This problem requires us to identify and retrieve the k-th smallest fraction from all possible combinations of elements in the array. A brute-force approach where we generate all possible pairs of fractions and sort them would be inefficient, especially for larger arrays. Instead, we use a **priority queue (min-heap)** approach to efficiently keep track of the smallest fractions.

The solution works by maintaining a priority queue (min-heap) that stores fractions along with the indices of the array elements involved in forming those fractions. The priority queue allows us to efficiently retrieve the smallest fraction at each step. After retrieving a fraction, the algorithm pushes the next fraction in sequence into the heap, ensuring that we keep track of only the next smallest fractions.

### Code Breakdown (Step by Step)

Let's break down the code step by step to understand how it works:

1. **Initialization**:
   - The function accepts two inputs: a sorted array `arr` and an integer `k`.
   - `n` is set to the size of the array `arr`.
   - We initialize a **priority queue** (`pq`) that will hold pairs of the form `(fraction value, (numerator index, denominator index))`. This queue is used to store fractions and allows us to always retrieve the smallest fraction efficiently.

   ```cpp
   int n = arr.size();
   priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>> pq;
   ```

2. **Filling the Priority Queue**:
   - We loop through the array to create an initial set of fractions where each fraction is formed by dividing the current element (`arr[i]`) by the last element (`arr[n - 1]`), ensuring that the fraction is of the form `arr[i] / arr[n-1]`.
   - The priority queue is populated with these fractions, and each fraction is represented by the value of the fraction and the indices `(i, n-1)`. The priority queue is sorted in descending order, meaning the fraction with the smallest value will always be at the top.
   
   ```cpp
   for (int i = 0; i < n; i++)
       pq.push(make_pair(-1.0 * arr[i] / arr[n - 1], make_pair(i, n - 1)));
   ```

3. **Extracting k-th Smallest Fraction**:
   - The main loop runs `k` times, each time extracting the fraction at the top of the priority queue (the smallest one), and then pushing the next fraction that can be formed by using the numerator at index `i` and the next possible denominator `arr[j-1]`, where `j` is the second element of the pair.
   - The pair `(i, j)` represents the indices of the fraction. After extracting the smallest fraction, we push a new fraction formed by `arr[i]` and `arr[j-1]` into the priority queue.
   - We continue this until we pop the k-th smallest fraction from the heap.

   ```cpp
   int i, j;        
   while(k--) {
       auto p = pq.top().second; pq.pop();
       i = p.first;
       j = p.second;
       pq.push(make_pair(-1.0 * arr[i] / arr[j - 1], make_pair(i, j - 1)));
   }
   ```

4. **Returning the Result**:
   - After `k` iterations, the fraction at the top of the priority queue is the k-th smallest fraction.
   - The result is a vector containing the two elements forming the k-th smallest fraction, i.e., the numerator `arr[i]` and the denominator `arr[j]`.

   ```cpp
   return vector<int>{arr[i], arr[j]};
   ```

### Complexity Analysis

- **Time Complexity**:
  - The main time complexity comes from maintaining and updating the priority queue. Inserting an element into a priority queue takes **O(log m)** time, where `m` is the number of elements in the priority queue.
  - Initially, we insert `n` elements into the priority queue (one for each `i` from `0` to `n-1`). After that, we perform `k` pop and push operations. Each pop and push operation takes **O(log n)** time since there are at most `n` elements in the priority queue at any given time.
  - Therefore, the time complexity is **O(n log n + k log n)**. The `n log n` term comes from the initial filling of the priority queue, and `k log n` comes from processing the top `k` smallest fractions.

- **Space Complexity**:
  - The space complexity is **O(n)**, as we store at most `n` elements in the priority queue at any given time. The space required for the output vector is negligible in comparison to the priority queue.

### Conclusion

This solution efficiently finds the **k-th smallest fraction** using a **priority queue (min-heap)**. By leveraging the heap's properties, we can efficiently retrieve the smallest fractions without needing to sort all possible fractions, which makes this approach much more efficient than a brute-force method. The use of the priority queue ensures that we only need to keep track of the smallest fractions, reducing unnecessary computation and making the solution scalable for larger inputs.

This algorithm is optimal for solving problems involving ordered or sorted data where we need to find specific elements in the sequence, such as the k-th smallest item. It's a perfect example of how data structures like priority queues can help us tackle problems efficiently, even when dealing with large datasets. The approach is both time and space efficient, making it well-suited for practical applications where performance is a priority.

In summary, this approach provides a clean, optimal solution to the problem by making use of heap properties to keep track of the smallest fractions efficiently, offering a significant performance improvement over naive methods.

[`Link to LeetCode Lab`](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

---
{{< youtube sJdJTXhxqjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
