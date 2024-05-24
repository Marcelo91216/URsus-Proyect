// Librerias
#include <Python.h>
#include <iostream>
#include <string>
#include <sstream>
#include "Tree.hpp"

static PyObject *is_valid_url(PyObject *self, PyObject *args)
{
    const char *url;
    if (!PyArg_ParseTuple(args, "s", &url))
    {
        return NULL;
    }

    URLGrammar grammar;
    bool is_valid = grammar.isValidURL(std::string(url));

    return PyBool_FromLong(is_valid);
}

static PyObject *analyze_url(PyObject *self, PyObject *args)
{
    const char *url;
    if (!PyArg_ParseTuple(args, "s", &url))
    {
        return NULL;
    }

    Tree *bin = new Tree();
    std::string url_str(url);
    bin->insert(url_str);

    // Redirigir std::cout a un stringstream
    std::stringstream buffer;
    std::streambuf *oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    bin->print();

    URLGrammar grammar;
    if (grammar.isValidURL(url_str))
    {
        std::cout << "La URL es válida." << std::endl;
    }
    else
    {
        std::cout << "La URL es inválida." << std::endl;
    }

    delete bin;

    // Restaurar el buffer original de std::cout
    std::cout.rdbuf(oldCoutBuffer);

    // Obtener el contenido del stringstream como una cadena
    std::string result = buffer.str();

    return PyUnicode_DecodeUTF8(result.c_str(), result.size(), "replace");
}

static PyMethodDef ModelMethods[] = {
    {"is_valid_url", is_valid_url, METH_VARARGS, "Comprueba si la URL es valida o no"},
    {"analyze_url", analyze_url, METH_VARARGS, "Imprime el analisis de la URL"},
    {NULL, NULL, 0, NULL}};
static struct PyModuleDef modelmodule = {
    PyModuleDef_HEAD_INIT,
    "modelSUS",
    "Nuestro modelo de analisis sintactico de una URL sospechosa",
    -1,
    ModelMethods};

PyMODINIT_FUNC PyInit_modelSUS(void)
{
    return PyModule_Create(&modelmodule);
}