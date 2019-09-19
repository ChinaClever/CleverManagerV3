
INCLUDEPATH += $$PWD

include(users/users.pri)
include(upgrade/upgrade.pri)

HEADERS += \	
    $$PWD/setupmainwid.h \
    $$PWD/pdudevices/setup_pdusquerydlg.h \
    $$PWD/pdudevices/setup_pdusbtnbar.h \
    $$PWD/pdudevices/setup_pdustablewid.h \
    $$PWD/pdudevices/setup_cabquerydlg.h \
    $$PWD/pdudevices/setup_roomquerydlg.h
	
SOURCES += \	
    $$PWD/setupmainwid.cpp \
    $$PWD/pdudevices/setup_pdusquerydlg.cpp \
    $$PWD/pdudevices/setup_pdusbtnbar.cpp \
    $$PWD/pdudevices/setup_pdustablewid.cpp \
    $$PWD/pdudevices/setup_cabquerydlg.cpp \
    $$PWD/pdudevices/setup_roomquerydlg.cpp

FORMS += \
    $$PWD/setupmainwid.ui \
    $$PWD/pdudevices/setup_pdusquerydlg.ui \
    $$PWD/pdudevices/setup_pdustablewid.ui \
    $$PWD/pdudevices/setup_cabquerydlg.ui




