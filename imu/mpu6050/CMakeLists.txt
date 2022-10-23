add_executable(mpu6050 
        mpu6050.cpp
        )

target_link_libraries(mpu6050 pico_stdlib)
pico_add_extra_outputs(mpu6050)