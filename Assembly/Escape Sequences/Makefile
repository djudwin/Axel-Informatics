#
# Leave the following lines alone!!!

LDFLAGS=-melf_i386
%.o: %.asm
	nasm -f elf -l $*.lst $< -o $@

#
# End of provided rules
#

# Modify following to the name of your linked program
TARGET=escapeseqs.out

# Modify following to the list of component object files
OBJS=escapeseqs.o

#
# Do not modify remainder of this Makefile
#
${TARGET}: ${OBJS}
	${LD} ${LDFLAGS} ${OBJS} -o ${TARGET}

.PHONY: run
run:
	escapeseqs.out

.PHONY: make
make:
	emacs Makefile

.PHONY: escape
escape:
	emacs escapeseqs.asm

.PHONY: submit
submit:
	submit cs313_park proj2 escapeseqs.asm typescript

.PHONY: clean
clean:
	-rm -f *# *~