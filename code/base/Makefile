#chentong project Makefile
#20240902

CXXFLAGS = $(COMPILE_OPT) $(patsubst %, -I%, $(shell find $(SRC_PATH) -type d))
TARGET = $(BUILD_PATH)/lib$(TARGET_NAME).a

OBJS := $(patsubst %.cc, $(BUILD_PATH)/%.o, $(shell find . -name \*.cc | sed 's/\.\///g'))
DEPS = $(OBJS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/.%.d)

all : $(TARGET)

-include $(DEPS)

$(DEPS) : $(BUILD_PATH)/.%.d : $(SRC_PATH)/%.cc
	@if [ ! -d "$(dir $@)" ]; then mkdir -pv $(dir $@); fi
	@$(CXX) -M $(CXXFLAGS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(BUILD_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(TARGET) : $(OBJS)
	@rm -rf $(TARGET)
	@ar cru $(TARGET) $(OBJS)
	@ranlib $(TARGET)
	@rm -rf $(TARGET_PATH)/*

$(OBJS) : $(BUILD_PATH)/%.o : $(SRC_PATH)/%.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@rm -rf $(BUILD_PATH) $(TARGET) core*.*

.PHONY: all clean