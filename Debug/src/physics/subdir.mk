################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/physics/Collision.cpp \
../src/physics/Object.cpp 

OBJS += \
./src/physics/Collision.o \
./src/physics/Object.o 

CPP_DEPS += \
./src/physics/Collision.d \
./src/physics/Object.d 


# Each subdirectory must supply rules for building sources it contributes
src/physics/%.o: ../src/physics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++14 -I"/home/schutzekatze/projects/cherry-aggregation" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


