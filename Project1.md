## Warm-up

Computing arithmetic intensity for given compute kernels. 

```C
  Y[j] += Y[j] + A[j][i] * B[i]
```

```C
  s += A[i] * A[i]
```

```C
  s += A[i] * B[i]
```

```C
  Y[i] = A[i] + C*B[i]
```

|   | Operations | Load | Write | Arithmetic intensities |
|:-:|:----------:|:----:|:-----:|:----------------------:|
| 1 |      3     |   3  |   1   |     3/(4*8) = 3/32     |
| 2 |      2     |   1  |   0   |      2/(1*8) = 1/4     |
| 3 |      2     |   2  |   0   |      2/(2*8) = 1/8     |
| 4 |      2     |   2  |   1   |     2/(3*8) = 1/12     |