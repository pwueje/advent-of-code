install:
	conan install . --build=missing -s build_type=Debug -pr:h .conan/default -pr:b .conan/default
	conan install . --build=missing -s build_type=Release -pr:h .conan/default -pr:b .conan/default