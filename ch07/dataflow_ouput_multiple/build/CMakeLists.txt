cmake_minimum_required(VERSION 2.6)

#set the project name
PROJECT ( hls ) 

SET (EXE_FILE run)
SET (CMAKE_BUILD_TYPE Debug)
SET (CMAKE_VERBOSE_MAKEFILE false)

FILE(GLOB SRC_TB  ../tb/*.cc)
FILE(GLOB SRC_HLS ../hls/*.cc)
INCLUDE_DIRECTORIES (./include ../hls ../tb)

SET (CMAKE_C_COMPILER "g++")
SET (CMAKE_C_FLAGS_DEBUG "-g")

ADD_EXECUTABLE (${EXE_FILE} ${SRC_TB} ${SRC_HLS})
