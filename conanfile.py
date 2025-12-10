from conan import ConanFile
from conan.tools.cmake import cmake_layout

class MatrixConanFile(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"
    
    def requirements(self):
        self.requires("argparse/3.2")
        self.requires("spdlog/1.16.0")
        self.requires("magic_enum/0.9.7")


    def build_requirements(self):
        self.test_requires("catch2/3.11.0")
        
    def layout(self):
        cmake_layout(self)