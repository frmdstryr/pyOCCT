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
#include <StepDimTol_GeometricTolerance.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <StepDimTol_ModifiedGeometricTolerance.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_PositionTolerance.hxx>
#include <StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(py::module &mod){

py::class_<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol, opencascade::handle<StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol(mod, "StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol", "None");

// Constructors
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("Init", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &, const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aMagnitude"), py::arg("aTolerancedShapeAspect"), py::arg("aGTWDR"), py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetGeometricToleranceWithDatumReference", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetGeometricToleranceWithDatumReference, "None", py::arg("aGTWDR"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetGeometricToleranceWithDatumReference", (opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetGeometricToleranceWithDatumReference, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetModifiedGeometricTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_ModifiedGeometricTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetModifiedGeometricTolerance, "None", py::arg("aMGT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetModifiedGeometricTolerance", (opencascade::handle<StepDimTol_ModifiedGeometricTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetModifiedGeometricTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("SetPositionTolerance", (void (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)(const opencascade::handle<StepDimTol_PositionTolerance> &)) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::SetPositionTolerance, "None", py::arg("aPT"));
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("GetPositionTolerance", (opencascade::handle<StepDimTol_PositionTolerance> (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::GetPositionTolerance, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_name, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::get_type_descriptor, "None");
cls_StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::*)() const) &StepDimTol_GeoTolAndGeoTolWthDatRefAndModGeoTolAndPosTol::DynamicType, "None");

// Enums

}