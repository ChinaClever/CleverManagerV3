QT      += network

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/udp/recv/udprecvsocket.h \
    $$PWD/udp/sent/udpbdsent.h \
    $$PWD/udp/sent/udpheartbeat.h \
    $$PWD/udp/sent/udpsentsocket.h \
    $$PWD/tcp/client/tcpclient.h \
    $$PWD/tftp/tftp.h \
    $$PWD/udp/recv/udpdataque.h \
    $$PWD/udp/recv/udpsocketlist.h \
    $$PWD/net_pdu/netdataformat.h \
    $$PWD/net_pdu/netanalyzedata.h \
    $$PWD/net_pdu/netpackdata.h \
    $$PWD/netdataanalyze.h

	
SOURCES += \
    $$PWD/udp/recv/udprecvsocket.cpp \
    $$PWD/udp/sent/udpbdsent.cpp \
    $$PWD/udp/sent/udpheartbeat.cpp \
    $$PWD/udp/sent/udpsentsocket.cpp \
    $$PWD/tcp/client/tcpclient.cpp \
    $$PWD/tftp/tftp.cpp \
    $$PWD/udp/recv/udpdataque.cpp \
    $$PWD/udp/recv/udpsocketlist.cpp \
    $$PWD/net_pdu/netanalyzedata.cpp \
    $$PWD/net_pdu/netpackdata.cpp \
    $$PWD/netdataanalyze.cpp

FORMS += \





