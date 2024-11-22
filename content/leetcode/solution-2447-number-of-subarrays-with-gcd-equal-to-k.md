
+++
authors = ["grid47"]
title = "Leetcode 2447: Number of Subarrays With GCD Equal to K"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2447: Number of Subarrays With GCD Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QEvLvINq730"
youtube_upload_date="2022-10-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QEvLvINq730/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int subarrayGCD(vector<int>& nums, int k) {        
        int cnt = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n && nums[j] % k == 0; j++) {
                nums[i] = __gcd(nums[i], nums[j]);
                cnt += (nums[i] == k);
            }
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array of integers `nums` and an integer `k`, the problem asks to find the number of contiguous subarrays of `nums` such that the greatest common divisor (GCD) of the elements in the subarray is equal to `k`. 

In other words, for each contiguous subarray of `nums`, we need to check if the GCD of its elements is exactly `k`, and count how many such subarrays exist.

### Approach

The key challenge in this problem is calculating the GCD of elements in subarrays efficiently and comparing it with `k`. A brute-force approach would involve calculating the GCD for every possible subarray, which could be computationally expensive. To optimize the process, we can take advantage of the properties of the GCD:

1. **GCD Properties**:
   - The GCD of any two numbers divides both numbers, so for a subarray to have a GCD equal to `k`, every element in that subarray must be divisible by `k`.
   - Once we know that all elements of a subarray are divisible by `k`, we can divide each element of the subarray by `k` and check if the GCD of the resulting numbers equals `1`. This is equivalent to checking if the GCD of the original elements is equal to `k`.

2. **Iterative Approach**:
   - Start by iterating over all possible starting points of subarrays (`i`).
   - For each starting point `i`, iterate over all subarrays ending at position `j` where the elements are divisible by `k`.
   - For each such subarray, compute the GCD of the elements and check if it equals `k`.
   - If the GCD of the subarray equals `k`, increment the count.

3. **Efficient GCD Calculation**:
   - The GCD of two numbers can be computed efficiently using the Euclidean algorithm, which is implemented by the function `__gcd` in C++.
   - To calculate the GCD of a subarray efficiently, we can iteratively update the GCD of the current subarray by including one new element at a time.

4. **Breaking Condition**:
   - If the GCD of a subarray becomes less than `k` at any point, we can break the inner loop early since adding more elements will not increase the GCD.

### Code Breakdown (Step by Step)

```cpp
int subarrayGCD(vector<int>& nums, int k) {        
    int cnt = 0, n = nums.size();
    
    // Outer loop for starting index of the subarray
    for(int i = 0; i < n; i++) {
        // Inner loop for ending index of the subarray
        for(int j = i; j < n && nums[j] % k == 0; j++) {
            // Update the GCD of the current subarray from nums[i] to nums[j]
            nums[i] = __gcd(nums[i], nums[j]);
            
            // If GCD equals k, increment the counter
            cnt += (nums[i] == k);
        }
    }
    return cnt;
}
```

#### Step 1: Initialization
```cpp
int cnt = 0, n = nums.size();
```
- `cnt`: This variable keeps track of the number of subarrays whose GCD is equal to `k`.
- `n`: The size of the `nums` array.

#### Step 2: Outer Loop for Subarray Starting Index
```cpp
for(int i = 0; i < n; i++) {
```
- This loop iterates over all possible starting indices `i` for subarrays.
- For each starting index `i`, we will explore all subarrays starting at `i` and ending at `j` (where `i <= j < n`).

#### Step 3: Inner Loop for Subarray Ending Index
```cpp
for(int j = i; j < n && nums[j] % k == 0; j++) {
```
- This loop iterates over all possible ending indices `j` of subarrays starting at index `i`.
- The condition `nums[j] % k == 0` ensures that we only consider elements that are divisible by `k`. If an element is not divisible by `k`, we can skip it since it will never contribute to a valid subarray with a GCD of `k`.

#### Step 4: Update GCD for the Current Subarray
```cpp
nums[i] = __gcd(nums[i], nums[j]);
```
- The `__gcd(nums[i], nums[j])` function computes the GCD of the current subarray from index `i` to `j`.
- The value of `nums[i]` is updated to the GCD of the current subarray as we iterate over `j`.
  
#### Step 5: Check if the GCD Equals `k`
```cpp
cnt += (nums[i] == k);
```
- After updating the GCD for the current subarray, we check if the GCD is equal to `k`.
- If it is, we increment the counter `cnt` to keep track of the number of valid subarrays.

#### Step 6: Return the Result
```cpp
return cnt;
```
- After processing all possible subarrays, we return the total count of subarrays where the GCD equals `k`.

### Complexity

#### Time Complexity

The time complexity of the solution is **O(n^2 log m)**, where `n` is the size of the input array `nums`, and `m` is the maximum value of an element in the array. 

1. **Outer Loop**: The outer loop runs `n` times, where `n` is the size of the array.
2. **Inner Loop**: The inner loop runs for each possible subarray starting at `i`. In the worst case, this loop will run up to `n` times.
3. **GCD Calculation**: The GCD of two numbers is calculated using the Euclidean algorithm, which takes **O(log m)** time where `m` is the value of the numbers. Since we update the GCD for each subarray, the GCD calculation is performed multiple times.
   
Thus, the overall time complexity is **O(n^2 log m)**, where `n` is the length of the array and `m` is the magnitude of the values in the array.

#### Space Complexity

The space complexity is **O(1)**, as we are only using a few variables to store intermediate results like `cnt`, and no extra space is used beyond the input array.

### Conclusion

This solution solves the problem of counting subarrays with a GCD equal to `k` by iterating through all possible subarrays, calculating the GCD incrementally, and checking if it equals `k`. The approach is straightforward but requires careful handling of GCD calculations and divisibility conditions to ensure efficient processing of the subarrays.

- **Time Complexity**: **O(n^2 log m)**, where `n` is the length of the array and `m` is the value of the numbers.
- **Space Complexity**: **O(1)**, as no additional space is used besides the input array.

This approach guarantees correctness and handles small to moderate input sizes efficiently, though it may be suboptimal for very large arrays or large numbers.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/)

---
{{< youtube QEvLvINq730 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
