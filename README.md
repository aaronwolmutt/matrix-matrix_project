# Multiplication timer
A c++ project that analyzes performance differences between using the standard c++ library and the Eigen library for matrix-matrix multiplication and vector dot product. 

This was a project submission I developed at the University of Iowa that was refactored as of February 2019. The Eigen library is included with the project.

### System wide dependencies required
```
Cmake 3.5 + 
c++ 14
```

### Installation and usage example:
Create the build:
```
$ mkdir build; cd build; cmake ..
```
Compile the project into an executable: 
```
$ make 
```
Execute the binaries: 
```
$ ./run
```
### Outputs: 

Matrix-matrix multiplication tests:
size: 100
	 Eigen: 0.00175811
	 std::vector: 2.6e-08


size: 1000
	 Eigen: 0.0329949
	 std::vector: 2e-08


size: 10000
	 Eigen: 3.09686
	 std::vector: 8.5e-08


Vector dot product tests:
size: 100
	 Eigen: 7.854e-06
	 std::vector: 2.5e-08


size: 1000
	 Eigen: 8.7736e-05
	 std::vector: 1.4e-08


size: 100000
	 Eigen: 0.00301381
	 std::vector: 1.5e-08


size: 1000000
	 Eigen: 0.0319976
	 std::vector: 5.9e-08
