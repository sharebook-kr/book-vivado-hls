cmake_minimum_required(VERSION 2.6)

#set the project name
project( hls ) 
MESSAGE( ${CMAKE_PROJECT_NAME} )

SET( EXE_FILE run )
SET( SRC_FILES ../hls/hls_rdo_subtract.cc              ../hls/hls_rdo_subtract.h
               ../tb/main.cc                                 )

INCLUDE_DIRECTORIES( ../hls ../tb include)
ADD_COMPILE_OPTIONS( "-g" )

#add the excutable
ADD_EXECUTABLE( ${EXE_FILE} ${SRC_FILES} )
