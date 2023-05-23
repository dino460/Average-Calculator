# Average Calculator

# Overview
Average Calculator is a simple C program designed to calculate the average, weighed average, standard deviation, highest and lowest values of a set of user-inputed floating point numbers. 
# Features
Calculations:
- [x] Average
- [x] Weighed Average
- [x] Standard Deviation

Data aquisition:
- [x] Highest value
- [x] Lowest value
- [x] Get all inputed values
- [x] Get all inputed weights
- [x] Number of inputs
- [x] Read values from file
- [x] Read weights from file
# Installing and Running
You must first clone the repository and then compile the C code (MakeFile coming soon):
```
git clone https://github.com/dino460/Average-Calculator
cd Average-Calculator
gcc -o average average.c calcfunctions.c gui.c -lm
```
### Running on Linux/MacOS
While in the folder that you compiled it:
```
./average
```
### Running on Windows
While in the folder that you compiled it:
```
average
```
# Why
Just an overkill way of implementing a simple calculator for an Introduction to Computer Science class.
# Usage
| Command | Description |
| --- | --- |
| set | Requests input for values |
| stw | Requests input for weights |
| sps | Requests input for sample size |
| rsv | Resets values to zero |
| rsw | Resets weights to zero |
| rsa | Resets values and weights to zero |
| rvf | Requests input for file name and reads values from file |
| rwf | Requests input for file name and reads weights from file |
| shs | Prints the current value for the sample size |
| shv | Prints all current inputed values |
| shw | Prints all current weights |
| sha | Executes `shs`, `shv` and `shw` |
| avg | Calculates and prints the average of inputed values |
| wav | Calculates and prints the weighted average of inputed values |
| std | Calculates and prints the standard deviation of inputed values |
| bvl | Prints biggest value of inputed values |
| svl | Prints smallest value of inputed values |
| hid | Hides no inputed values/weights message |
| rsc | Clears the screen and prints the 'main menu' |
| h | Shows this command list |
| q | Terminates the program | 



Developed by Raphael Zoega and Ian Freitas.
