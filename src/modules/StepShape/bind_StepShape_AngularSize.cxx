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
#include <StepShape_DimensionalSize.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepShape_AngleRelator.hxx>
#include <StepShape_AngularSize.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_AngularSize(py::module &mod){

py::class_<StepShape_AngularSize, opencascade::handle<StepShape_AngularSize>, StepShape_DimensionalSize> cls_StepShape_AngularSize(mod, "StepShape_AngularSize", "Representation of STEP entity AngularSize");

// Constructors
cls_StepShape_AngularSize.def(py::init<>());

// Fields

// Methods
cls_StepShape_AngularSize.def("Init", (void (StepShape_AngularSize::*)(const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<TCollection_HAsciiString> &, const StepShape_AngleRelator)) &StepShape_AngularSize::Init, "Initialize all fields (own and inherited)", py::arg("aDimensionalSize_AppliesTo"), py::arg("aDimensionalSize_Name"), py::arg("aAngleSelection"));
cls_StepShape_AngularSize.def("AngleSelection", (StepShape_AngleRelator (StepShape_AngularSize::*)() const) &StepShape_AngularSize::AngleSelection, "Returns field AngleSelection");
cls_StepShape_AngularSize.def("SetAngleSelection", (void (StepShape_AngularSize::*)(const StepShape_AngleRelator)) &StepShape_AngularSize::SetAngleSelection, "Set field AngleSelection", py::arg("AngleSelection"));
cls_StepShape_AngularSize.def_static("get_type_name_", (const char * (*)()) &StepShape_AngularSize::get_type_name, "None");
cls_StepShape_AngularSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_AngularSize::get_type_descriptor, "None");
cls_StepShape_AngularSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_AngularSize::*)() const) &StepShape_AngularSize::DynamicType, "None");

// Enums

}