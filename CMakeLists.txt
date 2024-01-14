cmake_minimum_required(VERSION 2.8)

project(hello)

find_package (Intl REQUIRED)
find_package(Gettext REQUIRED)
include_directories(${INTL_INCLUDE_DIRS})
link_directories(${INTL_LIBRARY_DIRS})

#SET(LOCALE_INSTALL_DIR "/usr/share/locale")
SET(LOCALE_INSTALL_DIR "~/.local/share/locale")
#SET(LOCALE_INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/locale)

FIND_PROGRAM(GETTEXT_MSGFMT_EXECUTABLE msgfmt)

IF(NOT GETTEXT_MSGFMT_EXECUTABLE)
    MESSAGE("------
    NOTE: msgfmt not found. Translations will *not* be installed
------")
ELSE(NOT GETTEXT_MSGFMT_EXECUTABLE)

  SET(catalogname rc)

  FILE(GLOB PO_FILES *.po)
  SET(GMO_FILES)

  FOREACH(_poFile ${PO_FILES})
    GET_FILENAME_COMPONENT(_poFileName ${_poFile} NAME)
    STRING(REGEX REPLACE "^${catalogname}_?" "" _langCode ${_poFileName} )
    STRING(REGEX REPLACE "\\.po$" "" _langCode ${_langCode} )

    IF( _langCode )
      GET_FILENAME_COMPONENT(_lang ${_poFile} NAME_WE)
      SET(_gmoFile ${CMAKE_CURRENT_BINARY_DIR}/${_lang}.gmo)

      ADD_CUSTOM_COMMAND(OUTPUT ${_gmoFile}
        COMMAND ${GETTEXT_MSGFMT_EXECUTABLE} --check -o ${_gmoFile} ${_poFile}
        DEPENDS ${_poFile})
      INSTALL(FILES ${_gmoFile} DESTINATION ${LOCALE_INSTALL_DIR}/${_langCode}/LC_MESSAGES/ RENAME ${catalogname}.mo)
      MESSAGE("--- WILL TRY TO INSTALL --- " ${_gmoFile} -> ${LOCALE_INSTALL_DIR}/${_langCode}/LC_MESSAGES/ " AS " ${catalogname}.mo)
      LIST(APPEND GMO_FILES ${_gmoFile})
    ENDIF( _langCode )

  ENDFOREACH(_poFile ${PO_FILES})

  ADD_CUSTOM_TARGET(translations ALL DEPENDS ${GMO_FILES})

ENDIF(NOT GETTEXT_MSGFMT_EXECUTABLE)

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake, 

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

add_executable(${PROJECT_NAME} "main.cpp" "helloworld.cpp")

target_link_libraries(hello 
    ${GTKMM_LIBRARIES}  )

