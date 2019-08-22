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
#include <StepVisual_PresentedItem.hxx>
#include <Standard_Handle.hxx>
#include <StepAP214_HArray1OfAutoDesignPresentedItemSelect.hxx>
#include <StepAP214_AutoDesignPresentedItemSelect.hxx>
#include <Standard_TypeDef.hxx>
#include <StepAP214_AutoDesignPresentedItem.hxx>
#include <Standard_Type.hxx>

void bind_StepAP214_AutoDesignPresentedItem(py::module &mod){

py::class_<StepAP214_AutoDesignPresentedItem, opencascade::handle<StepAP214_AutoDesignPresentedItem>, StepVisual_PresentedItem> cls_StepAP214_AutoDesignPresentedItem(mod, "StepAP214_AutoDesignPresentedItem", "None");

// Constructors
cls_StepAP214_AutoDesignPresentedItem.def(py::init<>());

// Fields

// Methods
cls_StepAP214_AutoDesignPresentedItem.def("Init", (void (StepAP214_AutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> &)) &StepAP214_AutoDesignPresentedItem::Init, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignPresentedItem.def("SetItems", (void (StepAP214_AutoDesignPresentedItem::*)(const opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> &)) &StepAP214_AutoDesignPresentedItem::SetItems, "None", py::arg("aItems"));
cls_StepAP214_AutoDesignPresentedItem.def("Items", (opencascade::handle<StepAP214_HArray1OfAutoDesignPresentedItemSelect> (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::Items, "None");
cls_StepAP214_AutoDesignPresentedItem.def("ItemsValue", (StepAP214_AutoDesignPresentedItemSelect (StepAP214_AutoDesignPresentedItem::*)(const Standard_Integer) const) &StepAP214_AutoDesignPresentedItem::ItemsValue, "None", py::arg("num"));
cls_StepAP214_AutoDesignPresentedItem.def("NbItems", (Standard_Integer (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::NbItems, "None");
cls_StepAP214_AutoDesignPresentedItem.def_static("get_type_name_", (const char * (*)()) &StepAP214_AutoDesignPresentedItem::get_type_name, "None");
cls_StepAP214_AutoDesignPresentedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepAP214_AutoDesignPresentedItem::get_type_descriptor, "None");
cls_StepAP214_AutoDesignPresentedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepAP214_AutoDesignPresentedItem::*)() const) &StepAP214_AutoDesignPresentedItem::DynamicType, "None");

// Enums

}