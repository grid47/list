
+++
authors = ["grid47"]
title = "Leetcode 1472: Design Browser History"
date = "2024-06-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1472: Design Browser History in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Linked List","Stack","Design","Doubly-Linked List","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pvj8WQMPlGY"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi/pvj8WQMPlGY/maxresdefault.jpg"
comments = true
+++



---
You are tasked with simulating the history of web page visits in a browser. Implement the BrowserHistory class to manage visit, back, and forward actions.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a series of method calls on the BrowserHistory object, including visit, back, and forward actions.
- **Example:** `["BrowserHistory", "visit", "visit", "visit", "back", "back", "forward", "visit", "forward", "back", "back"]`
- **Constraints:**
	- 1 <= homepage.length <= 20
	- 1 <= url.length <= 20
	- 1 <= steps <= 100
	- At most 5000 method calls will be made to visit, back, and forward.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output consists of the results of the method calls on the BrowserHistory object, which includes the current URL after back or forward operations.
- **Example:** `[null, null, null, null, "sports.com", "news.com", "sports.com", null, "social.com", "news.com", "tech.com"]`
- **Constraints:**
	- Output should follow the order of method calls with each result corresponding to the respective operation.

{{< dots >}}
### Core Logic 🔍
**Goal:** Simulate the behavior of a web browser's history functionality, managing navigation through visit, back, and forward actions.

- Initialize the BrowserHistory object with the homepage.
- Implement visit to record a page visit and clear forward history.
- Implement back to move back in history, ensuring not to exceed available pages.
- Implement forward to move forward in history, ensuring not to exceed available forward pages.
{{< dots >}}
### Problem Assumptions ✅
- The homepage will always be the first page visited.
- The back and forward methods will never exceed the available history or forward pages.
{{< dots >}}
## Examples 🧩
- **Input:** `For the input sequence, after visiting 'google.com', 'facebook.com', and 'youtube.com', and calling back and forward actions, the output will reflect the expected URLs after each action.`  \
  **Explanation:** The output reflects the changes in the current URL after each back and forward action, adhering to the constraints of the available history.

{{< dots >}}
## Approach 🚀
The problem can be solved using two stacks, one for back history and another for forward history.

### Initial Thoughts 💭
- We need to keep track of the current page, and allow navigating back and forward within the history.
- Stacks are an efficient way to manage backward and forward history, as they follow the Last In, First Out (LIFO) principle.
{{< dots >}}
### Edge Cases 🌐
- Ensure that there is at least one page visited, and no back operation can exceed the available history.
- Ensure the solution works efficiently even when there are up to 5000 method calls.
- Handle cases where no forward history exists after a visit or when back or forward exceeds available steps.
- Maintain the constraints of time and space efficiency.
{{< dots >}}
## Code 💻
```cpp
public:
BrowserHistory(string homepage) {
    bwd.push_back(homepage);
    fwd.resize(0);
}

void visit(string url) {
    bwd.push_back(url);
    fwd.resize(0);
}

string back(int steps) {
    int x = bwd.size();
    while(steps-- > 0 && bwd.size() > 1) {
        string p = bwd.back();
        fwd.push_back(p);
        bwd.pop_back();
    }
    return bwd.back();
}

string forward(int steps) {
    int x = fwd.size();
    while(steps-- > 0 && fwd.size() > 0) {
        string p = fwd.back();
        bwd.push_back(p);
        fwd.pop_back();
    }
    return bwd.back();        
}
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
```

The `BrowserHistory` class simulates a browser history with forward and backward navigation using two stacks (`bwd` for backward and `fwd` for forward). It provides the ability to visit new pages, go back, and go forward through the history.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Declaration**
	```cpp
	public:
	```
	The `public:` keyword makes the following methods accessible from outside the class, allowing interaction with the `BrowserHistory` object.

2. **Constructor**
	```cpp
	BrowserHistory(string homepage) {
	```
	This constructor initializes the browser history with a homepage URL. The homepage is added to the backward stack (`bwd`). The forward stack (`fwd`) is initialized as empty.

3. **Initialization**
	```cpp
	    bwd.push_back(homepage);
	```
	Adds the homepage URL to the backward stack (`bwd`). This represents the starting page of the browser history.

4. **Initialization**
	```cpp
	    fwd.resize(0);
	```
	Resets the forward stack (`fwd`) to ensure there is no forward history when the browser is first initialized.

5. **Method**
	```cpp
	void visit(string url) {
	```
	The `visit` method simulates visiting a new URL. It adds the URL to the backward stack and clears the forward stack (since visiting a new page resets the ability to move forward).

6. **Stack Operation**
	```cpp
	    bwd.push_back(url);
	```
	Adds the new URL to the backward stack (`bwd`) as the most recent page visited.

7. **Stack Operation**
	```cpp
	    fwd.resize(0);
	```
	Clears the forward stack (`fwd`) because visiting a new page invalidates any potential forward history.

8. **Method**
	```cpp
	string back(int steps) {
	```
	The `back` method allows the user to move backward in the browser history by a specified number of steps. It returns the URL after the backward navigation.

9. **Variable Declaration**
	```cpp
	    int x = bwd.size();
	```
	Stores the size of the backward stack (`bwd`) to track how many pages are available for backward navigation.

10. **Loop**
	```cpp
	    while(steps-- > 0 && bwd.size() > 1) {
	```
	The loop iterates until the required number of steps is reached or the backward stack contains only the homepage (since there's no page before it).

11. **Stack Operation**
	```cpp
	        string p = bwd.back();
	```
	Retrieves the most recent URL from the backward stack without removing it.

12. **Stack Operation**
	```cpp
	        fwd.push_back(p);
	```
	Adds the URL to the forward stack (`fwd`) because the user can potentially move forward to this page after going back.

13. **Stack Operation**
	```cpp
	        bwd.pop_back();
	```
	Removes the most recent URL from the backward stack as the user has moved backward.

14. **Return**
	```cpp
	    return bwd.back();
	```
	Returns the URL at the top of the backward stack, which is the current page after the backward navigation.

15. **Method**
	```cpp
	string forward(int steps) {
	```
	The `forward` method allows the user to move forward in the browser history by a specified number of steps. It returns the URL after the forward navigation.

16. **Variable Declaration**
	```cpp
	    int x = fwd.size();
	```
	Stores the size of the forward stack (`fwd`) to track how many pages are available for forward navigation.

17. **Loop**
	```cpp
	    while(steps-- > 0 && fwd.size() > 0) {
	```
	The loop iterates until the required number of steps is reached or the forward stack is empty.

18. **Stack Operation**
	```cpp
	        string p = fwd.back();
	```
	Retrieves the most recent URL from the forward stack without removing it.

19. **Stack Operation**
	```cpp
	        bwd.push_back(p);
	```
	Adds the URL to the backward stack (`bwd`) because the user can potentially move backward to this page after going forward.

20. **Stack Operation**
	```cpp
	        fwd.pop_back();
	```
	Removes the most recent URL from the forward stack as the user has moved forward.

21. **Return**
	```cpp
	    return bwd.back();        
	```
	Returns the URL at the top of the backward stack, which is the current page after the forward navigation.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for visit operations, O(min(steps, history)) for back/forward operations.
- **Average Case:** O(1) for visit, O(min(steps, history)) for back/forward.
- **Worst Case:** O(min(steps, history)) for back/forward operations.

Time complexity depends on the number of steps moved back or forward, but the visit operation is O(1).

### Space Complexity 💾
- **Best Case:** O(1) if no pages are visited.
- **Worst Case:** O(n) where n is the number of pages visited.

Space complexity is dependent on the number of visited pages stored in the history.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/design-browser-history/description/)

---
{{< youtube pvj8WQMPlGY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
