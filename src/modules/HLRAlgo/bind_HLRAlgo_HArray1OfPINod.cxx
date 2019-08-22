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
#include <HLRAlgo_Array1OfPINod.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <HLRAlgo_HArray1OfPINod.hxx>
#include <Standard_Type.hxx>

void bind_HLRAlgo_HArray1OfPINod(py::module &mod){

py::class_<HLRAlgo_HArray1OfPINod, opencascade::handle<HLRAlgo_HArray1OfPINod>, Standard_Transient> cls_HLRAlgo_HArray1OfPINod(mod, "HLRAlgo_HArray1OfPINod", "None", py::multiple_inheritance());

// Constructors
cls_HLRAlgo_HArray1OfPINod.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_HLRAlgo_HArray1OfPINod.def(py::init<const Standard_Integer, const Standard_Integer, const HLRAlgo_Array1OfPINod::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_HLRAlgo_HArray1OfPINod.def(py::init<const HLRAlgo_Array1OfPINod &>(), py::arg("theOther"));

// Fields

// Methods
// cls_HLRAlgo_HArray1OfPINod.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_HArray1OfPINod::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_HArray1OfPINod::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_HArray1OfPINod::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_HArray1OfPINod::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_HArray1OfPINod::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_HArray1OfPINod::operator delete, "None", py::arg(""), py::arg(""));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &HLRAlgo_HArray1OfPINod::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_HLRAlgo_HArray1OfPINod.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &HLRAlgo_HArray1OfPINod::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_HLRAlgo_HArray1OfPINod.def("Array1", (const HLRAlgo_Array1OfPINod & (HLRAlgo_HArray1OfPINod::*)() const) &HLRAlgo_HArray1OfPINod::Array1, "None");
cls_HLRAlgo_HArray1OfPINod.def("ChangeArray1", (HLRAlgo_Array1OfPINod & (HLRAlgo_HArray1OfPINod::*)()) &HLRAlgo_HArray1OfPINod::ChangeArray1, "None");
cls_HLRAlgo_HArray1OfPINod.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_HArray1OfPINod::get_type_name, "None");
cls_HLRAlgo_HArray1OfPINod.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_HArray1OfPINod::get_type_descriptor, "None");
cls_HLRAlgo_HArray1OfPINod.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_HArray1OfPINod::*)() const) &HLRAlgo_HArray1OfPINod::DynamicType, "None");

// Enums

}