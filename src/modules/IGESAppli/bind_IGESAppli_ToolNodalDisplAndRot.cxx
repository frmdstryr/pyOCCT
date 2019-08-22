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
#include <Standard_Handle.hxx>
#include <IGESAppli_NodalDisplAndRot.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESAppli_ToolNodalDisplAndRot.hxx>

void bind_IGESAppli_ToolNodalDisplAndRot(py::module &mod){

py::class_<IGESAppli_ToolNodalDisplAndRot> cls_IGESAppli_ToolNodalDisplAndRot(mod, "IGESAppli_ToolNodalDisplAndRot", "Tool to work on a NodalDisplAndRot. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESAppli_ToolNodalDisplAndRot.def(py::init<>());

// Fields

// Methods
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator new_", (void * (*)(size_t)) &IGESAppli_ToolNodalDisplAndRot::operator new, "None", py::arg("theSize"));
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator delete_", (void (*)(void *)) &IGESAppli_ToolNodalDisplAndRot::operator delete, "None", py::arg("theAddress"));
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator new[]_", (void * (*)(size_t)) &IGESAppli_ToolNodalDisplAndRot::operator new[], "None", py::arg("theSize"));
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator delete[]_", (void (*)(void *)) &IGESAppli_ToolNodalDisplAndRot::operator delete[], "None", py::arg("theAddress"));
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator new_", (void * (*)(size_t, void *)) &IGESAppli_ToolNodalDisplAndRot::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESAppli_ToolNodalDisplAndRot.def_static("operator delete_", (void (*)(void *, void *)) &IGESAppli_ToolNodalDisplAndRot::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESAppli_ToolNodalDisplAndRot.def("ReadOwnParams", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESAppli_ToolNodalDisplAndRot::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESAppli_ToolNodalDisplAndRot.def("WriteOwnParams", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, IGESData_IGESWriter &) const) &IGESAppli_ToolNodalDisplAndRot::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESAppli_ToolNodalDisplAndRot.def("OwnShared", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, Interface_EntityIterator &) const) &IGESAppli_ToolNodalDisplAndRot::OwnShared, "Lists the Entities shared by a NodalDisplAndRot <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESAppli_ToolNodalDisplAndRot.def("DirChecker", (IGESData_DirChecker (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &) const) &IGESAppli_ToolNodalDisplAndRot::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESAppli_ToolNodalDisplAndRot.def("OwnCheck", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESAppli_ToolNodalDisplAndRot::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESAppli_ToolNodalDisplAndRot.def("OwnCopy", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, const opencascade::handle<IGESAppli_NodalDisplAndRot> &, Interface_CopyTool &) const) &IGESAppli_ToolNodalDisplAndRot::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESAppli_ToolNodalDisplAndRot.def("OwnDump", (void (IGESAppli_ToolNodalDisplAndRot::*)(const opencascade::handle<IGESAppli_NodalDisplAndRot> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESAppli_ToolNodalDisplAndRot::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}