goal: TARG

!if "$(ITLROOT)" == ""
!error Must set ITLROOT.
!endif

OBJS = \
	$O\HelloPublisher.obj \
	$O\HelloPublisherDll.obj \

TARGET=$O\HelloPublisher.dll
TARGETTYPE=dyna
DEFFILE=HelloPublisher.def

LIBS=$(DROPROOT)\platman\sdk\lib\target\$(TARG)\RComHelperCE.lib uuid.lib commctrl.lib

!include $(ITLROOT)\itlmake.inc

CFLAGS=$(CFLAGS) /D_CLIENT_ /I$O /I$(DROPROOT)\platman\sdk\include

.cpp{$O}.obj:
    $(DISP)$(CC) $(CFLAGS) $(CDEFS) $<

.c{$O}.obj:
    $(DISP)$(CC) $(CFLAGS) $(CDEFS) $<

