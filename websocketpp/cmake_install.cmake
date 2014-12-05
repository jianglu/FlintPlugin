# Install script for directory: /Volumes/Developer/Workdir/websocketpp/websocketpp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/base64" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/base64/base64.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/client.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/close.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/chrono.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/connection_hdl.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/cpp11.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/functional.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/md5.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/memory.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/network.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/platforms.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/random.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/regex.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/stdint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/system_error.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/common" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/common/thread.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/concurrency" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/concurrency/basic.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/concurrency" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/concurrency/none.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/asio.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/asio_client.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/asio_no_tls.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/asio_no_tls_client.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/boost_config.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/core.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/core_client.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/debug.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/debug_asio.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/config" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/config/debug_asio_no_tls.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/connection.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/connection_base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/endpoint_base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/error.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/error_container.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/extensions" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/extensions/extension.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/extensions/permessage_deflate" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/extensions/permessage_deflate/disabled.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/extensions/permessage_deflate" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/extensions/permessage_deflate/enabled.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/frame.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/constants.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/impl/parser.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/impl/request.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/impl/response.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/parser.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/request.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/http" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/http/response.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/impl/connection_impl.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/impl/endpoint_impl.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/impl" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/impl/utilities_impl.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/logger" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/logger/basic.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/logger" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/logger/levels.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/logger" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/logger/stub.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/message_buffer" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/message_buffer/alloc.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/message_buffer" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/message_buffer/message.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/message_buffer" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/message_buffer/pool.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/hybi00.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/hybi07.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/hybi08.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/hybi13.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/processors" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/processors/processor.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/random" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/random/none.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/random" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/random/random_device.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/roles" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/roles/client_endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/roles" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/roles/server_endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/server.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/sha1" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/sha1/sha1.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/connection.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio/security" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/security/base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio/security" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/security/none.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/asio/security" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/asio/security/tls.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/base" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/base/connection.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/base" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/base/endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/iostream" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/iostream/base.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/iostream" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/iostream/connection.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp/transport/iostream" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/transport/iostream/endpoint.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/uri.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/utf8_validator.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/utilities.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/websocketpp" TYPE FILE FILES "/Volumes/Developer/Workdir/websocketpp/websocketpp/version.hpp")
endif()

