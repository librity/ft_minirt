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
- [ ] Turn in `Makefile`, `*.h`, `*.c` , `.linux` , `.gitignore`
- [ ] Allowed functions:
  - [ ] `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`
  - [ ] All `math.h`
  - [ ] All `mlx.h`
  - [ ] All `libft.h`
- [x] Create demo projects with miniLibX to see how it works
- [ ] Load scene from `.rt` file
  - [ ] Validate `.rt` file format
  - [ ] Ambient lightning: `A NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [ ] Camera: `C X,Y,Z OX,OY,OZ HORIZONTAL_FIELD_OF_VIEW`
  - [ ] Light: `L X,Y,Z NORMALIZED_BRIGHTNESS RED,GREEN,BLUE`
  - [ ] Sphere: `sp X,Y,Z DIAMETER RED,GREEN,BLUE`
  - [ ] Plane: `pl X,Y,Z OX,OY,OZ RED,GREEN,BLUE`
  - [ ] Cylinder: `cy X,Y,Z OX,OY,OZ DIAMETER HEIGHT RED,GREEN,BLUE`
- [x] Create Vectors functions
- [x] Create Linear Algebra functions
- [x] Define ray tracing logic
- [ ] Objects
  - [x] Spheres: diameter
  - [ ] Planes
  - [ ] Cylinders: width and height
  - [ ] Correctly handle object intersections
  - [ ] Correctly handle object inside
- [ ] Handle multiple lights
- [ ] Handle multiple cameras
- [ ] Create a user interface with `MiniLibX`
  - [ ] Use `MiniLibX` ’s images
  - [ ] Window management must remain smooth
  - [ ] Close window button exits the program cleanly
  - [ ] `q` and `esc` keys exits the program cleanly
  - [ ] arrow keys change camera view
- [x] Save trace to `.bmp` file

- [ ] Validate `.rt` scene files
- [ ] Parse `.rt` scene files
- [x] Vectors and Linear Algebra
- [x] Ray tracing logic
- [x] Spheres
- [ ] Planes
- [ ] Cylinders
- [ ] Ambient light
- [ ] Multiple lights
- [ ] Hard shadows
- [ ] Multiple cameras
- [ ] Minilibx user interface
- [x] Saving to `.bmp` file

## - [ ] Cleanup

- [x] Purge local minilibx
- [x] Create a repo for ft_libbmp - <https://github.com/librity/ft_libbmp>
- [x] Fix ft_libbmp norme errors
- [x] Add compatibility function between ft_libbmp and minilibx pixels
- [x] Consolidate header files (`vectors.h`, `random.h`, `rays.h`, etc.)
- [x] Remove metallic material functions
- [x] Remove dielectric material functions
- [x] Remove depth-of-field
- [x] Remove sampling
- [ ] Remove soft shadows (scattering) and add hard ones
- [x] Use `ft_libbmp` colors and _`t_mlx_image`_

# - [ ] Bonus
