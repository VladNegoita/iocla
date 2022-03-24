#include "Python.h"

int main()
{   
    PyObject *pModuleName, *pModule;
    PyObject *pFunc, *pythonArgument;
    PyObject *pValue;

    char *msg = "Hello World!";
    char *str = "World";

    setenv("PYTHONPATH","./python_modules",1);
    
	Py_Initialize();

	pModuleName = PyUnicode_DecodeFSDefault("my_module");

    pModule = PyImport_Import(pModuleName);

    pythonArgument = PyTuple_New(1);

    pValue = PyUnicode_DecodeFSDefault(msg);

    pFunc = PyObject_GetAttrString(pModule, "say");

    PyObject_CallObject(pFunc, pythonArgument);

    Py_DECREF(pFunc);
    Py_DECREF(pythonArgument);

    pythonArgument = PyTuple_New(2);

    pValue = PyUnicode_DecodeFSDefault(msg);

    pFunc = PyObject_GetAttrString(pModule, "subsir");

    PyObject_CallObject(pFunc, pythonArgument);

    Py_DECREF(pModuleName);
    Py_DECREF(pModule);

	Py_Finalize();

    return 0;
}
