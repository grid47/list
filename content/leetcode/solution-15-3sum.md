
+++
authors = ["grid47"]
title = "Leetcode 15: 3Sum"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 15: 3Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/15.webp"
youtube = "8IjCNFIo8YI"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/8IjCNFIo8YI/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/15.webp" 
    alt="Three circles of light coming together in harmony, overlapping in a gentle glow."
    caption="Solution to LeetCode 15: 3Sum Problem"
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int s = i + 1;
            int e = nums.size() - 1;
            while(s < e) {
                if(nums[s] + nums[e] < target) {
                   s++;
                } else if (nums[s] + nums[e] > target) {
                    e--;
                } else {
                    vector<int> res = {nums[i], nums[s], nums[e]};
                    ans.push_back(res);
                    while(s < e && nums[s] == res[1]) s++;
                    while(s < e && res[2] == nums[e]) e--;                    
                }
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🧩 **3Sum Problem: Finding Unique Triplets That Sum to Zero**

The task at hand is to find all unique triplets in an array of integers that sum up to zero. This is a classical problem often referred to as the "3Sum" problem. Here's a breakdown of how to efficiently solve it.

---

### 🔍 **Problem Understanding**

Given an array of integers `nums`, we need to return all unique triplets `[nums[i], nums[j], nums[k]]` such that:
```
nums[i] + nums[j] + nums[k] == 0
```
**Important Notes:**
- The triplets should be unique.
- We must avoid a brute-force approach of checking all possible triplets.

---

### ⚙️ **Efficient Approach: Sorting and Two-Pointer Technique**

To solve the problem efficiently, we can use a combination of sorting and a two-pointer technique. Here's how:

#### 1. **Sort the Array**
Sorting helps us easily identify duplicate triplets and also allows us to use a two-pointer approach to find pairs that sum to a specific target.

#### 2. **Fix One Element**
We start by fixing one element of the triplet (let’s call it `nums[i]`). For each fixed element, the problem reduces to finding two other elements that sum up to `-nums[i]`.

#### 3. **Use Two Pointers**
Once we fix `nums[i]`, use two pointers to find the other two numbers:
- The left pointer (`s`) starts right after `i`.
- The right pointer (`e`) starts from the end of the array.
- Adjust the pointers to find the valid triplet:
  - If the sum is smaller than the target, move the left pointer to the right.
  - If the sum is larger than the target, move the right pointer to the left.
  - If the sum equals the target, we have a valid triplet.

#### 4. **Skip Duplicates**
- After finding a valid triplet, skip over any duplicate values to avoid adding the same triplet multiple times.

#### 5. **Skip Duplicates for the Fixed Element**
- If the current element `nums[i]` is the same as the previous one, skip it to avoid duplicate triplets.

---

### 📝 **Code Explanation**

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;  // Result array to store unique triplets.
    sort(nums.begin(), nums.end());  // Sort the array to enable two-pointer technique.
    
    for(int i = 0; i < nums.size(); i++) {
        int target = -nums[i];  // We need the sum of the other two elements to be -nums[i].
        int s = i + 1;  // Left pointer starts just after the fixed element.
        int e = nums.size() - 1;  // Right pointer starts at the end of the array.
        
        while(s < e) {  // Loop until the left and right pointers meet.
            if(nums[s] + nums[e] < target) {
                s++;  // If the sum is smaller than the target, move the left pointer to the right.
            } else if (nums[s] + nums[e] > target) {
                e--;  // If the sum is larger than the target, move the right pointer to the left.
            } else {
                // A valid triplet is found: [nums[i], nums[s], nums[e]].
                vector<int> res = {nums[i], nums[s], nums[e]};
                ans.push_back(res);  // Add the triplet to the result.
                
                // Skip duplicates for the left pointer.
                while(s < e && nums[s] == res[1]) s++;
                // Skip duplicates for the right pointer.
                while(s < e && res[2] == nums[e]) e--;
            }
        }
        
        // Skip duplicates for the fixed element nums[i].
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    }
    
    return ans;  // Return the list of unique triplets.
}
```

---

### 🚀 **Code Walkthrough**

1. **Sorting the Array**: 
   ```cpp
   sort(nums.begin(), nums.end());
   ```
   - This step allows us to efficiently find triplets and avoid duplicates.

2. **Iterate through the Array**:
   ```cpp
   for(int i = 0; i < nums.size(); i++) {
       int target = -nums[i];
       int s = i + 1;
       int e = nums.size() - 1;
   ```
   - We fix the element `nums[i]` and calculate the target (`-nums[i]`). The goal is to find two other elements that sum up to the target.

3. **Two-Pointer Technique**:
   ```cpp
   while(s < e) {
       if(nums[s] + nums[e] < target) {
           s++;
       } else if (nums[s] + nums[e] > target) {
           e--;
       } else {
           vector<int> res = {nums[i], nums[s], nums[e]};
           ans.push_back(res);
           while(s < e && nums[s] == res[1]) s++;
           while(s < e && res[2] == nums[e]) e--;
       }
   }
   ```
   - We adjust the left and right pointers based on the sum of the values at `s` and `e`.
   - If a valid triplet is found, it is added to the result list, and we skip over any duplicates for the `s` and `e` pointers.

4. **Skipping Duplicates**:
   ```cpp
   while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
   ```
   - After finding a triplet, we skip the duplicate values of `nums[i]` to ensure unique triplets.

---

### 📊 **Time and Space Complexity**

- **Time Complexity**: **O(n²)**. 
  - Sorting the array takes **O(n log n)**.
  - The two-pointer loop runs **O(n)** times for each element, making the overall time complexity **O(n²)**.

- **Space Complexity**: **O(n)**. 
  - The space complexity is primarily used for storing the result list, which in the worst case could contain up to **O(n)** triplets.

---

### 🎯 **Key Takeaways**

- **Efficiency**: The time complexity of O(n²) is much better than brute-force methods.
- **Two-pointer technique**: A very common and effective approach for problems like 3Sum.
- **Avoiding Duplicates**: Sorting the array and skipping duplicate values ensure that we only store unique triplets.

#### **Advantages**:
- Fast and intuitive using sorting and two pointers.
- Handles duplicate elements gracefully.
  
#### **Limitations**:
- Assumes the input array has a reasonable size (works well up to a few thousand elements).

---

### 🏁 **Conclusion**

The 3Sum problem can be efficiently solved by sorting the array and using the two-pointer technique to find pairs that sum up to the negative of the fixed element. By carefully skipping duplicates, we ensure that only unique triplets are returned. This approach is optimal for this problem, with a time complexity of O(n²) and a space complexity of O(n).

[`Link to LeetCode Lab`](https://leetcode.com/problems/3sum/description/)

---
{{< youtube 8IjCNFIo8YI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
