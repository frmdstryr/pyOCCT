import os
import sys
import json
import argparse
from os.path import join, abspath, exists

# If running outside this folder we need to add this to the syspath
BINDER_ROOT = os.path.dirname(os.path.dirname(__file__))
if BINDER_ROOT not in sys.path:
    sys.path.append(BINDER_ROOT)

from binder.core import Generator


def get_search_paths():
    """ Generate a list of paths to search for clang and opencascade

    """
    for env_var in ('PREFIX', 'CONDA_PREFIX', 'BUILD_PREFIX',
                    'LIBRARY_PREFIX', 'LIBRARY_LIB', 'LIBRARY_INC'):
        path = os.environ.get(env_var)
        if path:
            yield path
    return '.'

# Use conda instead of system lib/includes
def find_occt_include_dir():
    for path in get_search_paths():
        occt_include_dir = abspath(join(path, 'include', 'opencascade'))
        if exists(occt_include_dir):
            print("Found {}".format(occt_include_dir))
            return occt_include_dir


def find_clang_include_dir():
    for path in get_search_paths():
        clang_include_path = join(path, 'lib', 'clang', '10.0.0', 'include')
        if exists(clang_include_path):
            print("Found {}".format(clang_include_path))
            return clang_include_path


def gen_includes(opencascade_include_path='../include/opencascade',
                 output_dir='.'):
    output_dir = abspath(output_dir)

    # Generate all_includes.h and output modules
    all_includes = []

    occt_mods = set()
    for fin in os.listdir(opencascade_include_path):
        if fin.endswith('.hxx'):
            all_includes.append(fin)
        if '_' in fin:
            mod = fin.split('_')[0]
        else:
            mod = fin.split('.')[0]
        occt_mods.add(mod)

    # OCCT modules
    occt_mods = list(occt_mods)
    occt_mods.sort(key=str.lower)
    with open(join(output_dir, 'all_modules.json'), 'w') as fout:
        json.dump(occt_mods, fout, indent=4)

    # Sort ignoring case
    all_includes.sort(key=str.lower)

    # all_includes.h
    with open(join(output_dir, 'all_includes.h'), 'w') as fout:
        fout.write("/*****************************************************/\n")
        fout.write("/* Do not edit! This file is automatically generated */\n")
        fout.write("/*****************************************************/\n")
        fout.write("#ifdef _WIN32\n")
        fout.write('    #include <Windows.h>\n')
        fout.write("#endif\n")

        fout.write("\n// OCCT\n")
        for header in all_includes:
            fout.write('#include <{}>\n'.format(header))

    return occt_mods


def main():
    parser = argparse.ArgumentParser()
    print('='*100)
    print("pyOCCT Binder")
    print('='*100)

    parser.add_argument(
        '-i',
        help='Path to opencascade includes',
        dest='opencascade_include_path',
        default=find_occt_include_dir())

    parser.add_argument(
        '-o',
        help='Path to pyOCCT',
        default='.',
        dest='pyocct_path')

    parser.add_argument(
        '--clang',
        help='Path to clang includes',
        dest='clang_include_path',
        default=find_clang_include_dir())

    args = parser.parse_args()

    if not exists(args.opencascade_include_path):
        print(f"ERROR: OpenCASCADE include path does not exist:"
              f"{args.opencascade_include_path}")
        sys.exit(1)

    if not exists(args.pyocct_path):
        print(f"ERROR: pyOCCT path is does not exist: "
              f"{args.pyocct_path}")
        sys.exit(1)

    # TODO: Move this to the binder?
    print('Collecting OpenCASCADE headers...')
    gen_dir = abspath(join(BINDER_ROOT, 'generate'))
    occt_mods = gen_includes(args.opencascade_include_path, gen_dir)

    # Force using conda's clangdev includes
    # TODO: This may not be needed on other systems but was getting errors
    # on linux.
    if not exists(args.clang_include_path):
        print(f"ERROR: libclang include path is does not exist:"
              f"{args.clang_include_path}")
        sys.exit(1)

    main = Generator(occt_mods,
                     args.opencascade_include_path,
                     args.clang_include_path)

    pyocct_inc = abspath(join(args.pyocct_path, 'inc'))
    pyocct_src = abspath(join(args.pyocct_path, 'src', 'occt'))

    if not exists(pyocct_inc):
        os.makedirs(pyocct_inc)

    if not exists(pyocct_src):
        os.makedirs(pyocct_src)

    print(f"Writing inc files to: {pyocct_inc}")
    print(f"Writing src files to: {pyocct_src}")

    # For debugging and dev
    main.bind_enums = True
    main.bind_functions = True
    main.bind_classes = True
    main.bind_typedefs = True
    main.bind_class_templates = True

    main.process_config(join(BINDER_ROOT, 'generate', 'config.txt'))

    print('Generate common header file...')
    main.generate_common_header(pyocct_inc)

    print('Parsing headers...')
    main.parse(join(gen_dir, 'all_includes.h'))
    main.dump_diagnostics()

    print('Traversing headers...')
    main.traverse()

    print('Sorting binders...')
    main.sort_binders()

    print('Building includes...')
    main.build_includes()

    print('Building imports...')
    main.build_imports()

    print('Checking circular imports...')
    main.check_circular()

    print('Binding templates...')
    main.bind_templates(pyocct_src)

    print('Binding...')
    main.bind(pyocct_src)
    print('Done!')
    print('='*100)


if __name__ == '__main__':
    main()
