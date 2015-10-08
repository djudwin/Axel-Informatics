#
# Leave the following lines alone!!!

LDFLAGS=-melf_i386
%.o: %.asm
	nasm -f elf -l $*.lst $< -o $@

#
# End of provided rules
#

# Modify following to the name of your linked program
TARGET=countchars.out

# Modify following to the list of component object files
OBJS=countchars.o

#
# Do not modify remainder of this Makefile
#
${TARGET}: ${OBJS}
	${LD} ${LDFLAGS} ${OBJS} -o ${TARGET}


.PHONY: make
make:
	emacs Makefile

.PHONY: countchars
countchars:
	emacs countchars.asm

.PHONY: submit
submit:
	submit cs313_park proj1 countchars.asm

.PHONY: submitls
submitls:
	submitls cs313_park proj1

.PHONY: clean
clean:
	rm -f *# *~

.PHONY: run
run:
	countchars.out

