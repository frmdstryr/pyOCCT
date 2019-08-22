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
#include <math_MultipleVarFunctionWithGradient.hxx>
#include <Standard.hxx>
#include <AppDef_MultiLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppParCurves_HArray1OfConstraintCouple.hxx>
#include <math_Vector.hxx>
#include <AppParCurves_MultiCurve.hxx>
#include <AppParCurves_Constraint.hxx>
#include <math_Matrix.hxx>
#include <AppDef_ParLeastSquareOfMyGradientOfCompute.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <AppDef_ParFunctionOfMyGradientOfCompute.hxx>

void bind_AppDef_ParFunctionOfMyGradientOfCompute(py::module &mod){

py::class_<AppDef_ParFunctionOfMyGradientOfCompute, math_MultipleVarFunctionWithGradient> cls_AppDef_ParFunctionOfMyGradientOfCompute(mod, "AppDef_ParFunctionOfMyGradientOfCompute", "None");

// Constructors
cls_AppDef_ParFunctionOfMyGradientOfCompute.def(py::init<const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const math_Vector &, const Standard_Integer>(), py::arg("SSP"), py::arg("FirstPoint"), py::arg("LastPoint"), py::arg("TheConstraints"), py::arg("Parameters"), py::arg("Deg"));

// Fields

// Methods
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new, "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new[], "None", py::arg("theSize"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete[]_", (void (*)(void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_ParFunctionOfMyGradientOfCompute.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_ParFunctionOfMyGradientOfCompute::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("NbVariables", (Standard_Integer (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::NbVariables, "returns the number of variables of the function. It corresponds to the number of MultiPoints.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Value", [](AppDef_ParFunctionOfMyGradientOfCompute &self, const math_Vector & X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "this method computes the new approximation of the MultiLine SSP and calculates F = sum (||Pui - Bi*Pi||2) for each point of the MultiLine.", py::arg("X"), py::arg("F"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Gradient", (Standard_Boolean (AppDef_ParFunctionOfMyGradientOfCompute::*)(const math_Vector &, math_Vector &)) &AppDef_ParFunctionOfMyGradientOfCompute::Gradient, "returns the gradient G of the sum above for the parameters Xi.", py::arg("X"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Values", [](AppDef_ParFunctionOfMyGradientOfCompute &self, const math_Vector & X, Standard_Real & F, math_Vector & G){ Standard_Boolean rv = self.Values(X, F, G); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "returns the value F=sum(||Pui - Bi*Pi||)2. returns the value G = grad(F) for the parameters Xi.", py::arg("X"), py::arg("F"), py::arg("G"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("NewParameters", (const math_Vector & (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::NewParameters, "returns the new parameters of the MultiLine.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("CurveValue", (const AppParCurves_MultiCurve & (AppDef_ParFunctionOfMyGradientOfCompute::*)()) &AppDef_ParFunctionOfMyGradientOfCompute::CurveValue, "returns the MultiCurve approximating the set after computing the value F or Grad(F).");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("Error", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)(const Standard_Integer, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::Error, "returns the distance between the MultiPoint of range IPoint and the curve CurveIndex.", py::arg("IPoint"), py::arg("CurveIndex"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("MaxError3d", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::MaxError3d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("MaxError2d", (Standard_Real (AppDef_ParFunctionOfMyGradientOfCompute::*)() const) &AppDef_ParFunctionOfMyGradientOfCompute::MaxError2d, "returns the maximum distance between the points and the MultiCurve.");
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("FirstConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientOfCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::FirstConstraint, "None", py::arg("TheConstraints"), py::arg("FirstPoint"));
cls_AppDef_ParFunctionOfMyGradientOfCompute.def("LastConstraint", (AppParCurves_Constraint (AppDef_ParFunctionOfMyGradientOfCompute::*)(const opencascade::handle<AppParCurves_HArray1OfConstraintCouple> &, const Standard_Integer) const) &AppDef_ParFunctionOfMyGradientOfCompute::LastConstraint, "None", py::arg("TheConstraints"), py::arg("LastPoint"));

// Enums

}