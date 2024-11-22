
+++
authors = ["grid47"]
title = "Leetcode 907: Sum of Subarray Minimums"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 907: Sum of Subarray Minimums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aX1F2-DrBkQ"
youtube_upload_date="2024-01-20"
youtube_thumbnail="https://i.ytimg.com/vi/aX1F2-DrBkQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        stack<pair<int, int>> stk_p;

        int n = nums.size();
        vector<int> left(n), right(n);
        // prefill, algo may not catch everything
        for(int i = 0; i < n; i++)  left[i] = i + 1;
        for(int i = 0; i < n; i++) right[i] = n - i;

        for(int i = 0; i < n; i++) {
            while(!stk_p.empty() && stk_p.top().first > nums[i]) {
                auto x = stk_p.top();
                stk_p.pop();
                right[x.second] = i - x.second;
            }
            left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
            stk_p.push({ nums[i], i });
        }
        
        long long ans = 0;
        int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; i++)
        ans = (ans + (long) nums[i] * (long) left[i] * (long) right[i]) % mod;
        return (int) ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to calculate the sum of the minimum values of all **subarrays** of a given array of integers. The array can contain both positive and negative numbers, and we need to compute the sum of the minimum values of all possible subarrays modulo \(10^9 + 7\).

### Approach

To solve this problem efficiently, a brute force approach where we generate all possible subarrays and compute their minimums would be too slow, especially for large arrays. Instead, we can use an efficient approach based on **monotonic stacks** and dynamic programming principles to reduce the time complexity.

#### **Key Insight:**
For each element in the array, we need to determine how many subarrays have that element as their **minimum**. This can be achieved by:
1. Using a **monotonic stack** to track the **previous smaller element** and the **next smaller element** for each element in the array.
2. Using the distances to compute how many subarrays have each element as the minimum.
3. Once we have this information, we can easily compute the sum of the minimum values for all subarrays by multiplying each element by the number of subarrays it serves as the minimum in.

#### **Steps:**
1. **Calculate `left[]` and `right[]` arrays**:
   - `left[i]`: The number of subarrays that end at index `i` where `nums[i]` is the minimum element.
   - `right[i]`: The number of subarrays that start at index `i` where `nums[i]` is the minimum element.
   
2. **Use a monotonic stack** to compute `left[]` and `right[]`:
   - Traverse the array to fill the `left[]` and `right[]` arrays using a stack to efficiently find the nearest smaller element on the left and right.

3. **Sum the contributions** of each element:
   - Once we have the `left[]` and `right[]` values, for each element `nums[i]`, its contribution to the total sum is \( \text{nums[i]} \times \text{left[i]} \times \text{right[i]} \).

4. **Take the modulo \(10^9 + 7\)** to avoid overflow and ensure that the result fits within the problem's constraints.

### Code Breakdown (Step by Step)

#### **Class Definition**

```cpp
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        stack<pair<int, int>> stk_p;
        int n = nums.size();
        vector<int> left(n), right(n);
```

- `stk_p`: A stack used to store pairs of the form `(value, index)`, which helps in calculating the left and right boundaries for each element.
- `n`: The size of the `nums` array.
- `left` and `right`: Arrays that will store the number of subarrays where `nums[i]` is the minimum for the left and right boundaries, respectively.

#### **Prefill the `left[]` and `right[]` Arrays**

```cpp
        for(int i = 0; i < n; i++)  left[i] = i + 1;
        for(int i = 0; i < n; i++) right[i] = n - i;
```
- Initially, we prefill the `left[]` array with `i + 1`, meaning that each element can at least form a subarray by itself.
- Similarly, we prefill the `right[]` array with `n - i`, meaning that each element can at least form a subarray ending at the last element.

#### **Fill `left[]` and `right[]` Using the Monotonic Stack**

```cpp
        for(int i = 0; i < n; i++) {
            while(!stk_p.empty() && stk_p.top().first > nums[i]) {
                auto x = stk_p.top();
                stk_p.pop();
                right[x.second] = i - x.second;
            }
            left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
            stk_p.push({ nums[i], i });
        }
```

- For each element in `nums` (at index `i`), we:
  - **Pop from the stack** while the top element of the stack is greater than the current element (`nums[i]`). This helps us find the nearest smaller element to the right and calculate the number of subarrays where the element at the popped index is the minimum. We then update `right[]` for the popped element.
  - **Update `left[i]`**: If the stack is empty, it means there is no smaller element on the left, and hence `left[i]` is simply `i + 1`. If there is a smaller element on the left (represented by the top of the stack), `left[i]` is calculated as `i - stk_p.top().second`, which gives the number of subarrays ending at `i` where `nums[i]` is the minimum.
  - Finally, push the current element `(nums[i], i)` onto the stack.

#### **Sum the Contributions**

```cpp
        long long ans = 0;
        int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; i++)
            ans = (ans + (long) nums[i] * (long) left[i] * (long) right[i]) % mod;
```

- We compute the total sum by iterating over each element `nums[i]`:
  - The total contribution of `nums[i]` is its value multiplied by `left[i]` and `right[i]`, which represent the number of subarrays where `nums[i]` is the minimum.
  - We take the modulo \(10^9 + 7\) at each step to avoid overflow and adhere to the problem's constraints.

#### **Return the Result**

```cpp
        return (int) ans;
    }
};
```
- Finally, we return the result as an integer.

### Complexity

#### **Time Complexity**

- **O(n)**: We iterate through the array once to compute `left[]` and `right[]` using the stack, and then iterate through the array again to compute the final sum. The stack operations (push and pop) each take constant time, making the overall time complexity linear with respect to the size of the input array `n`.

#### **Space Complexity**

- **O(n)**: The space complexity is dominated by the stack and the arrays `left[]` and `right[]`, which both require linear space relative to the size of the input array `n`.

### Conclusion

This solution efficiently computes the sum of the minimum values of all subarrays using the monotonic stack technique. By leveraging the stack to track the nearest smaller elements to the left and right, we can compute the number of subarrays where each element serves as the minimum in linear time. This approach is highly efficient and scales well with large input sizes, making it suitable for problems with large arrays. The modulo operation ensures that the result remains within the specified limits, and the use of dynamic programming principles ensures that we avoid a brute force solution that would be too slow.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-subarray-minimums/description/)

---
{{< youtube aX1F2-DrBkQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
