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
#include <StepBasic_Array1OfPerson.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepBasic_HArray1OfPerson.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_HArray1OfPerson(py::module &mod){

py::class_<StepBasic_HArray1OfPerson, opencascade::handle<StepBasic_HArray1OfPerson>, Standard_Transient> cls_StepBasic_HArray1OfPerson(mod, "StepBasic_HArray1OfPerson", "None", py::multiple_inheritance());

// Constructors
cls_StepBasic_HArray1OfPerson.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepBasic_HArray1OfPerson.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfPerson::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepBasic_HArray1OfPerson.def(py::init<const StepBasic_Array1OfPerson &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepBasic_HArray1OfPerson.def_static("operator new_", (void * (*)(size_t)) &StepBasic_HArray1OfPerson::operator new, "None", py::arg("theSize"));
// cls_StepBasic_HArray1OfPerson.def_static("operator delete_", (void (*)(void *)) &StepBasic_HArray1OfPerson::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_HArray1OfPerson.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_HArray1OfPerson::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_HArray1OfPerson.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_HArray1OfPerson::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_HArray1OfPerson.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_HArray1OfPerson::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_HArray1OfPerson.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_HArray1OfPerson::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepBasic_HArray1OfPerson.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepBasic_HArray1OfPerson::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepBasic_HArray1OfPerson.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepBasic_HArray1OfPerson::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepBasic_HArray1OfPerson.def("Array1", (const StepBasic_Array1OfPerson & (StepBasic_HArray1OfPerson::*)() const) &StepBasic_HArray1OfPerson::Array1, "None");
cls_StepBasic_HArray1OfPerson.def("ChangeArray1", (StepBasic_Array1OfPerson & (StepBasic_HArray1OfPerson::*)()) &StepBasic_HArray1OfPerson::ChangeArray1, "None");
cls_StepBasic_HArray1OfPerson.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfPerson::get_type_name, "None");
cls_StepBasic_HArray1OfPerson.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfPerson::get_type_descriptor, "None");
cls_StepBasic_HArray1OfPerson.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfPerson::*)() const) &StepBasic_HArray1OfPerson::DynamicType, "None");

// Enums

}