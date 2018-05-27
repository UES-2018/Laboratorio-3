cmake_minimum_required(VERSION 3.7) #Versión mínima de cmake 
# Project Name
PROJECT(LAB_OPenGL)

#########################################################
# INCLUYENDO LIBRERIA GLUT
#########################################################
find_package(GLUT REQUIRED) #buscar la libreria GlUT
include_directories(${GLUT_INCLUDE_DIRS}) # incluir los directorios 
link_directories(${GLUT_LIBRARY_DIRS}) #Linkeo de directorios 
add_definitions(${GLUT_DEFINITIONS}) #Agregar las definiciones 
#########################################################
# INCLUYENDO LIBRERIA OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
#######################################################
# INCLUYENDO LIBRERIA SOIL
#########################################################

include_directories(${GLFW_INCLUDE_DIRS}) 
include_directories(${GLEW_INCLUDE_DIRS}) 
add_definitions(-DGLEW_STATIC) 
include_directories(${GLM_INCLUDE_DIRS}) 
include_directories(/usr/include/SOIL) 
link_directories(/usr/lib/SOIL) 

########################################################
# INCLUYENDO LIBRERIA SDL2
########################################################
find_package(SDL2 REQUIRED)
include_directories( escena ${SDL2_INCLUDE_DIRS})
find_file(SDL2_INCLUDE_DIR NAME SDL.h HINTS SDL2)
find_library(SDL2_LIBRARY NAME SDL2)
#########################################################nea
# Incluyendo archivos 
#########################################################
add_executable(escena Escena.cpp) # Agregando nombre del script y compilado

#########################
# Linkeo de librerías 
#########################################################
# creación del ejecutable "hello"
target_link_libraries(escena ${OPENGL_LIBRARY} ${GLUT_LIBRARY} ${SDL2_LIBRARIES} SOIL) 

