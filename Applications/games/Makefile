CC = sdcc
ASM = sdasz80
AR = sdar
LINKER = sdcc
FCC = ../../Library/tools/fcc -O2
PLATFORM =
#PLATFORM = -tzx128

PROGLOAD=`(cat ../../Kernel/platform/config.h; echo PROGLOAD) | cpp -E | tail -n1`

# Used for programs that make sdcc go boom or take hours
CC_CRAP = -mz80 --std-c99 -c --opt-code-size --max-allocs-per-node 1000 -I../../Library/include
ASM_OPT = -l -o -s
LINKER_OPT = -mz80 --nostdlib --no-std-crt0 --code-loc $(PROGLOAD) --data-loc  0
BINMAN = ../../Library/tools/binman

.SUFFIXES: .c .rel

SRCSNS = qrun.c fortune.c

SRCS  = adv01.c adv02.c adv03.c adv04.c adv05.c adv06.c adv07.c \
        adv08.c adv09.c adv10.c adv11.c adv12.c adv13.c adv14a.c adv14b.c \
        myst01.c myst02.c myst03.c myst04.c myst05.c myst06.c myst07.c \
        myst08.c myst09.c myst10.c myst11.c fortune-gen.c mandel.c

SRCSBAD = 

OBJS = $(SRCS:.c=.rel)
OBJSNS = $(SRCSNS:.c=.rel)
OBJSBAD = $(SRCSBAD:.c=.rel)

LIBS = ../../Library/libs/syslib.lib

APPSNS = $(OBJSNS:.rel=)

APPS = $(OBJS:.rel=) $(OBJSBAD:.rel=) $(OBJSNS:.rel=)

all: $(APPS) sizes

$(OBJSBAD): $(SRCSBAD)
	$(CC) $(CC_CRAP) $(@:.rel=.c)

$(APPSNS): OPTS = --nostdio

$(OBJS): %.rel: %.c

$(OBJSNS): %.rel: %.c

$(OBJSBAD): %.rel: %.c

.c.rel:
	$(FCC) $(PLATFORM) -c $<

%: %.rel
	$(FCC) $(PLATFORM) $(OPTS) $< -o $@

sizes: $(APPS)
	ls -l $(APPS) >size.report

clean:
	rm -f $(OBJS) $(APPS) $(SRCS:.c=) core *~ *.asm *.lst *.sym *.map *.noi *.lk *.ihx *.tmp *.bin size.report

rmbak:
	rm -f *~ core

