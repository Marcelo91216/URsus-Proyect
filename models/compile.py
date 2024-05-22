# Se requiere setuptools para compilar la extensión
# pip install setuptools
# Se corre el archivo con el siguiente comando
# Adumiendo que se está en la carpeta models
# python compile.py build_ext --inplace

# Adicionalmente puedes hacer la compilacion sin este programa:
# g++ -shared -fPIC -o modelSUS.so model.cpp -I/path/to/directory/pythonX.X
# Donde X es la versión de Python que estás utilizando
from setuptools import setup, Extension

module = Extension(
    "modelSUS", sources=["model.cpp"], include_dirs=[], libraries=[], library_dirs=[]
)

setup(
    name="modelSUS",
    version="1.0",
    description="Extensión de Python para analizar URLs",
    ext_modules=[module],
)
