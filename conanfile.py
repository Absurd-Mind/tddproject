import os

from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps

class tddprojectRecipe(ConanFile):
    name = "tddproject"
    version = "1.0"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*", "include/*", "test/*"
    test_requires = "catch2/3.3.2", "fakeit/2.4.0"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if not self.conf.get("tools.build:skip_test", default=False):
            test_folder = os.path.join("test")
            if self.settings.os == "Windows":
                test_folder = os.path.join("test", str(self.settings.build_type))
            self.run(os.path.join(test_folder, "test_all"))

    def package(self):
        cmake = CMake(self)
        cmake.install()

