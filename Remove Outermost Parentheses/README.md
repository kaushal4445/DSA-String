# 🧩 Remove Outermost Parentheses

## 📌 Problem Statement

Given a valid parentheses string `s`, remove the **outermost parentheses** of every primitive substring and return the resulting string.

A **primitive parentheses string** is a non-empty valid parentheses string that cannot be divided into two non-empty valid parentheses strings.

---

## 💡 Approach

We use a variable called `level` to keep track of the current nesting depth of parentheses.

### Algorithm

1. Initialize:
   - `result = ""`
   - `level = 0`

2. Traverse each character in the string.
   - If the character is `'('`:
     - If `level > 0`, append it to the result.
     - Increase `level`.
   - If the character is `')'`:
     - Decrease `level`.
     - If `level > 0`, append it to the result.

3. Return the final result.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    string removeOuter(string &s) {

        string result = "";
        int level = 0;

        for(char ch : s){

            if(ch == '('){
                if(level > 0)
                    result += ch;
                level++;
            }
            else if(ch == ')'){
                level--;

                if(level > 0)
                    result += ch;
            }
        }

        return result;
    }
};
```

---

# 🔍 Dry Run

### Input

```text
(()())(())
```

Initial State

```text
level = 0
result = ""
```

| Character | Level Before | Action | Level After | Result |
|------------|-------------|--------|------------|--------|
| ( | 0 | Ignore outer '(' | 1 | "" |
| ( | 1 | Add '(' | 2 | "(" |
| ) | 2 | Decrease & Add ')' | 1 | "()" |
| ( | 1 | Add '(' | 2 | "()(" |
| ) | 2 | Decrease & Add ')' | 1 | "()()" |
| ) | 1 | Decrease to 0, Ignore | 0 | "()()" |
| ( | 0 | Ignore outer '(' | 1 | "()()" |
| ( | 1 | Add '(' | 2 | "()()(" |
| ) | 2 | Decrease & Add ')' | 1 | "()()()" |
| ) | 1 | Decrease to 0, Ignore | 0 | "()()()" |

### Output

```text
()()()
```

---

# 📊 Visual Explanation

## Input

```text
(()())(())
```

Split into primitive strings

```text
(()())     (())
```

Remove outer parentheses

```text
(()())  →  ()()
(())    →  ()
```

Final Output

```text
()()()
```

---

# 📈 Nesting Level Diagram

```
Input: (()())

Character   Level      Result

(             0→1        Ignore
(             1→2        (
)             2→1        ()
(             1→2        ()(
)             2→1        ()()
)             1→0        Ignore

Output
()()
```

---

# 🎯 Why `level > 0` for '('?

When we encounter an opening parenthesis:

```cpp
if(level > 0)
    result += ch;
level++;
```

If `level == 0`, it means this is the **outermost opening bracket**, so we skip it.

Example

```text
Input

(())

Diagram

( ( ) )
↑       ↑
Skip    Skip
```

Only the inner pair is kept.

Result

```text
()
```

---

# 🎯 Why decrement before checking ')'?

```cpp
level--;

if(level > 0)
    result += ch;
```

The last closing parenthesis of a primitive should also be removed.

Example

```text
(())

Last ')'

Before decrement

level = 1

After decrement

level = 0

Since level is now 0,
do not add this ')'.
```

---

# 📌 Example

### Example 1

**Input**

```text
(()())(())
```

**Output**

```text
()()()
```

---

### Example 2

**Input**

```text
(()())(())(()(()))
```

**Output**

```text
()()()()(())
```

---

### Example 3

**Input**

```text
()()
```

**Output**

```text
""
```

---

# ⏱ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time Complexity | **O(n)** |
| Space Complexity | **O(n)** |

- We traverse the string only once.
- The result string stores the required characters.

---

# 🧠 Key Points

- ✔ Use a **nesting level** variable.
- ✔ Skip the first `'('` of every primitive.
- ✔ Skip the last `')'` of every primitive.
- ✔ Every other parenthesis is added to the answer.
- ✔ Single traversal gives an efficient **O(n)** solution.

---

## 🚀 Output Example

```text
Input
(()())(())

↓

Remove Outer Parentheses

↓

Output
()()()
```
