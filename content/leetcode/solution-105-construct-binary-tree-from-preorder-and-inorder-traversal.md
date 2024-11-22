
+++
authors = ["grid47"]
title = "Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal"
date = "2024-10-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 105: Construct Binary Tree from Preorder and Inorder Traversal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Divide and Conquer","Tree","Binary Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/105.webp"
youtube = "GeltTz3Z1rw"
youtube_upload_date="2020-01-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/GeltTz3Z1rw/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/105.webp" 
    alt="A tree gently forming from two intertwining paths of glowing nodes, one representing preorder, the other inorder."
    caption="Solution to LeetCode 105: Construct Binary Tree from Preorder and Inorder Traversal Problem"
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
    map<int, int> mp;
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;

        for(int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

        return helper(0, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(int ps, int is, int ie) {
        if(ps >= preorder.size() || is > ie) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);
        root->left  = helper(ps + 1, is, mp[root->val] - 1);
        root->right = helper(ps + mp[root->val] - is + 1, mp[root->val] + 1, ie);

        return root;
    }
    
};
{{< /highlight >}}
---

### **🌱 Let's Build a Tree!**

Constructing a binary tree from **preorder** and **inorder** traversal is like solving a puzzle, and once we understand the rules, it becomes easy to fit all the pieces together.

#### **✨ Step 1: The Magic of Preorder & Inorder**

In **preorder** traversal, the root comes first, followed by the left subtree and then the right. Imagine you're reading a list of steps: *root → left → right*. 🧩

In **inorder** traversal, the order is: *left → root → right*. It’s like you’re first visiting the left side, then the root, and finally the right. 🌲

---

#### **🗺️ Step 2: Preprocessing with a Map**

We’ll start by creating a quick lookup map for the **inorder** array. This helps us locate the position of any node in constant time. ⚡

```cpp
map<int, int> mp;  // This stores the index of each element in inorder
```

We fill this map so we can find each root's position in **inorder** quickly. Remember, the root splits the array into the left and right subtrees. 🧠

---

#### **🔨 Step 3: Recursive Construction — Divide & Conquer**

Now, let’s dive into the heart of it all: recursion. 🎯

For the **preorder** array, the first element is always the root. Once we have the root, we can divide the **inorder** array into two parts: the left and right subtrees.

Here’s how we build the tree step-by-step:

```cpp
TreeNode* root = new TreeNode(preorder[ps]);  // Create the root node from preorder
```

👉 **Explain Simply:** We're using the first node from **preorder** as the root. Now we know where to "split" the **inorder** array based on where this root appears.

---

#### **🌳 Step 4: Recursive Call for Left & Right Subtrees**

Now, we recursively build the left and right subtrees by slicing the **inorder** array. Let's see the magic happen:

```cpp
root->left = helper(ps + 1, is, mp[root->val] - 1);  // Left subtree
root->right = helper(ps + mp[root->val] - is + 1, mp[root->val] + 1, ie);  // Right subtree
```

- **Left Subtree:** We use the portion of **inorder** to the left of the root (identified earlier).
- **Right Subtree:** We use the portion of **inorder** to the right of the root.

Every recursion narrows down the problem to smaller chunks. The key is breaking down each part of the tree recursively and processing one node at a time. 📚

---

### **💡 Why This Works:**

- The **preorder** array tells us the root in the beginning.
- The **inorder** array helps us split the tree into two parts (left and right).
- The map lets us find the root's position in **inorder** in constant time, making the process super efficient. 🏎️

### **🧠 Harmonic Thought:**  
> *"The more you practice, the more you master the art of tree-building!"* 🌳

---

### **⏱️ Performance: Time & Space Complexity**

- **🕰️ Time Complexity:** **O(n)**  
  We visit each node exactly once, and our map lookups are done in constant time.

- **🧠 Space Complexity:** **O(n)**  
  We store the map, the arrays, and the recursive call stack, making the overall space complexity **O(n)**. This is efficient, as each node only contributes a constant amount of space. 🎯

---

### **💥 Example Walkthrough: Let's Break it Down!**

Given:

- **Preorder:** `[3, 9, 20, 15, 7]`
- **Inorder:** `[9, 3, 15, 20, 7]`

1. The root is `3` (from **preorder[0]**). 🎉
2. Find `3` in **inorder**: 
   - Left subtree: `[9]`  
   - Right subtree: `[15, 20, 7]`  
   Split the tree in two halves! 🛠️
   
3. Recursively build the left and right subtrees:
   - Left subtree is `9` (from **preorder[1]**).
   - Right subtree: Now we're dealing with `[20, 15, 7]` and its corresponding **preorder** nodes.

This leads us to the final tree structure:  

```
        3
       / \
      9   20
         /  \
        15   7
```

---

### **🌟 Conclusion: Simple but Powerful!**

This approach combines the beauty of recursion with the power of indexing via a map. The time complexity is **O(n)**, making it a fast solution, and the space complexity is also **O(n)**, keeping it manageable.  

### **🌳 Harmonic Thought:**  
> *"Great things are not achieved through shortcuts. Step-by-step, we build trees!"* 🌳

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)

---
{{< youtube GeltTz3Z1rw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
