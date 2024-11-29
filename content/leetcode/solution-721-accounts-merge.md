
+++
authors = ["grid47"]
title = "Leetcode 721: Accounts Merge"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 721: Accounts Merge in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Depth-First Search","Breadth-First Search","Union Find","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/721.webp"
youtube = "otzKJY8YhRg"
youtube_upload_date="2020-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/otzKJY8YhRg/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/721.webp" 
    alt="A set of accounts where identical accounts are merged, with each merge softly glowing as it’s processed."
    caption="Solution to LeetCode 721: Accounts Merge Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a list of accounts, where each account consists of a name and a list of emails. Merge accounts that share common emails, and return the merged accounts in the format: name followed by sorted emails.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each account is represented by a list of strings. The first element is the name, and the rest are email addresses.
- **Example:** `accounts = [["Alice","alice@mail.com","alice_newyork@mail.com"], ["Alice","alice@mail.com","alice123@mail.com"], ["Bob","bob@mail.com"]]`
- **Constraints:**
	- 1 <= accounts.length <= 1000
	- 2 <= accounts[i].length <= 10
	- 1 <= accounts[i][j].length <= 30
	- accounts[i][0] consists of English letters.
	- accounts[i][j] (for j > 0) is a valid email.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the merged accounts, where each account starts with the name followed by a sorted list of email addresses.
- **Example:** `[["Alice","alice123@mail.com","alice@mail.com","alice_newyork@mail.com"]]`
- **Constraints:**
	- The accounts should be returned with emails in sorted order and merged by shared emails.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to merge accounts based on common emails.

- Use a graph where each email is a node, and there is an edge between two emails if they belong to the same account.
- For each account, build the graph by connecting emails together.
- Perform DFS (depth-first search) to find all connected emails for each component, representing one account.
- Sort the emails in lexicographical order and return the merged result with the name and emails.
{{< dots >}}
### Problem Assumptions ✅
- Each account contains at least one email.
- The same person may have multiple accounts with the same or different names.
{{< dots >}}
## Examples 🧩
- **Input:** `accounts = [["Alice","alice@mail.com","alice_newyork@mail.com"], ["Alice","alice@mail.com","alice123@mail.com"], ["Bob","bob@mail.com"]]`  \
  **Explanation:** The first and second Alice accounts are merged since they share the email 'alice@mail.com'. The result should contain Alice’s emails sorted, and Bob’s account should remain unchanged.

- **Input:** `accounts = [["John","john1@mail.com","john2@mail.com","john3@mail.com"], ["Mike","mike1@mail.com","mike2@mail.com"], ["John","john1@mail.com","john4@mail.com"]]`  \
  **Explanation:** Both John accounts share 'john1@mail.com', so they are merged, with all of John’s emails sorted.

{{< dots >}}
## Approach 🚀
The solution uses a graph-based approach to merge accounts that share common emails.

### Initial Thoughts 💭
- Each email can be treated as a node, and accounts with common emails form connected components in the graph.
- By performing DFS on the graph, we can find all connected emails for each account and merge them.
{{< dots >}}
### Edge Cases 🌐
- If the input list is empty, return an empty list.
- The solution must handle up to 1000 accounts efficiently.
- If no accounts share any emails, each account should be returned individually.
- The solution should work within time and space limits for the maximum input size.
{{< dots >}}
## Code 💻
```cpp
vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
    map<string, string> mp;
    map<string, set<string>> gph;
    for(auto ac: acc) {
        for(int i = 1; i < ac.size(); i++) {
            mp[ac[i]] = ac[0];
            gph[ac[i]].insert(ac[1]);
            gph[ac[1]].insert(ac[i]);
        }
    }
    
    set<string> seen;
    vector<vector<string>> ans;
    for(auto it: mp) {
        if(seen.count(it.first)) continue;
        vector<string> tmp;
        dfs(tmp, gph, seen, it.first);
        sort(tmp.begin(), tmp.end());
        tmp.insert(tmp.begin(), it.second);
        ans.push_back(tmp);
    }
    
    return ans;
}

void dfs(vector<string> &tmp, map<string, set<string>> &gph, set<string> &seen, string node) {
    tmp.push_back(node);
    seen.insert(node);
    for(auto it: gph[node]) {
        if(!seen.count(it)) {
            dfs(tmp, gph, seen, it);
        }
    }
    
}
```

This function merges email accounts by identifying connected components in a graph where each email represents a node and edges exist between emails belonging to the same account.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Graph Initialization**
	```cpp
	vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
	```
	The main function starts by initializing the structure to merge accounts.

2. **Data Mapping**
	```cpp
	    map<string, string> mp;
	```
	A mapping of emails to account names.

3. **Graph Construction**
	```cpp
	    map<string, set<string>> gph;
	```
	Graph representation where each email is a node connected to other emails.

4. **Graph Traversal**
	```cpp
	    for(auto ac: acc) {
	```
	Iterates over each account to construct the graph.

5. **Graph Edge Insertion**
	```cpp
	        for(int i = 1; i < ac.size(); i++) {
	```
	Iterates over emails in the account to establish edges.

6. **Mapping Emails**
	```cpp
	            mp[ac[i]] = ac[0];
	```
	Maps each email to its corresponding account name.

7. **Graph Edge Insertion**
	```cpp
	            gph[ac[i]].insert(ac[1]);
	```
	Adds an edge from the current email to the first email.

8. **Graph Edge Insertion**
	```cpp
	            gph[ac[1]].insert(ac[i]);
	```
	Adds an edge from the first email to the current email.

9. **Set Initialization**
	```cpp
	    set<string> seen;
	```
	A set to keep track of visited emails.

10. **Result Storage**
	```cpp
	    vector<vector<string>> ans;
	```
	Stores the merged accounts as a result.

11. **Graph Traversal**
	```cpp
	    for(auto it: mp) {
	```
	Iterates through the email-to-name map to traverse the graph.

12. **Visit Check**
	```cpp
	        if(seen.count(it.first)) continue;
	```
	Skips already visited emails.

13. **Temporary Storage**
	```cpp
	        vector<string> tmp;
	```
	Temporary storage for connected component emails.

14. **Depth First Search**
	```cpp
	        dfs(tmp, gph, seen, it.first);
	```
	Performs DFS to collect all connected emails.

15. **Sorting**
	```cpp
	        sort(tmp.begin(), tmp.end());
	```
	Sorts emails alphabetically for output.

16. **Insert Name**
	```cpp
	        tmp.insert(tmp.begin(), it.second);
	```
	Prepends the account name to the sorted emails.

17. **Store Result**
	```cpp
	        ans.push_back(tmp);
	```
	Adds the merged account to the result.

18. **Close Loop**
	```cpp
	    }
	```
	Closes the loop for iterating through the email-to-name map.

19. **Return Result**
	```cpp
	    return ans;
	```
	Returns the final merged account list.

20. **DFS Function**
	```cpp
	void dfs(vector<string> &tmp, map<string, set<string>> &gph, set<string> &seen, string node) {
	```
	Defines a helper function for DFS traversal.

21. **DFS Visit**
	```cpp
	    tmp.push_back(node);
	```
	Marks the current node as visited and adds it to the result.

22. **Mark Visited**
	```cpp
	    seen.insert(node);
	```
	Adds the node to the visited set.

23. **Iterate Neighbors**
	```cpp
	    for(auto it: gph[node]) {
	```
	Iterates over all neighbors of the current node.

24. **Check Unvisited**
	```cpp
	        if(!seen.count(it)) {
	```
	Checks if the neighbor has not been visited.

25. **Recursive DFS**
	```cpp
	            dfs(tmp, gph, seen, it);
	```
	Recursively calls DFS for unvisited neighbors.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of emails, because sorting the emails is the most time-consuming operation.
- **Average Case:** O(n + e), where n is the number of emails and e is the number of edges in the graph (connections between emails).
- **Worst Case:** O(n log n + e), where n is the number of emails and e is the number of edges.

The time complexity is dominated by DFS and sorting the emails in each connected component.

### Space Complexity 💾
- **Best Case:** O(n), in the case where no emails are shared between accounts.
- **Worst Case:** O(n + e), where n is the number of emails and e is the number of edges.

The space complexity is dominated by the graph representation and storage for the emails.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/accounts-merge/description/)

---
{{< youtube otzKJY8YhRg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
