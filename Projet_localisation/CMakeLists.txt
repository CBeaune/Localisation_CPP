cmake_minimum_required(VERSION 2.8)
project(Projet_localisation)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
#SET_TARGET_PROPERTIES(Projet_localisation PROPERTIES LINKER_LANGUAGE CXX)
include_directories(include)

#add_library(Projet_localisation SHARED include/RobotAndSensorDefinition.h include/DefineVariance.h include/usefulFunctions.h)

#Add executables Localisation and useful functions
add_executable(Localisation src/Localisation.cpp src/usefulFunctions.cpp include/DefineVariance.h)
#target_link_libraries(Localisation Projet_localisation)
