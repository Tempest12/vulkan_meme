#Compiler and flags
#Author Shane del Solar
CC     = g++
CFLAGS = -Wall -g -std=c++14
DEFINITIONS = -DGLFW_INCLUDE_VULKAN=1
LINKER = -lvulkan -lglfw

VKOBJECT = Main.o Log.o VkCore.o Trikey.o Parsing.o Config.o StringLib.o VkWindow.o VkFunctionTable.o

EXE = vk

all: build

build: $(VKOBJECT)
	$(CC) $(VKOBJECT) $(LINKER) -o $(EXE)

clean:
	rm -f *.o $(EXE)

%.o : %.cpp
	$(CC) $(CFLAGS) $(DEFINITIONS) -c $<
