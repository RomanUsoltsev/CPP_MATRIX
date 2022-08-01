GCC = g++ -std=c++17 -Wall -Werror -Wextra # -D_GNU_SOURCE
GCOV = -fprofile-arcs -ftest-coverage

TST = test/
BI = build/
DEB = debug_fun/
MA = main/
UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
    FLAGS = -lgtest
    GCOV = --coverage
endif

ifeq ($(UNAME),Linux)
    FLAGS = -lgtest -lpthread -lrt -lm
    GCOV = -fprofile-arcs -ftest-coverage
endif

#PROGECT_______________________________________PROGECT
SOURCE:= $(MA)*.cpp
SOURCES := $(wildcard $(SOURCE))
OBJECTS_1 := $(patsubst %.cpp, %.o, $(SOURCES))
OBJECTS_2 := $(patsubst $(MA)%, $(BI)%, $(OBJECTS_1))
OBJECTS_3 := $(patsubst $(DEB)%, $(BI)%, $(OBJECTS_2))
#PROGECT_______________________________________PROGECT

print:
	@echo $(SOURCE)

.PHONY: all clear.a clear.o clean test s21_matrix_oop.a linters cppcheck

default: all

all: clean s21_matrix_oop.a

clean: clear.a clear.o clear_exe clear_lib
	rm -rf report $(BI)*.gcda $(BI)*.gcno $(BI)*.info

clear.o:
	rm -rf $(BI)*.o *o
clear.a:
	rm -rf $(BI)*.a *.a
clear_exe:
	rm -rf $(BI)my_test $(BI)test $(BI)gcov_rep
clear_lib:
	rm -rf lib

# STATICLIB_________________________________STATICLIB
s21matrix.o: $(OBJECTS_3)

$(BI)%.o: $(MA)%.cpp
	$(GCC) -c $< -o $@

s21_matrix_oop.a: s21matrix.o
	ar rcs $(BI)s21_matrix_oop.a $(OBJECTS_3)
	ranlib $(BI)s21_matrix_oop.a
	cp $(BI)s21_matrix_oop.a $(BI)libs21_matrix_oop.a
# STATICLIB_________________________________STATICLIB


#dowlload lib gtest
download_lib: clear_lib
	mkdir "lib"
	git clone https://github.com/google/googletest.git lib
#dowlload lib gtest



# TEST_AND_REPORT_____________________TEST_AND_REPORT
test: s21_matrix_oop.a debug_fun.o
	$(GCC) $(TST)gtest_matrix.cpp $(BI)DebugFun.o $(BI)s21_matrix_oop.a $(FLAGS) -o $(BI)test
	./$(BI)test

gcov_report: s21_matrix_oop.a debug_fun.o
	$(GCC) -c -o $(BI)gtest_matrix.o $(TST)gtest_matrix.cpp $(FLAGS)
	$(GCC) $(GCOV) $(BI)gtest_matrix.o $(BI)DebugFun.o $(SOURCE) $(FLAGS) -o $(BI)gcov_rep
	./$(BI)gcov_rep
	lcov -t "gcov_rep" --no-external --output-file=coverag.info --capture --directory .
	genhtml -o ./report coverag.info
	rm -rf $(BI)*.gcda $(BI)*.gcno $(BI)*.info

debug_fun.o:
	$(GCC) -c -o $(BI)DebugFun.o $(DEB)DebugFun.cpp

# TEST_AND_REPORT_____________________TEST_AND_REPORT

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./$(BI)test

linters:
	python3 ../materials/linters/cpplint.py --extensions=cpp main/*.cpp main/*.h test/*.cpp

cppcheck:
	cppcheck --enable=all --check-config --suppress=missingIncludeSystem main/*.cpp main/*.h test/*.cpp debug_fun/*.cpp debug_fun/*.h