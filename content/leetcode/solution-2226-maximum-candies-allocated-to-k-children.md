
+++
authors = ["grid47"]
title = "Leetcode 2226: Maximum Candies Allocated to K Children"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2226: Maximum Candies Allocated to K Children in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Y2V4hLvjn10"
youtube_upload_date="2022-04-03"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Y2V4hLvjn10/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(vector<int>& candies, long long kids, int per) {
        long long cnt = 0;
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] < per) continue;
            
            int tmp = candies[i];
            cnt+= tmp/per;
        }
        
        return cnt >= kids;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum = accumulate(candies.begin(), candies.end(), 0L);
        if(sum < k) return 0;
        
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(can(candies, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement
You are given an array `candies` where each element represents the number of candies in a box. You also have an integer `k`, representing the number of kids. The task is to determine the maximum number of candies that can be evenly distributed among all `k` kids. Each kid should receive the same number of candies, and the number of candies given to each kid should be as large as possible. If it's not possible to distribute the candies such that each kid gets at least one candy, return `0`.

### Approach
To solve this problem, we need to determine the maximum possible number of candies each child can receive. The solution involves using a binary search strategy over the possible values of the maximum number of candies each kid can receive. The main idea is:
1. We need to check if it's possible to distribute `x` candies to each of the `k` kids, where `x` is a candidate number of candies that could be given to each child.
2. To check this, we iterate over the array of candies and count how many kids can be given at least `x` candies. If the total number of such kids is greater than or equal to `k`, then it's feasible to distribute `x` candies to each kid.
3. Using binary search, we progressively narrow down the range of possible values for `x` to find the maximum possible value that allows a valid distribution.

### Code Breakdown (Step by Step)

1. **Helper Function: `can`**
   ```cpp
   bool can(vector<int>& candies, long long kids, int per) {
       long long cnt = 0;
       for(int i = 0; i < candies.size(); i++) {
           if(candies[i] < per) continue;
           int tmp = candies[i];
           cnt += tmp / per;
       }
       return cnt >= kids;
   }
   ```
   - The function `can` checks if it's possible to distribute `per` candies to each of the `kids` (i.e., check if it's feasible to distribute `per` candies to `k` kids).
   - It iterates over the `candies` array. For each candy box, it calculates how many kids can receive `per` candies from that box (using integer division).
   - It accumulates the total number of kids who can receive at least `per` candies, and if this number is greater than or equal to `k`, the function returns `true`.

2. **Main Function: `maximumCandies`**
   ```cpp
   int maximumCandies(vector<int>& candies, long long k) {
       long long sum = accumulate(candies.begin(), candies.end(), 0L);
       if(sum < k) return 0;
   ```
   - First, it calculates the total number of candies using `accumulate` from the standard library. If the total number of candies is less than `k` (i.e., if there aren't enough candies to give at least one candy to each child), it returns `0`.

3. **Binary Search Setup**
   ```cpp
       int l = 1, r = *max_element(candies.begin(), candies.end());
       int ans = 0;
   ```
   - The binary search is set up with the left pointer `l` starting at `1` (because we can't give fewer than 1 candy to a kid), and the right pointer `r` set to the maximum number of candies in any single box (since that's the upper bound for the number of candies each kid can receive).

4. **Binary Search Logic**
   ```cpp
       while(l <= r) {
           int mid = l + (r - l + 1) / 2;
           if(can(candies, k, mid)) {
               ans = mid;
               l = mid + 1;
           } else {
               r = mid - 1;
           }
       }
       return ans;
   }
   ```
   - The binary search proceeds by calculating the middle point `mid` between `l` and `r`.
   - If it's possible to distribute `mid` candies to each of the `k` kids (checked by calling the `can` function), then we try to see if a larger number of candies can also be distributed by setting `l = mid + 1` and updating `ans` to `mid` (because `mid` is a valid solution).
   - If it's not possible, we search for smaller values by setting `r = mid - 1`.
   - The loop continues until `l` exceeds `r`, and the largest valid value of `mid` is stored in `ans`.

5. **Return Result**
   ```cpp
       return ans;
   ```
   - After the binary search finishes, the value of `ans` holds the maximum number of candies each kid can receive. This value is returned.

### Complexity

- **Time Complexity:**
  - **Binary Search:** The binary search runs in O(log(max(candies))) time, where `max(candies)` is the largest number in the `candies` array.
  - **Counting Feasible Distribution:** The `can` function loops through all `candies` once to check if a valid distribution is possible for a given `mid` value. This takes O(n) time, where `n` is the length of the `candies` array.
  - Therefore, the overall time complexity is O(n * log(max(candies))).

- **Space Complexity:**
  - The space complexity is O(1) since the algorithm only uses a constant amount of extra space, excluding the input and output.

### Conclusion
This solution efficiently solves the problem of distributing candies to kids in a way that maximizes the number of candies each kid receives, using binary search to optimize the process. By leveraging the helper function `can` to check the feasibility of each potential number of candies a kid can receive, the algorithm narrows down the solution space to find the maximum possible number of candies. The solution's time complexity, which is O(n * log(max(candies))), is optimal for large inputs, making it suitable for scenarios where the number of candy boxes and kids is large. The space complexity remains O(1), ensuring efficient memory usage.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/)

---
{{< youtube Y2V4hLvjn10 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
