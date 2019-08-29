
INCLUDEPATH += $$PWD

include(excel/excel.pri)
include(chars/chars.pri)
include(dbcom/dbcom.pri)
include(sqlcom/sqlcom.pri)
include(cfgcom/cfgcom.pri)
include(msgcom/msgcom.pri)
include(logcom/logcom.pri)
include(backcolour/backcolour.pri)

HEADERS += \	
    $$PWD/common.h
	
SOURCES += \	
    $$PWD/common.cpp

FORMS += \




