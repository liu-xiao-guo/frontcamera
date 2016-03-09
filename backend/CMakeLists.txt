include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set(
    FrontCamerabackend_SRCS
    modules/FrontCamera/backend.cpp
    modules/FrontCamera/mytype.cpp
    modules/FrontCamera/cameraselector.cpp
)

add_library(FrontCamerabackend MODULE
    ${FrontCamerabackend_SRCS}
)

set_target_properties(FrontCamerabackend PROPERTIES
         LIBRARY_OUTPUT_DIRECTORY FrontCamera)

qt5_use_modules(FrontCamerabackend Gui Qml Quick Multimedia)

# Copy qmldir file to build dir for running in QtCreator
add_custom_target(FrontCamerabackend-qmldir ALL
    COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/modules/FrontCamera/qmldir ${CMAKE_CURRENT_BINARY_DIR}/FrontCamera
    DEPENDS ${QMLFILES}
)

# Install plugin file
install(TARGETS FrontCamerabackend DESTINATION ${QT_IMPORTS_DIR}/FrontCamera/)
install(FILES   modules/FrontCamera/qmldir DESTINATION ${QT_IMPORTS_DIR}/FrontCamera/)

