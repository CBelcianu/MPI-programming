
## MPI using Python 3
> In order to install mpi4py run the following commands. In the following lines square brackets are used to denote optional strings that I personally used due to my system configuration, but they are not necessarly true for each and every system.

In case of getting some errors, try running:
```
brew install mpich
```

Otherwise, just run:
```
[sudo] pip[3] install mpi4py 
```

Or read the documentation from this [link](https://mpi4py.readthedocs.io/en/stable/install.html#requirements).

## Testing the MPI

You can find a test script under the '/exmps' folder made to quickly test if the installation succesfully succeded.

Run: `mpirun -np 4 python[3] exmp.py`

Expect: 
```
process 0 received message from process 1 : Hello from 1
process 0 received message from process 2 : Hello from 2
process 0 received message from process 3 : Hello from 3
```

## Karatsuba algorithm using Python3 and MPI

For this algorithm we need a minimum number of 4 nodes, given that the node labeled with 0 has the role of a parent node, computing the partial results provided by the child nodes labeled with numbers between 1 and 3. 

```
mpirun -np 4 python3 karatsuba_with_mpi.py 
```

Expected result:
```
username$ mpirun -np 4 python3 karatsuba.py 
0
received:  0
received:  10
received:  15
computed s4 as: 5
result:  60
1
result:  None
2
result:  None
3
result:  None
```

## Future read

 - [MIT OpenCourseWare, Karatsuba Multiplication, Newton's Method](https://www.youtube.com/watch?v=JRgIXyEPnbA)
 - [Algorithm explained, Karatsuba Algorithm for Fast Multiplication](https://www.youtube.com/watch?v=IxSxi2P6Fmg)
