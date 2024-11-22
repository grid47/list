
+++
authors = ["grid47"]
title = "Leetcode 2517: Maximum Tastiness of Candy Basket"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2517: Maximum Tastiness of Candy Basket in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mEZRRvBqSB0"
youtube_upload_date="2022-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mEZRRvBqSB0/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(vector<int> nums, int mid, int k) {
        int cnt = 1, n = nums.size();
        int i = 1;
        int prv = nums[0];
        while(i < n) {
            if(nums[i] - prv >= mid) {
                cnt++;
                prv = nums[i];
            }
            if(cnt >= k) return true;
            i++;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = r;
        
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, mid, k) << "\n";
            if(can(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
            
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the maximum "tastiness" of a set of `k` distinct items selected from a list of integers representing some measure of tastiness. The tastiness is defined as the minimum difference between the items in the set, and we want to maximize this minimum difference.

In simpler terms, we are given an array of integers `nums` and a number `k`. We need to select `k` elements from `nums` such that the minimum difference between any two selected elements is as large as possible. The goal is to find this maximum possible minimum difference.

### Approach

To solve this problem, we can apply a **binary search** technique to optimize the search for the largest minimum difference between selected elements. The key idea is to test different values for the minimum difference and check whether it's possible to select `k` elements that satisfy that difference.

#### Step-by-Step Explanation

We can break down the approach into two major parts:

1. **Binary Search for Maximum Minimum Difference**:
   - The idea is to maximize the minimum difference between the selected elements. 
   - The possible minimum differences can range from `0` (when all elements are the same) to `nums[n-1] - nums[0]` (the difference between the smallest and largest elements in the sorted array).
   - We perform a binary search between these two bounds (`0` and `nums[n-1] - nums[0]`), checking for each mid-point if it is possible to select `k` elements with at least that much difference between any two selected elements.

2. **Greedy Check for a Given Minimum Difference**:
   - For each value of `mid` (the current minimum difference being tested), we use a greedy approach to check if we can select `k` elements that satisfy this condition. We start by selecting the first element and then greedily select the next element that is at least `mid` units away from the previously selected element.
   - If we can select `k` elements this way, it means the current `mid` value is feasible, and we can attempt to increase it. Otherwise, we try smaller values for `mid`.

### Code Breakdown

#### Step 1: Binary Search Setup
```cpp
sort(nums.begin(), nums.end());
int n = nums.size();
int l = 0, r = nums[n - 1] - nums[0];
int ans = r;
```
- **Sorting**: The first step is to sort the array `nums`. Sorting ensures that we can efficiently check the difference between consecutive elements. After sorting, the largest possible minimum difference will be between the smallest and largest element (`nums[n-1] - nums[0]`), so we start with `l = 0` and `r = nums[n - 1] - nums[0]` as the binary search bounds.
- **Binary Search**: We initialize `l` and `r` to represent the lower and upper bounds of the search space for the minimum difference. We also initialize `ans` to hold the maximum minimum difference found during the search.

#### Step 2: Binary Search Loop
```cpp
while(l <= r) {
    int mid = l + (r - l + 1) / 2;
    if(can(nums, mid, k)) {
        ans = mid;
        l = mid + 1;
    } else {
        r = mid - 1;
    }
}
```
- **Midpoint Calculation**: In each iteration of the binary search, we calculate the midpoint `mid` between `l` and `r`. This `mid` represents the minimum difference we are testing.
- **Greedy Check**: We then call the `can` function to check if it's possible to select `k` elements such that the minimum difference between any two selected elements is at least `mid`.
- **Adjust Search Bounds**: 
  - If `can(nums, mid, k)` returns `true`, it means we can select `k` elements with at least `mid` difference, so we try to increase `mid` by setting `l = mid + 1`.
  - If `can(nums, mid, k)` returns `false`, it means we cannot select `k` elements with the current `mid`, so we try smaller values by setting `r = mid - 1`.

#### Step 3: Greedy Function (Checking Feasibility of a Given Difference)
```cpp
bool can(vector<int> nums, int mid, int k) {
    int cnt = 1, n = nums.size();
    int i = 1;
    int prv = nums[0];
    while(i < n) {
        if(nums[i] - prv >= mid) {
            cnt++;
            prv = nums[i];
        }
        if(cnt >= k) return true;
        i++;
    }
    return false;
}
```
- **Greedy Selection**: This function checks if it's possible to select `k` elements such that the minimum difference between any two selected elements is at least `mid`.
  - We start by selecting the first element (`prv = nums[0]`).
  - Then, for each subsequent element, we check if it satisfies the condition `nums[i] - prv >= mid`. If it does, we select this element, update `prv`, and increment the count (`cnt`).
  - If at any point `cnt` reaches `k`, we return `true`, indicating that it's possible to select `k` elements with at least `mid` difference.
  - If we exhaust the list and can't select `k` elements, we return `false`.

#### Step 4: Final Result
```cpp
return ans;
```
- Once the binary search completes, the value of `ans` will hold the maximum possible minimum difference between the selected elements.

### Example Walkthrough

#### Example 1:
**Input**:
```cpp
vector<int> nums = {1, 3, 6, 19, 20};
int k = 2;
```
- After sorting `nums`, we get `[1, 3, 6, 19, 20]`.
- We perform binary search to find the maximum possible minimum difference. 
  - Start with `l = 0` and `r = 19`.
  - After performing the binary search, the maximum minimum difference is found to be `17`.

**Output**:
```cpp
17
```

#### Example 2:
**Input**:
```cpp
vector<int> nums = {5, 10, 15, 20};
int k = 3;
```
- After sorting `nums`, we get `[5, 10, 15, 20]`.
- The binary search proceeds, and the largest possible minimum difference for `k = 3` is found to be `5`.

**Output**:
```cpp
5
```

### Time Complexity

1. **Sorting the array**: Sorting the array `nums` takes \(O(n \log n)\), where `n` is the size of the array.
2. **Binary Search**: The binary search loop runs in \(O(\log(\text{max} - \text{min}))\), where `max` and `min` are the largest and smallest elements in `nums`. This is typically \(O(\log(\text{max}))\), where `max` is the range of values in the array.
3. **Greedy Check**: For each binary search step, the `can` function runs in \(O(n)\), as it iterates through the array once.

Thus, the overall time complexity is \(O(n \log n + n \log(\text{max}))\), which simplifies to \(O(n \log n)\) in the worst case.

### Space Complexity

The space complexity is \(O(n)\) due to the storage used for sorting the array and performing the binary search.

### Conclusion

This approach efficiently solves the problem of selecting `k` elements with the largest possible minimum difference by combining binary search and a greedy selection strategy. The time complexity of \(O(n \log n)\) makes this approach scalable for large inputs, while the space complexity of \(O(n)\) ensures that the solution is memory-efficient.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/)

---
{{< youtube mEZRRvBqSB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
