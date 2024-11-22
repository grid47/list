
+++
authors = ["grid47"]
title = "Leetcode 2560: House Robber IV"
date = "2024-02-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2560: House Robber IV in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BJWTAclDvEA"
youtube_upload_date="2023-02-05"
youtube_thumbnail="https://i.ytimg.com/vi/BJWTAclDvEA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n;
    vector<int> nums;
    vector<vector<vector<map<int, int>>>> memo;
    
    int dp(int idx, int k, bool prv, int mx) {
        if(idx == n) return (k > 0)? INT_MAX: mx;
        
        if(memo[idx][k][prv].count(mx)) return memo[idx][k][prv][mx];
        
        int ans = dp(idx + 1, k, false, mx);
        
        if(!prv) {
            int tmp = dp(idx + 1, k - 1 < 1? 0: k-1, true, mx == 0? nums[idx]: (mx > nums[idx]) ? mx: nums[idx]);
            ans = min(ans, tmp);            
        }

        return memo[idx][k][prv][mx] = ans;
    }
    
    int minCap(vector<int>& nums, int k) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, vector<vector<map<int, int>>>(n + 1, vector<map<int,int>>(2)));
        return dp(0, k, false, 0);
    }
    
    bool can(vector<int> &nums, int k, int mid) {
        int n = nums.size();
        int cnt = 0, take = true;
        for(int i = 0; i < n; i += 1) {
            if(nums[i] <= mid && take) {
                take = false;
                cnt++;
            } else if(!take) {
                take = true;
            }
            if(cnt >= k) return true;
        }
        cnt = 0, take = true;
        for(int i = 1; i < n; i += 2) {
            if(nums[i] <= mid && take) {
                take = false;
                cnt++;
            } else if(!take) {
                take = true;
            }
            if(cnt >= k) return true;
        }        
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int l = mn, r = mx, ans = mx;
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, k, mid) << "\n";
            if(can(nums, k, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

We are tasked with finding the minimum capability of a number `x` such that we can select `k` non-adjacent numbers from a list of integers `nums`. The selected numbers should be less than or equal to `x`. 

The goal is to minimize the largest number in the selected subsequence, and `x` must be chosen such that there exists a way to select exactly `k` non-adjacent numbers. 

In simple terms, the problem asks us to determine the minimum maximum number `x` such that we can select `k` non-adjacent numbers from the list where each selected number is less than or equal to `x`.

### Approach

The problem is a combination of **dynamic programming** and **binary search**. The main idea is to use binary search to find the minimum maximum number `x`, and for each potential value of `x`, we check if it's possible to select `k` non-adjacent numbers less than or equal to `x`. Here's how we approach the solution:

1. **Binary Search**:
   - First, we perform a binary search over the range of possible values of `x`, which are the values in `nums`.
   - The search will be between the minimum value (`mn`) and the maximum value (`mx`) in the array `nums`. For each middle value (`mid`), we check if it's possible to select `k` non-adjacent numbers all less than or equal to `mid`.

2. **Checking Feasibility**:
   - For each `mid` value during the binary search, we check if it's possible to select `k` non-adjacent numbers from `nums` such that all the selected numbers are less than or equal to `mid`. This check is done by iterating through the array and greedily selecting the numbers.
   
3. **Memoization and Dynamic Programming**:
   - We use memoization with dynamic programming to avoid redundant calculations, especially when trying to find the minimal number for the selected subsequence.
   
By combining these two approaches (binary search and dynamic programming), we can efficiently find the solution.

### Code Breakdown

#### Step 1: Initialization and Binary Search Setup

```cpp
int mx = *max_element(nums.begin(), nums.end());
int mn = *min_element(nums.begin(), nums.end());
int l = mn, r = mx, ans = mx;
```

- **mx**: The maximum element in the list `nums`, which serves as the upper bound for our binary search.
- **mn**: The minimum element in `nums`, which is the lower bound for our binary search.
- **l** and **r** represent the left and right bounds of our binary search range.
- **ans** keeps track of the optimal value of `x`, which will store the minimum possible capability.

#### Step 2: Binary Search Loop

```cpp
while(l <= r) {
    int mid = l + (r - l + 1) / 2;
    if(can(nums, k, mid)) {
        ans = mid;
        r = mid - 1;
    } else l = mid + 1;
}
```

- In each iteration of the binary search loop, we calculate the middle point `mid`.
- We then call the `can` function to check if it's possible to select `k` non-adjacent numbers all less than or equal to `mid`.
- If it's possible, we update `ans` with the current `mid` and continue to search in the lower half (`r = mid - 1`).
- If it's not possible, we search in the upper half (`l = mid + 1`).

#### Step 3: Feasibility Check Function (`can`)

```cpp
bool can(vector<int> &nums, int k, int mid) {
    int n = nums.size();
    int cnt = 0, take = true;
    for(int i = 0; i < n; i++) {
        if(nums[i] <= mid && take) {
            take = false;
            cnt++;
        } else if(!take) {
            take = true;
        }
        if(cnt >= k) return true;
    }
    cnt = 0, take = true;
    for(int i = 1; i < n; i += 2) {
        if(nums[i] <= mid && take) {
            take = false;
            cnt++;
        } else if(!take) {
            take = true;
        }
        if(cnt >= k) return true;
    }        
    return false;
}
```

- **Feasibility Check**: This function checks whether we can select `k` non-adjacent numbers from `nums` where each selected number is less than or equal to `mid`.
- We use two passes through the array `nums` to ensure that the selected numbers are non-adjacent:
  1. The first pass starts from index 0 and selects every alternate number.
  2. The second pass starts from index 1 and selects every alternate number.
- The function returns `true` if it's possible to select `k` non-adjacent numbers under these constraints; otherwise, it returns `false`.

#### Step 4: Dynamic Programming and Memoization (Optional)

```cpp
vector<int> nums;
vector<vector<vector<map<int, int>>>> memo;
int dp(int idx, int k, bool prv, int mx) {
    if(idx == n) return (k > 0)? INT_MAX: mx;
    if(memo[idx][k][prv].count(mx)) return memo[idx][k][prv][mx];
    int ans = dp(idx + 1, k, false, mx);
    if(!prv) {
        int tmp = dp(idx + 1, k - 1 < 1? 0: k-1, true, mx == 0? nums[idx]: (mx > nums[idx]) ? mx: nums[idx]);
        ans = min(ans, tmp);            
    }
    return memo[idx][k][prv][mx] = ans;
}
```

- **Memoization**: The `memo` array stores the results of previously computed subproblems to avoid recalculating them.
- **Dynamic Programming**: The function `dp` recursively explores the possible states while maintaining the maximum number (`mx`) encountered during the process. It uses a depth-first search approach with memoization to avoid recalculating the same states.

#### Step 5: Return the Result

```cpp
return ans;
```

- Once the binary search is complete, the value of `ans` will be the minimum capability `x` for which it's possible to select `k` non-adjacent numbers.

### Complexity Analysis

#### Time Complexity:

- **Binary Search**: The binary search runs for \(O(\log(\text{max} - \text{min}))\), where the difference is between the maximum and minimum values in `nums`. This is at most \(O(\log(\text{max element}))\).
- **Feasibility Check**: Each call to the `can` function processes all elements of `nums` in linear time \(O(n)\).
- **Dynamic Programming (if used)**: The recursion and memoization can add additional complexity, but the combined approach with binary search ensures that the overall complexity remains manageable.

Thus, the time complexity of the solution is approximately:
\[
O(n \log(\text{max element}))
\]
where \(n\) is the number of elements in `nums`.

#### Space Complexity:

- **Memoization Storage**: The `memo` array requires space proportional to the size of the state space. In the worst case, this could be \(O(n \cdot k \cdot \log(\text{max element}))\), depending on the specific implementation of the DP approach.

Thus, the space complexity is approximately:
\[
O(n \cdot k)
\]

### Conclusion

This solution efficiently uses binary search combined with dynamic programming to find the minimum capability for selecting `k` non-adjacent numbers from the list. The use of memoization optimizes repeated subproblems, and the binary search reduces the range of possible values for `x`, making the solution optimal for large input sizes. The combination of these techniques ensures that the problem is solved efficiently within the given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/house-robber-iv/description/)

---
{{< youtube BJWTAclDvEA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
