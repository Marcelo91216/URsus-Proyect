# Se requiere setuptools para compilar la extensión
# pip install setuptools
# Se corre el archivo con el siguiente comando
# Asumnido que se está en la carpeta raiz del proyecto
# python models/compile.py build_ext --inplace
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
