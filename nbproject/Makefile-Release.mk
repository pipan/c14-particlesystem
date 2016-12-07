#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/lib/CircleParticleShape.o \
	${OBJECTDIR}/lib/ColisionGrid.o \
	${OBJECTDIR}/lib/ColisionGridObject.o \
	${OBJECTDIR}/lib/ColisionGridTile.o \
	${OBJECTDIR}/lib/ColorTemplate.o \
	${OBJECTDIR}/lib/Constraint.o \
	${OBJECTDIR}/lib/CursorLine.o \
	${OBJECTDIR}/lib/DefaultRadioGroup.o \
	${OBJECTDIR}/lib/DistanceConstraint.o \
	${OBJECTDIR}/lib/DistanceConstraintForm.o \
	${OBJECTDIR}/lib/Enviroment.o \
	${OBJECTDIR}/lib/EnviromentForm.o \
	${OBJECTDIR}/lib/Event.o \
	${OBJECTDIR}/lib/EventHandler.o \
	${OBJECTDIR}/lib/EventListener.o \
	${OBJECTDIR}/lib/Focusable.o \
	${OBJECTDIR}/lib/FormService.o \
	${OBJECTDIR}/lib/HorizontalDevider.o \
	${OBJECTDIR}/lib/ImageButton.o \
	${OBJECTDIR}/lib/Input.o \
	${OBJECTDIR}/lib/KeyboardComb.o \
	${OBJECTDIR}/lib/LabelInput.o \
	${OBJECTDIR}/lib/Layout.o \
	${OBJECTDIR}/lib/MouseCursorController.o \
	${OBJECTDIR}/lib/MouseCursorService.o \
	${OBJECTDIR}/lib/MouseService.o \
	${OBJECTDIR}/lib/Pane.o \
	${OBJECTDIR}/lib/Particle.o \
	${OBJECTDIR}/lib/ParticleForm.o \
	${OBJECTDIR}/lib/ParticleService.o \
	${OBJECTDIR}/lib/ParticleSystem.o \
	${OBJECTDIR}/lib/ParticleSystemGenerator.o \
	${OBJECTDIR}/lib/PlayButton.o \
	${OBJECTDIR}/lib/Provider.o \
	${OBJECTDIR}/lib/Radio.o \
	${OBJECTDIR}/lib/RadioGroup.o \
	${OBJECTDIR}/lib/Renderable.o \
	${OBJECTDIR}/lib/SectionBlock.o \
	${OBJECTDIR}/lib/SelectRadioGroup.o \
	${OBJECTDIR}/lib/SelectableText.o \
	${OBJECTDIR}/lib/ShortcutService.o \
	${OBJECTDIR}/lib/SquareParticleShape.o \
	${OBJECTDIR}/lib/Template.o \
	${OBJECTDIR}/lib/TimeInterval.o \
	${OBJECTDIR}/lib/TimeService.o \
	${OBJECTDIR}/lib/ToggleRadioGroup.o \
	${OBJECTDIR}/lib/TriangleParticleShape.o \
	${OBJECTDIR}/lib/VectorMath.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mmpafp.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mmpafp.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mmpafp ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/lib/CircleParticleShape.o: lib/CircleParticleShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/CircleParticleShape.o lib/CircleParticleShape.cpp

${OBJECTDIR}/lib/ColisionGrid.o: lib/ColisionGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ColisionGrid.o lib/ColisionGrid.cpp

${OBJECTDIR}/lib/ColisionGridObject.o: lib/ColisionGridObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ColisionGridObject.o lib/ColisionGridObject.cpp

${OBJECTDIR}/lib/ColisionGridTile.o: lib/ColisionGridTile.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ColisionGridTile.o lib/ColisionGridTile.cpp

${OBJECTDIR}/lib/ColorTemplate.o: lib/ColorTemplate.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ColorTemplate.o lib/ColorTemplate.cpp

${OBJECTDIR}/lib/Constraint.o: lib/Constraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Constraint.o lib/Constraint.cpp

${OBJECTDIR}/lib/CursorLine.o: lib/CursorLine.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/CursorLine.o lib/CursorLine.cpp

${OBJECTDIR}/lib/DefaultRadioGroup.o: lib/DefaultRadioGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/DefaultRadioGroup.o lib/DefaultRadioGroup.cpp

${OBJECTDIR}/lib/DistanceConstraint.o: lib/DistanceConstraint.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/DistanceConstraint.o lib/DistanceConstraint.cpp

${OBJECTDIR}/lib/DistanceConstraintForm.o: lib/DistanceConstraintForm.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/DistanceConstraintForm.o lib/DistanceConstraintForm.cpp

${OBJECTDIR}/lib/Enviroment.o: lib/Enviroment.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Enviroment.o lib/Enviroment.cpp

${OBJECTDIR}/lib/EnviromentForm.o: lib/EnviromentForm.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/EnviromentForm.o lib/EnviromentForm.cpp

${OBJECTDIR}/lib/Event.o: lib/Event.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Event.o lib/Event.cpp

${OBJECTDIR}/lib/EventHandler.o: lib/EventHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/EventHandler.o lib/EventHandler.cpp

${OBJECTDIR}/lib/EventListener.o: lib/EventListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/EventListener.o lib/EventListener.cpp

${OBJECTDIR}/lib/Focusable.o: lib/Focusable.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Focusable.o lib/Focusable.cpp

${OBJECTDIR}/lib/FormService.o: lib/FormService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/FormService.o lib/FormService.cpp

${OBJECTDIR}/lib/HorizontalDevider.o: lib/HorizontalDevider.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/HorizontalDevider.o lib/HorizontalDevider.cpp

${OBJECTDIR}/lib/ImageButton.o: lib/ImageButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ImageButton.o lib/ImageButton.cpp

${OBJECTDIR}/lib/Input.o: lib/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Input.o lib/Input.cpp

${OBJECTDIR}/lib/KeyboardComb.o: lib/KeyboardComb.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/KeyboardComb.o lib/KeyboardComb.cpp

${OBJECTDIR}/lib/LabelInput.o: lib/LabelInput.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/LabelInput.o lib/LabelInput.cpp

${OBJECTDIR}/lib/Layout.o: lib/Layout.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Layout.o lib/Layout.cpp

${OBJECTDIR}/lib/MouseCursorController.o: lib/MouseCursorController.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/MouseCursorController.o lib/MouseCursorController.cpp

${OBJECTDIR}/lib/MouseCursorService.o: lib/MouseCursorService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/MouseCursorService.o lib/MouseCursorService.cpp

${OBJECTDIR}/lib/MouseService.o: lib/MouseService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/MouseService.o lib/MouseService.cpp

${OBJECTDIR}/lib/Pane.o: lib/Pane.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Pane.o lib/Pane.cpp

${OBJECTDIR}/lib/Particle.o: lib/Particle.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Particle.o lib/Particle.cpp

${OBJECTDIR}/lib/ParticleForm.o: lib/ParticleForm.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ParticleForm.o lib/ParticleForm.cpp

${OBJECTDIR}/lib/ParticleService.o: lib/ParticleService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ParticleService.o lib/ParticleService.cpp

${OBJECTDIR}/lib/ParticleSystem.o: lib/ParticleSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ParticleSystem.o lib/ParticleSystem.cpp

${OBJECTDIR}/lib/ParticleSystemGenerator.o: lib/ParticleSystemGenerator.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ParticleSystemGenerator.o lib/ParticleSystemGenerator.cpp

${OBJECTDIR}/lib/PlayButton.o: lib/PlayButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/PlayButton.o lib/PlayButton.cpp

${OBJECTDIR}/lib/Provider.o: lib/Provider.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Provider.o lib/Provider.cpp

${OBJECTDIR}/lib/Radio.o: lib/Radio.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Radio.o lib/Radio.cpp

${OBJECTDIR}/lib/RadioGroup.o: lib/RadioGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/RadioGroup.o lib/RadioGroup.cpp

${OBJECTDIR}/lib/Renderable.o: lib/Renderable.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Renderable.o lib/Renderable.cpp

${OBJECTDIR}/lib/SectionBlock.o: lib/SectionBlock.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/SectionBlock.o lib/SectionBlock.cpp

${OBJECTDIR}/lib/SelectRadioGroup.o: lib/SelectRadioGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/SelectRadioGroup.o lib/SelectRadioGroup.cpp

${OBJECTDIR}/lib/SelectableText.o: lib/SelectableText.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/SelectableText.o lib/SelectableText.cpp

${OBJECTDIR}/lib/ShortcutService.o: lib/ShortcutService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ShortcutService.o lib/ShortcutService.cpp

${OBJECTDIR}/lib/SquareParticleShape.o: lib/SquareParticleShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/SquareParticleShape.o lib/SquareParticleShape.cpp

${OBJECTDIR}/lib/Template.o: lib/Template.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/Template.o lib/Template.cpp

${OBJECTDIR}/lib/TimeInterval.o: lib/TimeInterval.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/TimeInterval.o lib/TimeInterval.cpp

${OBJECTDIR}/lib/TimeService.o: lib/TimeService.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/TimeService.o lib/TimeService.cpp

${OBJECTDIR}/lib/ToggleRadioGroup.o: lib/ToggleRadioGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/ToggleRadioGroup.o lib/ToggleRadioGroup.cpp

${OBJECTDIR}/lib/TriangleParticleShape.o: lib/TriangleParticleShape.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/TriangleParticleShape.o lib/TriangleParticleShape.cpp

${OBJECTDIR}/lib/VectorMath.o: lib/VectorMath.cpp 
	${MKDIR} -p ${OBJECTDIR}/lib
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/lib/VectorMath.o lib/VectorMath.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mmpafp.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
