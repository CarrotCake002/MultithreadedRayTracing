# Multithreaded Raytracing Project

## Overview

This project is a C++ raytracing engine that leverages multithreading to efficiently generate high-quality reflections. The primary goals were to rediscover multithreading techniques and to learn the intricacies of raytracing. By implementing parallel computing, the project achieved a significant reduction in rendering time—from roughly 4 hours down to about 30 minutes (a 80% reduction). Extensive unit testing (80+ tests) has been integrated to ensure mathematical accuracy for the ray calculations.

## Features

- **Efficient Raytracing:** Generates reflections using advanced raytracing techniques.
- **Multithreading:** Dramatically reduces execution time by running computations in parallel.
- **Robust Testing:** Over 80 unit tests with Google Test ensure the precision of ray calculations.
- **Modern Build System:** Utilizes CMake for easy configuration and compilation.

## Technologies Used

- **C++** for the core implementation.
- **CMake** for build configuration and project compilation.
- **Google Test** for comprehensive unit testing.

## Prerequisites

Before you begin, ensure you have the following installed:
- A C++ compiler supporting C++11 or later (e.g., g++, clang, MSVC).
- [CMake](https://cmake.org/) (version 3.10 or higher recommended).
- [Git](https://git-scm.com/) (to clone the repository).
- [Google Test](https://github.com/google/googletest) (either integrated as a submodule or installed separately).

## Installation & Compilation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/CarrotCake002/MultithreadedRayTracing.git
   cd MultithreadedRayTracing
   ```

2. **Create a build directory and configure the project:**

   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. **Compile the project:**

   ```bash
   make
   ```

   *On Windows, use your preferred CMake generator (e.g., Visual Studio).*

## Running the Project

After a successful build, you can run the raytracing executable:

```bash
./raytracer > image.ppm
```

This will execute the raytracing engine and generate an image.ppm with reflections.

## Running Tests

The project includes an extensive suite of unit tests to verify the mathematical accuracy of the ray calculations. To run the tests:

1. **Create a build directory:**
   ```bash
   cd tests
   mkdir build && cd build
   cmake ..
   ```

2. **Execute the test suite:**

   ```bash
   ./testing
   ```

This will run all the tests (80+ in total) and provide detailed output on the correctness and performance of the raytracing computations.

## Project Structure

```
.
├── src/
│   ├── main.cpp          # Entry point for the raytracing engine
│   ├── raytracer.cpp     # Core raytracing logic and multithreading implementation
│   └── ...               # Additional source files
├── include/
│   ├── ray.hpp           # ray.cpp include file
│   └── ...               # Additional include files
├── tests/
│   ├── CMakeLists.txt
│   ├── ray_test.cpp      # Unit tests for mathematical accuracy of ray calculations
│   └── ...               # Additional test files
├── CMakeLists.txt        # CMake build configuration
└── README.md             # Project documentation
```
