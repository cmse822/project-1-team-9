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


## part 1
### 1. 

```
for (int i = 0; i < r1; i++) {
        for (int k = 0; k < c2; k++) {
            for (int j = 0; j < c1; j++) {
                answer[i][k] += Array1[i][j] * Array2[j][k];
            }
        }
    }
```

### 2. 
In the innermost line of the loops, there are two floating point operations. This line is executed $N^3$
 times. Therefore, the total number of flop is $2N^3$
.

### 3. 

One node on HPCC have been selected for this project. The specifications of this one CPU can be found in the following table:
| CPU                             | clock speed | L1 cache size | L2 cache size | L3 cache size | Number of cores per socket |
|:-------------------------------:|:-----------:|:-------------:|:-------------:|:-------------:|:--------------------------:|
| AMD EPYC 7H12 64-Core Processor | $2.6$ GHz  | $32$ KB       | $512$ KB      | $16$ MB       | 64                         |

