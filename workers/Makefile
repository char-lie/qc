CC=g++
CPPFLAGS=-std=c++11 -Wall

UTILS_DIR=utils
UTILS_SOURCES=Decimal.cpp
WORKER_DIR=worker
WORKER_SOURCES=Worker.cpp WorkerHour.cpp WorkerMonth.cpp
BUILDER_DIR=builder
BUILDER_SOURCES=WorkerDirector.cpp WorkerBuilder.cpp
SOURCE_FILES=main.cpp $(UTILS_SOURCES:%=$(UTILS_DIR)/%) $(WORKER_SOURCES:%=$(WORKER_DIR)/%) $(BUILDER_SOURCES:%=$(BUILDER_DIR)/%)
OUTPUT_FILE=workers

all: $(SOURCE_FILES)
	$(CC) $(SOURCE_FILES) $(CPPFLAGS) -o $(OUTPUT_FILE)
debug: $(SOURCE_FILES)
	$(CC) $(SOURCE_FILES) $(CPPFLAGS) -o $(OUTPUT_FILE) -g
memcheck: $(SOURCE_FILES)
	make debug
	valgrind --tool=memcheck --leak-check=full $(OUTPUT_FILE)
clean:
	rm $(OUTPUT_FILE)
