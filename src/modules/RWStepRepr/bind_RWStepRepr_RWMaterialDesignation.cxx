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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepReaderData.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <RWStepRepr_RWMaterialDesignation.hxx>

void bind_RWStepRepr_RWMaterialDesignation(py::module &mod){

py::class_<RWStepRepr_RWMaterialDesignation> cls_RWStepRepr_RWMaterialDesignation(mod, "RWStepRepr_RWMaterialDesignation", "Read & Write Module for MaterialDesignation");

// Constructors
cls_RWStepRepr_RWMaterialDesignation.def(py::init<>());

// Fields

// Methods
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new_", (void * (*)(size_t)) &RWStepRepr_RWMaterialDesignation::operator new, "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete_", (void (*)(void *)) &RWStepRepr_RWMaterialDesignation::operator delete, "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new[]_", (void * (*)(size_t)) &RWStepRepr_RWMaterialDesignation::operator new[], "None", py::arg("theSize"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete[]_", (void (*)(void *)) &RWStepRepr_RWMaterialDesignation::operator delete[], "None", py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator new_", (void * (*)(size_t, void *)) &RWStepRepr_RWMaterialDesignation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWStepRepr_RWMaterialDesignation.def_static("operator delete_", (void (*)(void *, void *)) &RWStepRepr_RWMaterialDesignation::operator delete, "None", py::arg(""), py::arg(""));
cls_RWStepRepr_RWMaterialDesignation.def("ReadStep", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<StepRepr_MaterialDesignation> &) const) &RWStepRepr_RWMaterialDesignation::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWStepRepr_RWMaterialDesignation.def("WriteStep", (void (RWStepRepr_RWMaterialDesignation::*)(StepData_StepWriter &, const opencascade::handle<StepRepr_MaterialDesignation> &) const) &RWStepRepr_RWMaterialDesignation::WriteStep, "None", py::arg("SW"), py::arg("ent"));
cls_RWStepRepr_RWMaterialDesignation.def("Share", (void (RWStepRepr_RWMaterialDesignation::*)(const opencascade::handle<StepRepr_MaterialDesignation> &, Interface_EntityIterator &) const) &RWStepRepr_RWMaterialDesignation::Share, "None", py::arg("ent"), py::arg("iter"));

// Enums

}