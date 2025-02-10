#chentong mymuduo Makefile
#20240901

INC_PATH := \
	-I. \

BUILD_DIR=$(PWD)
BUILD_PATH=$(BUILD_DIR)/.obj/release
DEBUG_BUILD_PATH=$(BUILD_DIR)/.obj/debug

TARGET_NAME=muduo
PREFIX ?= ../3rd
INSTALL ?= cp -a
INCLUDE_PATH ?= include/$(TARGET_NAME)
INSTALL_INCLUDE_PATH=$(PREFIX)/$(INCLUDE_PATH)
INSTALL_LIBRARY_PATH = $(PREFIX)/lib

CXX = /usr/bin/myg++

ADDRESS_SANITIZE = -fsanitize=address -fno-omit-frame-pointer -fsanitize=object-size -fsanitize=float-divide-by-zero -fsanitize=bounds -static-libasan -static-libubsan
ASAN_FIR_DEBUG_OPT = -fno-omit-frame-pointer
FIR_RELEASE_OPT = -O2 -fno-omit-frame-pointer
FIR_COMPILE_OPT = -std=gnu++11 -g -g3 -fPIC -Wno-stringop-truncation -fno-strict-aliasing -Werror -Wall -D_GNU_SOURCE -D_REENTRANT

CXXFLAGS = $(FIR_COMPILE_OPT) $(FIR_RELEASE_OPT)
TARGET = $(BUILD_PATH)/lib$(TARGET_NAME).a
OBJS := $(patsubst %.cc, $(BUILD_PATH)/%.o, $(wildcard *.cc))
DEPS = $(OBJS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/.%.d)

DEBUG_CXXFLAGS = $(FIR_COMPILE_OPT)
DEBUG_TARGET = $(DEBUG_BUILD_PATH)/lib$(TARGET_NAME)_D.a
DEBUG_OBJS := $(patsubst %.cc, $(DEBUG_BUILD_PATH)/%.o, $(wildcard *.cc))
DEBUG_DEPS = $(DEBUG_OBJS:$(DEBUG_BUILD_PATH)/%.o=$(DEBUG_BUILD_PATH)/.%.d)

all : $(DEBUG_TARGET) $(TARGET)

-include $(DEPS) $(DEBUG_DEPS)

$(DEPS) : $(BUILD_PATH)/.%.d : %.cc
	@if [ ! -d "$(dir $@)" ]; then mkdir -pv $(dir $@); fi
	@$(CXX) -M $(CXXFLAGS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(BUILD_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(DEBUG_DEPS) : $(DEBUG_BUILD_PATH)/.%.d : %.cc
	@if [ ! -d "$(dir $@)" ]; then mkdir -pv $(dir $@); fi
	@$(CXX) -M $(DEBUG_CXXFLAGS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(DEBUG_BUILD_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(TARGET) : $(OBJS)
	@rm -rf $(TARGET)
	@ar cru $(TARGET) $(OBJS)
	@ranlib $(TARGET)
	@ctags -R -h ".cc.h" -o tags

$(DEBUG_TARGET) : $(DEBUG_OBJS)
	@rm -rf $(DEBUG_TARGET)
	@ar cru $(DEBUG_TARGET) $(DEBUG_OBJS)
	@ranlib $(DEBUG_TARGET)
	@ctags -R -h ".cc.h" -o tags

$(OBJS) : $(BUILD_PATH)/%.o : %.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@

$(DEBUG_OBJS) : $(DEBUG_BUILD_PATH)/%.o : %.cc
	$(CXX) -c $(DEBUG_CXXFLAGS) $< -o $@

install : $(TARGET)
	mkdir -p $(INSTALL_INCLUDE_PATH) $(INSTALL_LIBRARY_PATH)
	$(INSTALL) *.h $(INSTALL_INCLUDE_PATH)
	$(INSTALL) $(TARGET) $(INSTALL_LIBRARY_PATH)
	$(INSTALL) $(DEBUG_TARGET) $(INSTALL_LIBRARY_PATH)

ctags:
	@ctags -R -h ".cc.h" -o tags

clean:
	@rm -rf $(BUILD_PATH) $(DEBUG_BUILD_PATH) $(TARGET) $(DEBUG_TARGET)

.PHONY : all clean install