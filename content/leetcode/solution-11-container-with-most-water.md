
+++
authors = ["grid47"]
title = "Leetcode 11: Container With Most Water"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 11: Container With Most Water in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp"
youtube = "Y_4_or0Sc7I"
youtube_upload_date="2024-02-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Y_4_or0Sc7I/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/11.webp" 
    alt="A serene water container being filled with calming light, symbolizing capacity and volume."
    caption="Solution to LeetCode 11: Container With Most Water Problem"
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
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() -1;
        
        while(i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j])
                i++;
            else j--;
        }
        return res;
    }
};
{{< /highlight >}}
---

### 💡 **Maximum Area of Water Between Two Lines** – Let's Solve It Together!

The **Maximum Area** problem asks us to find the largest possible container that can hold water between two lines in a given array. Each element in the array represents the height of a line drawn at that position. The width between two lines is simply the distance between their indices. Our goal is to maximize the area of the container formed by any two lines and the x-axis.

### 📝 **What’s the Problem?**

You are given:
- **`height[]`** — an array where `height[i]` represents the height of the line at index `i`.
- **`target`** — the maximum area we want to find between two lines.

Our task is to **determine the largest possible area** formed by any two lines in the array.

#### Example:

- **Input**: `height = [1,8,6,2,5,4,8,3,7]`
- **Output**: `49`  
  (The maximum area is formed between lines at positions 1 and 8, with heights 8 and 7).

---

### 🔍 **Approach: The Two-Pointer Technique**

To solve this efficiently, we use the **two-pointer technique**. The idea is to consider the container formed by two lines, one at the beginning (`i`) and one at the end (`j`) of the array. We calculate the area formed by the two lines and then move the pointers in such a way that we try to maximize the area.

#### Key Observations:
1. **Area Calculation**: The area between two lines is calculated as:
   \[
   \text{Area} = \text{min}(height[i], height[j]) \times (j - i)
   \]
   Where `height[i]` and `height[j]` are the heights of the two lines, and `(j - i)` is the width between them.
   
2. **Strategy to Maximize the Area**:
   - Start with two pointers, `i = 0` at the beginning of the array and `j = height.size() - 1` at the end.
   - Calculate the area formed between the two lines.
   - Move the pointer of the shorter line inward. The idea is that we may find a taller line that increases the area.

---

### 🧑‍💻 **Step-by-Step Code Implementation**

Let’s dive into how we can implement this approach:

1. **Initialize Variables**:
   ```cpp
   int res = 0;  // Variable to store the maximum area
   int i = 0, j = height.size() - 1;  // Pointers at the start and end of the array
   ```

2. **Calculate the Area**:
   ```cpp
   res = max(res, min(height[i], height[j]) * (j - i));
   ```
   - The area between the two lines at `i` and `j` is calculated as the minimum of their heights (`min(height[i], height[j])`) multiplied by the width (`j - i`).
   - We update the `res` variable with the maximum area found so far.

3. **Move the Pointers**:
   ```cpp
   if(height[i] < height[j]) 
       i++;  // Move i right if height[i] is shorter
   else 
       j--;  // Move j left if height[j] is shorter
   ```

   - We move the pointer corresponding to the shorter line inward. This is because the area is constrained by the shorter line, so we attempt to find a taller one by moving the shorter line.

4. **Return the Maximum Area**:
   ```cpp
   return res;
   ```

---

### ⏱️ **Time and Space Complexity**

- **Time Complexity**:  
  **O(n)** — The algorithm has a time complexity of O(n), where `n` is the length of the `height` array. The two-pointer technique ensures that each pointer is moved at most `n` times.

- **Space Complexity**:  
  **O(1)** — The space complexity is constant, O(1), as we use a fixed amount of extra space for the `res` variable and the two pointers.

---

### 💡 **Why This Approach Works**

- **Optimal Efficiency**: The two-pointer technique ensures that we only need **one pass** through the array, making the solution highly efficient.
- **Simplicity**: The approach is intuitive and easy to implement because it directly models the process of finding the maximum area by comparing heights and adjusting the pointers.

---

### 🏁 **Conclusion**

This solution efficiently finds the **maximum area** formed by two lines from an array of heights using the **two-pointer technique**.

#### Advantages:
- **Optimal Time Complexity**: O(n), making it perfect for large arrays.
- **Intuitive and Clean Logic**: The process is simple and avoids unnecessary computations.

#### Limitations:
- The solution assumes that the heights are non-negative, as negative heights don’t make sense in the context of the problem.

With this approach, we avoid the O(n²) brute-force solution, and our time and space complexity is greatly reduced. This technique ensures that even large datasets can be handled with ease!

---

Happy coding! 🚀 And remember, each problem you solve brings you one step closer to becoming a coding master! ✨


[`Link to LeetCode Lab`](https://leetcode.com/problems/container-with-most-water/description/)

---
{{< youtube Y_4_or0Sc7I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
