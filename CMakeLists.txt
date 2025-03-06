cmake_minimum_required(VERSION 3.10) 
project(TheBeatuyOfProgammingProj)

# 设置C++标准为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 确保该标准是必需的
set(CMAKE_CXX_EXTENSIONS OFF)        # 禁用编译器特定扩展（如GNU扩展）

# 查找当前目录及其子目录下的所有.cpp文件
file(GLOB SOURCES "*.cpp")

# 遍历找到的所有.cpp文件，并为每个文件生成一个可执行文件
foreach(source IN LISTS SOURCES)
    message(STATUS "file : ${source}")
    # 获取源文件的文件名（不包含扩展名）
    get_filename_component(exe_name ${source} NAME_WE)

    # 添加可执行文件
    add_executable(${exe_name} ${source})
endforeach()