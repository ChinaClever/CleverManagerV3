
INCLUDEPATH += $$PWD

include(users/users.pri)

HEADERS += \	
    $$PWD/setupmainwid.h \
    $$PWD/pdudevices/setup_pdusquerydlg.h
	
SOURCES += \	
    $$PWD/setupmainwid.cpp \
    $$PWD/pdudevices/setup_pdusquerydlg.cpp

FORMS += \
    $$PWD/setupmainwid.ui \
    $$PWD/pdudevices/setup_pdusquerydlg.ui




