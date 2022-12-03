<h3 align="center">42 São Paulo - miniRT</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_minirt?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_minirt?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_minirt?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_minirt?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_minirt?color=orange)

</div>

<div align="center">

[![Norminette v3](https://github.com/librity/ft_minirt/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_minirt/actions/workflows/norminette_v3.yml)

</div>

<p align="center"> A fully-featured ray tracer in pure C.
  <br>
</p>

---

```elixir
/-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~!777777!~~^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~!7??????????7!~^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~~~~~~^~7??????????????7~^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~!7JJYYYYJJJJ???????????????!^^^^^^^^^^^^^^^^|
!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~7JYYYYYYYYYYYYYJ?????????????7^^^^^^^^^^^^^^^^!
!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^~JYYYYYYYYYYYYYYYYY????????????!^^^^^^^^^^^^^^^^!
!^^^^^^^^^^^^^^^^^^~~~!!!~~^^^~JYYYYYYYYYYYYYYYYYYY??????????!^^^^^^^^^^^^^^^^^!
:^^^^^^^^^^^^^^~!?Y55PPPPP55J77YYYYYYYYYYYYYYYYYYYYJ???????7~^^^^^^^^^^^^^^^^^^:
:^^^^^^^^^^^^~?5PPPPPPPPPPPPPPPP5YYYYYYYYYYYYYYYYYY?7777!!~^^^^^^^^^^^^^^^^^^^^:
.^^^^^^^^^^^?PPPPPPPPPPPPPPPPPPPPPYYYYYYYYYYYYYYYYJ~^^^^^^^^^^^^^^^^^^^^^^^^^^^.
.^^^^^^^^^^JPPPPPPPPPPPPPPPPPPPPPPPYYYYYYYYYYYYYYJ~^^^^^^^^^^^^^^^^^^^^^^^^^^^^.
:^^^^^^^^^?PPPPPPPPPPPPPPPPPPPPPPPPPYYYYYYYYYYYJ7~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
:^^^^^^^^^5PPPPPPPPPPPPPPPPPPPPPPPPP??JJYYJJ?7!~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^:
!^^^^^^^^~5PPPPPPPPPPPPPPPPPPPPPPPP5^^^~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!
!^^^^^^^^^JPPPPPPPPPPPPPPPPPPPPPPPP?^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!
!^^^^^^^^^~5PPPPPPPPPPPPPPPPPPPPPPJ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^!
|^^^^^^^^^^~YPPPPPPPPPPPPPPPPPPP57^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^!YPPPPPPPPPPPPPPP5?~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^~7JY55PPPP5YJ7!^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^|
|-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=|
|                                                                              |
|            ┏━┓┏━┓━━━━━━━━━━━┓━━━━━━━━━━━━━━━┓━━━┓━━━┓━━━┓━━━┓━━━┓           |
|            ┃┃┗┛┃┃━━━━━━━━┏━┓┃━━━━━━━━━━━┏┓┏┓┃┏━┓┃┏━┓┃┏━┓┃┏━━┛┏━┓┃           |
|            ┃┏┓┏┓┃┓━┓━┓━━━┗━┛┃━━┓━┓━┏┓━━━┛┃┃┗┛┗━┛┃┃━┃┃┃━┗┛┗━━┓┗━┛┃           |
!            ┃┃┃┃┃┃┫┏┓┓┫━━━┏┓┏┛━┓┃━┃━┃┃━━━━┃┃━━┏┓┏┛┗━┛┃┃━┏┓┏━━┛┏┓┏┛           !
!            ┃┃┃┃┃┃┃┃┃┃┃━━━┃┃┗┓┗┛┗┓┗━┛┃━━━┏┛┗┓━┃┃┗┓┏━┓┃┗━┛┃┗━━┓┃┃┗┓           !
:            ┗┛┗┛┗┛┛┛┗┛┛━━━┛┗━┛━━━┛━┓┏┛━━━┗━━┛━┛┗━┛┛━┗┛━━━┛━━━┛┛┗━┛           :
:            ━━━━━━━━━━━━━━━━━━━━━━━┛┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━           :
.            ━━━━━━━━━━━━━━━━━━━━━━━━┛━━━━━━━━━━━━━━━━━━by lpaulo-m           .
.                                                                              .
:                      __ __     ___ __  __     __                             :
:                     /  /  \|\ | | |__)/  \|  (_                              :
!                     \__\__/| \| | | \ \__/|____)                             !
!                                                                              !
|                     - Esc or q: Exits program                                |
|                     - Left and Right Arrows: Switch camera                   |
|                     - s: Saves viewport to bitmap                            |
|                                                                              |
\-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=/
```

## 📜 Table of Contents

- [🧐 About](#about)
- [🏁 Getting Started](#getting_started)
- [🎨 Gallery](#gallery)
- [📝 Notes](#notes)
- [🐙 Github Actions](#github_actions)
- [🛸 42 São Paulo](#ft_sp)
- [📚 Resources](#resources)

## 🧐 About <a name = "about"></a>

A ray tracer written in C that handles scene files, spheres, planes, cylinders,
multiple cameras and hard shadows with multiple light.
Traces the scene described in a file and displays it in an interactive window.
It can also save the rendered scene to a `.bmp` file.

Based on my implementation of
[Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html):

- https://github.com/librity/weekendrt

For more details and examples you can read
the [Docs](./docs) and the [Checklist](./docs/checklist.md).

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

This project will only compile on Linux and FreeBSD.

You will need a C compiler (`gcc` or `clang`)
and [minilibx](https://github.com/42Paris/minilibx-linux),
an X-Window API made by 42 Paris:

```bash
# Clone the repo
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux

# Install dependencies and build
sudo apt install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev
make

# Copy archive and headers to system path
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/

# Add pages to man (optional)
sudo mkdir /usr/local/man/man1
sudo cp man/man1/* /usr/local/man/man1/
man mlx
```

### 🖥️ Installing

Clone the repo and run `make`:

```bash
$ git clone https://github.com/librity/ft_minirt.git
$ cd ft_minirt
$ make run
```

A beautiful image should pop out of your terminal like _magic_.

## 🎨 Gallery <a name="gallery"></a>

[and much, much more...](https://github.com/librity/ft_minirt/tree/main/gallery)

## 📝 Notes <a name = "notes"></a>

See the [Docs](./docs).

## 🐙 Github Actions <a name = "github_actions"></a>

[Norminette Github Action](https://github.com/AdrianWR/libft/blob/master/.github/workflows/norminette.yaml)
by [@AdrianWR](https://github.com/AdrianWR)

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

## 📚 Resources <a name="resources"></a>

See the [Docs](./docs).
