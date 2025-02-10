#chentong project Makefile
#20240901

CXXFLAGS = $(COMPILE_OPT)
CXXLFLAGS = $(LINK_OPT)
TARGET = $(TARGET_PATH)/$(TARGET_NAME)

OBJS := $(patsubst %.cc, $(BUILD_PATH)/%.o, $(wildcard UnionCompile*.cc))
DEPS = $(OBJS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/.%.d)

all : $(TARGET)

-include $(DEPS)

$(DEPS) : $(BUILD_PATH)/.%.d : $(SRC_PATH)/%.cc
	@if [ ! -d "$(dir $@)" ]; then mkdir -pv $(dir $@); fi
	@$(CXX) -M $(CXXFLAGS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(BUILD_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(TARGET) : $(OBJS)
	@rm -rf $(TARGET)
	@$(CXX) $(OBJS) -o $@ $(CXXLFLAGS)

$(OBJS) : $(BUILD_PATH)/%.o : $(SRC_PATH)/%.cc
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	@rm -rf $(BUILD_PATH) $(TARGET) core*.*

.PHONY: all clean