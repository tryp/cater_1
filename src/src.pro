SOURCES += app2.cpp \
           main.cpp
HEADERS += app2.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ../bin/app2
RESOURCES = application.qrc
