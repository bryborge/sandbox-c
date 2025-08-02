project('sandbox-c', 'c')

# Create a library from greeting.c (contains the testable functions)
greeting_lib = static_library('greeting_lib', 'src/greeting.c',
    include_directories: include_directories('src'))

# Main executable
executable('demo', ['src/main.c'],
    link_with: greeting_lib,
    include_directories: include_directories('src'))

# Test executable
test_exe = executable('test_main',
    'tests/test_main.c',
    link_with: greeting_lib,
    include_directories: include_directories('src')
)

# Register test
test('main_test', test_exe)
