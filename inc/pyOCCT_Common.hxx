/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019-2020  Trevor Laughlin and the pyOCCT contributors

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

#ifndef __pyOCCT_Common_Header__
#define __pyOCCT_Common_Header__
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <Standard_Handle.hxx>
namespace py = pybind11;
// Use opencascade::handle as holder type for Standard_Transient types
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);

// Allow downcasting subclasses of Standard_Transient*
namespace pybind11 {

    template<typename itype>
    struct py:polymorphic_type_hook<itype, detail::enable_if_t<std::is_base_of<Standard_Transient, itype>::value>> {
         static const void *get(const itype *src, const std::type_info*& type) {
             return static_cast<Standard_Transient*>(src);
         }
    };

}
#endif
