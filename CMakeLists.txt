cmake_minimum_required(VERSION 3.18...3.25)
project(se_for_sci_hw6 LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  eigen
  URL https://gitlab.com/libeigen/eigen/-/archive/3.4.0/eigen-3.4.0.tar.bz2
  URL_HASH
    SHA256=b4c198460eba6f28d34894e3a5710998818515104d6e74e5cc331ce31e46e626
  SOURCE_SUBDIR ignore_cmakelists)
FetchContent_MakeAvailable(eigen)

if(DEFINED SKBUILD)
  // I referenced https://scikit-build.readthedocs.io/en/latest/cmake-modules/PythonExtensions.html
  find_package(pybind11 REQUIRED)

  target_include_directories(se_for_sci_hw6 PRIVATE "${eigen_SOURCE_DIR}")
  target_compile_features(se_for_sci_hw6 PRIVATE cxx_std_11)
  python_extension_module(se_for_sci_hw6)
else()
  add_executable(main src/main.cpp src/integrator.hpp)
  target_include_directories(main PRIVATE src "${eigen_SOURCE_DIR}")
  target_compile_features(main PRIVATE cxx_std_11)
endif()
