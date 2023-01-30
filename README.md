# CS10BW2023
## GitHub for SI

## Setting up a GitHub Key

## Using GitHub

## Useful Commands:
**Compiling the Code**
MacOS/Linux:  
```
g++ -std=c++17 main.cpp
```
Windows:  
```
g++ main.cpp
```
**Running the Code**
MacOS/Linux:  
```
./a.out
```
Windows:  
```
a.exe
```

**Compilation Flags**
`-Werror` treats warnings as errors  
`-o <name>` creates a different output name (i.e. `run` instead of `a.out`  
`-std=c++#` sets C++ version to `#`  

**Useful Tips**
* If you want to learn makefiles, you can go [here](https://makefiletutorial.com/). Makefiles are essential a script that compiles and sets up everything that is needed to create your runnable code.
* Compiling multiple files is like this: `g++ main.cpp a.cpp b.cpp`. If you know you want to compile every `.cpp` file in the directory, do this instead `g++ *.cpp`. `*` in CS is universal for "Everything", and doing `*.cpp` means "Everything with `.cpp` as the extention.
