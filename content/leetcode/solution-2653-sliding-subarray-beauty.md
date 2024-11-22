
+++
authors = ["grid47"]
title = "Leetcode 2653: Sliding Subarray Beauty"
date = "2024-02-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2653: Sliding Subarray Beauty in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ovFs2xad0_Y"
youtube_upload_date="2023-04-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ovFs2xad0_Y/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> cnt;
    
    int no(int x) {
        int sum = 0;
        for(int i = 0; i <= 50; i++) {
            sum += cnt[i];
            if(sum >= x)
                return i - 50;
        }
        return 0;
    }
    
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        
        cnt.resize(101, 0);
        
        vector<int> ans;
        
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            cnt[nums[i] + 50]++;            
        }
        ans.push_back(no(x));

        for(int i = k; i < n; i++) {
            cnt[nums[i] + 50]++;
            cnt[nums[i - k] + 50]--;
            
            ans.push_back(no(x));
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the beauty of all subarrays of size `k` in a given array `nums`. For each subarray, the beauty is defined as the `x`-th smallest number in the subarray, where `x` is a given integer. However, there is an interesting twist: negative numbers in the array need to be treated in a way that offsets them into a positive index range. We need to compute the beauty of all subarrays of size `k` and return the result as a list of integers.

### Approach

To solve this problem, we need to efficiently compute the `x`-th smallest number in each sliding window (subarray) of size `k` within the input array `nums`. Here are the key steps involved:

1. **Sliding Window**: Since we need to compute the beauty for every contiguous subarray of size `k`, we use a sliding window technique. This means we slide over the array, adding and removing elements as the window moves to the next position.
   
2. **Efficiently Track Frequency**: Instead of sorting the subarray at each step, we can use a frequency array (`cnt`) to track how many times each number appears in the current window. This allows us to efficiently compute the `x`-th smallest number by checking the cumulative frequency of numbers.

3. **Mapping Negative Numbers**: The array can contain negative values, but the index in the frequency array needs to be positive. Therefore, we map each number to a positive index by adding 50 to it (`nums[i] + 50`). This ensures that all values, including negative ones, are mapped to non-negative indices.

4. **Efficient Query**: Once we have the frequency array updated, we need to find the `x`-th smallest number, which can be done by accumulating the frequency counts and checking when the cumulative count reaches `x`. This approach eliminates the need for sorting each subarray.

### Code Breakdown

The solution can be broken down into several key parts:

#### 1. **Helper Function: `no(int x)`**

This function computes the `x`-th smallest number in the current sliding window by iterating over the frequency array `cnt`:

```cpp
int no(int x) {
    int sum = 0;
    for(int i = 0; i <= 50; i++) {
        sum += cnt[i];
        if(sum >= x)
            return i - 50;
    }
    return 0;
}
```
- `sum` accumulates the counts of numbers as we traverse the `cnt` array.
- The loop iterates over possible indices (which represent numbers from `-50` to `50`).
- When the cumulative count reaches or exceeds `x`, it returns the corresponding number by adjusting the index (i.e., subtracting 50 to account for the offset).
- If no such number is found (although this shouldn't occur), it returns `0`.

#### 2. **Main Function: `getSubarrayBeauty(vector<int>& nums, int k, int x)`**

This function computes the beauty for each subarray of size `k` and returns the results as a vector.

```cpp
vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
    cnt.resize(101, 0);
    vector<int> ans;
    int n = nums.size();
    
    // Initialize the first window
    for(int i = 0; i < k; i++) {
        cnt[nums[i] + 50]++;            
    }
    ans.push_back(no(x));

    // Slide the window over the array
    for(int i = k; i < n; i++) {
        cnt[nums[i] + 50]++;  // Add the new element
        cnt[nums[i - k] + 50]--;  // Remove the element that goes out of the window
        
        ans.push_back(no(x));  // Find the x-th smallest number for the current window
    }
    
    return ans;
}
```

- **Step 1: Initialize Frequency Array**  
  The first step is to initialize the frequency array (`cnt`) of size `101` to store counts for the numbers from `-50` to `50` (after shifting by `50` to ensure non-negative indices). We populate the first window of size `k` by iterating through the first `k` elements of `nums`.

- **Step 2: Push Initial Beauty Value**  
  After processing the first `k` elements, we compute the beauty of the first subarray by calling the `no(x)` function. This adds the result to the `ans` vector.

- **Step 3: Slide the Window**  
  The next part of the function handles the sliding window. We start from the `k`-th element and slide the window to the right:
  - Add the new element (`nums[i]`) to the frequency array.
  - Remove the element that is no longer in the window (`nums[i - k]`).
  - After updating the frequency array, compute the beauty of the new window and add it to the result vector.

- **Step 4: Return Results**  
  Once the sliding window has processed all elements, the function returns the list of beauties for all subarrays of size `k`.

### Complexity

- **Time Complexity**:
  - **O(n)**: We iterate over all elements of the array `nums`. For each element, we perform constant-time operations such as updating the frequency array and calling the `no(x)` function.
  - The `no(x)` function has a time complexity of **O(101)**, which is constant since `101` is a fixed size (for the range `-50` to `50`).
  - Therefore, the overall time complexity is **O(n)**, where `n` is the length of the input array `nums`.

- **Space Complexity**:
  - **O(101)**: The frequency array `cnt` has a fixed size of `101`, and the output array `ans` has a size of `n - k + 1` (which is also proportional to `n`).
  - Thus, the space complexity is **O(n)** due to the space required for the result array.

### Conclusion

This solution uses the sliding window technique combined with a frequency array to efficiently compute the beauty of subarrays. By avoiding sorting and utilizing the frequency of elements, the algorithm performs well with a time complexity of **O(n)**, making it scalable for large input sizes. The approach is both time-efficient and space-efficient, with the primary focus on maintaining and updating the frequency of elements in the current window. This makes the solution optimal for the problem at hand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sliding-subarray-beauty/description/)

---
{{< youtube ovFs2xad0_Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
