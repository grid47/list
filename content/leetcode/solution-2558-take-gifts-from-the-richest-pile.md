
+++
authors = ["grid47"]
title = "Leetcode 2558: Take Gifts From the Richest Pile"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2558: Take Gifts From the Richest Pile in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_Nh-PvC1Wkg"
youtube_upload_date="2023-02-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/_Nh-PvC1Wkg/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  long long pickGifts(vector<int>& g, int k) {
    make_heap(g.begin(), g.end());
    while(k--) {
        pop_heap(begin(g), end(g));
        g.back() = sqrt(g.back());
        push_heap(begin(g), end(g));
    }
    return accumulate(begin(g), end(g), 0LL);
  }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to simulate the process of repeatedly selecting the largest gift, performing an operation on it, and then reinserting it back into the collection. Specifically, we are given an array of integers representing gift values, and an integer `k` representing the number of operations we can perform. In each operation, we:

1. Select the largest gift.
2. Replace it with its square root value (taking the integer square root).
3. Reinsert it back into the collection.

After performing `k` operations, we need to return the sum of the values of all the remaining gifts.

### Approach

To solve this problem, we can utilize a **max heap** (priority queue). A heap allows us to efficiently retrieve the largest element, perform the required operation, and then restore the heap property by reinserting the modified element. Here's the step-by-step approach to solving the problem:

1. **Use a Max Heap**: 
   - A max heap will help us efficiently extract the largest gift value in each operation. Since C++'s `priority_queue` provides a min-heap by default, we'll negate the values to simulate a max-heap.

2. **Perform Operations**:
   - For each of the `k` operations, we will:
     1. Extract the largest value (the gift with the highest value).
     2. Replace it with its integer square root.
     3. Push the modified value back into the heap.

3. **Return the Result**:
   - After completing the `k` operations, we will compute the sum of all the remaining gifts.

### Code Breakdown

Let's break down the code step by step to understand its functionality:

#### Step 1: Initializing the Max Heap

```cpp
make_heap(g.begin(), g.end());
```

- This function initializes a **max heap** from the vector `g`. The `make_heap` function rearranges the elements of `g` in such a way that the largest element is at the root of the heap.
- The time complexity of `make_heap` is \(O(n)\), where `n` is the number of elements in the vector.

#### Step 2: Performing the `k` Operations

```cpp
while(k--) {
    pop_heap(begin(g), end(g)); 
    g.back() = sqrt(g.back());
    push_heap(begin(g), end(g));
}
```

- **Loop**: The `while(k--)` loop runs `k` times, performing the operation for each round.
- **Extracting the Largest Element**:
  - `pop_heap(begin(g), end(g))`: This function removes the largest element from the heap and places it at the end of the vector `g`. After this operation, the heap property is violated, but the largest element is now at the back of the vector.
- **Modifying the Largest Element**:
  - `g.back() = sqrt(g.back())`: The largest element, which is now at the back of the vector, is replaced with its integer square root. This is done using the `sqrt` function, and we assign the result back to the last element of the vector.
- **Restoring the Heap Property**:
  - `push_heap(begin(g), end(g))`: This function restores the heap property by re-inserting the modified element back into the heap at the correct position. This ensures that the heap remains valid after the change.

#### Step 3: Calculating the Sum

```cpp
return accumulate(begin(g), end(g), 0LL);
```

- **Summing the Gifts**:
  - `accumulate(begin(g), end(g), 0LL)` computes the sum of all the elements in the vector `g` after the `k` operations. The `accumulate` function is part of the `<numeric>` header and is used to compute the sum of a range of elements.
  - The third argument, `0LL`, ensures that the sum is computed as a long long integer, which is useful if the sum could exceed the range of standard integers.

### Complexity Analysis

#### Time Complexity:

1. **Building the Heap**: 
   - The `make_heap` operation takes \(O(n)\) time, where `n` is the number of elements in the vector `g`.

2. **Looping `k` Times**:
   - In each iteration of the loop (which runs `k` times), we perform:
     - **`pop_heap`**: This operation takes \(O(\log n)\) time, where `n` is the number of elements in the heap.
     - **Modifying the Largest Element**: Taking the square root of the largest element takes constant time, i.e., \(O(1)\).
     - **`push_heap`**: This operation also takes \(O(\log n)\) time.
   
   Therefore, each iteration of the loop takes \(O(\log n)\) time, and since the loop runs `k` times, the total time complexity for the loop is \(O(k \log n)\).

3. **Summing the Gifts**: 
   - The `accumulate` function runs in \(O(n)\) time because it has to sum all the elements in the vector `g`.

   Overall, the time complexity is:
   \[
   O(n + k \log n)
   \]
   where `n` is the size of the vector and `k` is the number of operations.

#### Space Complexity:

- **Heap Storage**: The space required for the heap is \(O(n)\), where `n` is the number of elements in the vector `g`.
- **Auxiliary Space**: We use a few integer variables and the space for the input vector `g`, but no additional significant space is required.
  
Therefore, the space complexity is:
\[
O(n)
\]
where `n` is the number of gifts.

### Conclusion

The `pickGifts` function effectively solves the problem by simulating the process of performing `k` operations on the gifts, using a **max heap** to efficiently find and modify the largest gift in each operation. By leveraging heap operations (`pop_heap` and `push_heap`), the solution achieves an optimal time complexity of \(O(k \log n)\) for the main operations, where `n` is the number of elements in the input vector and `k` is the number of operations to perform.

This approach ensures that the solution is both time-efficient and easy to implement, given the problem's constraints. The use of a heap allows us to maintain an optimal performance in terms of both time and space, making the solution suitable for a large number of gifts and operations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/)

---
{{< youtube _Nh-PvC1Wkg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
