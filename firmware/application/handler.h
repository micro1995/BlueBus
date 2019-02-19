/*
 * File: handler.h
 * Author: Ted Salmon <tass2001@gmail.com>
 * Description:
 *     Implement the logic to have the BC127 and IBus communicate
 */
#ifndef HANDLER_H
#define HANDLER_H
#define _ADDED_C_LIB 1
#include <stdio.h>
#include "lib/bc127.h"
#include "lib/debug.h"
#include "lib/event.h"
#include "lib/ibus.h"
#include "lib/timer.h"
#include "lib/utils.h"
#include "ui/cd53.h"
#include "ui/bmbt.h"
#define HANDLER_BT_CONN_OFF 0
#define HANDLER_BT_CONN_ON 1
#define HANDLER_CDC_ANOUNCE_INT 1000
#define HANDLER_CDC_ANOUNCE_TIMEOUT 21000
#define HANDLER_CDC_STATUS_INT 500
#define HANDLER_CDC_STATUS_TIMEOUT 20000
#define HANDLER_DEVICE_MAX_RECONN 10
#define HANDLER_INT_DEVICE_CONN 30000
#define HANDLER_PROFILE_ERROR_INT 2500
#define HANDLER_SCAN_INT 60000
typedef struct HandlerContext_t {
    BC127_t *bt;
    IBus_t *ibus;
    uint8_t btStartupIsRun;
    uint8_t btConnectionStatus;
    uint8_t uiMode;
    uint8_t deviceConnRetries;
    uint32_t cdChangerLastKeepAlive;
    uint32_t cdChangerLastStatus;
} HandlerContext_t;
void HandlerInit(BC127_t *, IBus_t *, uint8_t);
void HandlerStartup(HandlerContext_t *);
void HandlerBC127DeviceLinkConnected(void *, unsigned char *);
void HandlerBC127DeviceDisconnected(void *, unsigned char *);
void HandlerBC127DeviceFound(void *, unsigned char *);
void HandlerBC127PlaybackStatus(void *, unsigned char *);
void HandlerBC127Ready(void *, unsigned char *);
void HandlerIBusCDCKeepAlive(void *, unsigned char *);
void HandlerIBusCDCStatus(void *, unsigned char *);
void HandlerIBusGTDiagnostics(void *, unsigned char *);
void HandlerIBusRADDiagnostics(void *, unsigned char *);
void HandlerIBusIgnitionStatus(void *, unsigned char *);
void HandlerTimerCDCAnnounce(void *);
void HandlerTimerCDCSendStatus(void *);
void HandlerTimerDeviceConnection(void *);
void HandlerTimerOpenProfileErrors(void *);
void HandlerTimerScanDevices(void *);
#endif /* HANDLER_H */
