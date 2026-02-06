# CMakeList.txt: projeto de CMake para Hello, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
add_executable(Hello "src/Hello.cpp" "src/graphlib/util/Shader.cpp" "src/graphlib/util/Shader.h" "src/graphlib/shape/Cubo3d.h" "src/graphlib/shape/Cubo3d.cpp" "src/graphlib/shape/Shape3d.h" "src/graphlib/shape/Shape3d.cpp" "src/graphlib/shape/VirtualUniverse.h" "src/graphlib/shape/VirtualUniverse.cpp" "src/graphlib/shape/Sphere3d.h" "src/graphlib/shape/Sphere3d.cpp" "src/graphlib/math/cgmath.h" "src/graphlib/math/cgmath.cpp" "src/graphlib/input/Mouse.h" "src/graphlib/input/Mouse.cpp" "src/graphlib/input/event/RotateMouseListener.h" "src/handle/HandleRotateMouse.h" "src/handle/HandleRotateMouse.cpp")

#add_executable (Hello "src/Hello.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hello PROPERTY CXX_STANDARD 20)
endif()

# TODO: Adicione testes e instale destinos, se necessário.

target_link_options(Hello PRIVATE /SUBSYSTEM:CONSOLE)

find_package(OpenGL REQUIRED)

target_include_directories(Hello 
	PRIVATE 
		"include"
		"externals/glm-1.0.3"
)

target_link_directories(Hello 
	PRIVATE
		"libs"
)

target_link_libraries(Hello
	PRIVATE
		glfw3
		opengl32
		glew32
)


set(DLL_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw3.dll"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/glew32.dll"
)

file(GLOB STRUCTS "${CMAKE_CURRENT_SOURCE_DIR}/struct/*.*")

add_custom_command(TARGET Hello POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${DLL_FILES}
        $<TARGET_FILE_DIR:Hello>  # Output directory of the executable
)

add_custom_command(TARGET Hello POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:Hello>/struct
)

add_custom_command(TARGET Hello POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${STRUCTS}
        $<TARGET_FILE_DIR:Hello>/struct  # Output directory of the executable
)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/Hello/struct")
file(COPY ${STRUCTS} DESTINATION "${CMAKE_BINARY_DIR}/Hello/struct")