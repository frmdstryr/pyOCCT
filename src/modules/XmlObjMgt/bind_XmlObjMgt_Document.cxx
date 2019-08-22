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
#include <LDOM_Document.hxx>
#include <XmlObjMgt_Document.hxx>

void bind_XmlObjMgt_Document(py::module &mod){

py::class_<LDOM_Document> cls_XmlObjMgt_Document(mod, "XmlObjMgt_Document", "None", py::module_local());

// Constructors
cls_XmlObjMgt_Document.def(py::init<>());
cls_XmlObjMgt_Document.def(py::init<const LDOM_MemManager &>(), py::arg("aMemManager"));

// Fields

// Methods
cls_XmlObjMgt_Document.def_static("createDocument_", (LDOM_Document (*)(const LDOMString &)) &LDOM_Document::createDocument, "None", py::arg("theQualifiedName"));
cls_XmlObjMgt_Document.def("createElement", (LDOM_Element (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createElement, "None", py::arg("theTagName"));
cls_XmlObjMgt_Document.def("createCDATASection", (LDOM_CDATASection (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createCDATASection, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("createComment", (LDOM_Comment (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createComment, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("createTextNode", (LDOM_Text (LDOM_Document::*)(const LDOMString &)) &LDOM_Document::createTextNode, "None", py::arg("theData"));
cls_XmlObjMgt_Document.def("getDocumentElement", (LDOM_Element (LDOM_Document::*)() const) &LDOM_Document::getDocumentElement, "None");
cls_XmlObjMgt_Document.def("getElementsByTagName", (LDOM_NodeList (LDOM_Document::*)(const LDOMString &) const) &LDOM_Document::getElementsByTagName, "None", py::arg("theTagName"));
// cls_XmlObjMgt_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const) &LDOM_Document::operator==, py::is_operator(), "None", py::arg("anOther"));
// cls_XmlObjMgt_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_Document &) const) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg("anOther"));
// cls_XmlObjMgt_Document.def("__eq__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const) &LDOM_Document::operator==, py::is_operator(), "None", py::arg(""));
// cls_XmlObjMgt_Document.def("__ne__", (Standard_Boolean (LDOM_Document::*)(const LDOM_NullPtr *) const) &LDOM_Document::operator!=, py::is_operator(), "None", py::arg(""));
cls_XmlObjMgt_Document.def("isNull", (Standard_Boolean (LDOM_Document::*)() const) &LDOM_Document::isNull, "None");
// cls_XmlObjMgt_Document.def("operator=", (LDOM_Document & (LDOM_Document::*)(const LDOM_NullPtr *)) &LDOM_Document::operator=, "None", py::arg(""));

// Enums

}