# fdf - Wireframe Renderer

**WARNING**: The "fdf" project adheres to the specific coding standards (`norms`) of 42 School. While these norms may appear unconventional, they serve an educational purpose, emphasizing certain programming concepts and techniques within a constrained environment.

## About fdf

`fdf`, short for "Fil de Fer" (French for wireframe), is an educational project from the 42 School's curriculum. It is designed to render 3D wireframe representations of terrain maps read from text files. This project is written in C and utilizes the minilibx library for graphics rendering.

![Showcase](https://i.imgur.com/Aq85MJW.png)

## Table Of Contents

- [Getting Started](#getting-started)
- [Installation](#installation)
- [Usage](#usage)
- [File Format](#file-format)
- [Features](#features)
- [Project Structure](#project-structure)

## Getting Started

This repository includes submodules for dependencies like the minilibx graphics library. To properly clone the full project, including its dependencies:

```bash
git clone --recurse-submodules https://github.com/suiramdev/42-fdf.git
```

Alternatively, if you've already cloned the repository, initialize and update the submodules with:

```bash
git submodule init
git submodule update
```

## Installation

After cloning the repository and setting up submodules, you can compile the project using the included Makefile:

```bash
make re
```

This will generate an executable named `fdf` in your project directory.

## Usage

To visualize a wireframe map, run the compiled executable with a map file as an argument:

```bash
./fdf maps/42.fdf
```

## File Format

The `fdf` program accepts a specific file format. Each data point represents a vertex's height and optionally its color. The format is a grid of space-separated numbers with optional hexadecimal color values, and each row is a new line. Consistent row lengths are required:

```
0  0          0  0  0
0  10,0x000ff 10 10 0
0  10         20 10 0
0  0          0  0  0
```

Files do not need to have a `.fdf` extension, although it is customary.

## Features

- **3D Wireframe Rendering**: Visualize any terrain in a three-dimensional perspective.
- **Color Parsing**: Recognize and display vertex colors as specified in the map file.
- **Interactive Zoom**: Use your mouse wheel or trackpad to zoom in and out.

## Project Structure

The project's source code is organized as follows:

- `/src`: Contains all the C source files.
- `/include`: Header files for the project.
- `/maps`: Example map files in the `.fdf` format.
- `/lib/minilibx`: The minilibx graphics library used for rendering.
- `/lib/libft`: A custom library with default C functions rewritten to suit project requirements.
