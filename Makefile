TARGET := poboy
SRC := src
INC := include
SRCS := $(shell find $(SRC) -type f -name "*.c")
OBJS := $(patsubst %.c,%.o,$(SRCS))
DEPS := $(patsubst %.c,%.d,$(SRCS))

CC ?= clang
CFLAGS = -std=c11 \
		  -pedantic \
		  -fvisibility=hidden \
		  -Wall \
		  -Wextra \
		  -Werror \
		  -I$(INC)

.PHONY: all debug release
all:: debug

debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

release: CFLAGS += -O3
release: $(TARGET)

-include $(DEPS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) -MMD -MP

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: run
run:
	@./$(TARGET)

.PHONY: clean
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJS)
	rm -rf $(DEPS)
