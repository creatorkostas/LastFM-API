# LastFM-API

An easy to use api for [https://www.last.fm](https://www.last.fm) for c++ aplications.

## Usage

1. Clone the repository in your project folder

```bash
git clone https://github.com/creatorkostas/LastFM-API
```

2. In your `CMakeLists.txt` file include the library

```cmake
add_subdirectory(LastFM-API)
include_directories(LastFM-API)

target_link_libraries(${PROJECT_NAME} LastFMApi)
```

3. To use the this library include the `LastFMApi.hpp` file


## License

This work is published under the [MIT License](LICENSE)