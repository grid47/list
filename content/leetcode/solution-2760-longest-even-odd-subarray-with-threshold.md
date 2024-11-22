
+++
authors = ["grid47"]
title = "Leetcode 2760: Longest Even Odd Subarray With Threshold"
date = "2024-02-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2760: Longest Even Odd Subarray With Threshold in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "_XNaJUXSh04"
youtube_upload_date="2023-07-02"
youtube_thumbnail="https://i.ytimg.com/vi/_XNaJUXSh04/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int longestAlternatingSubarray(vector<int>& n, int threshold) {
    int res = 0;
    for (int l = 0, cnt = 0; l < n.size(); ++l) {
        if (n[l] <= threshold)
            cnt = cnt == 0 ?
                n[l] % 2 == 0 :
                n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
        else
            cnt = 0;
        res = max(res, cnt);
    }
    return res;
  }
};
{{< /highlight >}}
---

### Problem Statement

We are given an array of integers `n` and a threshold value. The task is to find the length of the longest alternating subarray where each element in the subarray is less than or equal to the given threshold. An alternating subarray means that the elements of the subarray alternate between even and odd numbers. We need to return the length of the longest alternating subarray found.

### Approach

To solve this problem, we will utilize a sliding window technique to traverse the array and build potential alternating subarrays while keeping track of their length. The alternating condition means that we must ensure adjacent numbers have different parity, i.e., one is even and the other is odd.

The problem is broken down into the following steps:

1. **Iterate Over the Array**:
   - We will iterate through each element in the array `n`.
   - For each element, we check if it is less than or equal to the `threshold`. If it is greater than the threshold, we reset the length of the current alternating subarray.

2. **Check for Alternating Parity**:
   - If the current element satisfies the threshold condition, we check whether it alternates with the previous element in terms of parity (even or odd). 
   - If it alternates, we continue the current subarray and increase the count.
   - If it does not alternate, we start a new alternating subarray with the current element.

3. **Keep Track of the Longest Subarray**:
   - We will keep track of the longest alternating subarray encountered during the iteration and update the result accordingly.

4. **Return the Result**:
   - Once the iteration is complete, the longest length stored will be our result.

### Code Breakdown (Step by Step)

#### 1. **Initialization**

```cpp
int res = 0;
```

- `res`: This variable is used to store the length of the longest alternating subarray found during the iteration.

#### 2. **Sliding Window and Loop through the Array**

```cpp
for (int l = 0, cnt = 0; l < n.size(); ++l) {
```

- We start iterating through the array using the variable `l` (loop index).
- `cnt` is used to store the length of the current alternating subarray.
- Initially, `cnt` is set to 0, meaning no alternating subarray has been started yet.

#### 3. **Threshold Check and Parity Conditions**

```cpp
if (n[l] <= threshold)
    cnt = cnt == 0 ?
        n[l] % 2 == 0 :
        n[l] % 2 == n[l - 1] % 2 ? n[l] % 2 == 0 : cnt + 1;
else
    cnt = 0;
```

- **If the current element is less than or equal to the threshold (`n[l] <= threshold`)**:
    - If `cnt == 0`, this means we are starting a new alternating subarray, so we check if the current element is even (`n[l] % 2 == 0`).
    - If `cnt != 0`, it means we have an ongoing alternating subarray. We check whether the current element alternates with the previous one by comparing their parity (`n[l] % 2 == n[l - 1] % 2`). If they have the same parity, the subarray ends here, and we do not continue. Otherwise, we continue the alternating subarray and increase `cnt` by 1.
    - **If the current element is greater than the threshold**, we reset `cnt = 0` since the subarray cannot include this element.

#### 4. **Update the Longest Length**

```cpp
res = max(res, cnt);
```

- After checking the current element and updating `cnt`, we update `res` to store the maximum length of any alternating subarray encountered so far.

#### 5. **Return the Final Result**

```cpp
return res;
```

- After the loop finishes, we return `res`, which holds the length of the longest alternating subarray found.

### Complexity Analysis

#### Time Complexity

1. **Single Pass through the Array**:
   - The algorithm iterates through the array `n` exactly once.
   - The time complexity for this loop is \( O(n) \), where `n` is the size of the input array.

2. **Constant Time Operations**:
   - Each operation inside the loop (comparison, modulus, assignment) takes constant time, i.e., \( O(1) \).

Thus, the overall time complexity is \( O(n) \), where `n` is the length of the input array `n`.

#### Space Complexity

1. **Constant Space**:
   - The solution uses only a few integer variables (`res`, `cnt`, and `l`), which take constant space, \( O(1) \).

Thus, the space complexity is \( O(1) \), as we are not using any additional data structures that depend on the input size.

### Conclusion

This solution efficiently calculates the longest alternating subarray with elements less than or equal to a given threshold. By using a sliding window approach and tracking the length of alternating subarrays, the algorithm ensures that we process each element of the array in constant time. With a time complexity of \( O(n) \) and a space complexity of \( O(1) \), this solution is highly efficient and works well for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/)

---
{{< youtube _XNaJUXSh04 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
