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
#include <Standard_TypeDef.hxx>
#include <gce_ErrorType.hxx>
#include <GCE2d_Root.hxx>

void bind_GCE2d_Root(py::module &mod){

py::class_<GCE2d_Root> cls_GCE2d_Root(mod, "GCE2d_Root", "This class implements the common services for all classes of gce which report error.");

// Constructors

// Fields

// Methods
// cls_GCE2d_Root.def_static("operator new_", (void * (*)(size_t)) &GCE2d_Root::operator new, "None", py::arg("theSize"));
// cls_GCE2d_Root.def_static("operator delete_", (void (*)(void *)) &GCE2d_Root::operator delete, "None", py::arg("theAddress"));
// cls_GCE2d_Root.def_static("operator new[]_", (void * (*)(size_t)) &GCE2d_Root::operator new[], "None", py::arg("theSize"));
// cls_GCE2d_Root.def_static("operator delete[]_", (void (*)(void *)) &GCE2d_Root::operator delete[], "None", py::arg("theAddress"));
// cls_GCE2d_Root.def_static("operator new_", (void * (*)(size_t, void *)) &GCE2d_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GCE2d_Root.def_static("operator delete_", (void (*)(void *, void *)) &GCE2d_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_GCE2d_Root.def("IsDone", (Standard_Boolean (GCE2d_Root::*)() const) &GCE2d_Root::IsDone, "Returns true if the construction is successful.");
cls_GCE2d_Root.def("Status", (gce_ErrorType (GCE2d_Root::*)() const) &GCE2d_Root::Status, "Returns the status of the construction - gce_Done, if the construction is successful, or - another value of the gce_ErrorType enumeration indicating why the construction failed.");

// Enums

}