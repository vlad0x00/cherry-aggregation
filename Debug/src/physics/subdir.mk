################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/physics/Byekt.cpp \
../src/physics/Collision.cpp 

OBJS += \
./src/physics/Byekt.o \
./src/physics/Collision.o 

CPP_DEPS += \
./src/physics/Byekt.d \
./src/physics/Collision.d 


# Each subdirectory must supply rules for building sources it contributes
src/physics/%.o: ../src/physics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I"/home/schutzekatze/projects/cherry-aggregation" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


