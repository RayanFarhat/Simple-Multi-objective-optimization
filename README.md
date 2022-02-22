# Simple-Multi-objective-optimization
This is a simple c++ program that do Multi objective optimization.
it gets a file and do multi objective optimization (multi dimensions sorting) with it.<br/>
There is a feasible solution vectors (in the code it is vectors) in n dimensions and multiple objective functions in m dimensions, so for every vector there is function:<br/>
𝑓⃗<sup>𝑘</sup> (𝑥⃗<sup>𝑘</sup>) = {𝑓1<sup>𝑘</sup>(𝑥⃗<sup>𝑘</sup>), … , 𝑓𝑚<sup>𝑘</sup>(𝑥⃗<sup>𝑘</sup>)}<br/>
for more about how it is works please [click here](https://en.wikipedia.org/wiki/Multi-objective_optimization).
- I made it to provide simple solution for this problem in code, feel free to use it and i hope that this code will help you.<br/>
#### Development:
in part one I developed the element in templates so it will adopt almost all types.(I did it for practicing), And did the sorting functions (ParetoSorting).<br/>
in part two I developed the use of part one with normal vectors in `flout`.<br/>
- I developed in C++98 with GCC 4.8.4.<br/>
##### once you compiled the program you need to run it with two files (arguments) `./program_name input.dat output.dat`.<br/>
The output.dat is the output file and it will be empty.<br/>
input.dat is example of text file that that need to contain the elements under this conditions:
- in first line in input file :
  - first number is the number of objects
  - second number is the dimension of feasible solution vector
  - third number is the dimension of objective vector
  - forth number is how many times to generate new objects
- the rest of lines contain feasible solution vectors for objects
The results will printed in the output file.<br/>
Example:<br/>
example of input file content :<br/>
```
10 6 3 5000
0.5 0.5 0.5 0.5 0.5 0.5
0.1 0.1 0.2 0.5 0.5 0.5
0.0 0.0 0.0 0.0 0.0 0.1
0.1 0.0 0.2 0.5 0.5 1.0
1.0 0.0 0.0 0.0 0.0 0.0
0.0 1.0 0.0 0.0 0.0 0.0
0.0 0.0 1.0 0.0 0.0 0.0
0.0 0.0 0.0 1.0 0.0 0.0
0.0 0.0 0.0 0.0 1.0 0.0
0.0 0.0 0.0 0.0 0.0 1.0
```
example of output file content after running:<br/>
```
23.36 5.76 0.16
24.47 6.27 0.07
23.77 5.97 0.17
24.47 6.27 0.07
24.18 6.18 0.18
24.47 6.27 0.07
24.2 6.2 0.2
21.41 4.81 0.21
25.7 6.9 0.1
24.22 6.22 0.22
```
das
