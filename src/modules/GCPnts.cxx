/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <GCPnts_AbscissaType.hxx>
#include <GCPnts_DeflectionType.hxx>
#include <Standard.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GCPnts_TangentialDeflection.hxx>
#include <CPnts_AbscissaPoint.hxx>
#include <GCPnts_AbscissaPoint.hxx>
#include <math_Function.hxx>
#include <GCPnts_DistFunction.hxx>
#include <gp_Lin.hxx>
#include <math_MultipleVarFunction.hxx>
#include <math_Vector.hxx>
#include <GCPnts_DistFunction2d.hxx>
#include <gp_Lin2d.hxx>
#include <StdFail_NotDone.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <GCPnts_QuasiUniformAbscissa.hxx>
#include <GeomAbs_Shape.hxx>
#include <GCPnts_QuasiUniformDeflection.hxx>
#include <GCPnts_UniformAbscissa.hxx>
#include <GCPnts_UniformDeflection.hxx>

PYBIND11_MODULE(GCPnts, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.CPnts");
py::module::import("OCCT.math");
py::module::import("OCCT.StdFail");
py::module::import("OCCT.GeomAbs");

// ENUM: GCPNTS_ABSCISSATYPE
py::enum_<GCPnts_AbscissaType>(mod, "GCPnts_AbscissaType", "None")
	.value("GCPnts_LengthParametrized", GCPnts_AbscissaType::GCPnts_LengthParametrized)
	.value("GCPnts_Parametrized", GCPnts_AbscissaType::GCPnts_Parametrized)
	.value("GCPnts_AbsComposite", GCPnts_AbscissaType::GCPnts_AbsComposite)
	.export_values();


// ENUM: GCPNTS_DEFLECTIONTYPE
py::enum_<GCPnts_DeflectionType>(mod, "GCPnts_DeflectionType", "None")
	.value("GCPnts_Linear", GCPnts_DeflectionType::GCPnts_Linear)
	.value("GCPnts_Circular", GCPnts_DeflectionType::GCPnts_Circular)
	.value("GCPnts_Curved", GCPnts_DeflectionType::GCPnts_Curved)
	.value("GCPnts_DefComposite", GCPnts_DeflectionType::GCPnts_DefComposite)
	.export_values();


// CLASS: GCPNTS_TANGENTIALDEFLECTION
py::class_<GCPnts_TangentialDeflection> cls_GCPnts_TangentialDeflection(mod, "GCPnts_TangentialDeflection", "Computes a set of points on a curve from package Adaptor3d such as between two successive points P1(u1)and P2(u2) :");

// Constructors
cls_GCPnts_TangentialDeflection.def(py::init<>());
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"));
cls_GCPnts_TangentialDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));

// Methods
// cls_GCPnts_TangentialDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_TangentialDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_TangentialDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_TangentialDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_TangentialDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_TangentialDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_TangentialDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_TangentialDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Initialize(a0, a1, a2); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Integer a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Initialize(a0, a1, a2, a3, a4); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5); });
cls_GCPnts_TangentialDeflection.def("Initialize", [](GCPnts_TangentialDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Integer a5, const Standard_Real a6) -> void { return self.Initialize(a0, a1, a2, a3, a4, a5, a6); });
cls_GCPnts_TangentialDeflection.def("Initialize", (void (GCPnts_TangentialDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::Initialize, "None", py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("AngularDeflection"), py::arg("CurvatureDeflection"), py::arg("MinimumOfPoints"), py::arg("UTol"), py::arg("theMinLen"));
cls_GCPnts_TangentialDeflection.def("AddPoint", [](GCPnts_TangentialDeflection &self, const gp_Pnt & a0, const Standard_Real a1) -> Standard_Integer { return self.AddPoint(a0, a1); });
cls_GCPnts_TangentialDeflection.def("AddPoint", (Standard_Integer (GCPnts_TangentialDeflection::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &GCPnts_TangentialDeflection::AddPoint, "Add point to already calculated points (or replace existing) Returns index of new added point or founded with parametric tolerance (replaced if theIsReplace is true)", py::arg("thePnt"), py::arg("theParam"), py::arg("theIsReplace"));
cls_GCPnts_TangentialDeflection.def("NbPoints", (Standard_Integer (GCPnts_TangentialDeflection::*)() const) &GCPnts_TangentialDeflection::NbPoints, "None");
cls_GCPnts_TangentialDeflection.def("Parameter", (Standard_Real (GCPnts_TangentialDeflection::*)(const Standard_Integer) const) &GCPnts_TangentialDeflection::Parameter, "None", py::arg("I"));
cls_GCPnts_TangentialDeflection.def("Value", (gp_Pnt (GCPnts_TangentialDeflection::*)(const Standard_Integer) const) &GCPnts_TangentialDeflection::Value, "None", py::arg("I"));
cls_GCPnts_TangentialDeflection.def_static("ArcAngularStep_", (Standard_Real (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_TangentialDeflection::ArcAngularStep, "Computes angular step for the arc using the given parameters.", py::arg("theRadius"), py::arg("theLinearDeflection"), py::arg("theAngularDeflection"), py::arg("theMinLength"));

// CLASS: GCPNTS_ABSCISSAPOINT
py::class_<GCPnts_AbscissaPoint> cls_GCPnts_AbscissaPoint(mod, "GCPnts_AbscissaPoint", "Provides an algorithm to compute a point on a curve situated at a given distance from another point on the curve, the distance being measured along the curve (curvilinear abscissa on the curve). This algorithm is also used to compute the length of a curve. An AbscissaPoint object provides a framework for: - defining the point to compute - implementing the construction algorithm - consulting the result.");

// Constructors
cls_GCPnts_AbscissaPoint.def(py::init<>());
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Tol"), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Standard_Real, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("Tol"), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U0"), py::arg("Ui"), py::arg("Tol"));

// Methods
// cls_GCPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t)) &GCPnts_AbscissaPoint::operator new, "None", py::arg("theSize"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *)) &GCPnts_AbscissaPoint::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_AbscissaPoint::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_AbscissaPoint::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_AbscissaPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_AbscissaPoint.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_AbscissaPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C>.", py::arg("C"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def_static("Length_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_AbscissaPoint::Length, "Computes the length of the Curve <C> with the given tolerance. Constructs an empty algorithm. This function is used only for initializing a framework to compute the length of a curve (or a series of curves). Warning The function IsDone will return the value false after the use of this function.", py::arg("C"), py::arg("U1"), py::arg("U2"), py::arg("Tol"));
cls_GCPnts_AbscissaPoint.def("IsDone", (Standard_Boolean (GCPnts_AbscissaPoint::*)() const) &GCPnts_AbscissaPoint::IsDone, "True if the computation was successful, False otherwise. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_AbscissaPoint.def("Parameter", (Standard_Real (GCPnts_AbscissaPoint::*)() const) &GCPnts_AbscissaPoint::Parameter, "Returns the parameter on the curve of the point solution of this algorithm. Exceptions StdFail_NotDone if the computation was not successful, or was not done.");

// CLASS: GCPNTS_DISTFUNCTION
py::class_<GCPnts_DistFunction, math_Function> cls_GCPnts_DistFunction(mod, "GCPnts_DistFunction", "Class to define function, which calculates square distance between point on curve C(u), U1 <= u <= U2 and line passing through points C(U1) and C(U2) This function is used in any minimisation algorithm to define maximal deviation between curve and line, which required one variable function without derivative (for ex. math_BrentMinimum)");

// Constructors
cls_GCPnts_DistFunction.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("U1"), py::arg("U2"));
// cls_GCPnts_DistFunction.def(py::init<const GCPnts_DistFunction &>(), py::arg("theOther"));

// Methods
cls_GCPnts_DistFunction.def("Value", [](GCPnts_DistFunction &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));

// CLASS: GCPNTS_DISTFUNCTIONMV
py::class_<GCPnts_DistFunctionMV, math_MultipleVarFunction> cls_GCPnts_DistFunctionMV(mod, "GCPnts_DistFunctionMV", "The same as class GCPnts_DistFunction, but it can be used in minimization algorithms that requires multi variable function");

// Constructors
cls_GCPnts_DistFunctionMV.def(py::init<GCPnts_DistFunction &>(), py::arg("theCurvLinDist"));

// Methods
cls_GCPnts_DistFunctionMV.def("Value", [](GCPnts_DistFunctionMV &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_GCPnts_DistFunctionMV.def("NbVariables", (Standard_Integer (GCPnts_DistFunctionMV::*)() const) &GCPnts_DistFunctionMV::NbVariables, "None");

// CLASS: GCPNTS_DISTFUNCTION2D
py::class_<GCPnts_DistFunction2d, math_Function> cls_GCPnts_DistFunction2d(mod, "GCPnts_DistFunction2d", "Class to define function, which calculates square distance between point on curve C(u), U1 <= u <= U2 and line passing through points C(U1) and C(U2) This function is used in any minimisation algorithm to define maximal deviation between curve and line, which required one variable function without derivative (for ex. math_BrentMinimum)");

// Constructors
cls_GCPnts_DistFunction2d.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("theCurve"), py::arg("U1"), py::arg("U2"));
// cls_GCPnts_DistFunction2d.def(py::init<const GCPnts_DistFunction2d &>(), py::arg("theOther"));

// Methods
cls_GCPnts_DistFunction2d.def("Value", [](GCPnts_DistFunction2d &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));

// CLASS: GCPNTS_DISTFUNCTION2DMV
py::class_<GCPnts_DistFunction2dMV, math_MultipleVarFunction> cls_GCPnts_DistFunction2dMV(mod, "GCPnts_DistFunction2dMV", "The same as class GCPnts_DistFunction2d, but it can be used in minimization algorithms that requires multi variable function");

// Constructors
cls_GCPnts_DistFunction2dMV.def(py::init<GCPnts_DistFunction2d &>(), py::arg("theCurvLinDist"));

// Methods
cls_GCPnts_DistFunction2dMV.def("Value", [](GCPnts_DistFunction2dMV &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "None", py::arg("X"), py::arg("F"));
cls_GCPnts_DistFunction2dMV.def("NbVariables", (Standard_Integer (GCPnts_DistFunction2dMV::*)() const) &GCPnts_DistFunction2dMV::NbVariables, "None");

// CLASS: GCPNTS_QUASIUNIFORMABSCISSA
py::class_<GCPnts_QuasiUniformAbscissa> cls_GCPnts_QuasiUniformAbscissa(mod, "GCPnts_QuasiUniformAbscissa", "This class provides an algorithm to compute a uniform abscissa distribution of points on a curve, i.e. a sequence of equidistant points. The distance between two consecutive points is measured along the curve. The distribution is defined: - either by the curvilinear distance between two consecutive points - or by a number of points.");

// Constructors
cls_GCPnts_QuasiUniformAbscissa.def(py::init<>());
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));

// Methods
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new_", (void * (*)(size_t)) &GCPnts_QuasiUniformAbscissa::operator new, "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete_", (void (*)(void *)) &GCPnts_QuasiUniformAbscissa::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_QuasiUniformAbscissa::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_QuasiUniformAbscissa::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_QuasiUniformAbscissa::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_QuasiUniformAbscissa.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_QuasiUniformAbscissa::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints> and", py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints> and", py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_QuasiUniformAbscissa.def("Initialize", (void (GCPnts_QuasiUniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real)) &GCPnts_QuasiUniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformAbscissa.def("IsDone", (Standard_Boolean (GCPnts_QuasiUniformAbscissa::*)() const) &GCPnts_QuasiUniformAbscissa::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_QuasiUniformAbscissa.def("NbPoints", (Standard_Integer (GCPnts_QuasiUniformAbscissa::*)() const) &GCPnts_QuasiUniformAbscissa::NbPoints, "Returns the number of points of the distribution computed by this algorithm. This value is either: - the one imposed on the algorithm at the time of construction (or initialization), or - the one computed by the algorithm when the curvilinear distance between two consecutive points of the distribution is imposed on the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_QuasiUniformAbscissa.def("Parameter", (Standard_Real (GCPnts_QuasiUniformAbscissa::*)(const Standard_Integer) const) &GCPnts_QuasiUniformAbscissa::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));

// CLASS: GCPNTS_QUASIUNIFORMDEFLECTION
py::class_<GCPnts_QuasiUniformDeflection> cls_GCPnts_QuasiUniformDeflection(mod, "GCPnts_QuasiUniformDeflection", "This class computes a distribution of points on a curve. The points may respect the deflection. The algorithm is not based on the classical prediction (with second derivative of curve), but either on the evaluation of the distance between the mid point and the point of mid parameter of the two points, or the distance between the mid point and the point at parameter 0.5 on the cubic interpolation of the two points and their tangents. Note: this algorithm is faster than a GCPnts_UniformDeflection algorithm, and is able to work with non-'C2' continuous curves. However, it generates more points in the distribution.");

// Constructors
cls_GCPnts_QuasiUniformDeflection.def(py::init<>());
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_QuasiUniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));

// Methods
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_QuasiUniformDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_QuasiUniformDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_QuasiUniformDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_QuasiUniformDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_QuasiUniformDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_QuasiUniformDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_QuasiUniformDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("Initialize", [](GCPnts_QuasiUniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_QuasiUniformDeflection.def("Initialize", (void (GCPnts_QuasiUniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape)) &GCPnts_QuasiUniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, -- <U1>,<U2> This and the above algorithms initialize (or reinitialize) this algorithm and compute a distribution of points: - on the curve C, or - on the part of curve C limited by the two parameter values U1 and U2, where the deflection resulting from the distributed points is not greater than Deflection. The first point of the distribution is either the origin of curve C or the point of parameter U1. The last point of the distribution is either the end point of curve C or the point of parameter U2. Intermediate points of the distribution are built in such a way that the deflection is not greater than Deflection. Using the following evaluation of the deflection: if Pi and Pj are two consecutive points of the distribution, respectively of parameter ui and uj on the curve, the deflection is the distance between: - the mid-point of Pi and Pj (the center of the chord joining these two points) - and the point of mid-parameter of these two points (the point of parameter [(ui+uj) / 2 ] on curve C). Continuity, defaulted to GeomAbs_C1, gives the degree of continuity of the curve C. (Note that C is an Adaptor3d_Curve or an Adaptor2d_Curve2d object, and does not know the degree of continuity of the underlying curve). Use the function IsDone to verify that the computation was successful, the function NbPoints to obtain the number of points of the computed distribution, and the function Parameter to read the parameter of each point. Warning - The roles of U1 and U2 are inverted if U1 > U2. - Derivative functions on the curve are called according to Continuity. An error may occur if Continuity is greater than the real degree of continuity of the curve. Warning C is an adapted curve, i.e. an object which is an interface between: - the services provided by either a 2D curve from the package Geom2d (in the case of an Adaptor2d_Curve2d curve) or a 3D curve from the package Geom (in the case of an Adaptor3d_Curve curve), and those required on the curve by the computation algorithm.", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("Continuity"));
cls_GCPnts_QuasiUniformDeflection.def("IsDone", (Standard_Boolean (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_QuasiUniformDeflection.def("NbPoints", (Standard_Integer (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::NbPoints, "Returns the number of points of the distribution computed by this algorithm. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_QuasiUniformDeflection.def("Parameter", (Standard_Real (GCPnts_QuasiUniformDeflection::*)(const Standard_Integer) const) &GCPnts_QuasiUniformDeflection::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_QuasiUniformDeflection.def("Value", (gp_Pnt (GCPnts_QuasiUniformDeflection::*)(const Standard_Integer) const) &GCPnts_QuasiUniformDeflection::Value, "Returns the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_QuasiUniformDeflection.def("Deflection", (Standard_Real (GCPnts_QuasiUniformDeflection::*)() const) &GCPnts_QuasiUniformDeflection::Deflection, "Returns the deflection between the curve and the polygon resulting from the points of the distribution computed by this algorithm. This is the value given to the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");

// CLASS: GCPNTS_UNIFORMABSCISSA
py::class_<GCPnts_UniformAbscissa> cls_GCPnts_UniformAbscissa(mod, "GCPnts_UniformAbscissa", "This class allows to compute a uniform distribution of points on a curve (ie the points will all be equally distant).");

// Constructors
cls_GCPnts_UniformAbscissa.def(py::init<>());
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer>(), py::arg("C"), py::arg("NbPoints"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformAbscissa.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));

// Methods
// cls_GCPnts_UniformAbscissa.def_static("operator new_", (void * (*)(size_t)) &GCPnts_UniformAbscissa::operator new, "None", py::arg("theSize"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete_", (void (*)(void *)) &GCPnts_UniformAbscissa::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_UniformAbscissa::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_UniformAbscissa::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_UniformAbscissa::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_UniformAbscissa.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_UniformAbscissa::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Integer a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints>, <Toler> and", py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor3d_Curve & a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>", py::arg("C"), py::arg("Abscissa"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Integer a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <NbPoints>, <Toler> and", py::arg("C"), py::arg("NbPoints"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("Initialize", [](GCPnts_UniformAbscissa &self, const Adaptor2d_Curve2d & a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformAbscissa.def("Initialize", (void (GCPnts_UniformAbscissa::*)(const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &GCPnts_UniformAbscissa::Initialize, "Initialize the algoritms with <C>, <Abscissa>, <U1>, <U2>, <Toler>.", py::arg("C"), py::arg("NbPoints"), py::arg("U1"), py::arg("U2"), py::arg("Toler"));
cls_GCPnts_UniformAbscissa.def("IsDone", (Standard_Boolean (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::IsDone, "None");
cls_GCPnts_UniformAbscissa.def("NbPoints", (Standard_Integer (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::NbPoints, "None");
cls_GCPnts_UniformAbscissa.def("Parameter", (Standard_Real (GCPnts_UniformAbscissa::*)(const Standard_Integer) const) &GCPnts_UniformAbscissa::Parameter, "returns the computed Parameter of index <Index>.", py::arg("Index"));
cls_GCPnts_UniformAbscissa.def("Abscissa", (Standard_Real (GCPnts_UniformAbscissa::*)() const) &GCPnts_UniformAbscissa::Abscissa, "returne the current abscissa ie the distance between two consecutive points");

// CLASS: GCPNTS_UNIFORMDEFLECTION
py::class_<GCPnts_UniformDeflection> cls_GCPnts_UniformDeflection(mod, "GCPnts_UniformDeflection", "Provides an algorithm to compute a distribution of points on a 'C2' continuous curve. The algorithm respects a criterion of maximum deflection between the curve and the polygon that results from the computed points. Note: This algorithm is relatively time consuming. A GCPnts_QuasiUniformDeflection algorithm is quicker; it can also work with non-'C2' continuous curves, but it generates more points in the distribution.");

// Constructors
cls_GCPnts_UniformDeflection.def(py::init<>());
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C"), py::arg("Deflection"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"));
cls_GCPnts_UniformDeflection.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));

// Methods
// cls_GCPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t)) &GCPnts_UniformDeflection::operator new, "None", py::arg("theSize"));
// cls_GCPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *)) &GCPnts_UniformDeflection::operator delete, "None", py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator new[]_", (void * (*)(size_t)) &GCPnts_UniformDeflection::operator new[], "None", py::arg("theSize"));
// cls_GCPnts_UniformDeflection.def_static("operator delete[]_", (void (*)(void *)) &GCPnts_UniformDeflection::operator delete[], "None", py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator new_", (void * (*)(size_t, void *)) &GCPnts_UniformDeflection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCPnts_UniformDeflection.def_static("operator delete_", (void (*)(void *, void *)) &GCPnts_UniformDeflection::operator delete, "None", py::arg(""), py::arg(""));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1) -> void { return self.Initialize(a0, a1); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>", py::arg("C"), py::arg("Deflection"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor3d_Curve & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2>", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("Initialize", [](GCPnts_UniformDeflection &self, const Adaptor2d_Curve2d & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Initialize(a0, a1, a2, a3); });
cls_GCPnts_UniformDeflection.def("Initialize", (void (GCPnts_UniformDeflection::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GCPnts_UniformDeflection::Initialize, "Initialize the algoritms with <C>, <Deflection>, <U1>,<U2> This and the above methods initialize (or reinitialize) this algorithm and compute a distribution of points: - on the curve C, or - on the part of curve C limited by the two parameter values U1 and U2, where the maximum distance between C and the polygon that results from the points of the distribution is not greater than Deflection. The first point of the distribution is either the origin of curve C or the point of parameter U1. The last point of the distribution is either the end point of curve C or the point of parameter U2. Intermediate points of the distribution are built using interpolations of segments of the curve limited at the 2nd degree. The construction ensures, in a first step, that the chordal deviation for this interpolation of the curve is less than or equal to Deflection. However, it does not ensure that the chordal deviation for the curve itself is less than or equal to Deflection. To do this a check is necessary, which may generate (second step) additional intermediate points. This check is time consuming, and can be avoided by setting WithControl to false. Note that by default WithControl is true and check is performed. Use the function IsDone to verify that the computation was successful, the function NbPoints to obtain the number of points of the computed distribution, and the function Parameter to read the parameter of each point. Warning - C is necessary, 'C2' continuous. This property is not checked at construction time. - The roles of U1 and U2 are inverted if U1 > U2. Warning C is an adapted curve, i.e. an object which is an interface between: - the services provided by either a 2D curve from the package Geom2d (in the case of an Adaptor2d_Curve2d curve) or a 3D curve from the package Geom (in the case of an Adaptor3d_Curve curve), - and those required on the curve by the computation algorithm.", py::arg("C"), py::arg("Deflection"), py::arg("U1"), py::arg("U2"), py::arg("WithControl"));
cls_GCPnts_UniformDeflection.def("IsDone", (Standard_Boolean (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::IsDone, "Returns true if the computation was successful. IsDone is a protection against: - non-convergence of the algorithm - querying the results before computation.");
cls_GCPnts_UniformDeflection.def("NbPoints", (Standard_Integer (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::NbPoints, "Returns the number of points of the distribution computed by this algorithm. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");
cls_GCPnts_UniformDeflection.def("Parameter", (Standard_Real (GCPnts_UniformDeflection::*)(const Standard_Integer) const) &GCPnts_UniformDeflection::Parameter, "Returns the parameter of the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_UniformDeflection.def("Value", (gp_Pnt (GCPnts_UniformDeflection::*)(const Standard_Integer) const) &GCPnts_UniformDeflection::Value, "Returns the point of index Index in the distribution computed by this algorithm. Warning Index must be greater than or equal to 1, and less than or equal to the number of points of the distribution. However, pay particular attention as this condition is not checked by this function. Exceptions StdFAil_NotDone if this algorithm has not been initialized, or if the computation was not successful.", py::arg("Index"));
cls_GCPnts_UniformDeflection.def("Deflection", (Standard_Real (GCPnts_UniformDeflection::*)() const) &GCPnts_UniformDeflection::Deflection, "Returns the deflection between the curve and the polygon resulting from the points of the distribution computed by this algorithm. This value is the one given to the algorithm at the time of construction (or initialization). Exceptions StdFail_NotDone if this algorithm has not been initialized, or if the computation was not successful.");


}