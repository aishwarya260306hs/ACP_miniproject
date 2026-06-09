# 2D Graphics Editor in C

## Overview

This project is a simple **2D Graphics Editor** developed in C using a text-based canvas. The application allows users to draw, delete, modify, and display basic geometric shapes on a console-based canvas.

The project demonstrates the implementation of fundamental computer graphics algorithms and menu-driven programming concepts in C.

---

## Features

* Draw Rectangle
* Draw Line (Bresenham's Line Algorithm)
* Draw Circle (Midpoint Circle Algorithm)
* Draw Triangle
* Delete Shapes

  * Rectangle
  * Line
  * Circle
  * Triangle
* Modify Existing Rectangle
* Display Canvas
* Boundary-safe plotting of points

---

## Technologies Used

* Programming Language: C
* Compiler: GCC / MinGW GCC
* Platform: Windows/Linux Console

---

## Canvas Specifications

| Property       | Value |
| -------------- | ----- |
| Rows           | 25    |
| Columns        | 60    |
| Empty Pixel    | `_`   |
| Draw Character | `*`   |

---

## Algorithms Implemented

### 1. Bresenham's Line Drawing Algorithm

Used for efficient rasterization of straight lines.

### 2. Midpoint Circle Algorithm

Used for drawing circles using integer arithmetic.

### 3. Rectangle Drawing

Draws the boundary of a rectangle using horizontal and vertical edges.

### 4. Triangle Drawing

Constructed using three line segments connecting three vertices.

---

## Project Structure

```text
acp_miniproject.c
│
├── main()
├── newCanvas()
├── displayCanvas()
├── plot()
├── drawRectangle()
├── drawLine()
├── circlePoints()
├── drawCircle()
└── drawTriangle()
```

---

## Compilation

Using GCC:

```bash
gcc acp_miniproject.c -o graphics_editor
```

Run:

```bash
./graphics_editor
```

### Windows (PowerShell)

```powershell
gcc acp_miniproject.c -o graphics_editor
.\graphics_editor.exe
```

---

## Sample Menu

```text
===== 2D GRAPHICS EDITOR =====

1. Draw Rectangle
2. Draw Line
3. Draw Circle
4. Draw Triangle
5. Delete Rectangle
6. Delete Line
7. Delete Circle
8. Delete Triangle
9. Modify Rectangle
10. Display Canvas
0. Exit
```

---

## Example Usage

### Draw Rectangle

Input:

```text
1
2 5 10 4
```

Where:

* Row = 2
* Column = 5
* Width = 10
* Height = 4

### Draw Triangle

Input:

```text
4
3 5
10 20
15 8
```

---

## Learning Outcomes

This project helps in understanding:

* Computer Graphics Fundamentals
* Raster Graphics
* Geometric Shape Construction
* Data Representation using 2D Arrays
* Menu-Driven Program Design
* Modular Programming in C

---

## Future Enhancements

* Shape Filling
* Color Support
* Shape Movement
* Shape Rotation
* Shape Scaling
* File Save and Load Functionality
* Graphical User Interface (GUI)
* Undo/Redo Operations

---

## Author

Aishwarya

ACP Mini Project
2D Graphics Editor using C
