################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MainWindow.cpp \
../src/OptimizationRunSelector.cpp \
../src/ProblemDefBox.cpp \
../src/ProblemDefViewers.cpp \
../src/ShapeDiscretizationDrawingArea.cpp \
../src/ShapeLinesDrawingArea.cpp \
../src/ShapeTextDesc.cpp \
../src/SolutionDrawingArea.cpp \
../src/SolutionsBox.cpp \
../src/packing_optimizer_gui.cpp 

OBJS += \
./src/MainWindow.o \
./src/OptimizationRunSelector.o \
./src/ProblemDefBox.o \
./src/ProblemDefViewers.o \
./src/ShapeDiscretizationDrawingArea.o \
./src/ShapeLinesDrawingArea.o \
./src/ShapeTextDesc.o \
./src/SolutionDrawingArea.o \
./src/SolutionsBox.o \
./src/packing_optimizer_gui.o 

CPP_DEPS += \
./src/MainWindow.d \
./src/OptimizationRunSelector.d \
./src/ProblemDefBox.d \
./src/ProblemDefViewers.d \
./src/ShapeDiscretizationDrawingArea.d \
./src/ShapeLinesDrawingArea.d \
./src/ShapeTextDesc.d \
./src/SolutionDrawingArea.d \
./src/SolutionsBox.d \
./src/packing_optimizer_gui.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/gtkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/giomm-2.4 -I/usr/lib/x86_64-linux-gnu/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I/usr/include/gtk-3.0 -I/usr/include/cairomm-1.0 -I/usr/lib/x86_64-linux-gnu/cairomm-1.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I/usr/include/atk-1.0 -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/harfbuzz -O3 -Wall -c -fmessage-length=0 -pthread -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


