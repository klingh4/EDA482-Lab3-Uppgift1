# name of the app (= name of working directory) is defined in 
# settings.json per default. below is just a fallback solution
# for when make is invoked without the APP_NAME definition 
SPACE := $(null) $(null)
APP_NAME = $(notdir $(subst $(SPACE),-,$(CURDIR)))

# output files
TARGET_EXEC = $(BUILD_DIR)/$(APP_NAME).elf
TARGET_S19 = $(BUILD_DIR)/$(APP_NAME).s19
TARGET_LST = $(BUILD_DIR)/$(APP_NAME).lst

# linker script
LINKER_SCRIPT = md407-ram.x

# directories containing source files and libraries
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
SRC_DIRS = src lib/src
INC_DIRS = src inc lib/inc
LIB_DIRS = .

SRCS := $(foreach d, $(SRC_DIRS), $(wildcard $(d)/*.c) $(wildcard $(d)/*.s $(wildcard $(d)/*.S)))
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# arm toolchain paths
CC = $(GCC_PATH)arm-none-eabi-gcc
OBJCOPY = $(GCC_PATH)arm-none-eabi-objcopy
OBJDUMP = $(GCC_PATH)arm-none-eabi-objdump

# compiler and linker flags
CFLAGS += -g -Wall -Wextra -Wno-main -MMD -march=armv6-m -mno-unaligned-access $(addprefix -I, $(INC_DIRS))
LDFLAGS += -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -T$(LINKER_SCRIPT) -nostartfiles --specs=nano.specs
LDFLAGS += $(addprefix -L, $(LIB_DIRS))
ASFLAGS += -g

# compiler, standard and local libraries
LDLIBS += -l:md407-runtime.a -lgcc -lc_nano

# check if os is windows, imitate mkdir UNIX behavior
ifeq ($(OS), Windows_NT)
    MKDIR = powershell mkdir -Force 
else
    MKDIR = mkdir -p
endif

all: $(TARGET_EXEC)

# link object files into executable, generate s-records and debug files
$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(LDLIBS) -o "$@"
	$(OBJCOPY) -S -O srec "$@" "$(TARGET_S19)"
	$(OBJDUMP) -d -S --dwarf-depth=1 "$@" > "$(TARGET_LST)"

# compile .s and .c-files
$(OBJ_DIR)/%.o: %
	$(MKDIR) $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)