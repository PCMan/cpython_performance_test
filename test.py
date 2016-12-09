#!/usr/bin/env python2
import testc
import sys

def py_func():
    return 0

def main():
    test = sys.argv[1]
    num = int(sys.argv[2])
    if test == "p2c":
        print "Test calling C method from python for", num, "iterations"
        for i in xrange(num):
            testc.call_c_from_py(None)
    else:
        print "Test calling python method from C for", num, "iterations"
        testc.call_py_from_c(py_func, xrange(num))

if __name__ == "__main__":
    main()
