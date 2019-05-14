# 输入一个文件名 

echo "请输入项目名："
read projectname

# 添加前缀
filename="Pro"$projectname

#选择
echo -e "请选择：\n1、建立项目\n2、删除项目"
read choice

if [ $choice == 1 ]
then

    # 源文件目录
    Src="$filename/Sources"

    # 头文件目录
    Inc="$filename/Headers"

    # 创建项目树
    mkdir -p $Src $Inc

    # 创建makefile文件
    touch makefile

    # 创建 main.cpp文件
    touch $Src/main.cpp

    # 向main.cpp中写入内容
    echo "#include <iostream> " >> $Src/main.cpp
    echo "" >> $Src/main.cpp
    echo "using namespace std;" >> $Src/main.cpp
    echo "" >> $Src/main.cpp
    echo "int main()" >> $Src/main.cpp
    echo "{" >> $Src/main.cpp
    echo "    cout << \"Hello VsCode!\" << endl;" >> $Src/main.cpp
    echo "    return 0;" >> $Src/main.cpp
    echo "}" >> $Src/main.cpp

    # 导入makefile
    echo "# 头文件存放目录" >> makefile
    echo "header := ./$Inc/" >> makefile
    echo "# 源文件存放目录" >> makefile
    echo "source := ./$Src/" >> makefile

    echo "" >> makefile
    echo "executable := out" >> makefile
    echo "sources := \$(wildcard \$(source)*.cpp)" >> makefile
    echo "objects := \$(sources:.cpp=.o)" >> makefile

    echo "" >> makefile
    echo "\$(executable) : \$(objects)" >> makefile
    echo -e "\tg++ -o \$@ \$^" >> makefile
    echo "\$(objects) : %.o:%.cpp" >> makefile
    echo -e "\tg++ -o \$@ -c -g \$< -I \$(header)" >> makefile
    echo "" >> makefile
    echo ".PHONY : clean" >> makefile
    echo "clean :" >> makefile
    echo -e "\t-rm \$(objects)" >> makefile
else
    rm -rf $filename
    rm -rf makefile
    rm -rf out
fi