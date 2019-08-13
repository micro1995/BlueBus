/*
 * IO Mappings for the PIC24
 */
#ifndef MAPPINGS_H
#define MAPPINGS_H

#define BC127_UART_MODULE 1
#define BC127_UART_RX_PIN 21
#define BC127_UART_TX_PIN 26

#define SYSTEM_UART_MODULE 2
#define SYSTEM_UART_RX_PIN 23
#define SYSTEM_UART_TX_PIN 24

#define BOOTLOADER_PLATFORM "BLUEBUS_BOOTLOADER_1_3"
/* Defined in milliseconds */
#define BOOTLOADER_TIMEOUT 250

#define BOOT_MODE_APPLICATION 0
#define BOOT_MODE_BOOTLOADER 1
#define BOOT_MODE_NOW 2

#define BOOT_SOURCE_SYSTEM 0x01
#define BOOT_SOURCE_BC127 0x02

#define CONFIG_BOOTLOADER_MODE 0x04
#define CONFIG_SN_MSB 0x00
#define CONFIG_SN_LSB 0x01

#define BOOTLOADER_BOOTLOADER_START 0x800
#define BOOTLOADER_APPLICATION_START 0x1800
#define BOOTLOADER_APPLICATION_VECTOR 0x2000
#define BOOTLOADER_APPLICATION_END 0xAA700

#define ON_LED_MODE TRISEbits.TRISE0
#define ON_LED LATEbits.LATE0

#define EEPROM_SPI_SDO_MODE 7
#define EEPROM_SPI_SCK_MODE 8
#define EEPROM_CS_PIN PORTDbits.RD8
#define EEPROM_CS_IO_MODE TRISDbits.TRISD8
#define EEPROM_SCK_PIN RPOR8bits.RP16R
#define EEPROM_SDI_PIN 4
#define EEPROM_SDO_PIN RPOR15bits.RP30R

#define BT_DATA_SEL_MODE TRISEbits.TRISE4
#define BT_DATA_SEL LATEbits.LATE4

#define UART_SEL_MODE TRISDbits.TRISD3
#define UART_SEL LATDbits.LATD3
#define UART_SEL_BT 0
#define UART_SEL_MCU 1

#define IVT_MODE INTCON2bits.AIVTEN
#define IVT_MODE_APP 1
#define IVT_MODE_BOOT 0

#define RECOVERY_MODE TRISDbits.TRISD5 
#define RECOVERY_STATUS PORTDbits.RD5

#define NOP_COUNT 1024
#endif /* MAPPINGS_H */
