TARGET = tst_xmlpatternsxslts
CONFIG += testcase
SOURCES += tst_xmlpatternsxslts.cpp \
           ../qxmlquery/TestFundament.cpp

include (../xmlpatterns.pri)

HEADERS += ../xmlpatternsxqts/tst_suitetest.h
SOURCES += ../xmlpatternsxqts/tst_suitetest.cpp
LIBS += -l$$XMLPATTERNS_SDK

QT += xml testlib
INCLUDEPATH += $$(QTSRCDIR)/tests/auto/xmlpatternssdk  \
               $$(QTDIR)/include/QtXmlPatterns/private \
               $$(QTSRCDIR)/tests/auto/xmlpatternsxqts \
               ../xmlpatternsxqts                      \
               ../xmlpatternssdk

wince*: {
    testdata.files = XSLTS Baseline.xml
    testdata.path = .
    DEPLOYMENT += testdata
}

requires(contains(QT_CONFIG,private_tests))
