# project name (generate executable with this name)
TARGET   = rlcsim

CC       = gcc

# compiling flags here
CFLAGS   = -std=c99 -Wall -I. -lm

LINKER   = gcc -o

# linking flags here
LFLAGS   = -Wall -I.  -Xlinker --no-as-needed -lm

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f
mkdir    = mkdir

.PHONY: all clean remove dirs

all: dirs $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): dirs $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

dirs:
	-@$(mkdir) $(BINDIR) $(OBJDIR) 2>/dev/null || true
	

clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
