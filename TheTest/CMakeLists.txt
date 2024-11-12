cmake_minimum_required(VERSION 3.16)

project(TheTest VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

find_package(Qt6 6.4 COMPONENTS Quick QuickControls2 REQUIRED)

qt_add_executable(appTheTest
	main.cpp
	Test.cpp
        Test.h
)

qt_add_qml_module(appTheTest
    URI TheTest
    VERSION 1.0
        QML_FILES main.qml
)

target_link_libraries(appTheTest
        PRIVATE Qt6::Quick Qt6::QuickControls2 )

install(TARGETS appTheTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
