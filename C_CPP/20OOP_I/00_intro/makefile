CC = g++
CFLAGS   = -Wall -std=c++20

SRCDIR   = src
HEADDIR  = include
OBJDIR   = build
BINDIR   = bin
# where the executable will be stored
EXECUTABLE := $(BINDIR)/main

# list of all source files
SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
# list of all header files
INCLUDES := $(wildcard $(HEADDIR)/*.h)
# from the list of all source files, create a list of all object files
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# all: clean $(EXECUTABLE)
all: $(EXECUTABLE)

# Link: Generate executable file from object file
$(EXECUTABLE): $(OBJECTS)
	@echo LINKING..... $(CC) -o $@ $(OBJECTS)
	@$(CC) -o $@ $(OBJECTS)
	@echo RUNNING: $(EXECUTABLE)
	@$(EXECUTABLE)

# Compile: Generate object files from source files
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp | makedirs
	@echo COMPILING... $(CC) $(CFLAGS) -c "$<" -o "$@"
	@$(CC) $(CFLAGS) -c $< -o $@
# @echo Compiled "$<" successfully!

# `|` is order-only-prerequisites
# https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
makedirs:
# check if the file exists; if not, create it
# mkdir -p $(OBJDIR) in linux
	@if not exist "$(OBJDIR)" mkdir $(OBJDIR)
	@if not exist "$(BINDIR)" mkdir $(BINDIR)

#Delete dependence files, object files, and the EXECUTABLE file
clean:
	@echo CLEANING UP
# check if the directories exist; if so, delete them
	@if exist "$(OBJDIR)" rmdir /s /q $(OBJDIR)
	@if exist "$(BINDIR)" rmdir /s /q $(BINDIR)