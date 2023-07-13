# Compiler options
CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic
RELEASEFLAGS := -O2

# Directories
SRCDIR := src
OBJDIR := objs
BINDIR := bin
DEBUGDIR := $(BINDIR)/Debug
RELEASEDIR := $(BINDIR)/Release

# Files and targets
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
DEBUGOBJS := $(patsubst $(OBJDIR)/%.o,$(OBJDIR)/Debug/%.o,$(OBJS))
RELEASEOBJS := $(patsubst $(OBJDIR)/%.o,$(OBJDIR)/Release/%.o,$(OBJS))
DEBUGTARGET := $(DEBUGDIR)/main
RELEASETARGET := $(RELEASEDIR)/main

# Build rules
.PHONY: all clean debug release

all: debug release

debug: $(DEBUGTARGET)

release: $(RELEASETARGET)

$(DEBUGTARGET): $(DEBUGOBJS)
	@mkdir -p $(DEBUGDIR)
	@echo "$^ -> $@"
	@$(CXX) $(CXXFLAGS) -o $@ $^

$(RELEASETARGET): $(RELEASEOBJS)
	@mkdir -p $(RELEASEDIR)
	@echo "$^ -> $@"
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -o $@ $(RELEASEOBJS)

$(OBJDIR)/Debug/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$< -> $@"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/Release/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	@echo "$< -> $@"
	@$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJDIR) $(BINDIR)
