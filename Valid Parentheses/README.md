# 🧩 Valid Parentheses

![C++](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green.svg)
![Status](https://img.shields.io/badge/Status-Solved-brightgreen.svg)

---

## 📌 Problem Statement

Given a string `s` containing just the characters:

```
( ) { } [ ]
```

Determine if the input string is **valid**.

### ✅ A string is valid if:

* Open brackets are closed by the same type.
* Open brackets are closed in the correct order.
* Every closing bracket has a corresponding opening bracket.

---

## 🧠 Approach (Using Stack)

We use a **stack (LIFO)** to track opening brackets.

### 💡 Idea:

* Push opening brackets → `(` `{` `[`
* When a closing bracket appears:

  * Check if stack is empty → ❌ invalid
  * Compare with top of stack
  * If matching → pop
  * Else → ❌ invalid
* At the end:

  * If stack is empty → ✅ valid

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            // Push opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty → invalid
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching pairs
                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Final check
        return st.empty();
    }
};
```

---

## 🔄 Dry Run Example

### Input:

```
s = "{[()]}"
```

### Step-by-step:

| Character | Stack   |
| --------- | ------- |
| `{`       | `{`     |
| `[`       | `{ [`   |
| `(`       | `{ [ (` |
| `)`       | `{ [`   |
| `]`       | `{`     |
| `}`       | empty ✅ |

✔ All matched → **Valid**

---

### ❌ Invalid Example

```
s = "(]"
```

| Character | Stack      |
| --------- | ---------- |
| `(`       | `(`        |
| `]`       | ❌ mismatch |

→ **Invalid**

---

## ⏱️ Complexity Analysis

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n)       |
| Space | O(n)       |

---

## 🎯 Key Takeaways

* Stack is perfect for matching problems
* Always check:

  * Stack empty condition
  * Correct bracket pairing
* Final stack must be empty

---

## 🚀 How LeetCode Works

* You **do not print** anything
* Just return:

  ```cpp
  return true;  // valid
  return false; // invalid
  ```
* The platform automatically displays:

  ```
  true / false
  ```

---

## 🏁 Summary

✔ Push opening brackets
✔ Match closing brackets
✔ Pop when matched
✔ Stack empty → Valid

---

⭐ If you found this helpful, consider giving a star!
