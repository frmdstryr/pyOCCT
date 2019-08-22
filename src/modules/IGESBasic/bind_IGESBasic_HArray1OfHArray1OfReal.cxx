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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_IGESBasic_HArray1OfHArray1OfReal(py::module &mod){

py::class_<IGESBasic_HArray1OfHArray1OfReal, opencascade::handle<IGESBasic_HArray1OfHArray1OfReal>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfReal(mod, "IGESBasic_HArray1OfHArray1OfReal", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Fields

// Methods
cls_IGESBasic_HArray1OfHArray1OfReal.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfReal::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESBasic_HArray1OfHArray1OfReal::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfReal.def("Value", (opencascade::handle<TColStd_HArray1OfReal> (IGESBasic_HArray1OfHArray1OfReal::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfReal::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfReal.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfReal::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfReal::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::DynamicType, "None");

// Enums

}