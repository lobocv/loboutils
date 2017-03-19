CC=gcc

PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)

BOOST_LIB = /usr/lib
TARGET = src/loboutils

$(TARGET).so: $(TARGET).o
	$(CC) -shared -I ~/lobocv/cpp/boost_1_63_0/stage/lib -o $(TARGET).so $(TARGET).o -lpython2.7 -lboost_python


$(TARGET).o: 
	$(CC) -o $(TARGET).o -c $(TARGET).cpp -Wall -fPIC -I/usr/include/python2.7


clean:
	rm $(TARGET).o $(TARGET).so
