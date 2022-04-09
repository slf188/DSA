# 18 - Asymptotic Notations

- We have seen various algorithms, functions and operations on data structures.
- We have came up with the time complexities in various forms.
- We have gotten time complexities that include:

$$
1<\log n<n<n\log n<n^2<n^3<...<2^n<3^n...<n^n
$$

- The algorithms will differ in the amount of time they will get performed
- The time complexities we just included differ in different categories which are:

$$
Polynomial: ~1<\log n<n<n\log n<n^2<n^3<...<2^n<3^n\\Exponential:~2^n<3^n...<n^n
$$

- By knowing the function we can give the time complexity

![Screen Shot 2022-01-30 at 12.28.27.png](18%20-%20Asymp%2088487/Screen_Shot_2022-01-30_at_12.28.27.png)

- But suppose we have a function that is: $f(n)=\sum^{n}_{i=1}ix2^i$, it is difficult to expand and get a single formula, we have to approximate because we will not be able to get the exact formula,
- This means we cannot mention the time, except if we choose between taking a lower or higher value. In case we take:
    - **Lower bound:** Lower value we will have to use $\Omega()$
    - **Upper bound:** bigO for a higher value $O()$
    - **Tight bound:** Too take an exact value we can use: $\theta()$
- These notations are perfect if we cannot get the exact polynomial formula for a function.
- These notations can be explained if we take the following example: Let’s say we are interested in buying a phone but we don’t know the price of that phone, someone can answer that question to tackle BigO by saying it will cost 1000$ at most, or to tackle omega they can say it will cost 250$ at least, or someone who knows the exact price will say it costs 800$.
- If we are worried about these notations, fear not. **Most of the time we will get exact results so we will use order of or theta.**
- The reason why a lot of text books prefer using BigO for algorithm analysis is because bigO means greater or equal, so it is more precise if we compare the following cases:

$$
f(n)=O(n)\\f(n)=\Omega(n)\\f(n)=\theta(n)
$$