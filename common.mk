
CLIB_SRC = $(wildcard common/clib/src/*.c)

CLIB_INC = -Icommon/clib/inc \
	-Icommon/


MCUMISC_SRC = common/mcu-misc/src/sys_time.c \
common/mmlib_config.c

MCUMISC_INC = -Icommon/mcu-misc/inc 
