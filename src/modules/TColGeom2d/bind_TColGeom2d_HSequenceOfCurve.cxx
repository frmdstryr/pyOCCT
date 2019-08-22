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
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>
#include <Standard_Type.hxx>

void bind_TColGeom2d_HSequenceOfCurve(py::module &mod){

py::class_<TColGeom2d_HSequenceOfCurve, opencascade::handle<TColGeom2d_HSequenceOfCurve>, Standard_Transient> cls_TColGeom2d_HSequenceOfCurve(mod, "TColGeom2d_HSequenceOfCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HSequenceOfCurve.def(py::init<>());
cls_TColGeom2d_HSequenceOfCurve.def(py::init<const TColGeom2d_SequenceOfCurve &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HSequenceOfCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HSequenceOfCurve.def("Sequence", (const TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)() const) &TColGeom2d_HSequenceOfCurve::Sequence, "None");
cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve::value_type &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theItem"));
cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom2d_HSequenceOfCurve.def("ChangeSequence", (TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)()) &TColGeom2d_HSequenceOfCurve::ChangeSequence, "None");
cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfCurve::get_type_name, "None");
cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfCurve::get_type_descriptor, "None");
cls_TColGeom2d_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfCurve::*)() const) &TColGeom2d_HSequenceOfCurve::DynamicType, "None");

// Enums

}