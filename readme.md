# CMake sample of parallel projects with shared build artefacts

Scenario:
You have a project A with libaries build as part of the build. Another project B builds on top of the lbiraries that get build by A's build process. B should not build the libraries again and reuse the CMake targets defined by the libraries.

to build this, start at the directory level which contains this readme.

~~~bash
mkdir -p build/project_a
cd build/project_a
cmake ../../project_a
make
./project_a
~~~

this builds project A and the libs it depends on. the libs could be installed, untested as not the scope here. project B rather makes use of targets that got exported by the libraries. Those are found only because project B is build adjacent to project A in the same build folder. Sadly CMake makes it hard to discover a specific files recursively, so this aproach is still fickle.

~~~bash
cd ..
mkdir -p build/project_b
cd build/project_b
cmake ../../project_b
make
./project_b
~~~

Please tell others where you got inspired if you are going to use this in one of your projects.

Regards
Thomas Lobig
