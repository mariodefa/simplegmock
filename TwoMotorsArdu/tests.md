# run tests guide
## Create gtest docker img  
start docker and then  
```Shell
cd gtestDocker
docker build -t mario-gtest .
cd ..
```
## Create this project docker img  
```Shell
docker build -t tmotrs .
```
and run container and enter the container bash  
## Setup the project config  
```Shell
cmake -S . -B build
```
## Compile the project   
```Shell
cmake --build build
```
## Run tests  
```Shell
cd build && ctest
```

