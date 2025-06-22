file(GLOB_RECURSE APPMODEL_SRC CONFIGURE_DEPENDS ./app/*.cpp)

add_library(app ${APPMODEL_SRC})

target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/include)

# executable
file(GLOB_RECURSE UI_SRC CONFIGURE_DEPENDS main.cpp ui/*.cpp)

add_executable(ldsv ${UI_SRC})

target_include_directories(ldsv PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(ldsv PRIVATE app Qt6::Widgets)
