*This project has been created as part of the 42 curriculum by thitoe, hakama.*

# miniRT

A minimal ray tracer written in C as part of the 42 curriculum.
This project introduces the fundamentals of computer graphics, linear algebra, and ray tracing by rendering simple 3D scenes using mathematical calculations.

---

# Table of Contents

- [Description](#description)
- [Features](#features)
- [Project Structure](#project-structure)
- [Instructions](#instructions)
- [Scene Format](#scene-format)
- [Rendering Pipeline](#rendering-pipeline)
- [Technical Concepts](#technical-concepts)
- [Example](#example)
- [Resources](#resources)
- [AI Usage](#ai-usage)
- [Authors](#authors)

---

# Description

miniRT is an educational ray tracing engine developed in C using the MiniLibX graphical library.

The goal of the project is to build a renderer capable of generating images from a scene description file (`.rt`). The renderer simulates how rays of light interact with objects in a virtual 3D world to produce realistic lighting and shading.

The project focuses on:

- Ray-object intersection calculations
- Vector mathematics
- Camera projection
- Lighting models
- Scene parsing
- Rendering pipelines
- Graphics programming fundamentals

The program reads a `.rt` scene file and renders the corresponding image in a graphical window.

---

# Features

## Mandatory Features

- Ambient lighting
- Point light source
- Camera system
- Sphere rendering
- Plane rendering
- Cylinder rendering
- Phong lighting model
- Scene parsing and validation
- Window rendering using MiniLibX

---

# Project Structure

```bash
miniRT/
├── include/
├── src/
├── minilibx/
├── Makefile
└── README.md
````

---

# Instructions

## Requirements

### Linux

Install dependencies:

```bash
sudo apt update
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

### macOS

Install XQuartz:

```bash
brew install --cask xquartz
```

---

## Clone the Repository

```bash
git clone --recursive https://github.com/thaperei-hermarti/minirt.git
cd minirt
```

---

## Compilation

Compile the project:

```bash
make
```

Available Makefile rules:

```bash
make clean
make fclean
make re
```

---

## Execution

Run the renderer with a scene file:

```bash
./miniRT scenes/mandatory/simple.rt
```

---

# Scene Format

The renderer uses `.rt` files to describe scenes.

Example:

```txt
A 0.2 255,255,255

C -50.0,0,20 0,0,1 70

L -40.0,50.0,0.0 0.6 255,255,255

sp 0.0,0.0,20.6 12.6 10,0,255

pl 0.0,-1.0,0.0 0.0,1.0,0.0 255,0,225

cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```

## Supported Elements

| Identifier | Description   |
| ---------- | ------------- |
| `A`        | Ambient light |
| `C`        | Camera        |
| `L`        | Light source  |
| `sp`       | Sphere        |
| `pl`       | Plane         |
| `cy`       | Cylinder      |
---

# Rendering Pipeline

The rendering process follows these steps:

* Read and tokenize the .rt scene description file
* Build internal scene representation (camera, lights, and transformed quadratic surfaces)
* Generate primary rays from the camera through each pixel
* Compute ray–object intersections using matrix-defined quadric surfaces in object/world space
* Evaluate illumination at hit points (ambient, diffuse, specular shading with shadows)
* Write computed color values into the frame buffer
* Present the final image in the rendering window via MiniLibX

---

# Technical Concepts

## Ray Tracing

Ray tracing simulates the behavior of light by casting rays from the camera into the scene and calculating intersections with objects.

## Linear Algebra

The project relies heavily on:

* Vector addition and subtraction
* Dot products
* Cross products
* Vector normalization
* Geometric calculations

## Lighting

The renderer generally uses:

* Ambient lighting
* Diffuse lighting
* Specular highlights

## Graphics Programming

MiniLibX is used to:

* Create windows
* Draw images
* Manipulate pixels
* Handle keyboard and window events

---

# Example

Example execution:

```bash
./miniRT　test/04Shadow.rt
```

---

# Resources
We referred to the following resources during the development of this project.

## Ray Tracing
https://jun-networks.hatenablog.com/entry/2021/04/02/043216#%E4%BD%8D%E7%BD%AE%E3%81%A8%E5%90%91%E3%81%8D%E3%81%A8FOV%E3%81%8C%E5%8F%AF%E5%A4%89%E3%81%AA%E3%82%AB%E3%83%A1%E3%83%A9c
https://knzw.tech/raytracing/?page_id=1243

## Mathematics
https://manabitimes.jp/math/2649
https://zenn.dev/mebiusbox/articles/8e765148576919#%F0%9F%93%8C-%E3%81%8A%E3%82%8F%E3%82%8A%E3%81%AB

## 42 References
* 42 miniRT subject
* MiniLibX official documentation

---

# AI Usage

AI tools were used to support the development process in areas such as understanding ray tracing principles, clarifying mathematical formulations, debugging vector and geometric computations, and assisting with documentation structure and README formatting.

---

# Authors

* thitoe
* hakama

---
