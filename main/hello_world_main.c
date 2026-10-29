/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"

#include"bluetooth.h"
#include"bluetooth_spp.h"

void app_main(void)
{
    printf("Hello world!\n");
    // print_data();

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");


    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    printf("before bt init");
    bt_app_main();
    printf("After bt init");

    printf("before bt_spp init");
    // bt_app_main();
    bt_spp_init();
    printf("before bt_spp init");

    // // for (int i = 10; i >= 0; i--) {
    // //     printf("Restarting in %d seconds...\n", i);
    //     vTaskDelay(10000 / portTICK_PERIOD_MS);
    // // }
    // printf("Restarting now.\n");
    // fflush(stdout);
    // esp_restart();
}
