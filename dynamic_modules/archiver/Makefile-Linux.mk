#Build archiver dynamic module for LINUX
#
#There is no tool or dependency needed on a typical linux
#installation. To build the simple.so and simple change your
#directory to the modules/dynamic_modules/archiver/ folder 
#
#user $ cd modules/dynamic_modules/archiver/
#
#This is to ensure That the output generated are in 
#appropriate `dist` folder in modules folder. 
#Execute the below command in your command prompt of bash
#
#simple/src/makefiles/archiver/ $ make -f Makefile-Linux.mk

# Flags
CFLAGS= -c -fpic -g
LFlAGS= -lm -ldl
LDFLAGS= "-Wl,-rpath,../../../simple/src/dist/"

# Macros
CND_PLATFORM=
CND_DLIB_EXT=so
CND_BUILDDIR=build
CND_DISTDIR =../dist

# Object Directory
OBJECTDIR=$(CND_DISTDIR)/$(CND_BUILDDIR)/$(CND_PLATFORM)

# Object Files
OBJECTFILES= \
	$(OBJECTDIR)/archiver.o \
	$(OBJECTDIR)/zip.o
	
# Link Libraries and Options
LDLIBSOPTIONS=../../../simple/src/dist/simple.so

${CND_DISTDIR}/${CND_PLATFORM}/archiver.${CND_DLIB_EXT}: $(OBJECTFILES)
	$(CC) $(LFlAGS) -shared -o $(CND_DISTDIR)/$(CND_PLATFORM)/simple.$(CND_DLIB_EXT) $(OBJECTFILES) $(LDLIBSOPTIONS) -shared

$(OBJECTDIR)/archiver.o: archiver.c
	mkdir -p $(OBJECTDIR)
	$(CC) $(CFLAGS) archiver.c
	mv archiver.o $(OBJECTDIR)
	
$(OBJECTDIR)/zip.o: zip.c
	$(CC) $(CFLAGS) zip.c
	mv zip.o $(OBJECTDIR)

clean:
	@- $(RM) $(OBJECTDIR)/*.o
	@- $(RM) $(program_OBJS)

distclean: clean

#This Makefile-Windows.mk was written in adaptation to the standard
#method of writing makefiles
#
#If this make file does not work on your LINUX PC feel free to 
#write your own Makefile and send us a pull request at 
#https://github.com/simple-lang/simple . Your make file must follow 
#the below format for request to be accepted
#
#File-Name : Makefile-Linux-{distro}.mk
#
#e.g Makefile-Linux-mint-cinnamon.mk
#
#looking forward to your contribution
#Thank You
