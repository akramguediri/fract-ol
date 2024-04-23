# Fract'ol Project

## Overview
This project aims to create a small computer graphics program using the MiniLibX library. The project is intentionally kept concise to serve as a foundation for understanding fractals and MiniLibX usage. It focuses on exploring fractals, specifically the Julia set and the Mandelbrot set, providing an opportunity to become familiar with MiniLibX, utilize complex numbers, understand optimization in computer graphics, and practice event handling.

## Objectives
- Utilize MiniLibX for graphical rendering
- Implement the Julia set and the Mandelbrot set fractals
- Allow zooming in and out using the mouse wheel
- Support creating different Julia sets with customizable parameters
- Display fractals using various colors to show depth
- Ensure smooth window management
- Implement clean program exit on ESC key press or window close
- Enhance visual effects, including psychedelic effects if possible

## Common Instructions
- Written in C language
- Compliance with project norms and guidelines
- Avoid unexpected program termination and memory leaks
- Submission of a Makefile for compilation
- Separate compilation of mandatory and bonus parts
- Use of own libft library if necessary

## Mandatory Part (fractol)
### Files to Turn in
- Makefile
- Header files (*.h)
- Source files (*.c)

### Arguments
- The type of fractal to display and any additional options

### External Functions
- Standard C library functions: open, close, read, write, malloc, free, perror, strerror, exit
- Math library functions (-lm compiler option)
- MiniLibX functions
- Custom printf function (if implemented)

### Description
The fractol program is designed for fractal exploration, focusing on the Julia set and the Mandelbrot set. It utilizes MiniLibX for graphical rendering and provides options for customizing fractal parameters.

### Rendering (V.1)
- Offers rendering of the Julia set and the Mandelbrot set
- Supports zooming in and out using the mouse wheel
- Allows creating different Julia sets with customizable parameters
- Handles rendering options through command-line parameters
- Uses colors to visualize the depth of each fractal, with optional psychedelic effects

### Graphic Management (V.2)
- Displays the image in a window using MiniLibX
- Ensures smooth window management, including minimizing and switching windows
- Allows clean program exit on ESC key press or window close

## Bonus Part
- Implementation of additional fractals beyond Julia and Mandelbrot sets
- Zoom functionality that follows the mouse position
- Movement of the view using arrow keys in addition to zoom
- Dynamic shifting of the color range for visual effects

## Note
The project is intentionally kept small to serve as a foundation for learning and understanding fractals and MiniLibX. It is designed to be easily understandable so that individuals can use it as a reference or basis for their own projects without overwhelming complexity.
