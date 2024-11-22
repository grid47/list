
+++
authors = ["grid47"]
title = "Leetcode 16: 3Sum Closest"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 16: 3Sum Closest in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp"
youtube = "PXWT4wzkA6M"
youtube_upload_date="2024-07-29"
youtube_thumbnail="https://i.ytimg.com/vi/PXWT4wzkA6M/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/16.webp" 
    alt="Three glowing points forming a close triangle, with the central point shimmering in light."
    caption="Solution to LeetCode 16: 3Sum Closest Problem"
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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int front;
        int sum = nums[0] + nums[1] + nums[2], sum1 = 0;

        for(int i = 0; i < nums.size(); i++) {

            front = i + 1;

            int back = nums.size() - 1;

            while( front < back ) {

                sum1 = nums[front] + nums[back] + nums[i];

                if (abs(sum1-target) <= abs(sum-target)) sum = sum1;

                     if(sum1 > target) back--;
                else if(sum1 < target) front++;
                else return sum1;

            }
        }

        return sum;
    }
};
{{< /highlight >}}
---

### 💡 **Closest Three Sum Problem** – Let’s Solve It Together!

The **Closest Three Sum** problem is a popular coding challenge. The goal is to **find the sum of three integers in an array** that is closest to a given target value. Let’s dive into the steps and approach that make this problem solvable efficiently!

### 📝 **What’s the Problem?**

You are given:
- An integer **target** — the value we want to get as close as possible to by summing three numbers.
- An array of integers **nums** — a collection of numbers where we need to find the three numbers whose sum is closest to the target.

Your task is to **return the sum of the three integers** that is closest to the target.

#### Example:

For the array `nums = [-1, 2, 1, -4]` and target `1`, the closest sum is `2` since the sum of `-1`, `2`, and `1` is closest to `1`.

---

### 🔍 **Approach: How We’ll Solve It**

This problem is a variation of the popular **3-sum** problem, but instead of finding an exact match for the sum, we need to find the sum that is closest to the target. Let’s break down the approach!

#### Key Steps:

1. **Sort the Input Array**  
   - Sorting helps us use a **two-pointer technique**, which is essential for efficiently finding the closest sum. Sorting simplifies the problem and reduces unnecessary comparisons.

2. **Iterate Through the Array**  
   - We iterate through the array and treat each element as one of the three numbers in the sum. For each element, we use two pointers to find the other two numbers that make the sum closest to the target.

3. **Two-Pointer Technique**  
   - For each element `i`, maintain two pointers:
     - **`front`**: Starts at the element immediately after `i` (`i+1`).
     - **`back`**: Starts at the last element of the array.
   
   - The pointers will move toward each other to find the sum closest to the target.

4. **Calculate the Sum**  
   - For each iteration, calculate the sum of the three numbers:  
     `sum1 = nums[i] + nums[front] + nums[back]`.

5. **Update Closest Sum**  
   - If the absolute difference between `sum1` and the target is smaller than the current closest sum, update the closest sum.

6. **Adjust Pointers**  
   - Depending on whether `sum1` is greater than or less than the target:
     - If `sum1 > target`, move the `back` pointer left to reduce the sum.
     - If `sum1 < target`, move the `front` pointer right to increase the sum.
     - If `sum1 == target`, return the sum immediately since it’s the best possible match.

7. **Repeat Until Completion**  
   - Continue this process for all elements in the array, and the result will be the closest sum to the target.

---

### 🧑‍💻 **Code Breakdown (Step-by-Step)**

#### Step 1: Sort the Array

```cpp
sort(nums.begin(), nums.end());
```
- Sorting the array enables the two-pointer technique to work efficiently. Sorting takes **O(n log n)** time.

#### Step 2: Initialize Variables

```cpp
int front;
int sum = nums[0] + nums[1] + nums[2], sum1 = 0;
```
- `sum` stores the sum of the first three elements of the sorted array, which serves as the initial closest sum.
- `sum1` will store the sum of three integers in each iteration.

#### Step 3: Iterate Through the Array

```cpp
for(int i = 0; i < nums.size(); i++) {
    front = i + 1;
    int back = nums.size() - 1;
```
- The outer loop iterates through each element in the array, treating it as one of the three integers in the sum.
- `front` points to the element right after `i`, and `back` points to the last element in the array.

#### Step 4: Two-Pointer Approach

```cpp
while(front < back) {
    sum1 = nums[front] + nums[back] + nums[i];
```
- The inner while loop ensures `front` is less than `back`, meaning we haven’t compared the same element twice.
- Calculate `sum1` as the sum of `nums[i]`, `nums[front]`, and `nums[back]`.

#### Step 5: Check for Closest Sum

```cpp
if(abs(sum1 - target) <= abs(sum - target)) sum = sum1;
```
- If the absolute difference between `sum1` and the target is smaller or equal to the current closest sum, update `sum`.

#### Step 6: Move Pointers Based on Comparison

```cpp
if(sum1 > target) back--;
else if(sum1 < target) front++;
else return sum1;
```
- If `sum1` is greater than the target, move `back` left to reduce the sum.
- If `sum1` is less than the target, move `front` right to increase the sum.
- If `sum1` equals the target, return `sum1` immediately since we’ve found the closest possible sum.

#### Step 7: Return the Closest Sum

```cpp
return sum;
```
- Once the loop completes, return the closest sum found.

---

### 🧠 **Time and Space Complexity**

- **Time Complexity**:  
  Sorting the array takes **O(n log n)**. The two-pointer technique processes each element in the array once, which is **O(n)** for each outer loop iteration. So, the overall time complexity is **O(n log n)**.

- **Space Complexity**:  
  The space complexity is **O(1)** since we use only a constant amount of extra space, aside from the input and output.

---

### 🎯 **Why This Approach Works Well**

- Sorting the array simplifies the two-pointer technique, making it easy to adjust the pointers based on whether the sum is above or below the target.
- This approach guarantees that we only traverse the array once per element, making it efficient.
- It also handles edge cases, such as when no exact sum matches the target, by finding the closest sum in linear time after sorting.

---

### 🏁 **Conclusion**

This solution efficiently solves the problem of finding the closest sum of three integers to a given target. By using sorting and the two-pointer approach, we ensure the solution runs in **O(n log n)** time, making it optimal for this kind of problem. With the combination of simplicity and efficiency, this approach is a great example of how to solve coding problems with minimal complexity.

Happy coding, and keep pushing the boundaries! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/3sum-closest/description/)

---
{{< youtube PXWT4wzkA6M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
