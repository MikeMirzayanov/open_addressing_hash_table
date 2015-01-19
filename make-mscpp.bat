call "%VS120COMNTOOLS%..\..\VC\bin\vcvars32.bat"
cl.exe /W4 /O2 /MD /EHsc benchmark.cpp
