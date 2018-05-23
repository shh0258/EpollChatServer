################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/180517_chatserver.cpp \
../src/Channel.cpp \
../src/ChannelManager.cpp \
../src/Client.cpp \
../src/Clientmanager.cpp \
../src/EpollController.cpp \
../src/PacketManager.cpp \
../src/Tcp.cpp \
../src/TcpServer.cpp 

OBJS += \
./src/180517_chatserver.o \
./src/Channel.o \
./src/ChannelManager.o \
./src/Client.o \
./src/Clientmanager.o \
./src/EpollController.o \
./src/PacketManager.o \
./src/Tcp.o \
./src/TcpServer.o 

CPP_DEPS += \
./src/180517_chatserver.d \
./src/Channel.d \
./src/ChannelManager.d \
./src/Client.d \
./src/Clientmanager.d \
./src/EpollController.d \
./src/PacketManager.d \
./src/Tcp.d \
./src/TcpServer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


