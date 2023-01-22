> **WARNING** The "fdf" project follows the norms set by the school 42, which some people may not agree with. Some users may feel that the structure of the project does not look aesthetically pleasing or intuitive due to the constraints imposed by these norms. However, it is important to remember that the purpose of the "fdf" project is to teach students certain programming concepts and techniques, and the strict adherence to the norms set by the school is necessary to ensure that students are able to learn these concepts effectively.

# fdf
fdf, which stands for Fil de Fer or Wireframe, is a project from the 42 School curriculum that displays a terrain based on file data.

## How to run
Compile the solution with the Makefile provided, using the command `make re`. This will create an executable (for linux), which 
you can run in the terminal, followed by the data file you want to display.
```
make re && ./fdf maps/42.fdf
```

## File format
The file format accepted by the program is very precise, the data forming nodes or in other words tiles must be spaced with spaces,
and line breaks. For now, the map must be of regular size, i.e. the length of the lines must be the same everywhere.\
The data containing, represent the heights of the nodes, but also its colours by the following format:
```
0  0          0  0 0
0 10,0x000ff 10 10 0
0 10         20 10 0
0  0          0  0 0
```
Also, note that it does not have to end with `.fdf`
