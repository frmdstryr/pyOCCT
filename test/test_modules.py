# This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
# geometry kernel.
#
# Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
import sys
import json
import pytest
from os.path import join, dirname

# Collect all the modules
BASE_DIR = dirname(dirname(__file__))
with open(join(BASE_DIR, 'binder', 'generate', 'all_modules.json')) as f:
    ALL_MODULES = json.load(f)

@pytest.mark.parametrize('mod', ALL_MODULES)
def test_module(mod):
    __import__(f'OCCT.{mod}')
