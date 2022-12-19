# - [ ] Overview

- [ ] Validate `.rt` scene files
- [x] Vectors
- [x] Parse `.rt` scene files
- [ ] Ray tracing logic
  - [ ] Camera
  - [ ] Spheres
  - [ ] Planes
  - [ ] Cylinders
  - [ ] Ambient light
  - [ ] Spot Light
  - [ ] Hard Shadows
- [ ] Minilibx user interface

# - [ ] Mandatory

- [ ] Don't turn in libs as submodules.
- [ ] Makefile should explicitly name all source files (`make dump_sources`).
- [ ] Make must compile without relinking
  - [ ] `make all` shouldn't recompile/rearchive any objects or sources.
  - [ ] Add `.keep` to object dirs
  - [ ] Create non-phony rule for each lib archive
- [ ] Compiles with workspace's `cc` (`clang` version `12.0.1`)
  - [ ] Switch Makefile's `clang-12` to `CC` before submitting.
- [ ] Program name `miniRT`
- [ ] Test in workspaces
- [ ] Follows `norminette 3.3.51`
- [ ] Makefile rules: `$(NAME)` `all` `clean` `fclean` `re` `bonus`
- [ ] Make must compile without relinking
- [ ] Compiles with `-Wall -Wextra -Werror`
- [ ] `Makefile` must not relink
- [ ] Should not quit unexpectedly (segmentation fault, bus error, double
      free, etc.)
- [ ] All allocated heap memory properly freed, no memory leaks.
  - [ ] Use gcc `-fsanitize=leak` flag.
  - [ ] Check memory leaks with `valgrind`.
- [ ] Turn in `Makefile`, `*.h`, `*.c`, `.gitignore`
- [ ] Allowed functions:
  - [ ] `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`
  - [ ] All `math.h`
  - [ ] All `mlx.h`
  - [ ] All `libft.h`
- [ ] Create demo projects with miniLibX to see how it works
- [ ] Load scene from `.rt` file
  - [ ] Validate file name: `*.rt`
  - [ ] Validate `.rt` file format
  - [ ] Ambient lightning: `A NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [ ] Camera: `C X,Y,Z OX,OY,OZ HORIZONTAL_FIELD_OF_VIEW`
  - [ ] Light: `L X,Y,Z NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [ ] Sphere: `sp X,Y,Z DIAMETER RED,GREEN,BLUE`
  - [ ] Plane: `pl X,Y,Z OX,OY,OZ RED,GREEN,BLUE`
  - [ ] Cylinder: `cy X,Y,Z OX,OY,OZ DIAMETER HEIGHT RED,GREEN,BLUE`
- [ ] Create Vectors functions
- [ ] Create Linear Algebra functions
- [ ] Define ray tracing logic
- [ ] Objects
  - [ ] Spheres
  - [ ] Planes
  - [ ] Cylinders
  - [ ] Correctly handle object intersections
  - [ ] Correctly handle object inside
- [ ] Create a user interface with `MiniLibX`
  - [ ] Use `MiniLibX` ’s images
  - [ ] Window management must remain smooth
  - [ ] Close window button exits the program cleanly
  - [ ] `q` and `esc` keys exits the program cleanly

# - [ ] Bonus

- [ ] Add specular reflection to have a full Phong reflection model.
- [ ] Color disruption: checkerboard.
- [ ] Colored and multi-spot lights.
- [ ] One other 2nd degree object: Cone, Hyperboloid, Paraboloid..
- [ ] Handle bump map textures.
- [ ] Save trace to `.bmp` file
  - [ ] `s` key saves the image
