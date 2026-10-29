idf_component_register(SRC_DIRS "src"
                       PRIV_REQUIRES bt nvs_flash
                       INCLUDE_DIRS "inc")

#    idf_component_register(SRCS "src/Bluetooth.c" "src/bluetooth_spp.c"
#    INCLUDE_DIRS "inc")