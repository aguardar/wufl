from ctypes import *
h=windll.LoadLibrary('CH375DLL.DLL')
def openled():
    h.CH375OpenDevice(0)
    a=1
    h.CH375WriteData(0,'1',id(a))
    h.CH375CloseDevice(0)
