## Project FDF

FDF (Fil de Fer) is a graphic project from the 42 School curriculum. The objective of this project is to create a program that takes in a 3D file representation and renders a 2D representation of its wireframe.

### Requirements
- X11 library
- GCC compiler
- Make

### Installation
1. Clone this repository.
2. Enter the repository: `cd fdf`
3. Compile the program: `make`

### Usage
1. Run the program: `./fdf [map]`
2. The program takes in a single argument, the name of the map file.
3. Use the following keys to interact with the image:
    - Move: arrow keys
    - Zoom: + and - keys
    - Change projection: 1 and 2 keys
    - Exit: Esc key

### Map file format
The map file is a text file that represents the 3D data to be rendered. The file consists of a series of integers separated by spaces, with a new line for each vertex. The first two integers represent the x and y coordinates of the vertex, and the third integer represents the z coordinate. The coordinates are used to calculate the position of each vertex in 3D space, and the program uses these positions to draw the wireframe.

Here is an example map file:

0 0 0

0 1 0

1 0 0

