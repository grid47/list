
+++
authors = ["grid47"]
title = "Leetcode 1962: Remove Stones to Minimize the Total"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1962: Remove Stones to Minimize the Total in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "lLAvgl2voc4"
youtube_upload_date="2021-08-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/lLAvgl2voc4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        
        priority_queue<int> pq;
        
        for(int i = 0; i < piles.size(); i++)
            pq.push(piles[i]);
        
        while(k--) {
            int top = pq.top();
            top = top - floor(top/2);
            pq.pop();
            if(top > 0)
            pq.push(top);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to minimize the total number of stones in a collection of piles after performing a specific operation a given number of times. Each pile can be represented by an integer value indicating the number of stones in it. The operation allows you to reduce the number of stones in the pile with the maximum stones by half (rounded down) a certain number of times, \( k \). The goal is to find the minimum possible sum of stones remaining in all piles after performing the operation \( k \) times.

### Approach

To solve this problem, we can utilize a max-heap (or priority queue) data structure to efficiently access and modify the largest pile of stones. The approach can be summarized as follows:

1. **Initialize a Max-Heap**: Create a max-heap to store the piles of stones. This allows us to always access the pile with the maximum stones quickly.

2. **Perform the Operations**: For each of the \( k \) operations, extract the largest pile from the heap, reduce its size by half (using integer division), and push it back into the heap if it's still greater than zero.

3. **Calculate the Final Sum**: After all operations are performed, calculate the sum of all remaining piles in the max-heap.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
This begins the definition of the `Solution` class, which will contain our method to solve the problem.

```cpp
    int minStoneSum(vector<int>& piles, int k) {
```
The function `minStoneSum` takes two parameters:
- `piles`: a vector of integers representing the number of stones in each pile.
- `k`: an integer indicating the number of operations to perform.

```cpp
        priority_queue<int> pq;
```
We declare a max-heap using the `priority_queue` class. This will store the piles of stones.

```cpp
        for(int i = 0; i < piles.size(); i++)
            pq.push(piles[i]);
```
We iterate through the `piles` vector and push each pile into the max-heap. This allows us to easily access the largest pile.

```cpp
        while(k--) {
```
We start a loop that will run \( k \) times to perform the operations.

```cpp
            int top = pq.top();
```
We retrieve the largest pile from the max-heap.

```cpp
            top = top - floor(top/2);
```
We reduce the size of this pile by half (rounded down). The `floor` function is implicitly handled by integer division in C++, so this is effectively the same as `top / 2`.

```cpp
            pq.pop();
```
We remove the largest pile from the max-heap.

```cpp
            if(top > 0)
            pq.push(top);
```
If the new size of the pile is greater than zero, we push it back into the heap.

```cpp
        int sum = 0;
```
We initialize a variable `sum` to store the total number of stones remaining.

```cpp
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
```
We enter a loop that continues until the heap is empty. In each iteration, we add the number of stones in the largest pile (the top of the heap) to `sum` and remove that pile from the heap.

```cpp
        return sum;
    }
};
```
Finally, we return the computed sum, which represents the minimum possible total number of stones remaining in all piles after \( k \) operations.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(k \log n + n \log n)\), where \(n\) is the number of piles. This is because:
  - Constructing the heap from the piles takes \(O(n \log n)\).
  - Each of the \(k\) operations takes \(O(\log n)\) for both extracting the maximum and inserting the modified pile back.

- **Space Complexity**: The space complexity is \(O(n)\) due to the storage of the piles in the priority queue.

### Conclusion

The `minStoneSum` function efficiently reduces the total number of stones in the piles by strategically using a max-heap to ensure that the largest pile is always processed. By performing \(k\) operations of reducing the maximum pile by half, we achieve the desired minimization of the total stone count. This solution is optimal for scenarios where quick access to the largest element is crucial.

### Key Features

1. **Max-Heap Utilization**: The algorithm effectively utilizes a max-heap to always target the largest pile, ensuring that operations are directed towards the most impactful changes.

2. **Efficient Operations**: The use of a priority queue allows for efficient extraction and insertion operations, keeping the overall complexity manageable even for larger inputs.

3. **Versatile Application**: This approach can be applied in various scenarios, including game design where resource management is needed, or in simulation models where iterative reductions are common.

### Example Usage

Here’s an example of how to use the `minStoneSum` function:

```cpp
Solution sol;
vector<int> piles = {5, 4, 9};
int k = 2;
int result = sol.minStoneSum(piles, k);
cout << "Minimum stones remaining: " << result << endl; // Output: Minimum stones remaining: 12
```

In this example, we create an instance of the `Solution` class, define a vector of piles and a number of operations \( k \), and then call the `minStoneSum` method. The result is printed, showing the minimum number of stones remaining after performing the operations. 

This approach is efficient and easily understandable, making it suitable for competitive programming or coding interviews where problem-solving skills are evaluated.

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/)

---
{{< youtube lLAvgl2voc4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
