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
#include <math_FunctionWithDerivative.hxx>
#include <Standard.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <Extrema_PCFOfEPCOfExtPC2d.hxx>

void bind_Extrema_PCFOfEPCOfExtPC2d(py::module &mod){

py::class_<Extrema_PCFOfEPCOfExtPC2d, math_FunctionWithDerivative> cls_Extrema_PCFOfEPCOfExtPC2d(mod, "Extrema_PCFOfEPCOfExtPC2d", "None");

// Constructors
cls_Extrema_PCFOfEPCOfExtPC2d.def(py::init<>());
cls_Extrema_PCFOfEPCOfExtPC2d.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Fields

// Methods
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_PCFOfEPCOfExtPC2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_PCFOfEPCOfExtPC2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_PCFOfEPCOfExtPC2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_PCFOfEPCOfExtPC2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Initialize", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const Adaptor2d_Curve2d &)) &Extrema_PCFOfEPCOfExtPC2d::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SetPoint", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const gp_Pnt2d &)) &Extrema_PCFOfEPCOfExtPC2d::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Value", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Derivative", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Values", [](Extrema_PCFOfEPCOfExtPC2d &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("GetStateNumber", (Standard_Integer (Extrema_PCFOfEPCOfExtPC2d::*)()) &Extrema_PCFOfEPCOfExtPC2d::GetStateNumber, "Save the found extremum.");
cls_Extrema_PCFOfEPCOfExtPC2d.def("NbExt", (Standard_Integer (Extrema_PCFOfEPCOfExtPC2d::*)() const) &Extrema_PCFOfEPCOfExtPC2d::NbExt, "Return the nunber of found extrema.");
cls_Extrema_PCFOfEPCOfExtPC2d.def("SquareDistance", (Standard_Real (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("IsMin", (Standard_Boolean (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("Point", (const Extrema_POnCurv2d & (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Integer) const) &Extrema_PCFOfEPCOfExtPC2d::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SubIntervalInitialize", (void (Extrema_PCFOfEPCOfExtPC2d::*)(const Standard_Real, const Standard_Real)) &Extrema_PCFOfEPCOfExtPC2d::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Extrema_PCFOfEPCOfExtPC2d.def("SearchOfTolerance", (Standard_Real (Extrema_PCFOfEPCOfExtPC2d::*)()) &Extrema_PCFOfEPCOfExtPC2d::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// Enums

}