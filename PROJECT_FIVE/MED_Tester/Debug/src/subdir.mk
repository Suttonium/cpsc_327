################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MED_Tester.cpp 

OBJS += \
./src/MED_Tester.o 

CPP_DEPS += \
./src/MED_Tester.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -std=c++11 -pthread -I"/home/raymond_sutton/Desktop/C++/stringdatabase" -I"/home/raymond_sutton/Desktop/C++/datastore" -I"/home/raymond_sutton/Desktop/C++/crypto" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


