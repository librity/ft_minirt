# Resources

## C Quirks

- https://overiq.com/c-programming-101/fwrite-function-in-c/
- https://www.c-programming-simple-steps.com/typedef-in-c.html
- https://www.geeksforgeeks.org/use-fflushstdin-c/
- https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
- https://www.tutorialspoint.com/c_standard_library/c_function_fwrite.htm
- https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
- https://stackoverflow.com/questions/13252697/writing-bits-to-a-file-in-c
- https://stackoverflow.com/questions/39002052/how-i-can-print-to-stderr-in-c
- https://stackoverflow.com/questions/5248919/undefined-reference-to-sqrt-or-other-mathematical-functions
- https://stackoverflow.com/questions/4842424/list-of-ansi-color-escape-sequences
- https://stackoverflow.com/questions/5834635/how-do-i-get-double-max
- https://stackoverflow.com/questions/33058848/generate-a-random-double-between-1-and-1
- https://stackoverflow.com/questions/9912151/math-constant-pi-value-in-c#9912169
- https://stackoverflow.com/questions/1157209/is-there-an-alternative-sleep-function-in-c-to-milliseconds
- https://askubuntu.com/questions/749882/how-to-recursively-and-automatically-convert-all-bmp-images-to-png-files-in-a-gi
- https://www.codeproject.com/tips/800474/function-pointer-in-c-struct
- https://aticleworld.com/function-pointer-in-c-struct/

## Math

- https://en.wikipedia.org/wiki/Dot_product
- https://en.wikipedia.org/wiki/Quadratic_formula
- https://en.wikipedia.org/wiki/Snell's_law
- https://en.wikipedia.org/wiki/Refractive_index
- https://en.wikipedia.org/wiki/Specular_reflection#Direction_of_reflection
- https://en.wikipedia.org/wiki/Dielectric
- https://en.wikipedia.org/wiki/Fresnel_equations
- https://en.wikipedia.org/wiki/Schlick%27s_approximation
- https://en.wikipedia.org/wiki/Thin_lens
- https://graphicscompendium.com/raytracing/11-fresnel-beer
- https://gaim.umbc.edu/2010/09/07/approximation/
- https://en.wikipedia.org/wiki/Beer%E2%80%93Lambert_law
- https://stats.stackexchange.com/questions/137907/division-of-vectors
- http://www.r-tutor.com/r-introduction/vector/vector-arithmetics
- https://physics.stackexchange.com/questions/111652/can-we-divide-two-vectors
- https://mathworld.wolfram.com/VectorDivision.html
- https://en.wikipedia.org/wiki/List_of_Unicode_characters

## Docs

- https://en.wikipedia.org/wiki/Extended_ASCII
- https://en.cppreference.com/w/cpp/io/manip/flush
- https://www.cplusplus.com/reference/cstdio/printf/
- https://linux.die.net/man/3/random
- https://cplusplus.com/reference/cmath/fmin/
- https://harm-smits.github.io/42docs/libs/minilibx

## minilibx

- https://harm-smits.github.io/42docs/libs/minilibx
- https://gontjarow.github.io/MiniLibX/
- https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx
- https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx
- https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
- https://github.com/42sp/minilibx-linux
- https://github.com/42Paris/minilibx-linux/issues/24
- http://cyber.dabamos.de/unix/x11/
- https://qst0.github.io/ft_libgfx/man_mlx.html
- https://gontjarow.github.io/MiniLibX/mlx-tutorial-create-image.html
- https://elearning.intra.42.fr/notions/minilibx/subnotions
- https://elearning.intra.42.fr/tags/716/notions

## minilibx functions

```c
void	*mlx_init();
void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
void	*mlx_new_image(void *mlx_ptr,int width,int height);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int	mlx_get_color_value(void *mlx_ptr, int color);
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop (void *mlx_ptr);
int mlx_loop_end (void *mlx_ptr);
int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);
int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int	mlx_destroy_display(void *mlx_ptr);
int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);
int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);
int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
```

## ⬇️ Markdown

- https://casual-effects.com/markdeep/
- https://github.github.com/gfm/
- https://emojipedia.org/sun/
- https://jaantollander.com/post/scientific-writing-with-markdown/
- https://paperhive.org/help/markdown
- http://www.sciweavers.org/free-online-latex-equation-editor
- http://latex.codecogs.com/
- http://csrgxtu.github.io/2015/03/20/Writing-Mathematic-Fomulars-in-Markdown/
- https://en.wikibooks.org/wiki/LaTeX/Mathematics#Controlling_horizontal_spacing

## Discord Channel

- http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
- http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides.html
- https://80.lv/articles/illuminating-scenes-in-blender-with-iphone-s-gyroscope/
- https://api.intra.42.fr/oauth/authorize?response_type=code&redirect_uri=https%3A%2F%2Ffind-peers.codam.nl%2Fauth%2F42%2Fcallback&scope=public&client_id=70dcca837e7f371d76c7db6198e41878e5c53059747707d3c4e94a036be47bc3
- https://devblogs.microsoft.com/oldnewthing/20210525-00/?p=105250
- https://elearning.intra.42.fr/notions/the-norm/subnotions/norm-v3/pdfs/Norm%20V3
- https://engineering.purdue.edu/ece264/17au/hw/HW15
- https://fabiensanglard.net/rayTracing_back_of_business_card/
- https://fabiensanglard.net/revisiting_the_businesscard_raytracer/index.html
- https://github.com/42Paris/minilibx-linux
- https://github.com/42Paris/minilibx-linux/issues/24
- https://github.com/araggohnxd/mini_rstack/blob/master/sources/shape/shape_cone.c
- https://github.com/fde-capu/miniRT
- https://github.com/ficociroo/miniRT
- https://github.com/lrcouto/MiniRT
- https://github.com/marceFrasson/miniRT_subject_pt/blob/main/en.subject.en.pt.pdf
- https://github.com/rkrocha/mlx_basics
- https://hackaday.com/2022/03/16/opengl-in-500-lines-sort-of/
- https://harm-smits.github.io/42docs/libs/minilibx
- https://harm-smits.github.io/42docs/libs/minilibx/colors.html
- https://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
- https://invidious.weblibre.org/watch?v=DpkUAg9hrjQ&list=PLAp0ZhYvW6Xbt-VMIde2pe_EpJ9d8tx4E&ab_channel=GeorgeLecakes&dark_mode=true
- https://invidious.weblibre.org/watch?v=LlNaI6upK94&dark_mode=true
- https://invidious.weblibre.org/watch?v=frLwRLS_ZR0&dark_mode=true
- https://invidious.weblibre.org/watch?v=gBPNO6ruevk&list=PL5B692fm6--sgm8Uiava0IIvUojjFOCSR&index=1&dark_mode=true
- https://invidious.weblibre.org/watch?v=gfW1Fhd9u9Q&ab_channel=TheCherno&dark_mode=true
- https://invidious.weblibre.org/watch?v=p8u_k2LIZyo&dark_mode=true
- https://invidious.weblibre.org/watch?v=p8u_k2LIZyo&t=401s&dark_mode=true
- https://lodev.org/cgtutor/raycasting.html
- https://mrl.cs.nyu.edu/~perlin/courses/fall2005ugrad/phong.html
- https://private-tungsten-357.notion.site/miniRT-stack-vs-heap-eaab52ce792047b5b71e2fcb59074ffb
- https://qst0.github.io/ft_libgfx/man_mlx_loop.html
- https://raytracing.github.io/books/RayTracingInOneWeekend.html
- https://web.cs.hacettepe.edu.tr/~erkut/bco511.s12/
- https://wikiless.org/wiki/Endianness?lang=en
- https://www.khanacademy.org/computing/pixar/rendering
- https://www.khanacademy.org/computing/pixar/rendering/rendering1/a/start-here-rendering
- https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436
- https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
- https://www.tutorialspoint.com/cprogramming/c_bitwise_operators.htm
- https://www.wired.com/2014/10/astrophysics-interstellar-black-hole/

## Testing Frameworks

- [Unity](https://github.com/ThrowTheSwitch/Unity)
- [Cucumber](https://www.guru99.com/introduction-to-cucumber.html)
- https://github.com/cucumber/cucumber-ruby

## math.h

- https://docs.oracle.com/cd/E86824_01/html/E54772/math.h-3head.html
- https://www.unix.com/man-page/posix/7posix/math.h/
- https://www.tutorialspoint.com/c_standard_library/math_h.htm
- https://code-reference.com/c/math.h
- https://www.geeksforgeeks.org/c-library-math-h-functions/
- https://www.codingunit.com/category/c-language-reference/c-reference-math-h-functions
- https://www.cplusplus.com/reference/cmath/
- https://www.man7.org/linux/man-pages/man0/math.h.0p.html
- https://stackoverflow.com/questions/16974669/using-sqrtf-in-c-undefined-reference-to-sqrtf
- https://www.tutorialspoint.com/c_standard_library/c_function_pow.htm

## Errors

- https://www.man7.org/linux/man-pages/man3/errno.3.html
- https://www.tutorialspoint.com/c_standard_library/c_function_strerror.htm
- https://www.tutorialspoint.com/c_standard_library/c_function_perror.htm
- https://www.tutorialspoint.com/c_standard_library/c_function_exit.htm
- https://en.cppreference.com/w/c/program/EXIT_status

## miniLibX

- https://harm-smits.github.io/42docs/libs/minilibx
- https://github.com/42sp/minilibx-linux
- https://github.com/42Paris/minilibx-linux/issues/24
- https://github.com/42Paris/minilibx-linux/issues/24

## Norminette v3

- https://github.com/42School/norminette
- https://elearning.intra.42.fr/notions/the-norm/subnotions/norm-v3/pdfs/Norm%20V3

## Ray Tracers

- https://en.wikipedia.org/wiki/Ray_tracing_(graphics)
- http://www.realtimerendering.com/raytracing.html
- https://news.developer.nvidia.com/ray-tracing-essentials-part-1-basics-of-ray-tracing/
- https://tmcw.github.io/literate-raytracer/

## Techniques

- http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
- https://mrl.cs.nyu.edu/~perlin/courses/fall2005ugrad/phong.html

## businesscard_raytracer.c

- https://gist.github.com/sungiant/9524044
- https://fabiensanglard.net/rayTracing_back_of_business_card/

## Ray Casters

## Rasterizers

- https://blogs.nvidia.com/blog/2018/03/19/whats-difference-between-ray-tracing-rasterization/
- https://magazine.renderosity.com/article/4233/whats-the-difference-between-ray-tracing-and-rasterization
- https://medium.com/@junyingw/future-of-gaming-rasterization-vs-ray-tracing-vs-path-tracing-32b334510f1f

## Shaders

- https://en.wikipedia.org/wiki/Shader

## Gamma Correction

- https://raytracing.github.io/books/RayTracingInOneWeekend.html#diffusematerials/usinggammacorrectionforaccuratecolorintensity
- https://wikiless.org/wiki/Gamma_correction?lang=en

## Bounding Volume Hierarchy

- https://en.wikipedia.org/wiki/Bounding_volume_hierarchy

## Parsing

- https://stackoverflow.com/questions/2661983/parsing-a-file-in-c
- https://bytes.com/topic/c/insights/657086-how-parse-file-c
- https://codereview.stackexchange.com/questions/226293/parse-a-simple-key-value-config-file-in-c
- https://www.tutorialspoint.com/cprogramming/c_file_io.htm
- https://www.programiz.com/c-programming/c-file-input-output

## .bmp

- https://duckduckgo.com/?q=c+bitmap+file
- https://en.wikipedia.org/wiki/BMP_file_format
- https://stackoverflow.com/questions/11004868/creating-a-bmp-file-bitmap-in-c
- https://github.com/nothings/stb
- https://elcharolin.wordpress.com/2018/11/28/read-and-write-bmp-files-in-c-c/
- https://engineering.purdue.edu/ece264/17au/hw/HW15
- https://github.com/marc-q/libbmp
- https://github.com/Midarius/42-libbmp

## Floating-Point Arithmetic

- https://docs.oracle.com/cd/E19957-01/806-3568/ncg_goldberg.html

## Math

- https://en.wikipedia.org/wiki/Rendering_equation
- https://www.youtube.com/watch?v=AODo_RjJoUA
- https://en.wikipedia.org/wiki/Rotation_matrix#Rotation_matrix_from_axis_and_angle
- https://geogebra.org/3d/gwwksgug

## Ray Tracing in One Weekend

- https://www.youtube.com/watch?v=_5hD0gxRzzg
- https://github.com/RayTracing/raytracing.github.io
- https://raytracing.github.io/books/RayTracingInOneWeekend.html
- https://github.com/snarkyboojum/ray_tracer

## The Ray Tracer Challenge

- http://library.lol/main/06BDEEEECBF70277320C240DEFB8C3EA

## The Ray Tracer Challenge Repos

- https://github.com/search?&q=the+ray+tracer+challenge
- https://github.com/javan/ray-tracer-challenge
- https://github.com/tobiasmarciszko/qt_raytracer_challenge
- https://github.com/garfieldnate/ray_tracer_challenge
- https://github.com/eriklupander/rt
- https://github.com/AdrianGerber/TheRayTracerChallenge

## Videos

- https://www.youtube.com/user/shiffman
- https://www.youtube.com/results?search_query=one+lone+coder+ray+tracer
- https://www.youtube.com/watch?v=ih20l3pJoeU
- https://www.youtube.com/watch?v=r2lw132iV-0

## ASCII Art

- https://www.asciiart.eu/art-and-design/escher
- https://www.asciiart.eu/art-and-design/borders
- https://www.asciiart.eu/art-and-design/geometries
- https://www.text-image.com/convert/ascii.html
- https://textfancy.com/multiline-text-art/

## Window System/APIs

- https://en.wikipedia.org/wiki/X_Window_System
- https://en.wikipedia.org/wiki/Cocoa_(API)
- https://en.wikipedia.org/wiki/Wayland_(display_server_protocol)

## Bitwise Operations

- https://en.wikipedia.org/wiki/Bitwise_operations_in_C

## Physics

- https://en.wikipedia.org/wiki/Lambert's_cosine_law

## C Quirks

- https://codeforwin.org/2017/09/global-variables-c.html

## C Compiler Packing

- https://en.wikipedia.org/wiki/Data_structure_alignment
- https://stackoverflow.com/questions/3285035/when-writing-struct-to-a-file-too-many-bytes-are-written
- https://stackoverflow.com/questions/3318410/pragma-pack-effect

## pthread.h

- https://www.man7.org/linux/man-pages/man0/pthread.h.0p.html
- https://iq.opengenus.org/multithreading-and-pthread-in-c/
- https://www.geeksforgeeks.org/multithreading-c-2/
- https://www.tutorialspoint.com/multithreading-in-c
- https://github.com/samuelpio01/multithreading-in-c/blob/master/pthread_multithreading.c
- https://github.com/samuelpio01/multithreading-in-c

## Quake Quick Square Root

- https://invidious.weblibre.org/watch?time_continue=53&v=p8u_k2LIZyo&feature=emb_title&dark_mode=true

## Fde-capu

- https://www.khanacademy.org/computing/pixar/rendering/rendering1/a/start-here-rendering
- http://web.cse.ohio-state.edu/~shen.94/681/Site/Slides.html
- https://web.cs.hacettepe.edu.tr/~erkut/bco511.s12/
- https://raytracing.github.io/books/RayTracingInOneWeekend.html
- https://mrl.cs.nyu.edu/~perlin/courses/fall2005ugrad/phong.html
- http://hugi.scene.org/online/hugi24/coding%20graphics%20chris%20dragan%20raytracing%20shapes.htm
- https://lodev.org/cgtutor/raycasting.html
- https://qst0.github.io/ft_libgfx/man_mlx_loop.html

## 3D Renderers

- https://en.wikipedia.org/wiki/List_of_3D_rendering_software
- https://renderman.pixar.com/
- https://en.wikipedia.org/wiki/Pixar_RenderMan

## Evaluations

- https://find-peers.herokuapp.com/
- https://42evaluators.com/result/

## Misc

- [Miro: the collaborative whiteboard platform for distributed teams](https://miro.com/welcomeonboard/2hutLOYNP8Vajr7A8iADYmbs8UBu0oaRMNvLVwLdsHIAPnICKG0upKBXFEY7qIxr)
- [Ray Tracing Essentials, Part 1: Basics of Ray Tracing](https://youtu.be/gBPNO6ruevk)
- [Rendering | Pixar in a Box | Computing | Khan Academy](https://www.khanacademy.org/computing/pixar/rendering)
- [A Minimal Ray-Tracer: Rendering Simple Shapes (Sphere, Cube, Disk, Plane, etc.)](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes)
- [Introduction to Ray Tracing: a Simple Method for Creating 3D Images](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing)
- [Essence of linear algebra](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
- [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
- [Writing a Raytracer in Rust - Part 1 - First Rays](https://bheisler.github.io/post/writing-raytracer-in-rust-part-1/)
- [Ray Tracer](https://users.csc.calpoly.edu/~zwood/teaching/csc471/final09/nkowshik_webpage/)
- [Advanced C Programming](https://engineering.purdue.edu/ece264/17au/hw/HW15)
