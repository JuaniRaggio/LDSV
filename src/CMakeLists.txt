file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "*.hpp")

add_executable(ldsv ${SOURCES} ${HEADERS})
target_include_directories(ldsv PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ldsv PRIVATE Qt6::Widgets)
