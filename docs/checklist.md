# - [ ] Overview

- [x] Vectors, Matrices and Rays
- [x] Validate `.rt` scene files
- [x] Parse `.rt` scene files
- [x] Ray tracing logic
  - [x] Camera
  - [x] Spheres
  - [x] Planes
  - [x] Cylinders
  - [x] Ambient light
  - [x] Spot Light
  - [x] Hard Shadows
- [x] Minilibx user interface
- [ ] `norminette`

# - [ ] Mandatory

- [ ] Don't turn in libs as submodules.
- [ ] Migrate `ft_libbmp` to `minirt.h`.
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
- [x] Create demo projects with miniLibX to see how it works
- [x] Load scene from `.rt` file
  - [x] Validate file name: `*.rt`
  - [x] Validate `.rt` file format
  - [x] Ambient lightning: `A NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [x] Camera: `C X,Y,Z OX,OY,OZ HORIZONTAL_FIELD_OF_VIEW`
  - [x] Light: `L X,Y,Z NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [x] Sphere: `sp X,Y,Z DIAMETER RED,GREEN,BLUE`
  - [x] Plane: `pl X,Y,Z OX,OY,OZ RED,GREEN,BLUE`
  - [x] Cylinder: `cy X,Y,Z OX,OY,OZ DIAMETER HEIGHT RED,GREEN,BLUE`
- [x] Create Vectors functions
- [x] Create Linear Algebra functions
- [x] Define ray tracing logic
- [x] Objects
  - [x] Spheres
  - [x] Planes
  - [x] Cylinders
  - [x] Correctly handle object intersections
  - [x] Correctly handle object inside
- [x] Create a user interface with `MiniLibX`
  - [x] Use `MiniLibX` ’s images
  - [x] Window management must remain smooth
  - [x] Close window button exits the program cleanly
  - [x] `esc` key exits the program cleanly

# - [ ] Bonus

- [x] Add specular reflection to have a full Phong reflection model.
- [ ] One other 2nd degree object
  - [ ] Cone
  - [ ] Hyperboloid
  - [ ] Paraboloid
- [ ] Color disruption: checkerboard.
- [ ] Colored and multi-spot lights.
- [ ] Handle bump map textures.
- [ ] Save trace to `.bmp` file
  - [ ] `s` key saves the image
