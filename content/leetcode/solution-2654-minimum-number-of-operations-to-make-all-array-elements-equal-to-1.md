
+++
authors = ["grid47"]
title = "Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2654: Minimum Number of Operations to Make All Array Elements Equal to 1 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "9LOYxdctbs0"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi/9LOYxdctbs0/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int minOperations(vector<int>& nums) {


        int cnt = 0;
        
        for(int x: nums) if (x == 1) cnt++;
        if(cnt > 0) return nums.size() - cnt;
        
        int t = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int last = nums[i];
            for(int j = i + 1; j < nums.size(); j++) {
                last = __gcd(last, nums[j]);
                if(last == 1) {
                    t = min(t, j - i);
                }
            }
        }
        
        
        return t == INT_MAX? -1: t + nums.size() - 1;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the minimum number of operations required to make all elements in the given integer array `nums` equal to `1`. The allowed operation is to select any two elements and replace them with their greatest common divisor (GCD). If the array already contains `1`, no operations are needed. Otherwise, we need to perform some number of GCD operations to transform the elements into `1`. The goal is to determine the minimum number of such operations, or return `-1` if it is impossible to transform all elements to `1`.

### Approach

To solve this problem, the key idea is to consider the following two observations:

1. **Presence of `1`**: If the array already contains `1`, then no operations are needed. We can directly return the number of operations as the size of the array minus the count of `1`s, because the other elements can be reduced to `1` in one operation each.

2. **Subarrays with GCD `1`**: If the array does not contain `1`, we need to find a subarray whose GCD is equal to `1`, because the GCD operation can only reduce two numbers to their greatest common divisor. Once we find such a subarray, the minimum number of operations will be the length of the subarray minus one, since that is the number of operations needed to reduce the entire subarray to `1`.

3. **GCD Properties**: The GCD of multiple numbers is associative, meaning that the GCD of a range of numbers can be computed progressively. Therefore, we can explore each subarray and compute its GCD to see if we can find a valid subarray with a GCD of `1`. The smaller the length of this subarray, the fewer operations we will need.

### Code Breakdown

The solution can be divided into the following steps:

#### 1. **Count the Occurrence of `1` in the Array**

The first step is to count how many times the number `1` appears in the array. If the count is greater than `0`, we return `nums.size() - cnt` because that many elements are already `1`, and we do not need any more operations.

```cpp
int cnt = 0;
for(int x: nums) if (x == 1) cnt++;
if(cnt > 0) return nums.size() - cnt;
```

- We iterate through the `nums` array and count the number of `1`s.
- If there is at least one `1`, the answer is simply the number of elements that are not `1`, because each non-`1` element can be replaced by `1` in one operation.

#### 2. **Find the Subarray with GCD Equal to `1`**

If there are no `1`s in the array, we need to search for a subarray with a GCD of `1`. To do this, we use a nested loop to check every possible subarray and compute the GCD progressively.

```cpp
int t = INT_MAX;
for(int i = 0; i < nums.size(); i++) {
    int last = nums[i];
    for(int j = i + 1; j < nums.size(); j++) {
        last = __gcd(last, nums[j]);
        if(last == 1) {
            t = min(t, j - i);
        }
    }
}
```

- For each starting index `i`, we initialize `last` as `nums[i]` and compute the GCD progressively with the next elements.
- If the GCD of the current subarray is `1`, we update the minimum length of such a subarray using the formula `t = min(t, j - i)`, where `j` is the end index of the subarray.
- The inner loop computes the GCD for each subarray, and as soon as we find a subarray with a GCD of `1`, we check if it is the shortest one so far.

#### 3. **Return the Minimum Operations**

After finding the shortest subarray with a GCD of `1`, the minimum number of operations required is `t + nums.size() - 1`. This is because the length of the subarray with a GCD of `1` is `t + 1`, and it takes `t` operations to reduce the subarray to `1`. The remaining elements outside this subarray will require `nums.size() - 1 - t` operations to be reduced to `1`.

```cpp
return t == INT_MAX ? -1 : t + nums.size() - 1;
```

- If no subarray with a GCD of `1` is found (`t == INT_MAX`), it means it is impossible to reduce the array to `1`, and we return `-1`.
- Otherwise, we return the number of operations needed, which is the length of the subarray with the GCD of `1` minus one (`t`) plus the number of remaining elements in the array.

### Complexity

- **Time Complexity**:
  - The algorithm iterates over all pairs of elements in the array, which requires **O(n^2)** time, where `n` is the length of the array.
  - For each pair, it computes the GCD of two numbers, which takes **O(log(max(nums)))** time. However, since the nested loop runs at most **n^2** times, the overall time complexity is **O(n^2 log(max(nums)))**.

- **Space Complexity**:
  - The space complexity is **O(1)** since we only use a few integer variables (`cnt`, `t`, etc.) for storing intermediate results. The space used for the input array is not considered in the complexity analysis.

### Conclusion

The solution effectively computes the minimum number of operations needed to make all elements of the array equal to `1` using GCD operations. The approach utilizes a sliding window-like strategy to find subarrays with a GCD of `1` and keeps track of the smallest subarray length. While the algorithm has a time complexity of **O(n^2 log(max(nums)))**, it is an efficient way to solve the problem for moderately sized arrays. For larger arrays, optimization techniques such as more advanced GCD computation methods or dynamic programming could be considered to improve performance further.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/)

---
{{< youtube 9LOYxdctbs0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
