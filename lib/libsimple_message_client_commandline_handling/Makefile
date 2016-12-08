##
## @file Makefile
## Makefile for VCS TCP/IP bulletin board exercise.
##
## In the course "Verteilte Computer Systeme" the students shall
## implement a bulletin board. It shall consist of a spawning TCP/IP
## server which executes the business logic provided by the lector,
## and a suitable TCP/IP client.
##
## This is the Makefile for the reference implementation.
##
## @author Thomas M. Galla <galla@technikum-wien.at>
## @date 2014/08/22
##

-include global.mak
-include ../global.mak

##
## ------------------------------------------------------------- variables --
##

# override install dir for manual page
INSTALL_MAN_DIR := $(INSTALL_BASE_DIR)/man/man3

PACKAGE := libsimple_message_client_commandline_handling

OBJECTS := \
	simple_message_client_commandline_handling.o

ARCHIVE_SOURCES := \
	simple_message_client_commandline_handling.c \
	simple_message_client_commandline_handling.h \
	smc_parsecommandline.3 \
	Makefile \
	global.mak \
        doxygen.dcf \
	README.txt

SYMLINKS := \
	global.mak

GLOBAL_MAK := \
	$(wildcard ../global.mak)

ARCHIVES := $(foreach EXT,zip tar.gz,$(PACKAGE).$(EXT))

LIBRARIES := \
	$(PACKAGE).a

MANPAGES := \
	smc_parsecommandline.3

HEADERS := \
	simple_message_client_commandline_handling.h

CFLAGS := $(CFLAGS11)
LFLAGS :=

##
## --------------------------------------------------------------- targets --
##

all: symlinks libs

symlinks: $(SYMLINKS)

libs: $(LIBRARIES)

archs: $(ARCHIVES)

$(PACKAGE).a: $(OBJECTS)
	$(AR) -rcs $@ $^ 

global.mak: $(GLOBAL_MAK)
	$(LN) $< $@

clean:
	$(RM) $(OBJECTS) *~

clobber: clean
	$(RM) $(LIBRARIES) $(ARCHIVES)

distclean: clobber
	$(RM) -r doc $(SYMLINKS)

##
## ---------------------------------------------------------- dependencies --
##

simple_message_client_commandline_handling.o: simple_message_client_commandline_handling.c simple_message_client_commandline_handling.h Makefile

##
## =================================================================== eof ==
##
