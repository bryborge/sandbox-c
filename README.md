# Sandbox (C Edition)

A portable "C" Development Environment for experimentation and glory.

## ⚙️ Dependencies

-   [Podman](https://podman.io/)

## 🔧 Up and Running

These instructions assume you have the above dependencies installed, configured, and running.

1.  Spin up the container.

    ```sh
    podman compose up -d
    ```

2.  Optional: Enter the container.

    ```sh
    podman compose exec sandbox-c bash
    ```

### ⚙️ Build System

This project uses the [Meson](https://mesonbuild.com/index.html) build system.

1.  Configure the build directory.

    ```sh
    meson setup build
    ```

2.  Compile the build.

    ```sh
    meson compile -C build
    ```

3.  Run the compiled artifact.

    ```
    ./build/demo
    ```

### ✅ Testing

To run the test suite (after compiling), run the following command.

```sh
meson test -C build -v
```

### 🐛 Debugging / Profiling

This project uses [Valgrind](https://valgrind.org/) for debugging and profiling.

1.  Build with debug info and compile.

    ```sh
    meson setup build -Dbuildtype=debug
    meson compile -C build
    ```

2.  Look for memory errors and leaks _(Memcheck)_.

    ```sh
    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=1 ./build/demo
    ```

3.  Thread / data race debugging _(Helgrind)_.

    ```sh
    valgrind --tool=helgrind --error-exitcode=1 ./build/demo
    ```

4.  CPU profiling _(Callgrind)_.

    ```sh
    valgrind --tool=callgrind ./build/demo
    ```

    Analyze:

    ```sh
    callgrind_annotate --threshold=99 callgrind.out.* | less
    ```

5) Heap profiling over time _(Massif)_.

    ```sh
    valgrind --tool=massif ./build/demo
    ```

    Analyze:

    ```sh
    ms_print massif.out.* | less
    ```

## 📚 Resources

-   [GNU Make Documentation](https://www.gnu.org/software/make/)
-   [Meson Documentation](https://mesonbuild.com/SimpleStart.html)
-   [Microsoft's C Documentation](https://learn.microsoft.com/en-us/cpp/c-language/?view=msvc-170)
-   ["Official" C Documentation (ISO Standard)](https://www.iso.org/standard/82075.html)
-   [Valgrind Documentation](https://valgrind.org/docs/)
