TEMPLATE = app
CONFIG += console c++11 opengl
CONFIG -= app_bundle
QT += widgets
QT += multimedia

DEFINES += SFML_STATIC
SOURCES += \
        Bullet.cpp \
        Button.cpp \
        Enemy.cpp \
        Game.cpp \
        Health.cpp \
        Player.cpp \
        Score.cpp \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-main -lsfml-graphics -lsfml-window -lsfml-system -lOpengl32
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/SFML/lib/ -lsfml-main-d -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -lOpengl32

INCLUDEPATH += $$PWD/SFML/include
DEPENDPATH += $$PWD/SFML/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/SFML/lib/libsfml-graphics-s.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/SFML/lib/libsfml-graphics-s-d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/SFML/lib/sfml-graphics-s.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/SFML/lib/sfml-graphics-s-d.lib

DISTFILES += \
    readme.txt

HEADERS += \
    Bullet.h \
    Button.h \
    Enemy.h \
    Game.h \
    Health.h \
    Player.h \
    Score.h

RESOURCES += \
    res.qrc
