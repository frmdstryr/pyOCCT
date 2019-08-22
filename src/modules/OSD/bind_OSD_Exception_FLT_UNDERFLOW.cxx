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
#include <OSD_Exception.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <OSD_Exception_FLT_UNDERFLOW.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_OSD_Exception_FLT_UNDERFLOW(py::module &mod){

py::class_<OSD_Exception_FLT_UNDERFLOW, opencascade::handle<OSD_Exception_FLT_UNDERFLOW>, OSD_Exception> cls_OSD_Exception_FLT_UNDERFLOW(mod, "OSD_Exception_FLT_UNDERFLOW", "None");

// Constructors
cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<>());
cls_OSD_Exception_FLT_UNDERFLOW.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("Raise_", (void (*)(Standard_SStream &)) &OSD_Exception_FLT_UNDERFLOW::Raise, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("NewInstance_", (opencascade::handle<OSD_Exception_FLT_UNDERFLOW> (*)(const Standard_CString)) &OSD_Exception_FLT_UNDERFLOW::NewInstance, "None", py::arg("theMessage"));
cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_name_", (const char * (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_name, "None");
cls_OSD_Exception_FLT_UNDERFLOW.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OSD_Exception_FLT_UNDERFLOW::get_type_descriptor, "None");
cls_OSD_Exception_FLT_UNDERFLOW.def("DynamicType", (const opencascade::handle<Standard_Type> & (OSD_Exception_FLT_UNDERFLOW::*)() const) &OSD_Exception_FLT_UNDERFLOW::DynamicType, "None");

// Enums

}