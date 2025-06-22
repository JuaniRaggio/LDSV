file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.hpp")

add_executable(LDSV ${SOURCES} ${HEADERS})
target_include_directories(LDSV PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(LDSV PRIVATE Qt6::Widgets)
