#include <Python.h>
#include <iostream>

using namespace std;

static PyObject* call_c_from_py(PyObject* self, PyObject* arg) {
    // cout << "call C from py\n";
    return PyInt_FromLong(0);
}

static PyObject* call_py_from_c(PyObject* self, PyObject* arg) {
    // cout << "call py from C\n";
    Py_INCREF(arg);
    PyObject* func;
    PyObject* range;
    PyArg_ParseTuple(arg, "OO", &func, &range);
    int len = PySequence_Length(range);
    for(int i = 0; i < len; ++i) {
        // cout << PyInt_AS_LONG(item) << endl;
        PyObject_Call(func, Py_None, nullptr);
   }
    Py_DECREF(arg);
    return PyInt_FromLong(0);
}

// exported methods of the python extension module
static PyMethodDef python_methods[] = {
    {"call_c_from_py", call_c_from_py, METH_O, ""},
    {"call_py_from_c", call_py_from_c, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};


// entry point of the python extension module
PyMODINIT_FUNC inittestc(void) {
    (void) Py_InitModule("testc", python_methods);
}
