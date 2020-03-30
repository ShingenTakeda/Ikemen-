from conans import ConanFile

class DepsConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "poco/1.10.1","glfw/3.3.2@bincrafters/stable", "stb/20200203", "glad/0.1.33", "spdlog/1.5.0", "lua/5.3.5", "imgui/1.75", "glad/0.1.33", "glm/0.9.9.7"
    generators = "premake", "gcc", "txt"
