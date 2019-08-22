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
#include <StepGeom_Array1OfTrimmingSelect.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepGeom_HArray1OfTrimmingSelect.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_HArray1OfTrimmingSelect(py::module &mod){

py::class_<StepGeom_HArray1OfTrimmingSelect, opencascade::handle<StepGeom_HArray1OfTrimmingSelect>, Standard_Transient> cls_StepGeom_HArray1OfTrimmingSelect(mod, "StepGeom_HArray1OfTrimmingSelect", "None", py::multiple_inheritance());

// Constructors
cls_StepGeom_HArray1OfTrimmingSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepGeom_HArray1OfTrimmingSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepGeom_Array1OfTrimmingSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepGeom_HArray1OfTrimmingSelect.def(py::init<const StepGeom_Array1OfTrimmingSelect &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator new_", (void * (*)(size_t)) &StepGeom_HArray1OfTrimmingSelect::operator new, "None", py::arg("theSize"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator delete_", (void (*)(void *)) &StepGeom_HArray1OfTrimmingSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_HArray1OfTrimmingSelect::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_HArray1OfTrimmingSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_HArray1OfTrimmingSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_HArray1OfTrimmingSelect::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepGeom_HArray1OfTrimmingSelect::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepGeom_HArray1OfTrimmingSelect.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepGeom_HArray1OfTrimmingSelect::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepGeom_HArray1OfTrimmingSelect.def("Array1", (const StepGeom_Array1OfTrimmingSelect & (StepGeom_HArray1OfTrimmingSelect::*)() const) &StepGeom_HArray1OfTrimmingSelect::Array1, "None");
cls_StepGeom_HArray1OfTrimmingSelect.def("ChangeArray1", (StepGeom_Array1OfTrimmingSelect & (StepGeom_HArray1OfTrimmingSelect::*)()) &StepGeom_HArray1OfTrimmingSelect::ChangeArray1, "None");
cls_StepGeom_HArray1OfTrimmingSelect.def_static("get_type_name_", (const char * (*)()) &StepGeom_HArray1OfTrimmingSelect::get_type_name, "None");
cls_StepGeom_HArray1OfTrimmingSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_HArray1OfTrimmingSelect::get_type_descriptor, "None");
cls_StepGeom_HArray1OfTrimmingSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_HArray1OfTrimmingSelect::*)() const) &StepGeom_HArray1OfTrimmingSelect::DynamicType, "None");

// Enums

}