
INCLUDEPATH += $$PWD

include(up_ips/up_ips.pri)
include(up_work/up_work.pri)

HEADERS += \
    $$PWD/datapacket.h \
    $$PWD/devselectwid.h \
    $$PWD/up_maindlg.h
	
SOURCES += \
    $$PWD/datapacket.cpp \
    $$PWD/devselectwid.cpp \
    $$PWD/up_maindlg.cpp

FORMS += \
    $$PWD/devselectwid.ui \
    $$PWD/up_maindlg.ui




