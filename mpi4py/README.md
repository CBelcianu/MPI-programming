
## MPI using Python 3
> In order to install mpi4py run the following commands.

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

To be described.

## Future read

 - [MIT OpenCourseWare, Karatsuba Multiplication, Newton's Method](https://www.youtube.com/watch?v=JRgIXyEPnbA)
 - [Algorithm explained, Karatsuba Algorithm for Fast Multiplication](https://www.youtube.com/watch?v=IxSxi2P6Fmg)
