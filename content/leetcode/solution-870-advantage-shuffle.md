
+++
authors = ["grid47"]
title = "Leetcode 870: Advantage Shuffle"
date = "2024-08-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 870: Advantage Shuffle in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fY310tCXS_E"
youtube_upload_date="2021-03-24"
youtube_thumbnail="https://i.ytimg.com/vi/fY310tCXS_E/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> s(begin(nums1), end(nums1));
        for ( auto i = 0; i < nums2.size(); i++) {
            auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
            nums1[i] = *p;
            s.erase(p);
        }
        return nums1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to rearrange the elements of the array `nums1` in such a way that, when compared element-wise to the array `nums2`, each element in `nums1` is greater than the corresponding element in `nums2` wherever possible. The task is to maximize the number of elements in `nums1` that are greater than the elements in `nums2` by selecting elements in an advantageous manner.

For example:
- **Input**: `nums1 = [2, 7, 11, 15]`, `nums2 = [1, 10, 4, 11]`
- **Output**: `[2, 11, 7, 15]`
  - Here, we want to maximize how many times an element from `nums1` is strictly greater than the corresponding element in `nums2`. We can see that the optimal arrangement is `[2, 11, 7, 15]`, where all values of `nums1` are greater than the corresponding elements in `nums2` (except for the second one).

### Approach

The approach for solving this problem revolves around the idea of "greedy matching," where we want to find the smallest element in `nums1` that can beat the current element in `nums2`. If we cannot beat the element in `nums2`, we simply choose the smallest element from `nums1` that hasn't been used yet.

1. **Sort the arrays**: We first sort `nums1` and `nums2` in ascending order. The goal is to try and match each element from `nums2` with the smallest element from `nums1` that is strictly greater.
   
2. **Use a multiset for efficient element selection**: A `multiset` is used to store the elements of `nums1`. The reason we use a `multiset` is that it allows us to efficiently retrieve the smallest element greater than a given value (`upper_bound` operation) and also removes elements from the set after they have been assigned.

3. **Greedy element assignment**: For each element in `nums2`, check if we can find a larger element in `nums1`. If we can, replace the corresponding element in `nums1`. If we cannot, simply use the smallest element left from `nums1`.

4. **Return the rearranged `nums1`**: After matching all elements, we return the modified `nums1` which represents the advantageous arrangement.

### Code Breakdown (Step by Step)

```cpp
vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    multiset<int> s(begin(nums1), end(nums1));  // Step 1: Convert nums1 to a multiset
    for (auto i = 0; i < nums2.size(); i++) {
        // Step 2: Try to find a number from nums1 that is greater than nums2[i]
        auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
        nums1[i] = *p;  // Step 3: Assign the selected number from nums1 to nums2's current position
        s.erase(p);  // Step 4: Remove the used element from the multiset
    }
    return nums1;  // Step 5: Return the rearranged nums1
}
```

#### Step 1: Convert `nums1` to a `multiset`

```cpp
multiset<int> s(begin(nums1), end(nums1));
```
- We convert `nums1` into a `multiset`. A multiset is a data structure that stores elements in a sorted order and allows us to efficiently search for elements greater than a given value.
- The multiset `s` holds all the elements of `nums1`. We can access the smallest element using `s.begin()` and the largest element using `s.rbegin()`.

#### Step 2: Greedily assign elements to `nums1`

```cpp
auto p = *s.rbegin() <= nums2[i] ? s.begin() : s.upper_bound(nums2[i]);
```
- For each element `nums2[i]`, we attempt to find the smallest element from `nums1` that is greater than `nums2[i]`.
- If the largest element in `nums1` (i.e., `*s.rbegin()`) is not greater than `nums2[i]`, we take the smallest element (`s.begin()`).
- Otherwise, we use the `upper_bound` function to find the first element in `nums1` that is strictly greater than `nums2[i]`.

#### Step 3: Assign the selected element to the result

```cpp
nums1[i] = *p;
```
- Once we have found an element from `nums1` that is greater than `nums2[i]` (or the smallest element if no larger one exists), we assign it to the corresponding position in `nums1`.

#### Step 4: Remove the used element from the `multiset`

```cpp
s.erase(p);
```
- After using the element, we remove it from the multiset to prevent reusing it in the subsequent steps.

#### Step 5: Return the final result

```cpp
return nums1;
```
- After all elements in `nums2` have been processed, we return the rearranged `nums1` array.

### Complexity

#### Time Complexity:

- **Sorting `nums1`**: Sorting the array `nums1` takes `O(n log n)`, where `n` is the size of `nums1`.
- **Using `upper_bound`**: For each element in `nums2`, we perform an `upper_bound` operation, which takes `O(log n)` because the `multiset` is sorted.
- **Looping through `nums2`**: We loop through each element of `nums2`, and for each element, we perform the `upper_bound` operation and an `erase` operation, both of which are `O(log n)`.

Thus, the total time complexity is `O(n log n)` due to sorting and the log operations in the loop.

#### Space Complexity:

- We use a `multiset` to store the elements of `nums1`, which takes `O(n)` space.
- Therefore, the overall space complexity is `O(n)`.

### Conclusion

This solution effectively rearranges `nums1` to maximize the number of elements that are greater than the corresponding elements in `nums2`. By utilizing a `multiset`, we can efficiently manage and select elements to achieve the desired result. The greedy approach ensures that we always pick the smallest possible element from `nums1` that can beat the current element in `nums2`, which optimizes the number of "wins" in the rearranged array.

Key Points:
- **Greedy Strategy**: We aim to maximize the advantage by always selecting the smallest available element that can beat the current element from `nums2`.
- **Multiset Usage**: The use of a multiset allows efficient searching and removing elements from `nums1`.
- **Optimal Complexity**: With a time complexity of `O(n log n)` and space complexity of `O(n)`, the solution is efficient enough for large inputs.

This approach is an excellent demonstration of using efficient data structures (like `multiset`) to solve optimization problems in a greedy manner.

[`Link to LeetCode Lab`](https://leetcode.com/problems/advantage-shuffle/description/)

---
{{< youtube fY310tCXS_E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
