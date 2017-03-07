# OpenCV pratices
This my practice of OpenCV at a lab at my university

## Compile and Run

All of the `.cpp` files here are single files (not being related to other `.cpp` files in any way, such as `#include`),
but they require media resources from `./image` and `./video` so you need to make sure the C++ files can load these resources

### Using GCC

#### Requirements

* libopencv-dev

* pkg-config

* A BASH terminal, e.g. Linux terminal, Cygwin terminal, MSYS2 terminal, etc.

* C++11 supports, e.g. auto keywords, etc.

#### Compilation and Execution commands

**Compilation**

Open a bash/sh terminal

```bash
export libs="$(pkg-config --cflags --libs opencv)"
g++ -std=c++11 -o output_executable_filename input_cpp_filename $libs
```

If you want to use a zsh shell instead

```zsh
export libs=$(pkg-config --cflags --libs opencv)
eval g++ -std=c++11 -o output_executable_filename input_cpp_filename $libs
```

**Execution**

```bash
./output_executable_filename
```

### Using Visual Studio

#### Requirements

* Visual Studio 2013 or later

* Download [OpenCV](http://opencv.org)
  - Follow [this instruction](http://docs.opencv.org/2.4/doc/tutorials/introduction/windows_install/windows_install.html) to install OpenCV in Windows
  - Read [this instruction](http://docs.opencv.org/2.4/doc/tutorials/introduction/windows_visual_studio_Opencv/windows_visual_studio_Opencv.html) to know how to build an OpenCV application in Visual Studio
  - If you still cannot install nor use OpenCV in Visual Studio, I won't be able to even care because I created this repo when I was using Linux

#### Compilation and Execution

1. Create an OpenCV C++ project (read the instructions above to know how)

2. Copy exactly one single `.cpp` file from this repo to replace file `main.cpp` (or whatever it's called) in the created project

3. Copy folders `image` and `video` (if there's one) to the folder contains `main.cpp` (see 2. above)

4. If there's a `video` folder, follow instruction within `video/README.md`

5. Hit the glorious `Build & Run` button

## License

[MIT](./LICENSE.md) © [Hoàng Văn Khải](https://github.com/KSXGitHub)
