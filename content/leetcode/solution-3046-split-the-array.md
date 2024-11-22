
+++
authors = ["grid47"]
title = "Leetcode 3046: Split the Array"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3046: Split the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ItimQQYIHEw"
youtube_upload_date="2024-02-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ItimQQYIHEw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > 2) return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement:

The problem asks us to determine whether it is possible to split an array into subarrays, with the condition that no number in the array appears more than twice. If a number appears more than twice, it's not possible to split the array according to the given rule. The task is to return a boolean value, `true` if it is possible to split the array and `false` otherwise.

### Approach:

To solve this problem efficiently, we can leverage a **map (hashmap)** to keep track of the frequency of each element in the input array. The basic idea is to iterate through the array, and for each element, check if it appears more than twice. If any element appears more than twice, we immediately return `false`. If we reach the end of the array without encountering any element that appears more than twice, then we can return `true`.

The problem can be solved in a single pass through the array, making the solution efficient. The key operation involves checking the frequency of each element, and if any element exceeds the allowed frequency (which is two), we terminate the process early.

### Code Breakdown (Step by Step):

#### Step 1: Declare a Map to Track Frequencies

```cpp
map<int, int> mp;
```

- We define a `map` called `mp` where the keys are the elements from the `nums` array, and the values are their corresponding frequencies. The map will help us count how many times each number appears in the array.

#### Step 2: Iterate Over the Array

```cpp
for(int x: nums) {
    mp[x]++;
    if(mp[x] > 2) return false;
}
```

- We iterate over each element `x` in the `nums` array.
- For each element `x`, we increment its count in the `map` (`mp[x]++`).
- After incrementing the count, we check if the frequency of `x` has exceeded 2. If it has, we immediately return `false`. This means that the number `x` has appeared more than twice, which violates the problem's constraints. Thus, splitting the array into valid subarrays is not possible.

#### Step 3: Return True If No Element Appears More Than Twice

```cpp
return true;
```

- If we reach the end of the loop without finding any element that appears more than twice, it means that all elements in the array appear at most twice. Hence, it is possible to split the array, and we return `true`.

### Complexity:

#### Time Complexity:

- **O(n)**, where `n` is the number of elements in the `nums` array.
  - We only need to iterate over the array once. For each element, the operations of updating the map and checking the frequency are constant time operations (amortized constant time due to the properties of the map).
  - Therefore, the total time complexity is proportional to the size of the array.

#### Space Complexity:

- **O(n)**, where `n` is the number of unique elements in the `nums` array.
  - The space complexity is determined by the number of unique elements in the map. In the worst case, where all elements are distinct, the space complexity will be proportional to `n`. 
  - This is because we store each unique element and its frequency in the map.

### Conclusion:

This solution effectively solves the problem by using a map to track the frequency of each element in the array. By doing so, we can quickly detect if any element appears more than twice, which would prevent us from splitting the array into valid subarrays. 

- The time complexity is linear, O(n), which is optimal for problems involving checking conditions across all elements of the array.
- The space complexity is O(n), which is manageable given the constraints, as we only store the frequency of each unique element.

The approach is efficient and handles edge cases (such as arrays with repeated elements or arrays with only one element) effectively. This method ensures that we solve the problem in a single pass through the array, making it suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/split-the-array/description/)

---
{{< youtube ItimQQYIHEw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
