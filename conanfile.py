from conans import ConanFile
from parktoma.vscconan import update_cpp_tools



class DepsConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "glfw/3.3.2@bincrafters/stable", "stb/20200203", "glad/0.1.33", "spdlog/1.5.0", "lua/5.3.5", "imgui/1.75", "glad/0.1.33", "glm/0.9.9.7", "openal/1.19.1", "lua/5.3.5", "nlohmann_json/3.7.3"
    generators = "premake", "cmake"

    def imports(self):
        update_cpp_tools(self, conanfile_path=__file__)
