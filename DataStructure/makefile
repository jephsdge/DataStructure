# 头文件存放目录
header := ./ProDataStructre/Headers/
# 源文件存放目录
source := ./ProDataStructre/Sources/

executable := out
sources := $(wildcard $(source)*.cpp)
objects := $(sources:.cpp=.o)

$(executable) : $(objects)
	g++ -o $@ $^
$(objects) : %.o:%.cpp
	g++ -o $@ -c -g $< -I $(header)

.PHONY : clean
clean :
	-rm $(objects)
