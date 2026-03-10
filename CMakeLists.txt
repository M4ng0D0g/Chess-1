cmake_minimum_required(VERSION 3.5)

set(_PUBLISH publish)

######################################################
#
# Solution
#
######################################################
set(PRJ_NAME Chess)
project(${PRJ_NAME})

set(_ROOT ${PROJECT_SOURCE_DIR})

# 通用编译选项
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if(WIN32)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
  set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
  set(CMAKE_SHARED_LINKER_FLAGS_RELEASE  "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
  set(CMAKE_STATIC_LINKER_FLAGS_RELEASE  "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
endif()

set_property(GLOBAL PROPERTY RULE_MESSAGES   OFF)
set_property(GLOBAL PROPERTY TARGET_MESSAGES OFF)
set(CMAKE_INSTALL_MESSAGE NEVER)

if(UNIX)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

if(WIN32)
  set(TARGET_SUFFIX WIN32)
else()
  set(TARGET_SUFFIX POSIX)
endif()

# System Architecture
if(CMAKE_SIZEOF_VOID_P MATCHES 8)
  if(BUILD_ARM64_SUITE)
    set(PROJECT_ARCH "arm64")
  else()
    set(PROJECT_ARCH "x64")
  endif()
else()
    set(PROJECT_ARCH "x86")
endif()

message(STATUS "PROJECT_ARCH is ${PROJECT_ARCH}")

# 按照操作系统、平台和编译配置定安装目录
if(CMAKE_CONFIGURATION_TYPES)
  if(APPLE)
    set(TARGET_TRIPLE_CONFIG
        ${CMAKE_SYSTEM_NAME}-${PROJECT_ARCH}-$(CONFIGURATION))
  set(BUILD_CONFIG $(CONFIGURATION))
  else()
    set(TARGET_TRIPLE_CONFIG
      ${CMAKE_SYSTEM_NAME}-${PROJECT_ARCH}-${CMAKE_CFG_INTDIR})
  set(BUILD_CONFIG ${CMAKE_CFG_INTDIR})
  endif()
else()
  set(BUILD_CONFIG ${CMAKE_BUILD_TYPE})
  if(NOT BUILD_CONFIG)
    set(BUILD_CONFIG "Debug")
  endif()
  set(TARGET_TRIPLE_CONFIG ${CMAKE_SYSTEM_NAME}-${PROJECT_ARCH}-${BUILD_CONFIG})
  add_definitions(-fpermissive)
  add_compile_definitions("__stdcall=__attribute__((__cdecl__))")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--unresolved-symbols=report-all")
endif()

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})
set(TARGET_ROOT ${CMAKE_INSTALL_PREFIX})

set(TARGET_TRIPLE_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/${TARGET_TRIPLE_CONFIG})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/${BUILD_CONFIG})
if(WIN32)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/lib/${BUILD_CONFIG})
else()
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin/${BUILD_CONFIG})
endif()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin/${BUILD_CONFIG})
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/pdb/${BUILD_CONFIG})

# 强制修改安装目录
foreach(config ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER "${config}" config_uc)
  foreach(type ARCHIVE LIBRARY RUNTIME PDB)
    set(CMAKE_${type}_OUTPUT_DIRECTORY_${config_uc}
        ${CMAKE_${type}_OUTPUT_DIRECTORY})
  endforeach()
  unset(config_uc)
endforeach()

# 设定动态库默认相对路径
if(UNIX)
  set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
  if(NOT APPLE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
  else()
    cmake_policy(SET CMP0068 NEW)
    set(CMAKE_MACOSX_RPATH ON)
    set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
    set(CMAKE_INSTALL_NAME_DIR "@loader_path/../lib")
  endif()
endif()

# SDK
if (APPLE)
  set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
  set(CMAKE_XCODE_ATTRIBUTE_DWARF_DSYM_FOLDER_PATH ${CMAKE_INSTALL_PREFIX}/pdb/${BUILD_CONFIG})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_SHARED_MODULE_SUFFIX .dylib)
  set(VULKAN_SDK /usr/local)
endif ()

if(MSVC)
  add_definitions(/wd4250 /wd4275 /wd4435 /wd4514 /wd4548 /wd4668 /wd4710 /wd4711
                  /wd4820 /wd4828 /wd4267 /D_HAS_EXEPTIONS=0 /GR /source-charset:utf-8 -D_CRT_SECURE_NO_WARNINGS)
  add_definitions(/W3 /WX-)
  remove_definitions(/W4 /WX)
  set(CMAKE_VS_PLATFORM_TOOLSET 120)
else()
  add_definitions(-fvisibility=default
                  -fstrict-enums -Wabi -Wreorder -Wsign-compare -Wunused-value
                  -Wno-overloaded-virtual -Wno-unused-command-line-argument)
endif()

# Symbol generation
if(APPLE)
  set(CMAKE_XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym")
elseif(UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()

function(clear_parameters)
  unset(ITF_HEADERS)
  unset(IMPL_HEADERS)
  unset(SRC)
  unset(ASSETS)
endfunction()

function(import_subdirectory subdirectory)
  if(EXISTS ${PROJECT_SOURCE_DIR}/${subdirectory}/CMakeLists.txt)
    add_subdirectory(${subdirectory})
  clear_parameters()
  else()
    message(AUTHOR_WARNING "No CMakeLists.txt found in ${subdirectory}")
  endif()
endfunction()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE INCS LIST_DIRECTORIES false include/*.*)
file(GLOB_RECURSE SRCS LIST_DIRECTORIES false src/*.*)

add_executable(${PRJ_NAME} ${INCS} ${SRCS})

# ======================================================
# ==== 新增：Raylib 外部庫與 Assets 路徑設定 ====
# ======================================================

# 1. 設定 Assets 目錄
set(ASSETS_SRC_DIR ${CMAKE_SOURCE_DIR}/assets)
# 將 Assets 複製到執行檔輸出的 bin 目錄下
set(ASSETS_DEST_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)

# 2. 環境判斷與路徑設定
if(WIN32)
  set(RAYLIB_INC_DIR ${CMAKE_SOURCE_DIR}/external/raylib-5.0_win64_msvc16/include)
  set(RAYLIB_LIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib-5.0_win64_msvc16/lib)
elseif(UNIX)
  set(RAYLIB_INC_DIR ${CMAKE_SOURCE_DIR}/external/raylib-5.5_linux_amd64/include)
  set(RAYLIB_LIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib-5.5_linux_amd64/lib)
endif()

# 3. 配置編譯與連結路徑
target_include_directories(${PRJ_NAME} PRIVATE include ${RAYLIB_INC_DIR})
target_link_directories(${PRJ_NAME} PRIVATE ${RAYLIB_LIB_DIR})

# 4. 連結函式庫 (整合 Linux 系統依賴)
if(WIN32)
  target_link_libraries(${PRJ_NAME} PRIVATE raylib)
elseif(UNIX)
  # 確保 X11 等庫被正確連結
  target_link_libraries(${PRJ_NAME} PRIVATE raylib m pthread dl rt X11)
endif()

# 5. POST_BUILD: 自動同步 Assets 資源
# 無論是 Windows 或 Linux，在編譯完成後都將根目錄的 assets 複製到 bin 目錄
# 在原本的 POST_BUILD 區塊中加入這一行
add_custom_command(TARGET ${PRJ_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${ASSETS_DEST_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_SRC_DIR} ${ASSETS_DEST_DIR}
    
    # === 新增這行：把 .so 檔也複製過去 ===
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RAYLIB_LIB_DIR}/libraylib.so.550 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    
    COMMENT "--- 正在同步資源文件與動態庫 ---"
)

# 6. 保留原本 Windows 特有的發佈邏輯
if(WIN32)
  set_target_properties(${PRJ_NAME} PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY ${_ROOT}/${_PUBLISH}/${PRJ_NAME}
  )

  add_custom_command(TARGET ${PRJ_NAME} POST_BUILD 
    COMMENT "copy ${PRJ_NAME} libraries files..."
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${_ROOT}/${_PUBLISH}/${PRJ_NAME}
    # 注意：這裡假設 raylib 是動態庫才需要 copy，如果是靜態庫 (.lib) 則不需要
    COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:${PRJ_NAME}> ${_ROOT}/${_PUBLISH}/${PRJ_NAME}
    COMMAND ${CMAKE_COMMAND} -E make_directory  ${_ROOT}/${_PUBLISH}/${PRJ_NAME}/images
    COMMAND ${CMAKE_COMMAND} -E copy_directory assets/images ${_ROOT}/${_PUBLISH}/${PRJ_NAME}/images
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  )
endif()
# ======================================================