add_executable(gy-neo6mv2 
        gy-neo6mv2.cpp
        )

target_link_libraries(gy-neo6mv2 pico_stdlib hardware_uart)
pico_add_extra_outputs(gy-neo6mv2)

