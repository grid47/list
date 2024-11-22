
+++
authors = ["grid47"]
title = "Leetcode 18: 4Sum"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 18: 4Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/18.webp"
youtube = "EYeR-_1NRlQ"
youtube_upload_date="2022-03-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EYeR-_1NRlQ/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/18.webp" 
    alt="Four soft light orbs orbiting around a central glowing point, signifying combination."
    caption="Solution to LeetCode 18: 4Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        vector<vector<int>> output;
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1, high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] < newTarget){
                        low++;
                    }
                    else if(nums[low] + nums[high] > newTarget){
                        high--;
                    }
                    else{
                        set.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++; high--;
                    }
                }
            }
        }
        for(auto it : set){
            output.push_back(it);
        }
        return output;
    }
};
{{< /highlight >}}
---

### 🎯 **4Sum Problem: Find All Unique Quadruplets**

In this problem, we are given an integer array `nums` and an integer `target`. Our goal is to find all unique quadruplets `[nums[i], nums[j], nums[k], nums[l]]` such that:

- `i < j < k < l`
- `nums[i] + nums[j] + nums[k] + nums[l] == target`

We need an efficient approach that can handle large input sizes while avoiding duplicate quadruplets.

---

### 🧑‍💻 **Approach**

This problem is a variation of the "4Sum" problem, and we can solve it effectively by using a combination of sorting and the two-pointer technique. Let's break down the steps in detail:

#### 1. **Sorting the Array**:
   - First, we sort the input array `nums` in ascending order. Sorting simplifies the combination search and helps us avoid duplicates.
   - After sorting, we can use the two-pointer technique to find two numbers that sum to a given target.

#### 2. **Using a Set to Track Unique Quadruplets**:
   - To ensure that all quadruplets are unique, we store them in a set. The set automatically handles duplicate quadruplets, as it only keeps distinct values.

#### 3. **Two Nested Loops for the First Two Elements**:
   - The outer two loops select the first two elements of the quadruplet. These loops are indexed by `i` and `j` such that `i < j`.
   - For each pair `(nums[i], nums[j])`, we calculate the new target, which is the original `target` minus the sum of the first two numbers.

#### 4. **Using Two Pointers for the Remaining Two Elements**:
   - After selecting the first two numbers, the new target (`newTarget`) is the sum we need for the remaining two numbers. We calculate it as:  
     `newTarget = target - nums[i] - nums[j]`.
   - We then use two pointers, `low` and `high`, starting just after `j` and at the end of the array, respectively.
   - The two-pointer technique is used to find the remaining two numbers such that their sum equals `newTarget`.

#### 5. **Storing the Results**:
   - Once all valid quadruplets are found, we transfer the unique elements from the set into a result vector. This vector will contain the unique quadruplets.

---

### 🧑‍💻 **Code Breakdown (Step by Step)**

#### Step 1: Sorting the Array
```cpp
sort(nums.begin(), nums.end());
```
- Sorting the array helps manage the two-pointer approach and ensures we can skip duplicate elements.

#### Step 2: Outer Loops for the First Two Elements
```cpp
for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
        long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
```
- We iterate over the array with two outer loops, where `i < j`. This selects the first two numbers of the quadruplet. The new target (`newTarget`) is calculated by subtracting the sum of `nums[i]` and `nums[j]` from the original `target`.

#### Step 3: Two-Pointer Approach for the Remaining Elements
```cpp
int low = j + 1, high = n - 1;
while (low < high) {
    if (nums[low] + nums[high] < newTarget) {
        low++;
    } else if (nums[low] + nums[high] > newTarget) {
        high--;
    } else {
        set.insert({nums[i], nums[j], nums[low], nums[high]});
        low++; high--;
    }
}
```
- We initialize two pointers, `low` and `high`, to find two numbers that sum up to `newTarget`.
- If `nums[low] + nums[high]` is less than `newTarget`, we increment `low`. If the sum is greater, we decrement `high`.
- If the sum matches `newTarget`, we add the quadruplet to the set and move both pointers inward.

#### Step 4: Transfer Results to Output
```cpp
for (auto it : set) {
    output.push_back(it);
}
```
- After finding all quadruplets, we transfer them from the set to the result vector `output`.

#### Step 5: Return the Result
```cpp
return output;
```
- Finally, we return the list of unique quadruplets.

---

### ⏱️ **Time and Space Complexity**

#### Time Complexity:
- **Sorting** the array takes `O(n log n)`.
- The **nested loops** for selecting the first two elements (`i` and `j`) run in `O(n^2)` time, where `n` is the size of the array.
- The **two-pointer approach** inside the loops runs in `O(n)` for each pair of `i` and `j`.
- Overall, the time complexity is **O(n^3)**.

#### Space Complexity:
- The space complexity is primarily determined by the space needed to store the unique quadruplets, which can be at most `O(n^3)` in the worst case.
- We also use a set to store unique quadruplets and a vector for the result, so the space complexity is **O(n^3)**.

---

### 💡 **Conclusion**

The "4Sum" problem can be efficiently solved using a combination of sorting and the two-pointer technique. By sorting the input array first and using a set to store unique quadruplets, we ensure that the solution is both time and space efficient. While the time complexity is **O(n^3)**, this approach is significantly faster than brute force methods, which would have a time complexity of **O(n^4)**. This makes the solution feasible for moderately large input sizes.

Happy coding! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/4sum/description/)

---
{{< youtube EYeR-_1NRlQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
