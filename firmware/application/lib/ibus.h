/*
 * File:   ibus.h
 * Author: Ted Salmon <tass2001@gmail.com>
 * Description:
 *     This implements the I-Bus
 */
#ifndef IBUS_H
#define IBUS_H
#define IBUS_CDC_GET_STATUS 0x00
#define IBUS_CDC_PLAYING 0x09
#define IBUS_CDC_NOT_PLAYING 0x02
#define IBUS_CDC_CHANGE_TRACK 0x0A
#define IBUS_CDC_STOP_PLAYING 0x01
#define IBUS_CDC_START_PLAYING 0x02
#define IBUS_CDC_START_PLAYING_BM54 0x03
#define IBUS_CDC_START_PLAYING_CD53 0x03
#define IBUS_CDC_SCAN_CD53 0x04
#define IBUS_CDC_SCAN_FORWARD 0x03
#define IBUS_CDC_SCAN_BACKWARDS 0x04
#define IBUS_CDC_MANUAL_MODE 0x04
#define IBUS_CDC_SONG_END 0x05
#define IBUS_CDC_CD_CHANGE 0x06
#define IBUS_CDC_SCAN_MODE 0x07
#define IBUS_CDC_SCAN_MODE_ACTION 0x19
#define IBUS_CDC_RANDOM_MODE 0x08
#define IBUS_CDC_RANDOM_MODE_ACTION 0x29
/* Sending this to the BM53 prevents it from clearing the GT as often */
#define IBUS_CDC_BM53_START_PLAYING 0x01
#define IBUS_CDC_BM53_PLAYING 0x0C
// Commands
#define IBUS_COMMAND_CDC_ALIVE 0x01
#define IBUS_COMMAND_CDC_GET_STATUS 0x38
#define IBUS_COMMAND_CDC_SET_STATUS 0x39
// Devices
#define IBUS_DEVICE_GM 0x00 /* Body module */
#define IBUS_DEVICE_CDC 0x18 /* CD Changer */
#define IBUS_DEVICE_FUH 0x28 /* Radio controlled clock */
#define IBUS_DEVICE_CCM 0x30 /* Check control module */
#define IBUS_DEVICE_GT 0x3B /* Graphics driver (in navigation system) */
#define IBUS_DEVICE_DIA 0x3F /* Diagnostic */
#define IBUS_DEVICE_GTF 0x43 /* Graphics driver for rear screen (in navigation system) */
#define IBUS_DEVICE_EWS 0x44 /* EWS (Immobileiser) */
#define IBUS_DEVICE_CID 0x46 /* Central information display (flip-up LCD screen) */
#define IBUS_DEVICE_MFL 0x50 /* Multi function steering wheel */
#define IBUS_DEVICE_IHK 0x5B /* HVAC */
#define IBUS_DEVICE_RAD 0x68 /* Radio */
#define IBUS_DEVICE_DSP 0x6A /* DSP */
#define IBUS_DEVICE_SM0 0x72 /* Seat memory - 0 */
#define IBUS_DEVICE_SDRS 0x73 /* Sirius Radio */
#define IBUS_DEVICE_CDCD 0x76 /* CD changer, DIN size. */
#define IBUS_DEVICE_NAVE 0x7F /* Navigation (Europe) */
#define IBUS_DEVICE_IKE 0x80 /* Instrument cluster electronics */
#define IBUS_DEVICE_GLO 0xBF /* Global, broadcast address */
#define IBUS_DEVICE_MID 0xC0 /* Multi-info display */
#define IBUS_DEVICE_TEL 0xC8 /* Telephone */
#define IBUS_DEVICE_TCU 0xCA /* BMW Assist */
#define IBUS_DEVICE_LCM 0xD0 /* Light control module */
#define IBUS_DEVICE_IRIS 0xE0 /* Integrated radio information system */
#define IBUS_DEVICE_ANZV 0xE7 /* Front display */
#define IBUS_DEVICE_BMBT 0xF0 /* On-board monitor */
#define IBUS_DEVICE_LOC 0xFF /* Local */

// All buttons presses are triggered on the "Push" message
#define IBUS_DEVICE_BMBT_Button_Next 0x00
#define IBUS_DEVICE_BMBT_Button_Prev 0x10
#define IBUS_DEVICE_BMBT_Button_PlayPause 0x14
#define IBUS_DEVICE_BMBT_Button_Knob 0x05
#define IBUS_DEVICE_BMBT_Button_Display 0x30

#define IBUS_CMD_BMBT_BUTTON 0x48

#define IBUS_CMD_CD53_CD_SEL 0x06

#define IBUS_CMD_DIAG_IDENTITY 0xA0

#define IBUS_CMD_GT_SCREEN_MODE_SET 0x45
#define IBUS_CMD_GT_MENU_SELECT 0x31
#define IBUS_CMD_GT_WRITE_MK4 0x21
#define IBUS_CMD_GT_WRITE_TITLE 0x23
// Newer GTs use a different action to write to fields
#define IBUS_CMD_GT_WRITE_MK2 0xA5
#define IBUS_CMD_GT_WRITE_INDEX 0x60
#define IBUS_CMD_GT_WRITE_INDEX_TMC 0x61
#define IBUS_CMD_GT_WRITE_ZONE 0x62
#define IBUS_CMD_GT_WRITE_STATIC 0x63

#define IBUS_CMD_GT_DISPLAY_RADIO_MENU 0x37

#define IBUS_CMD_IGN_STATUS_REQ 0x11

#define IBUS_CMD_RAD_SCREEN_MODE_UPDATE 0x46
#define IBUS_CMD_RAD_UPDATE_MAIN_AREA 0x23
#define IBUS_CMD_RAD_C43_SCREEN_UPDATE 0x21
#define IBUS_CMD_RAD_C43_SET_MENU_MODE 0xC0
#define IBUS_CMD_RAD_WRITE_MID_DISPLAY 0x23
#define IBUS_CMD_RAD_WRITE_MID_MENU 0x21

#define IBUS_GT_MKI 1
#define IBUS_GT_MKII 2
#define IBUS_GT_MKIII 3
#define IBUS_GT_MKIV 4
// MKIV Nav systems with version >= 40 support static screens
#define IBUS_GT_MKIV_STATIC 5
#define IBUS_GT_HW_ID_OFFSET 11
#define IBUS_GT_SW_ID_OFFSET 33
#define IBUS_GT_TONE_SELECT_MENU_OFF 0x0C
#define IBUS_GT_RADIO_SCREEN_OFF 0x02
#define IBUS_IGNITION_OFF 0
#define IBUS_IGNITION_ON 1

#define IBusMIDSymbolNext 0xC9
#define IBusMIDSymbolBack 0xCA

#define IBus_MID_MAX_CHARS 23
#define IBus_MID_TITLE_MAX_CHARS 11
#define IBus_MID_MENU_MAX_CHARS 4

#define IBUS_TX_TIMEOUT_OFF 0
#define IBUS_TX_TIMEOUT_ON 1
#define IBUS_TX_TIMEOUT_DATA_SENT 2
#define IBUS_TX_TIMEOUT_WAIT 250

#define IBusEvent_CDKeepAlive 33
#define IBusEvent_CDStatusRequest 34
#define IBusEvent_CDClearDisplay 35
#define IBusEvent_IgnitionStatus 36
#define IBusEvent_GTDiagResponse 37
#define IBusEvent_BMBTButton 38
#define IBusEvent_GTMenuSelect 39
#define IBusEvent_ScreenModeUpdate 40
#define IBusEvent_RADUpdateMainArea 41
#define IBusEvent_ScreenModeSet 42
#define IBusEvent_RADDiagResponse 43
#define IBusEvent_MFLButton 44
#define IBusEvent_RADC43ScreenModeUpdate 45
#define IBusEvent_RADDisplayMenu 46
#define IBusEvent_RADMIDDisplayText 47
#define IBusEvent_RADMIDDisplayMenu 48
#define IBusEvent_LightStatus 49

#define IBus_UI_CD53 1
#define IBus_UI_BMBT 2
#define IBus_UI_MID 3
#define IBus_UI_MID_BMBT 4
#define IBus_UI_BUSINESS_NAV 5
#define IBus_CDC_DiscCount1 0x01
#define IBus_CDC_DiscCount6 0x3F

#define IBUS_C43_TITLE_MODE 0xC4

#define IBUS_RADIO_TYPE_C43 1
#define IBUS_RADIO_TYPE_BM53 2
#define IBUS_RADIO_TYPE_BM54 3
#define IBUS_RADIO_TYPE_BRCD 4
#define IBUS_RADIO_TYPE_BRTP 5

#define IBUS_LCM_LIGHT_STATUS 0x5B
#define IBUS_LCM_E46_DRV_SIG_BIT 5
#define IBUS_LCM_E46_PSG_SIG_BIT 6
#define IBUS_LCM_E46_BLINKER_DRV 0x50
#define IBUS_LCM_E46_BLINKER_PSG 0x80

#define IBUS_LCM_DRV_SIG_BIT 5
#define IBUS_LCM_PSG_SIG_BIT 6
#define IBUS_LCM_BLINKER_DRV 0x80
#define IBUS_LCM_BLINKER_PSG 0x40
#define IBUS_LCM_BLINKER_DRV_E46 0x50
#define IBUS_LCM_BLINKER_PSG_E46 0x80

#define IBUS_MFL_BTN_EVENT 0x3B
#define IBusMFLButtonNextRelease 0x21
#define IBusMFLButtonPrevRelease 0x28
#define IBusMFLButtonRTPress 0x40
#define IBusMFLButtonRTRelease 0x00
#define IBusMFLButtonVoiceRelease 0xA0
#define IBusMFLButtonVoiceHold 0x90

#define IBUS_VEHICLE_TYPE_E38_E39_E53 0x01
#define IBUS_VEHICLE_TYPE_E39_LATE 0x02
#define IBUS_VEHICLE_TYPE_E46 0x03
#define IBUS_VEHICLE_TYPE_E46_LCI_Z4 0x04

// Configuration and protocol definitions
#define IBUS_MAX_MSG_LENGTH 47 // Src Len Dest Cmd Data[42 Byte Max] XOR
#define IBUS_RAD_MAIN_AREA_WATERMARK 0x10
#define IBUS_RX_BUFFER_SIZE 256
#define IBUS_TX_BUFFER_SIZE 16
#define IBUS_RX_BUFFER_TIMEOUT 70 // At 9600 baud, we transmit ~1.5 byte/ms
#define IBUS_TX_BUFFER_WAIT 7 // If we transmit faster, other modules may not hear us
#include <stdint.h>
#include <string.h>
#include "../mappings.h"
#include "char_queue.h"
#include "log.h"
#include "event.h"
#include "ibus.h"
#include "timer.h"
#include "uart.h"
#include "utils.h"

/**
 * IBus_t
 *     Description:
 *         This object defines helper functionality to allow us to interact
 *         with the I-Bus
 */
typedef struct IBus_t {
    UART_t uart;
    unsigned char rxBuffer[IBUS_RX_BUFFER_SIZE];
    uint8_t rxBufferIdx;
    uint32_t rxLastStamp;
    unsigned char txBuffer[IBUS_TX_BUFFER_SIZE][IBUS_MAX_MSG_LENGTH];
    uint8_t txBufferReadbackIdx;
    uint8_t txBufferReadIdx;
    uint8_t txBufferWriteIdx;
    uint32_t txLastStamp;
    unsigned char cdChangerStatus;
    unsigned char ignitionStatus;
} IBus_t;
IBus_t IBusInit();
void IBusProcess(IBus_t *);
void IBusSendCommand(IBus_t *, const unsigned char, const unsigned char, const unsigned char *, const size_t);
uint8_t IBusGetDeviceManufacturer(const unsigned char);
uint8_t IBusGetRadioType(uint32_t);
uint8_t IBusGetNavHWVersion(unsigned char *);
uint8_t IBusGetNavSWVersion(unsigned char *);
uint8_t IBusGetNavType(unsigned char *);
void IBusCommandCDCAnnounce(IBus_t *);
void IBusCommandCDCKeepAlive(IBus_t *);
void IBusCommandCDCStatus(IBus_t *, unsigned char, unsigned char, unsigned char);
void IBusCommandDIAGetCodingData(IBus_t *, unsigned char, unsigned char);
void IBusCommandDIAGetIdentity(IBus_t *, unsigned char);
void IBusCommandDIAGetIOStatus(IBus_t *, unsigned char);
void IBusCommandDIATerminateDiag(IBus_t *, unsigned char);
void IBusCommandGTUpdate(IBus_t *, unsigned char);
void IBusCommandGTWriteBusinessNavTitle(IBus_t *, char *);
void IBusCommandGTWriteIndex(IBus_t *, uint8_t, char *, unsigned char);
void IBusCommandGTWriteIndexTMC(IBus_t *, uint8_t, char *, unsigned char);
void IBusCommandGTWriteIndexTitle(IBus_t *, char *);
void IBusCommandGTWriteIndexStatic(IBus_t *, uint8_t, char *);
void IBusCommandGTWriteTitle(IBus_t *, char *);
void IBusCommandGTWriteTitleC43(IBus_t *, char *);
void IBusCommandGTWriteZone(IBus_t *, uint8_t, char *);
void IBusCommandIKEGetIgnition(IBus_t *);
void IBusCommandIKEText(IBus_t *, char *);
void IBusCommandIKETextClear(IBus_t *);
void IBusCommandLCMEnableBlinker(IBus_t *, unsigned char, unsigned char);
void IBusCommandMIDDisplayTitleText(IBus_t *, char *);
void IBusCommandMIDDisplayText(IBus_t *, char *);
void IBusCommandMIDMenuText(IBus_t *, uint8_t, char *);
void IBusCommandRADC43ScreenModeSet(IBus_t *, unsigned char);
void IBusCommandRADClearMenu(IBus_t *);
void IBusCommandRADDisableMenu(IBus_t *);
void IBusCommandRADEnableMenu(IBus_t *);
void IBusCommandRADExitMenu(IBus_t *);
/* Temporary */
void IBusCommandIgnitionStatus(IBus_t *, unsigned char);
void IBusCommandLCMTurnLeft(IBus_t *);
void IBusCommandLCMTurnRight(IBus_t *);
#endif /* IBUS_H */
