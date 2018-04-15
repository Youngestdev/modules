#Build CORE_DYNAMIC_MODULE dynamic module for LINUX
#
#There is no tool or dependency needed on a typical linux
#installation. To build the simple.so and simple change your
#directory to the modules/dynamic_modules/consoler/ folder 
#
#user $ cd modules/dynamic_modules/core_dynamic_module/
#
#This is to ensure That the output generated are in 
#appropriate `dist` folder in modules folder. 
#Execute the below command in your command prompt of bash
#
#simple/src/makefiles/core_dynamic_module/ $ make -f Makefile-Linux.mk

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

# Simple Object Directory
SIMPLE_OBJECTDIR=../../../simple/src/dist/$(CND_BUILDDIR)/$(CND_PLATFORM)

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/core_dynamic_module.o

# Simple Object Files
SIMPLE_OBJECTFILES = \
	$(SIMPLE_OBJECTDIR)/simple_api.o 
	
# Link Libraries and Options
LDLIBSOPTIONS=../../../simple/src/dist/simple.so

${CND_DISTDIR}/${CND_PLATFORM}/core_dynamic_module.${CND_DLIB_EXT}: $(OBJECTFILES)
	$(CC) -shared -o $(CND_DISTDIR)/$(CND_PLATFORM)/core_dynamic_module.$(CND_DLIB_EXT) $(SIMPLE_OBJECTFILES) $(OBJECTFILES) 

$(OBJECTDIR)/core_dynamic_module.o: core_dynamic_module.c
	mkdir -p $(OBJECTDIR)
	$(CC) $(CFLAGS) core_dynamic_module.c
	mv core_dynamic_module.o $(OBJECTDIR)

clean:
	@- $(RM) $(OBJECTDIR)/*.o
	@- $(RM) $(program_OBJS)

distclean: clean

#This Makefile-Windows.mk was written in adaptation to the standard
#method of writing makefiles
#
#If this make file does not work on your LINUX PC feel free to 
#write your own Makefile and send us a pull request at 
#https://github.com/simple-lang/modules . Your make file must follow 
#the below format for request to be accepted
#
#File-Name : Makefile-Linux-{distro}.mk
#
#e.g Makefile-Linux-mint-cinnamon.mk
#
#looking forward to your contribution
#Thank You
