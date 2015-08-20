#include <Python.h>

static void hello_python();
static PyObject* emb_hello(PyObject *self, PyObject *args);

static PyMethodDef EmbMethods [] = {
  {"emb_hello",emb_hello, METH_VARARGS, ""},
  {NULL, NULL, 0, NULL}
};

int main()
{
  hello_python();
  return 0;
}

PyObject* emb_hello(PyObject *self, PyObject *args)
{ 
  printf("Hello from C\n");
  return Py_BuildValue("i",1);
}

void hello_python()
{
  FILE *f = fopen("script.py","r");
  Py_Initialize();
  Py_InitModule("emb", EmbMethods);
  PyRun_SimpleFile(f,"script.py");
  Py_Finalize();
}
