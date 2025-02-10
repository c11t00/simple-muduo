#chentong project Makefile
#20240901

CXX = /usr/bin/myg++
STD = gnu++11
GCCVERSION = gcc-8.5.0
IGNORE_WARN = -Wno-overloaded-virtual -Wno-mismatched-tags -Wno-delete-non-abstract-non-virtual-dtor -Wno-pointer-bool-conversion -Wno-inconsistent-missing-override -Wno-unused-private-field -Wno-misleading-indentation -Wno-frame-address -Wno-unused-function -Wno-unused-local-typedefs -Wno-sign-compare

BUILD_DIR = $(PWD)
BUILD_PATH = $(BUILD_DIR)/.obj
TARGET_PATH = $(BUILD_DIR)/bin
PROTO_PATH = $(BUILD_DIR)/protos
COMM_PATH = $(BUILD_DIR)/comm


TARGET_PROJECTS := \
	Test \
	TestClient \

INC_PATH := \
	-I $(BUILD_DIR)/base \
	-I $(PROTO_PATH) \
	-I $(THIRD_PATH)/include \
	-I $(THIRD_PATH)/include/muduo \
	-I /usr/include \

LIB_DEBUG := -lmuduo_D -Wl,--end-group
LIB_RELEASE := -lmuduo -Wl,--end-group

LIB_PATH := \
	-L$(BUILD_PATH)/base -lbase \
	-L$(BUILD_PATH)/protos -lprotos \
	-L$(THIRD_PATH)/lib -Wl,--start-group -lprotobuf \

DEP_SCRIPT := \
	proto \

DEP_LIBS := \
	base \
	protos \

ALLTARGET := $(DEP_LIBS) $(TARGET_PROJECTS)

DEBUG_OPT = -D_DEBUG_GM -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
DEBUG_LINK_OPT = $(LIB_PATH) $(LIB_DEBUG) -lpthread -lrt -ldl -rdynamic

RELEASE_OPT = -O2 -fno-omit-frame-pointer -Wno-array-bounds
RELEASE_LINK_OPT = $(LIB_PATH) $(LIB_RELEASE) -lpthread -lrt -ldl

COMPILE_OPT = -std=$(STD) -g3 -ggdb -gdwarf-4 -fno-strict-aliasing -Werror -Wall $(IGNORE_WARN) -D_GNU_SOURCE -D_REENTRANT -D_PROJECT_PINK -D_USE_GCC_4 $(INC_PATH)

all : $(TARGET_PROJECTS)

$(DEP_LIBS) : $(DEP_SCRIPT)
	@$(MAKE) -C $@ CXX=$(CXX) \
   	COMPILE_OPT='$(COMPILE_OPT) $(DEBUG_OPT)' \
	LINK_OPT='$(DEBUG_LINK_OPT)' \
   	THIRD_PATH='$(THIRD_PATH)' \
   	BUILD_DIR='$(BUILD_DIR)' \
   	BUILD_PATH='$(BUILD_PATH)/$@' \
   	SRC_PATH='$(BUILD_DIR)/$@' \
   	TARGET_PATH='$(TARGET_PATH)' \
	TARGET_NAME='$@'

$(TARGET_PROJECTS) : $(DEP_LIBS)
	@if [ ! -d "$(TARGET_PATH)" ]; then mkdir -pv $(TARGET_PATH); fi
	@$(MAKE) -C $@ CXX=$(CXX) \
		COMPILE_OPT='$(COMPILE_OPT) $(DEBUG_OPT)' \
		LINK_OPT='$(DEBUG_LINK_OPT)' \
		THIRD_PATH='$(THIRD_PATH)' \
		BUILD_DIR='$(BUILD_DIR)' \
		BUILD_PATH='$(BUILD_PATH)/$@' \
		SRC_PATH='$(BUILD_DIR)/$@' \
		TARGET_PATH='$(TARGET_PATH)' \
		TARGET_NAME='$@'

proto :
	$(MAKE) -C $(PROTO_PATH) protoc COMM_PATH=$(COMM_PATH)

clean :
	@rm -rf $(BUILD_PATH)
	@rm -rf $(TARGET_PATH)/*
	@rm -rf core.*
	@rm -rf $(PROTO_PATH)/*.{cc,h}

time :
	@find . -type f -exec touch {} \'

ctags:
	@ctags -R -h ".cc.h" -o tags

.PHONY : all proto clean time ctags $(DEP_SCRIPT) $(ALLTARGET)