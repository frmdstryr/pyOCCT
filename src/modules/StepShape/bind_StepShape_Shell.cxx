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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepShape_OpenShell.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_Shell.hxx>

void bind_StepShape_Shell(py::module &mod){

py::class_<StepShape_Shell, StepData_SelectType> cls_StepShape_Shell(mod, "StepShape_Shell", "None");

// Constructors
cls_StepShape_Shell.def(py::init<>());

// Fields

// Methods
// cls_StepShape_Shell.def_static("operator new_", (void * (*)(size_t)) &StepShape_Shell::operator new, "None", py::arg("theSize"));
// cls_StepShape_Shell.def_static("operator delete_", (void (*)(void *)) &StepShape_Shell::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_Shell.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_Shell::operator new[], "None", py::arg("theSize"));
// cls_StepShape_Shell.def_static("operator delete[]_", (void (*)(void *)) &StepShape_Shell::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_Shell.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_Shell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_Shell.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_Shell::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_Shell.def("CaseNum", (Standard_Integer (StepShape_Shell::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_Shell::CaseNum, "Recognizes a Shell Kind Entity that is : 1 -> OpenShell 2 -> ClosedShell 0 else", py::arg("ent"));
cls_StepShape_Shell.def("OpenShell", (opencascade::handle<StepShape_OpenShell> (StepShape_Shell::*)() const) &StepShape_Shell::OpenShell, "returns Value as a OpenShell (Null if another type)");
cls_StepShape_Shell.def("ClosedShell", (opencascade::handle<StepShape_ClosedShell> (StepShape_Shell::*)() const) &StepShape_Shell::ClosedShell, "returns Value as a ClosedShell (Null if another type)");

// Enums

}