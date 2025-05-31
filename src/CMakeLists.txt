# Define the source files
file(GLOB_RECURSE SOURCES
    "*.cpp"
)

# Define the include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Create the executable
add_executable(cacheapp ${SOURCES})
