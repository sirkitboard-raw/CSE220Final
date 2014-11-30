#
# Use GNU make for this Makefile
#
# Makefile for cross-compiling C into MIPSEL COFF binaries
# and then dumping them as MARS-compatible .asm files.
#

#
# Default target - do nothing.
#
default:

include Makefile.compile

#
# Makefile.compile contains predefined rules for the following:
#
#	compiling a .c source file to a .o object file
#	compiling a .c source file to a .s assembly language file
#	linking a .coff executable from a single .o file
#	constructing a MARS .asm file from a .coff file
#
# So if you want to build "demo.asm" you can just say "gmake demo.asm"
# and it will work automatically if there is a demo.c or demo.s source
# file available.
#
# If you want to build an executable from multiple source files,
# then you need to create a new rule for linking the corresponding
# object files into a COFF executable.  The following sample rule
# shows how to create "demo.coff" from object files demo1.o and demo2.o.
# Note that demo1.o and demo2.o will be constructed automatically
# if .c or .s source files are available.  Once you have a rule to
# build "demo.coff", then "gmake demo.asm" will work automatically.
#
demo.coff: demo1.o demo2.o crt0.o libc.a
	$(LD) $(LDFLAGS) crt0.o demo1.o demo2.o -o demo.coff libc.a

#
# Clean up.
#
clean:
	rm -f *.o *.a *.coff *.asm *~
