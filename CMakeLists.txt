cmake_minimum_required(VERSION 3.15)
project(Bahasa)

# Add bahasavm library
add_subdirectory(bahasavm)

# Add bahc executable and link it to bahasavm
add_subdirectory(bahc)