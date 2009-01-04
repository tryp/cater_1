SOURCES += app2.cpp \
           main.cpp \
 featurepoint.cpp
HEADERS += app2.h \
 featurepoint.h
TEMPLATE = app
CONFIG += warn_on \
	  thread \
          qt
TARGET = ../bin/app2
RESOURCES = application.qrc
