CC=gcc

PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)

BOOST_LIB = ~/lobocv/cpp/boost_1_63_0/stage/lib
TARGET = loboutils
SRC_DIR = src
OUTPUT_DIR = build


$(OUTPUT_DIR)/$(TARGET).so: $(OUTPUT_DIR)/$(TARGET).o
	$(CC) -shared -I BOOT_LIB -o $(OUTPUT_DIR)/$(TARGET).so $(OUTPUT_DIR)/$(TARGET).o -lpython2.7 -lboost_python


$(OUTPUT_DIR)/$(TARGET).o: 
	$(CC) -o $(OUTPUT_DIR)/$(TARGET).o -c $(SRC_DIR)/$(TARGET).cpp -Wall -fPIC -I$(PYTHON_INCLUDE)


clean:
	rm $(OUTPUT_DIR)/*
	touch $(OUTPUT_DIR)/__init__.py
