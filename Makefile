#############################################################################
# Makefile for building: QTFractal
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat Jan 12 01:58:57 2013
# Project:  QTFractal.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile QTFractal.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = evaluate.cc \
		iterated_fractal.cc \
		main.cc \
		mandelbrot.cc \
		palette.cc \
		result.cc \
		viewport.cc \
		fractal.cc \
		fractal_view.cc \
		julia.cc \
		main_window.cc moc_fractal_view.cpp \
		moc_main_window.cpp
OBJECTS       = evaluate.o \
		iterated_fractal.o \
		main.o \
		mandelbrot.o \
		palette.o \
		result.o \
		viewport.o \
		fractal.o \
		fractal_view.o \
		julia.o \
		main_window.o \
		moc_fractal_view.o \
		moc_main_window.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		QTFractal.pro
QMAKE_TARGET  = QTFractal
DESTDIR       = 
TARGET        = QTFractal

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: QTFractal.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile QTFractal.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile QTFractal.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/QTFractal1.0.0 || $(MKDIR) .tmp/QTFractal1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/QTFractal1.0.0/ && $(COPY_FILE) --parents evaluate.hh iterated_fractal.hh mandelbrot.hh palette.hh result.hh viewport.hh fractal.hh fractal_view.hh julia.hh main_window.hh .tmp/QTFractal1.0.0/ && $(COPY_FILE) --parents evaluate.cc iterated_fractal.cc main.cc mandelbrot.cc palette.cc result.cc viewport.cc fractal.cc fractal_view.cc julia.cc main_window.cc .tmp/QTFractal1.0.0/ && (cd `dirname .tmp/QTFractal1.0.0` && $(TAR) QTFractal1.0.0.tar QTFractal1.0.0 && $(COMPRESS) QTFractal1.0.0.tar) && $(MOVE) `dirname .tmp/QTFractal1.0.0`/QTFractal1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QTFractal1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_fractal_view.cpp moc_main_window.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_fractal_view.cpp moc_main_window.cpp
moc_fractal_view.cpp: fractal.hh \
		viewport.hh \
		fractal_view.hh
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) fractal_view.hh -o moc_fractal_view.cpp

moc_main_window.cpp: main_window.hh
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) main_window.hh -o moc_main_window.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

evaluate.o: evaluate.cc evaluate.hh \
		result.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o evaluate.o evaluate.cc

iterated_fractal.o: iterated_fractal.cc iterated_fractal.hh \
		fractal.hh \
		viewport.hh \
		evaluate.hh \
		result.hh \
		palette.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o iterated_fractal.o iterated_fractal.cc

main.o: main.cc fractal_view.hh \
		fractal.hh \
		viewport.hh \
		mandelbrot.hh \
		iterated_fractal.hh \
		evaluate.hh \
		result.hh \
		palette.hh \
		julia.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cc

mandelbrot.o: mandelbrot.cc mandelbrot.hh \
		iterated_fractal.hh \
		fractal.hh \
		viewport.hh \
		evaluate.hh \
		result.hh \
		palette.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mandelbrot.o mandelbrot.cc

palette.o: palette.cc palette.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o palette.o palette.cc

result.o: result.cc result.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o result.o result.cc

viewport.o: viewport.cc viewport.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o viewport.o viewport.cc

fractal.o: fractal.cc fractal.hh \
		viewport.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fractal.o fractal.cc

fractal_view.o: fractal_view.cc fractal_view.hh \
		fractal.hh \
		viewport.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o fractal_view.o fractal_view.cc

julia.o: julia.cc julia.hh \
		iterated_fractal.hh \
		fractal.hh \
		viewport.hh \
		evaluate.hh \
		result.hh \
		palette.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o julia.o julia.cc

main_window.o: main_window.cc main_window.hh
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_window.o main_window.cc

moc_fractal_view.o: moc_fractal_view.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_fractal_view.o moc_fractal_view.cpp

moc_main_window.o: moc_main_window.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_main_window.o moc_main_window.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

