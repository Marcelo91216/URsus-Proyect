// Librerias
#include <Python.h>
#include <iostream>
#include <string>
#include "Tree.hpp"

static PyObject* is_valid_url(PyObject* self, PyObject* args) {
    const char* url;
    if (!PyArg_ParseTuple(args, "s", &url)) {
        return NULL;
    }
    
    URLGrammar grammar;
    bool is_valid = grammar.isValidURL(std::string(url));
    
    return PyBool_FromLong(is_valid);
}

static PyMethodDef ModelMethods[] = {
    {"is_valid_url", is_valid_url, METH_VARARGS, "Check if a URL is valid"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef modelmodule = {
    PyModuleDef_HEAD_INIT,
    "model",
    "A module to validate URLs",
    -1,
    ModelMethods
};

PyMODINIT_FUNC PyInit_model(void) {
    return PyModule_Create(&modelmodule);
}