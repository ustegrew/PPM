# -----------------------------------------------------------------------------
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
# -----------------------------------------------------------------------------

#-------------------------------------------------
# Project created by QtCreator 2016-08-31T16:54:47
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = PPM
TEMPLATE = app

LIBS    += -ljack

#-------------------------------------------------
# Root folder
#-------------------------------------------------
SOURCES         += main.cpp \
    stream/endpoint/vendpoint.cpp \
    stream/endpoint/websocket/tendpoint_websocket.cpp \
    stream/endpoint/directio/tendpoint_directio.cpp \
    stream/endpoint/iostream/tendpoint_iostream.cpp

OTHER_FILES     += README.md \
                   license.txt

#-------------------------------------------------
# Module: Gui
#-------------------------------------------------
SOURCES +=  gui/twndmain.cpp \
            gui/tdlgtoolsjackd.cpp

HEADERS +=  gui/twndmain.h \
            gui/tdlgtoolsjackd.h \
    stream/endpoint/vendpoint.h \
    stream/endpoint/websocket/tendpoint_websocket.h \
    stream/endpoint/directio/tendpoint_directio.h \
    stream/endpoint/iostream/tendpoint_iostream.h

FORMS    += gui/twndmain.ui \
            gui/tdlgtoolsjackd.ui

#-------------------------------------------------
# Module: JackD
#-------------------------------------------------
SOURCES +=  jackd/tjackdadapter.cpp
HEADERS  += jackd/tjackdadapter.h

#-------------------------------------------------
# Module: Router
#-------------------------------------------------
SOURCES +=  router/trouter.cpp
HEADERS  += router/trouter.h

#-------------------------------------------------
# Module: Stream
#-------------------------------------------------
SOURCES +=  stream/conduit/tconduit.cpp \
            stream/plugin/vplugin.cpp \
            stream/plugin/tplugin_peakextractor.cpp \
            stream/plugin/tplugin_integrator.cpp

HEADERS +=  stream/conduit/tconduit.h \
            stream/plugin/vplugin.h \
            stream/plugin/tplugin_peakextractor.h \
            stream/plugin/tplugin_integrator.h
