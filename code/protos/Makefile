#chentong project Makefile
#20240902

CXXFLAGS = $(COMPILE_OPT)
TARGET = $(BUILD_PATH)/lib$(TARGET_NAME).a

OBJS := $(patsubst %.cc, $(BUILD_PATH)/%.o, $(wildcard *.cc))
DEPS = $(OBJS:$(BUILD_PATH)/%.o=$(BUILD_PATH)/.%.d)

COMM_PROTO = $(wildcard $(COMM_PATH)/*.proto)
PROTO_CPP = $(COMM_PROTO:$(COMM_PATH)/%.proto=%.pb.cc)

all : $(TARGET)

$(PROTO_CPP) : %.pb.cc : $(COMM_PATH)/%.proto
	@$(THIRD_PATH)/bin/protoc -I=. --proto_path=$(COMM_PATH) --cpp_out=. $<
	@echo "111111!!!!!!!!!!!!!!!!!!!!!!!! $(OBJS)"

-include $(DEPS)

$(DEPS) : $(BUILD_PATH)/.%.d : $(SRC_PATH)/%.cc
	@if [ ! -d "$(dir $@)" ]; then mkdir -pv $(dir $@); fi
	@$(CXX) -M $(CXXFLAGS) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(BUILD_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(TARGET) : $(OBJS)
	@rm -rf $(TARGET)
	@ar cru $(TARGET) $(OBJS)
	@ranlib $(TARGET)
	@rm -rf $(TARGET_PATH)/*

$(OBJS) : $(BUILD_PATH)/%.o : $(SRC_PATH)/%.cc $(BUILD_PATH)/.%.d
	$(CXX) -c $(CXXFLAGS) $< -o $@

protoc : $(PROTO_CPP)

clean:
	@rm -rf $(BUILD_PATH) $(TARGET) core*.*

.PHONY: all clean