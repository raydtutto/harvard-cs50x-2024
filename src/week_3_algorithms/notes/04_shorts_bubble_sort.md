# Bubble sort

Instructor: **[Doug Lloyd](https://github.com/dlloyd09)**

---

In bubble sort, the idea of the algorithm is to move higher valued
elements generally towards the right and lower value elements
generally towards the left.

Pseudocode:

```
Set swap counter to a non-zero value
• Repeat until the swap counter is 0:
    • Reset swap counter to 0
    • Look at each adjacent pair
        • If two adjacent elements are not in order, swap them and add one to the swap
          counter
```

Set swap counter to a non-zero value:

<img src="img/15.png" alt="1">

Reset swap counter to a zero value:

<img src="img/16.png" alt="1">

Look at adjacent pair and check the order:

<img src="img/17.png" alt="1">

Swap and counter++:

<img src="img/18.png" alt="1">

Look for the next adjacent pair:

<img src="img/19.png" alt="1">

Swap and counter++:

<img src="img/20.png" alt="1">

...

Repeat till the last pair:

<img src="img/21.png" alt="1">

We can declare that the last number is the largest, and it is on the right position in the array:

<img src="img/22.png" alt="1">

Reset counter to 0:

<img src="img/23.png" alt="1">

Repeat steps with adjacent pairs but without the last element:

<img src="img/24.png" alt="1">

...



<img src="img/25.png" alt="1">

<img src="img/26.png" alt="1">

We checked all adjacent pair and do not swap anything, so the counter is `0`.
Thus, we can declare that the array was sorted successfully.

<img src="img/27.png" alt="1">

> #### Worst case scenario `O(n2)`
> The array is in reverse order; we have to “bubble” each of the n elements all the way across the array, and since
> we can only fully bubble one element into position per pass, we must do this n times.

> #### Best case scenario `Ω(n)`
> The array is already perfectly sorted, and we make no swaps on the first pass.