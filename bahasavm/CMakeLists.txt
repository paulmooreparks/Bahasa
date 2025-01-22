# CMakeList.txt : CMake project for bahasavm, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("bahasavm")

set(LIBRARY_TYPE SHARED)

set(SOURCES
    src/bahasavm.cpp
    src/bahasavm.h
)

# Create the shared library
add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET bahasavm PROPERTY CXX_STANDARD 20)
endif()

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE BAHASA_WINDOWS)
elseif(UNIX)
    target_compile_definitions(${PROJECT_NAME} PRIVATE BAHASA_LINUX)
endif()

# Include directories for headers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_compile_definitions(${PROJECT_NAME} PRIVATE BAHASAVM_EXPORTS)

# Specify installation rules
install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Config
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)
install(DIRECTORY src/ DESTINATION include FILES_MATCHING PATTERN "*.h")

# Export the library configuration
export(TARGETS ${PROJECT_NAME} FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake)
