
+++
authors = ["grid47"]
title = "Leetcode 433: Minimum Genetic Mutation"
date = "2024-09-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 433: Minimum Genetic Mutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Breadth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/433.webp"
youtube = "XLvyInrFjm4"
youtube_upload_date="2024-04-06"
youtube_thumbnail="https://i.ytimg.com/vi/XLvyInrFjm4/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/433.webp" 
    alt="A series of genes evolving through mutations, with each valid mutation softly glowing as it occurs."
    caption="Solution to LeetCode 433: Minimum Genetic Mutation Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given two gene strings, `startGene` and `endGene`, both consisting of 8 characters. You also have a gene bank of valid gene strings that can be mutated into one another. A mutation is defined as changing one character at a time, and the mutated gene string must exist in the gene bank. Your task is to determine the minimum number of mutations needed to transform `startGene` into `endGene`. If transformation is impossible, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given three inputs: `startGene` (an 8-character gene string), `endGene` (an 8-character gene string), and a `bank` (a list of valid gene strings).
- **Example:** `startGene = 'AACCGGTT', endGene = 'AACCGGTA', bank = ['AACCGGTA']`
- **Constraints:**
	- 0 <= bank.length <= 10
	- startGene.length == endGene.length == bank[i].length == 8
	- startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T']

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of mutations needed to transform `startGene` to `endGene`. If it's not possible, return -1.
- **Example:** `1`
- **Constraints:**
	- If no mutation path exists, return -1.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the shortest path from `startGene` to `endGene` by performing valid mutations and using the gene bank.

- 1. Check if `endGene` exists in the gene bank. If not, return -1.
- 2. Use a breadth-first search (BFS) to explore all possible gene strings starting from `startGene`.
- 3. For each gene string, generate all possible mutations by changing one character at a time.
- 4. If a mutated gene string exists in the gene bank, add it to the BFS queue.
- 5. Keep track of the number of mutations, and return the result when `endGene` is reached.
{{< dots >}}
### Problem Assumptions ✅
- The startGene is always valid.
- Mutations are only allowed if the resulting gene string exists in the bank.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: startGene = 'AACCGGTT', endGene = 'AACCGGTA', bank = ['AACCGGTA']`  \
  **Explanation:** We mutate the last character from 'T' to 'A', which results in the endGene after one mutation.

- **Input:** `Input: startGene = 'AACCGGTT', endGene = 'AAACGGTA', bank = ['AACCGGTA','AACCGCTA','AAACGGTA']`  \
  **Explanation:** The solution involves two mutations: first from 'AACCGGTT' to 'AACCGGTA', and then from 'AACCGGTA' to 'AAACGGTA'.

{{< dots >}}
## Approach 🚀
We will use a breadth-first search (BFS) approach to find the shortest path from `startGene` to `endGene` by exploring all possible valid mutations in the gene bank.

### Initial Thoughts 💭
- This is a shortest path problem, and BFS is ideal because it explores all nodes at the present depth level before moving to nodes at the next depth level.
- We need to generate all possible gene strings from the current string by changing one character at a time, and check if the mutated string is in the gene bank.
{{< dots >}}
### Edge Cases 🌐
- If the gene bank is empty, return -1 unless `startGene` is equal to `endGene`.
- Ensure that the BFS approach handles up to 10 valid mutations efficiently.
- If the `startGene` is equal to `endGene`, return 0 because no mutation is needed.
- Handle cases where no valid mutations exist or where the gene bank is empty.
{{< dots >}}
## Code 💻
```cpp
int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string> st{bank.begin(), bank.end()};
    if(!st.count(endGene)) return -1;

    queue<string> q;
    q.push(startGene);
    int step = 0, s;
    string cur, t;
    while(!q.empty()) {
        s = q.size();
        while(s--) {
            cur = q.front();
            q.pop();
            if(cur == endGene) return step;
            st.erase(cur);
            for(int i= 0; i < 8; i++) {
                t = cur;
                t[i] = 'A';
                if(st.count(t)) q.push(t);
                t[i] = 'T';
                if(st.count(t)) q.push(t);
                t[i] = 'G';
                if(st.count(t)) q.push(t);
                t[i] = 'C';
                if(st.count(t)) q.push(t);                    
            }
        }
        step++;
    }
    return -1;
}
```

This function finds the minimum number of mutations required to transform the start gene into the end gene using BFS.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minMutation(string startGene, string endGene, vector<string>& bank) {
	```
	Declares the function to compute the minimum mutations required for gene transformation.

2. **Set Initialization**
	```cpp
	    unordered_set<string> st{bank.begin(), bank.end()};
	```
	Initializes a set with the bank to allow O(1) lookups for gene sequences.

3. **Base Condition**
	```cpp
	    if(!st.count(endGene)) return -1;
	```
	Checks if the end gene is in the bank; if not, returns -1 as transformation is impossible.

4. **Queue Initialization**
	```cpp
	    queue<string> q;
	```
	Declares a queue for BFS traversal of gene mutations.

5. **Enqueue**
	```cpp
	    q.push(startGene);
	```
	Adds the starting gene to the BFS queue.

6. **Variable Initialization**
	```cpp
	    int step = 0, s;
	```
	Initializes variables for BFS steps and queue size.

7. **Variable Declaration**
	```cpp
	    string cur, t;
	```
	Declares strings to hold the current gene and temporary mutations.

8. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	Iterates as long as the queue is not empty.

9. **Queue Size**
	```cpp
	        s = q.size();
	```
	Stores the current queue size for level-wise processing.

10. **For Each Level**
	```cpp
	        while(s--) {
	```
	Processes all nodes at the current level in the BFS.

11. **Front Element**
	```cpp
	            cur = q.front();
	```
	Gets the current gene at the front of the queue.

12. **Dequeue**
	```cpp
	            q.pop();
	```
	Removes the processed gene from the queue.

13. **Check Goal**
	```cpp
	            if(cur == endGene) return step;
	```
	Returns the number of steps if the current gene matches the end gene.

14. **Set Erase**
	```cpp
	            st.erase(cur);
	```
	Removes the current gene from the set to avoid revisiting.

15. **Loop**
	```cpp
	            for(int i= 0; i < 8; i++) {
	```
	Iterates through each character of the current gene to mutate.

16. **Copy String**
	```cpp
	                t = cur;
	```
	Creates a copy of the current gene for mutation.

17. **Character Mutation**
	```cpp
	                t[i] = 'A';
	```
	Mutates the ith character of the gene to 'A'.

18. **Conditional Insertions**
	```cpp
	                if(st.count(t)) q.push(t);
	```
	Checks if the mutated gene is in the set and enqueues it.

19. **Character Mutation**
	```cpp
	                t[i] = 'T';
	```
	Mutates the ith character of the gene to 'T'.

20. **Conditional Insertions**
	```cpp
	                if(st.count(t)) q.push(t);
	```
	Checks if the mutated gene is in the set and enqueues it.

21. **Character Mutation**
	```cpp
	                t[i] = 'G';
	```
	Mutates the ith character of the gene to 'G'.

22. **Conditional Insertions**
	```cpp
	                if(st.count(t)) q.push(t);
	```
	Checks if the mutated gene is in the set and enqueues it.

23. **Character Mutation**
	```cpp
	                t[i] = 'C';
	```
	Mutates the ith character of the gene to 'C'.

24. **Conditional Insertions**
	```cpp
	                if(st.count(t)) q.push(t);
	```
	Checks if the mutated gene is in the set and enqueues it.

25. **Increment Step**
	```cpp
	        step++;
	```
	Increments the step counter for the next level of BFS.

26. **Return Result**
	```cpp
	    return -1;
	```
	Returns -1 if the end gene is not reachable from the start gene.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1), if startGene is equal to endGene.
- **Average Case:** O(N * 8), where N is the number of gene strings in the bank and each mutation takes O(8) time (since the length of each gene string is 8).
- **Worst Case:** O(N * 8), where N is the number of possible gene mutations.

BFS explores each possible mutation in the gene bank.

### Space Complexity 💾
- **Best Case:** O(1), if no mutations are required.
- **Worst Case:** O(N), where N is the number of gene strings stored in the queue and the bank.

The space complexity depends on the number of nodes in the BFS queue.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-genetic-mutation/description/)

---
{{< youtube XLvyInrFjm4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
