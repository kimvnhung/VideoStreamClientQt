QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimediawidgets

TARGET = VideoStreamClient
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

QMAKE_CXXFLAGS += -O2 -D_FILE_OFFSET_BITS=64 -D_LARGEFILE64_SOURCE

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    controllers/connectionpage.cpp \
    controllers/displaypage.cpp \
    controllers/mainwindow.cpp \
# Network
    protobufs/Command.pb.cc \
    protobufs/Reply.pb.cc \
    utility/protobufhelper.cpp \
    utility/tcpclient.cpp

HEADERS += \
    controllers/connectionpage.h \
    controllers/displaypage.h \
    controllers/mainwindow.h \
#Network
    protobufs/Command.pb.h \
    protobufs/Reply.pb.h \
    utility/protobufhelper.h \
    utility/tcpclient.h

FORMS += \
    connectionpage.ui \
    displaypage.ui \
    mainwindow.ui

###Custom libraries
## Protobuf Libs
LIBS += -L/usr/local/lib/ -lprotobuf

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
