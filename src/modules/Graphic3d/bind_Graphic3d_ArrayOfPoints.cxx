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
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_ArrayOfPoints.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_ArrayOfPoints(py::module &mod){

py::class_<Graphic3d_ArrayOfPoints, opencascade::handle<Graphic3d_ArrayOfPoints>, Graphic3d_ArrayOfPrimitives> cls_Graphic3d_ArrayOfPoints(mod, "Graphic3d_ArrayOfPoints", "Contains points array definition.");

// Constructors
cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer>(), py::arg("theMaxVertexs"));
cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("theMaxVertexs"), py::arg("theHasVColors"));
cls_Graphic3d_ArrayOfPoints.def(py::init<const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("theMaxVertexs"), py::arg("theHasVColors"), py::arg("theHasVNormals"));

// Fields

// Methods
cls_Graphic3d_ArrayOfPoints.def_static("get_type_name_", (const char * (*)()) &Graphic3d_ArrayOfPoints::get_type_name, "None");
cls_Graphic3d_ArrayOfPoints.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_ArrayOfPoints::get_type_descriptor, "None");
cls_Graphic3d_ArrayOfPoints.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_ArrayOfPoints::*)() const) &Graphic3d_ArrayOfPoints::DynamicType, "None");

// Enums

}