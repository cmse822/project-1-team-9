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

|kernels| Operations | Load | Write | Arithmetic intensities |
|:-:|:----------:|:----:|:-----:|:----------------------:|
| Y[j] += Y[j] + A[j][i] * B[i] |      3     |   3  |   1   |     3/(4*8) = 3/32     |
| s += A[i] * A[i] |      2     |   1  |   0   |      2/(1*8) = 1/4     |
| s += A[i] * B[i] |      2     |   2  |   0   |      2/(2*8) = 1/8     |
| Y[i] = A[i] + C*B[i] |      2     |   2  |   1   |     2/(3*8) = 1/12     |
