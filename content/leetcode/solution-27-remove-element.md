
+++
authors = ["grid47"]
title = "Leetcode 27: Remove Element"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 27: Remove Element in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp"
youtube = "Pcd1ii9P9ZI"
youtube_upload_date="2021-09-13"
youtube_thumbnail="https://i.ytimg.com/vi/Pcd1ii9P9ZI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/27.webp" 
    alt="A soft, radiant element being gently pulled away from a sequence, leaving a streamlined flow."
    caption="Solution to LeetCode 27: Remove Element Problem"
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
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        
        for(int node: nums)
            if(node != val)
            {
                nums[i] = node;
                i++;
            }
        
        return i;
    }
};
{{< /highlight >}}
---

### 🌟 **Removing All Occurrences of a Specific Value from a List**

This problem asks you to remove all occurrences of a specific value from a list (in this case, a vector of integers), while maintaining the order of the remaining elements. The challenge is to perform this removal **in-place**, which means no extra space should be used for a new list.

---

#### 🧠 **The Simple Idea**

The task is to "shift" all elements that aren't equal to the specified value (`val`) to the front of the list. This can be done efficiently with two pointers:
1. **One pointer** will traverse the list.
2. **The other pointer** will track the position of the next available slot for valid elements.

By the end of the traversal, you'll have the desired elements packed at the beginning of the list, and the final position of the second pointer will give the new length of the list.

---

#### 👇 **Steps to Solve the Problem:**

1. **Initialize a Pointer**  
   Start with an index `i` that will keep track of the position for placing elements that are **not equal to** `val`.

2. **Iterate Through the List**  
   Go through each element of the list. If the element is not `val`, place it in the position indicated by `i` and increment `i`.

3. **Return the New Length**  
   At the end of the iteration, the value of `i` will represent the number of elements that are not equal to `val`. This is the length of the modified list.

---

#### 🛠 **Breaking Down the Code:**

1. **Initialize the Pointer**  
   ```cpp
   int i = 0;
   ```
   Here, `i` will act as the marker for where to place the next valid (non-`val`) element.

2. **Loop Through the List**  
   ```cpp
   for(int node: nums)
   ```
   This `for-each` loop iterates through each element in the `nums` vector. We check each element (`node`) to see if it should stay in the list.

3. **Check and Shift Valid Elements**  
   ```cpp
   if(node != val)
   {
       nums[i] = node;
       i++;
   }
   ```
   If `node` is not equal to `val`, we place it at index `i` and then increment `i`. This ensures that all elements that should remain are moved to the front, and `i` keeps track of the new length of the list.

4. **Return the New Length**  
   ```cpp
   return i;
   ```
   At the end, `i` represents the number of elements in the list that are not equal to `val`. This is returned as the new length of the modified list.

---

#### ⏳ **Complexity Breakdown**

- **Time Complexity: O(n)**  
  The algorithm traverses the `nums` array exactly once. For each element, it either keeps or ignores it based on its value, making the time complexity linear in the number of elements (`n`).

- **Space Complexity: O(1)**  
  The algorithm uses only a constant amount of extra space. No additional data structures are used, and all modifications are done **in-place**.

---

#### 💡 **Why This Approach Works**

- **Efficient One-Pass Solution**: We only need a single traversal of the list to remove the elements. Each element is either retained or skipped based on its value, making this approach both time and space efficient. 🚀
- **Minimal Space Usage**: By modifying the list in-place, we avoid using extra memory and achieve **O(1)** space complexity. 🌍

---

#### 🚀 **Conclusion**

The `removeElement` function is a highly efficient solution for removing all occurrences of a specific value from a list. It runs in **O(n)** time and uses **O(1)** space, making it optimal for large lists where minimizing memory usage is crucial. By using the two-pointer technique, this approach is simple, clear, and works perfectly within the problem constraints. 🎯

Now you’re ready to remove elements from any list without needing extra space—just a little ingenuity with pointers! 💡 Happy coding! 🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/remove-element/description/)

---
{{< youtube Pcd1ii9P9ZI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
