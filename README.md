# 42KL-CP-Push_swap
Writing a sorting algorithm is always a very important step in a developer’s journey.

Sorting values is simple.

To sort them the fastest way possible is less simple.

Especially because from one integer configuration to another, the most efficient sorting solution can differ.

Push Swap challenges sorting data on a stack using a limited set of instructions in C, aiming to achieve the lowest possible number of actions.

I've learned to manipulate various types of sorting algorithms and choose the most appropriate and optimized solution for efficiently sorting data.


## Project Demo

![Project Demo](https://github.com/DoughnutsNCookies/42KL-CP-Push_swap/blob/main/readmeAssets/Push%20Swap-gif.gif)


## Rules
- There are 2 stacks named `a` and `b`
- In the beginning
    - Stack `a` contains a random amount of negative and/or positive numbers which cannot be duplicated.
    - Stack `b` is empty.
- The goal is to sort in ascending order numbers into stack `a`. Here are the following operations at your disposal:

**Swaps**:
- `sa` (swap `a`): Swap the first 2 elements at the top of stack `a`. Do nothing if there is only one or no element.
- `sb` (swap `b`): Swap the first 2 elements at the top of stack `b`. Do nothing if there is only one or no element.
- `ss`: `sa` and `sb` at the same time.

**Push**    
- `pa` (push `a`): Take the first element at the top of `b` and put it at the top of `a`. Do nothing if `b` is empty.
- `pb` (push `b`): Take the first element at the top of `a` and put it at the top of `b`. Do nothing if `a` is empty.
    
**Rotate**
- `ra` (rotate `a`): Shift up all elements of stack `a` by 1. The first element becomes the last one.
- `rb` (rotate `b`): Shift up all elements of stack `b` by 1. The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.

**Reverse Rotate**
- `rra` (reverse rotate `a`): Shift down all elements of stack `a` by 1. The last element becomes the first one.
- `rrb` (reverse rotate `b`): Shift down all elements of stack `b` by 1. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time.


## Example
**Initialize stack `a` and stack `b`**
```
2
1
3
5
4
6
_ _
a b
```

**`sa`: Swaps the first 2 elements at the top of stack `a`**
```
1
2
3
5
4
6
_ _
a b
```

**`pb` `pb` `pb`: Take the first element at the top of `a` and put it at the top of `b` 3 times**
```
5 3
4 2
6 1
_ _
a b
```

**`rr`: `ra` and `rb` at the same time. Shift up all elements of stack `a` and stack `b` by 1. The first element becomes the last one**
```
4 2
6 1
5 3
_ _
a b
```

**`rrr`: `rra` and `rrb` at the same time. Shift down all elements of stack `a` and stack `b` by 1. The last element becomes the first one**
```
5 3
4 2
6 1
_ _
a b
```

**`sa`: Swaps the first 2 elements at the top of stack `a`**
```
4 3
5 2
6 1
_ _
a b
```

**`pa` `pa` `pa`: Take the first element at the top of `b` and put it at the top of `a` 3 times**
```
1
2
3
4 
5 
6 
_ _
a b
```
## Author
- [@DoughnutsNCookies](https://www.github.com/DoughnutsNCookies)

