cmake_minimum_required(VERSION 3.16)

project(QMLJNI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appQMLJNI
    main.cpp
)

qt_add_qml_module(appQMLJNI
    URI QMLJNI
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES
        SOURCES calculator.h calculator.cpp
        SOURCES JniMessenger.cpp
)
qt_add_resources(appQMLJNI "android"
    PREFIX /
    FILES
        android/src/com/example/jnisample/MainActivity.java
        android/AndroidManifest.xml
        android/build.gradle
        android/res/values/libs.xml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQMLJNI PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQMLJNI
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
)

target_link_libraries(appQMLJNI
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appQMLJNI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
