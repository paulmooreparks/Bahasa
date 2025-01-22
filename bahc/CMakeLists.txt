# CMakeList.txt : CMake project for bahc, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("bahc")

set(SOURCES
    src/bahc.cpp
    src/bahc.h
)

# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE bahasavm)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src ../bahasavm/src )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bahc PROPERTY CXX_STANDARD 20)
endif()

add_custom_command(TARGET bahc POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:bahasavm> $<TARGET_FILE_DIR:bahc>
)
