# morpho-datetime Extension

This is an experiment of mine to use a Rust library to write a Morpho extension.

Here, I built a simple date-time module using the [chrono](https://docs.rs/chrono/latest/chrono/index.html) crate. I wrote simple functions to print `chrono::offset::Local::now())` and `chrono::offset::Utc::now())` and expose them to C using Rust-ffi. Building this as a dynamic library, I then linked them to the morpho extension in the CmakeLists.txt like so:

```
target_link_libraries(datetime ${MORPHO_LIBRARY} ${CMAKE_SOURCE_DIR}/src/datetimers/target/release/libdatetimers.dylib)
```

Lots more to document, but it seems to work!
