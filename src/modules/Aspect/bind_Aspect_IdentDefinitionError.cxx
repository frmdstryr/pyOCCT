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
#include <Standard_OutOfRange.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Aspect_IdentDefinitionError.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Aspect_IdentDefinitionError(py::module &mod){

py::class_<Aspect_IdentDefinitionError, opencascade::handle<Aspect_IdentDefinitionError>, Standard_OutOfRange> cls_Aspect_IdentDefinitionError(mod, "Aspect_IdentDefinitionError", "None");

// Constructors
cls_Aspect_IdentDefinitionError.def(py::init<>());
cls_Aspect_IdentDefinitionError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(const Standard_CString)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("Raise_", (void (*)(Standard_SStream &)) &Aspect_IdentDefinitionError::Raise, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("NewInstance_", (opencascade::handle<Aspect_IdentDefinitionError> (*)(const Standard_CString)) &Aspect_IdentDefinitionError::NewInstance, "None", py::arg("theMessage"));
cls_Aspect_IdentDefinitionError.def_static("get_type_name_", (const char * (*)()) &Aspect_IdentDefinitionError::get_type_name, "None");
cls_Aspect_IdentDefinitionError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Aspect_IdentDefinitionError::get_type_descriptor, "None");
cls_Aspect_IdentDefinitionError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Aspect_IdentDefinitionError::*)() const) &Aspect_IdentDefinitionError::DynamicType, "None");

// Enums

}