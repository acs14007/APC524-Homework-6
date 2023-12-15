#include <pybind11/eigen.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "integrator.hpp"

namespace py = pybind11;

PYBIND11_MODULE(_core, m) {
  // HarmonicOscillator Class
    py::class_<HarmonicOscillator> harmonicOscillator(m, "HarmonicOscillator");
    .def(py::init<>())
    .def("f", &HarmonicOscillator::f)
    .def("integrate", &HarmonicOscillator::integrate)
}