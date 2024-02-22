## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gestionliste

gestionliste_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	lse.c lse.h \
	bureauv.c bureauv.h \
	tree.c tree.h \
	user.c user.h \
	election.c election.h \
	login.c login.h

gestionliste_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

