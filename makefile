# makefile
# Created by IBM WorkFrame/2 MakeMake at 21:38:02 on 15 Feb 1997
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES: .c .obj 

.all: \
    E:\C_Projects\Joystick_Source\joydemo.exe

.c.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tdp /Ti /Fo"%|dpfF.obj" /C %s

E:\C_Projects\Joystick_Source\joydemo.exe: \
    E:\C_Projects\Joystick_Source\joydemo.obj \
    E:\C_Projects\Joystick_Source\joyos2.obj
    @echo " Link::Linker "
    icc.exe @<<
     /B" /de"
     /FeE:\C_Projects\Joystick_Source\joydemo.exe 
     E:\C_Projects\Joystick_Source\joydemo.obj
     E:\C_Projects\Joystick_Source\joyos2.obj
<<

E:\C_Projects\Joystick_Source\joydemo.obj: \
    E:\C_Projects\Joystick_Source\joydemo.c \
    {E:\C_Projects\Joystick_Source;$(INCLUDE);}joyos2.h

E:\C_Projects\Joystick_Source\joyos2.obj: \
    E:\C_Projects\Joystick_Source\joyos2.c \
    {E:\C_Projects\Joystick_Source;$(INCLUDE);}joyos2.h
