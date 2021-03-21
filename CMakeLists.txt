cmake_minimum_required(VERSION 3.15)
project(TubeScreamer VERSION 0.0.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(JUCE)

juce_add_plugin(TubeScreamer
    COMPANY_NAME "Barabas Raffai"
    PLUGIN_MANUFACTURER_CODE BaRa
    PLUGIN_CODE Tube
    FORMATS VST3 Standalone
    PRODUCT_NAME "Tube Screamer")

juce_generate_juce_header(TubeScreamer)

target_sources(TubeScreamer
    PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp
        FaustParameterFloat.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/TubeScreamer.h)

target_include_directories(TubeScreamer
    PRIVATE
        .
        ${CMAKE_CURRENT_BINARY_DIR})

target_compile_definitions(TubeScreamer
    PUBLIC
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

#TODO remove unused libraries
target_link_libraries(TubeScreamer
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/TubeScreamer.h
     COMMAND faust -i -a faustMinimal.h tubescreamer.dsp -o ${CMAKE_CURRENT_BINARY_DIR}/TubeScreamer.h
     DEPENDS tubescreamer.dsp
     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
     VERBATIM)
