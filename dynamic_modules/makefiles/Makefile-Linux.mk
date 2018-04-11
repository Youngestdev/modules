#Build simple `Dynamic Modules` for LINUX
#
#There is no tool or dependency needed on a typical linux
#installation. To build the simple.so and simple change your
#directory to the modules/dynamic_modules/consoler/ folder 
#
#user $ cd modules/dynamic_modules/makefiles/
#
#This is to ensure That the output generated are in 
#appropriate `dist` folder in modules folder. 
#Execute the below command in your command prompt of bash
#
#modules/dynamic_modules/makefiles/ $ make -f Makefile-Linux.mk
#
#This make file generate dynamic library for the following 
#dynamic libraries
#
#	archiver
#	consoler
#	file_savant
#	mathic
#	string_savant
#	networker
#	parser
#	security
#	systemic

# Environment
MKDIR=mkdir
CP = cp
RMDIR=rmdir
RM=rm

# Macros
CND_PLATFORM=Windows
CND_DLIB_EXT=dll
CND_DISTDIR=../dist
CLEAN_DEBUGDIR=../../../s0.3.302-debug
DYNAMIC_MODULEDIR=.modules/dynamic_modules

clean: 
	cd ../archiver/ && $(MAKE) -f Makefile-Windows.mk
	cd ../consoler/ && $(MAKE) -f Makefile-Windows.mk
	cd ../file_savant/ && $(MAKE) -f Makefile-Windows.mk
	cd ../mathic/ && $(MAKE) -f Makefile-Windows.mk
	cd ../string_savant/ && $(MAKE) -f Makefile-Windows.mk
	cd ../networker/ && $(MAKE) -f Makefile-Windows.mk
	cd ../parser/ && $(MAKE) -f Makefile-Windows.mk
	cd ../security/ && $(MAKE) -f Makefile-Windows.mk
	cd ../systemic/ && $(MAKE) -f Makefile-Windows.mk
	
	${RM} ${CND_DISTDIR}/build/*.o
	${RM} ${CND_DISTDIR}/build/*.d
	#${RM} ${CND_DISTDIR}/build/includes/*.o
	#${RM} ${CND_DISTDIR}/build/includes/*.d
	#${RMDIR} ${CND_DISTDIR}/build/includes
	${RMDIR} ${CND_DISTDIR}/build
	#${MKDIR} -p ${CLEAN_DEBUGDIR}/${DYNAMIC_MODULEDIR}
	#${CP} ${CND_DISTDIR}/${CND_PLATFORM}/*.${CND_DLIB_EXT} ${CLEAN_DEBUGDIR}/${DYNAMIC_MODULEDIR}


#This Makefile-Windows.mk was written in adaptation to the MINGW
#description using the Netbeans IDE Makefiles as Guide.
#
#If this make file does not work on your Windows PC or you use 
#alternative compiler e.g Visual Studio, Cygwin e.t.c feel free to 
#write your own Makefile and send us a pull request at 
#https://github.com/simple-lang/modules . Your make file must follow 
#the below format for request to be accepted
#
#File-Name : Makefile-Windows-{Compiler}-{WindowsVersion}.mk
#
#e.g Makefile-Windows-cygwin-Windows8.mk
#
#looking forward to your contribution
#Thank You

