goal: TARG

!if "$(ITLROOT)" == ""
!error Must set ITLROOT.
!endif

OBJS = \
	$O\tickstatsce.obj \

TARGET=$O\TickStatCE.exe
TARGETTYPE=PROGRAM

LIBS=commctrl.lib

!include $(ITLROOT)\itlmake.inc

CFLAGS=$(CFLAGS) /D_CLIENT_ /I$O /I$(DROPROOT)\sdk\platman\include /I..\include

.cpp{$O}.obj:
    $(DISP)$(CC) $(CFLAGS) $(CDEFS) $<

.c{$O}.obj:
    $(DISP)$(CC) $(CFLAGS) $(CDEFS) $<

